#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, s, p, q;
    int count=0;
    cin>>n>>s>>p>>q;

    int* a = new int[n];
    a[0]=s%(2^31);
    for (int i=1; i<n;i++){
        a[i]=(a[i-1]*p)+(q%(s^31));
    }

    bool* flag = new bool[n];
    for (int i=1; i<n;i++){
        flag[i]=false;
    }

    for (int i = 0; i<n; i++){
        if (flag[i]==false){
            flag[i]=true;
            count++;
            for (int j=i+1; j<n; j++){
                if ( (flag[j]==false)&&(a[i]==a[j]) ){
                    flag[j]=true;
                }
            }
        }
        else{
        }
    }
    cout<<count<<endl;    
    return 0;
}