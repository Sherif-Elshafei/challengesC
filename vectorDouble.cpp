#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Matrix{
    public:
    vector<vector<int>> a;
    public:
    Matrix(){}
    // void setMatrix(vector<int> matrixElement){
    //     a.push_back(matrixElement);
    // }
    // vector<vector<int>> getMatrix(){
    //     return a;
    // }
    Matrix operator +(const Matrix &m2) const{
        int s1 = a.size();
        int s2 = a[0].size();
        Matrix temp;
		temp.a.resize(s1);
		for (int j=0;j<s1;j++){
			temp.a[j].resize(s2);
		}
        for(int j=0;j<s1;j++){
            for(int i=0;i<s2;i++){
				//temp.a[j].push_back( a[j][i] + m2.a[j][i] );
				temp.a[j].at(i)= a[j][i] + m2.a[j][i];
			}
        }
        return temp;
    }
};
int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}