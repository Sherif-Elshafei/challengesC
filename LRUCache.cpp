#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache{
    public:
    LRUCache (int capacity) {
        mp= {};
        cp = capacity;
        tail = NULL;
        head = NULL;
    };    
    ~LRUCache(){/*cout<<"Destructor in LRUCache"<<endl;*/}

    public:
    void set(int key, int value);
    int get(int key);
};

void LRUCache::set(int key, int value){
   int maxValue = -100;
   int key_of_max_value;

   Node* node_to_be_inserted = new Node(1,value);
   if (mp.count(key)==0){
      //if cache key doesn't exists in map
      if (mp.size() < cp){
         //Cache still have space
         for (auto itr = mp.begin(); itr!= mp.end(); itr++){
            itr->second->key ++;
         }
         mp[key]=node_to_be_inserted;
      }
      else{
         //Cache capacity is filled
         for (auto itr = mp.begin(); itr!= mp.end(); itr++){
            itr->second->key++;
         }
         for (const auto &entry: mp){
            if (maxValue < entry.second->key){
               maxValue = entry.second->key;
               key_of_max_value = entry.first;
            }
         }
         mp.erase(key_of_max_value);
         mp[key_of_max_value]=node_to_be_inserted;
      }
   }
   else{
      //key exists in map
      const auto iterator_to_existent_key=mp.find(key);
      int t = iterator_to_existent_key->second->key;
      for (const auto &entry:mp){
         if (entry.second->key<t){
            entry.second->key++;
         }
      }
      mp.erase(iterator_to_existent_key->first);
      mp[iterator_to_existent_key->first]=node_to_be_inserted;
   }
}

int LRUCache::get(int key){
   if (mp.count(key)==0){
      return -1;
   }
   else{
      const auto iterator_to_existent_key=mp.find(key);
      int t = iterator_to_existent_key->second->key;
      for (const auto &entry:mp){
         if (entry.second->key<t){
            entry.second->key++;
         }
         else if (entry.second->key==t){
            entry.second->key = 1;
         }
      }
      //iterator_to_existent_key->second->key=1;
      return iterator_to_existent_key->second->value;
   }
}


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}
