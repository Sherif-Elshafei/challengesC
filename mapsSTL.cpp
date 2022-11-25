#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
using namespace std;


int main() {
    int num;
    map<string,int> m;
    map<string,int>::iterator it;
    int grade, t;
    string name;
    struct Query_Tuple{
        int q;
        string x;
        int y;
    };
    Query_Tuple query_tuple;
    vector<Query_Tuple> vec;
    

    cin>>num;
    for (int i=0;i<num;i++){
        cin>>query_tuple.q;
        if (query_tuple.q==1){
            cin>>query_tuple.x>>query_tuple.y;
        }
        else{
            cin>>query_tuple.x; 
            query_tuple.y = -1;
        }
        vec.push_back(query_tuple);
    }

    for (int i=0; i<num; i++){
        switch(vec[i].q){
            case 1:
                it = m.find(vec[i].x);
                if (it!=m.end()){
                    it->second=it->second+vec[i].y;
                }
                else{
                    m.insert(make_pair(vec[i].x, vec[i].y));
                }
                break;
            case 2:
                m.erase(vec[i].x);
                break;
            case 3:
                it = m.find(vec[i].x);
                if(it!=m.end()){
                   cout<<m[vec[i].x]<<endl;
                }
                else{
                    cout<<0<<endl;
                }
                break;       
        }
    }
    return 0;
}