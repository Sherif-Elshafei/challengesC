#include <iostream>
#include <deque> 

using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    int result[n-k+1];
	deque<int> dq(k);
	int count;
	count = 0;
	for (int i=0; i<n; i++){
		dq.push_front(i);
		if(arr[i]>=arr[dq.back()]){
			dq.pop_back();
		}
		if (count<k){
			count ++;
		}
		else {
			count=0;
		}
	}
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}