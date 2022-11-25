#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int myfunc (int a, int b){
    int* c = new int;
    int d = a+b;
    c = &d;
    return *c;
}

int main(){
    cout<<myfunc(3,4)<<endl;
    return 0;

}