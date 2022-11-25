#include<bits/stdc++.h>

using namespace std;

struct Workshop{
   int start_time;
   int duration;
   int end_time;
};

struct Available_Workshops{
   int n; //the number of workshops the student signed up for
   Workshop* array;
};

Available_Workshops* initialize (int start_time[], int duration[], int n){
    Available_Workshops* p_ws = new Available_Workshops;
    p_ws->n = n;
    p_ws->array = new Workshop[n];
    for (int i; i<n; i++){
        p_ws->array[i].start_time = start_time[i];
        p_ws->array[i].duration = duration[i];
    }
    return p_ws;
}

string* find_non_overlapped_workshops(Available_Workshops* p_ws){
    string* p_str = new string[p_ws->n];
    int j;
    for (int i=0; i<p_ws->n; i++){
        for (int j=0; j<p_ws->n; j++){
            if (i!=j){
                //cout<<"i:j"<<" "<<i<<j<<endl;
                if  ( (p_ws->array[i].start_time >= p_ws->array[j].end_time) ||
                    (p_ws->array[i].end_time <= p_ws->array[j].start_time) ) 
                {
                    p_str[i] = p_str[i] + to_string(j) + "," ;
                    //cout<<"here\n";
                }
                else{}
            }
            else{}
        }
    }
    // cout<<"non_overlapped workshops\n";
    // for (int i=0; i<p_ws->n; i++){
    //     cout<<i<<"==="<<p_str[i]<<endl;
    // }
    return p_str;
}

struct Node{
    int index;
    string non_overlapped_workshops;
    bool investigated;
    int* pParent;
};

Node initialize_node(string non_overlapped_workshops, int i){
    Node node;
    node.index = i;
    node.non_overlapped_workshops = non_overlapped_workshops;
    node.pParent = nullptr;
    node.investigated = false;
    return node;
}

Available_Workshops* sort_available_workshops(Available_Workshops* p_ws){
    Available_Workshops* Sorted_Available_Workshops;
    Sorted_Available_Workshops = new Available_Workshops[p_ws->n];
    bool* sorted = new bool[p_ws->n];
    int temp;

    for (int i = 0; i<p_ws->n; i++){
        sorted[i]=false;
    }

    int first_start = 1000;
    for (int j=0; j<p_ws->n; j++){
        for (int i = 0; i<p_ws->n; i++){
            if ( (p_ws->array[i].start_time < first_start)&& (sorted[i]==false) ){
                first_start=p_ws->array[i].start_time;
                temp = i;
            }
        }
        Sorted_Available_Workshops[j]=p_ws[temp];
        sorted[temp]=true;
    }

    for (int j=0; j<p_ws->n; j++){
        cout<<Sorted_Available_Workshops->array[j].start_time<<endl;
    }

    return Sorted_Available_Workshops;
}

int CalculateMaxWorkshops(Available_Workshops* p_ws){
    int max_workshops;
    string* non_overlapped_workshops;
    Available_Workshops* p_sorted_ws;
    Node* p_nodes = new Node[p_ws->n];

    for (int i=0; i<p_ws->n; i++){
        p_ws->array[i].end_time = p_ws->array[i].start_time + p_ws->array[i].duration;
        //cout<<p_ws->array[i].end_time<<endl;
    }

    non_overlapped_workshops = find_non_overlapped_workshops(p_ws);
    
    for (int i=0; i < p_ws->n; i++){
        p_nodes[i] = initialize_node(non_overlapped_workshops[i], i);
    }

    p_sorted_ws=sort_available_workshops(p_ws);

    // for (int i=0; i < p_ws->n; i++){
    //     cout<<p_nodes[i].index<<" "<<p_nodes[i].non_overlapped_workshops<<" "<<p_nodes[i].pParent<<endl;
    // }

    return 598;
}


//Define the structs Workshops and Available_Workshops.
//Implement the functions initialize and CalculateMaxWorkshops

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}
