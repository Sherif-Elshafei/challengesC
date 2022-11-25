#include<iostream>
#include<string>

using namespace std;

class Plane{
    string _name;
    string _body;
    string _engine;

    public:
    Plane(string name):_name(name){}
    void setEngine(string engine){_engine=engine;}
    void setBody(string body){_body=body;}
    void showPlane(){
        cout<<_name<<endl;
        cout<<_body<<endl;
        cout<<_engine<<endl;
    }
};

class PlaneBuilder{
    protected:
    Plane* _plane;
    public:
    virtual void getPartsDone()=0;
    virtual void buildBody()=0;
    virtual void buildEngine()=0;
    Plane* getPlane(){return _plane;}
};

class PropellerBuilder:public PlaneBuilder{
    public:
    void getPartsDone(){ _plane = new Plane("this is a propeller plane"); }
    void buildBody(){ _plane->setBody("propeller body"); }
    void buildEngine(){ _plane->setEngine("propeller engine is built"); }
};

class Director{
    public:
    Plane* createPlane(PlaneBuilder* builder){
        builder->getPartsDone();
        builder->buildBody();
        builder->buildEngine();
        return builder->getPlane();
    }
};

int main(){
    Director dir;
    PropellerBuilder* b1;

    dir.createPlane(b1);
    return 0;
}