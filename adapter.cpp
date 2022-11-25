#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>

using namespace std;

class LocalAdapter{
    public:
    virtual void localCharger(int)=0;
};

class USAAdapter{
    public:
    void usaCharger(){
        cout<<"you are using usa charger"<<endl;
    }
};

class GermanAdapter{
    public:
    void germanCharger(){
        cout<<"you are using german adapter"<<endl;
    }
};

class Adapter:public LocalAdapter, public USAAdapter, public GermanAdapter{
    public:
    Adapter(){}
    void localCharger(int type){
        switch(type){
            case 1: usaCharger();
                    break;
            case 2: germanCharger();
                    break;
            dafault:cout<<"using local adapter"<<endl;
                    break;
        }
    }
};

int main(){
    LocalAdapter* adapter = new Adapter();  
    adapter->localCharger(2);
    return 0;
}
