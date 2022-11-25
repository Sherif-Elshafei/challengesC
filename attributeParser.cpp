#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string strip_first_part_of_query(string mystring) {
        string first_part_of_query="";
        for (auto x:mystring){
            if(x=='~'){
                break;
            }
            else{
                first_part_of_query = first_part_of_query + x;
            }
        }
        //cout<< "my stripped string is: " << first_part_of_query << endl;
        return first_part_of_query;
    }

string strip_attribute(string mystring) {
    string last_part_of_query="";
    int N = mystring.length();
    for (int i = 0; i<N; i++) {
        if (mystring[i]=='~'){
            for (int j =i+1; j<N; j++){
                last_part_of_query=last_part_of_query+mystring[j];
            }
        }
    }
    return last_part_of_query;
}

int query_tag_count(string s){
    int dot_count=0;
    for(int i=0; i<s.length(); i++){
        if(s[i]=='.'){
            dot_count++;
        }
    }
    return dot_count+1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int n,q;
    char mystring[200];
    string strip_first_part_of_query(string mystring);
    string strip_attribute(string mystring);
    int query_tag_count(string s);

    cin>>n>>q;
    cin.ignore();
    string* inputs = new string[n+q];

    for (int i=0; i<n+q; i++){
        cin.getline(mystring,200);
        inputs[i]=mystring;
    }

    for (int i=n; i<n+q; i++){
        string s1 = strip_first_part_of_query(inputs[i]);
        string s2 = strip_attribute(inputs[i]);
        int dot_count = query_tag_count(s1);
        //cout<<s1<<endl;
        //cout<<s2<<endl;
        //cout<<dot_count<<endl;

        int attribute_found_at = inputs[dot_count-1].find(s2);
        //cout<<attribute_found_at<<endl;
        string strip_value = "";
        if(attribute_found_at==-1){
            cout<<"Not Found!"<<endl;
        }
        else{
            int length_of_attribute = s2.length();
            //cout<<length_of_attribute<<endl;
            int value_start_at = attribute_found_at+length_of_attribute+4;
            //cout<<value_start_at<<endl;
            int value_end_at = value_start_at;
            //cout<<inputs[dot_count-1][value_start_at]<<endl;
            while(inputs[dot_count-1][value_end_at]!='"'){
                //cout<<inputs[i][value_end_at]<<endl;
                strip_value = strip_value + inputs[dot_count-1][value_end_at];
                value_end_at++;
            }
            cout<<strip_value<<endl;
        }
    }
    return 0;   
}