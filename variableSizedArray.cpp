#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int** ArrayOfPointers;
    int numOfEntriesInArray;
    int numOfQueries;
    int numbOfEntriesInSubArray_i;
    
    scanf("%d %d", &numOfEntriesInArray, &numOfQueries);
    ArrayOfPointers = new int*[numOfEntriesInArray];

    for (int i=0; i<numOfEntriesInArray; i++){
        scanf("%d",&numbOfEntriesInSubArray_i);
        ArrayOfPointers[i]=new int[numbOfEntriesInSubArray_i];
        for(int j=0; j<numbOfEntriesInSubArray_i; j++){
            scanf("%d",&ArrayOfPointers[i][j]);
        }
    }
    
    int *arrayEntryQuery = new int[numOfQueries];
    int *subArrayEntryQuery = new int[numOfQueries];

    for (int i=0; i<numOfQueries; i++){
        scanf("%d %d", &arrayEntryQuery[i], &subArrayEntryQuery[i]);
    }

    for (int k=0; k<numOfQueries; k++){
        printf("%d\n",ArrayOfPointers[arrayEntryQuery[k]][subArrayEntryQuery[k]]);
    }
    
    return 0;
}