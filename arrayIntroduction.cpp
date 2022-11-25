#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,i;
    int a[1000];
    scanf("%d",&n);
    for (i=0; i<n; i++){
        scanf("%d",&a[i]);
    }
    
    for (i=n-1; i>=0; i--){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
