#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int>& arr) {
    vector<int> candy(arr.size(), 1);
    for (int i=1;i<arr.size();i++){
        //cout<<i<<endl;
        if(arr[i]>arr[i-1])
            candy[i]=candy[i-1]+1;
        else if(arr[i]<arr[i-1]){
            if (candy[i]>=candy[i-1]){
                candy[i-1]=candy[i]+1;
            }
        }
        else{}            
    }
    for (int i=candy.size()-1; i>=0;--i){
        //cout<<i<<endl;
        if (arr[i]>arr[i-1]){}
        else if(arr[i]<arr[i-1]){
            if(candy[i]>=candy[i-1])
                candy[i-1]=candy[i]+1;
        }
        else{}
    }
    return accumulate(candy.begin(), candy.end(), 0);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
