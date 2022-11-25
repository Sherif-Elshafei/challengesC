#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    struct Query_Tuple{
        int c;
        int v;
    };
    
    set<int> s;
    vector<Query_Tuple> vec;

    int count;
    Query_Tuple q;

    cin>>count;
    for (int i=0;i<count;i++){
        cin>>q.c>>q.v;
        vec.push_back(q);
    }

    set<int>::iterator it;
    for (int i=0; i<count; i++){
        switch(vec[i].c){
            case 1: s.insert(vec[i].v); break;
            case 2: s.erase(vec[i].v); break;
            case 3: 
                    it=s.find(vec[i].v);
                    //variable = (condition)? expressionTrue: expressionFalse;
                    it != s.end()? cout<<"Yes\n": cout<<"No\n";
                    break;
        }
    }
    return 0;
}