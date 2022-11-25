#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int n, q;
    int a;
    vector<int> v;
    
    cin>>n;
    for (int i=0;i<n;i++){
        cin>>a;
        v.push_back(a);
    }
    
    cin>>q;
    int* p_query = new int[q];
    for (int i=0;i<q;i++){
        cin>>p_query[i];
    }
    
    vector<int>::iterator it1, it2;
    for (int i=0;i<q;i++){
        it1 = lower_bound(v.begin(), v.end(), p_query[i]);
        it2 = find(v.begin(), v.end(), p_query[i]);
        if (it2!=v.end())
            cout<<"Yes ";
        else
            cout<<"No ";
        cout<<( it1-v.begin() + 1 )<<endl;
    }

    // it = lower_bound(v.begin(), v.end(), 10);
    // cout<<*it<<endl;
      
    return 0;
}