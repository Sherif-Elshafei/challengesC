#include <iostream>
#include <cstdio>
#include <cstring>

using std::string;

class Tire{
    public:
    int pressure;
    Tire();
    Tire(int p):pressure(p){}
};

class SimpleTire:public Tire{
    public:
    SimpleTire():Tire(75){}
};

class LuxuryTire:public Tire{
    public:
    LuxuryTire():Tire(100){}
};

class Body{
    public:
    int strength;
    Body();
    Body(int s):strength(s){}
};

class SimpleBody:public Body{
    public:
    SimpleBody():Body(750){}
};

class LuxuryBody:public Body{
    public:
    LuxuryBody():Body(1500){}
};

class Car{
    private:
    Tire* tire;
    Body* body;
    string name;
    public:
    Car();
    Car(string s):name(s){};
    void setTire(Tire* t){
        std::cout<<"here we are setting tire "<<std::endl;
        tire = t;
    }
    void setBody(Body* b){
        std::cout<<"here we are setting body"<<std::endl;
        body = b;
    }
    void showCarDetails(){
        std::cout<<"printing car details: "<<tire->pressure<<" "<<body->strength<<std::endl;
    }
};

class CarFactory{
    private:
    Car* car;
    public:
    virtual Car* buildWholeCar()=0;
    virtual Tire* buildTire()=0;
    virtual Body* buildBody()=0;
};

class SimpleCarFactory:public CarFactory{
    Tire* buildTire(){
        return new SimpleTire();
    }
    Body* buildBody(){
        return new SimpleBody();
    }
    public:
    SimpleCarFactory(){std::cout<<"hello simple car"<<std::endl;};
    Car* buildWholeCar(){
        Car* c = new Car("Simple Car");
        c->setTire(buildTire());
        c->setBody(buildBody());
        return c;
    }
};

class LuxuryCarFactory:public CarFactory{
    Tire* buildTire(){
        return new LuxuryTire();
    }
    Body* buildBody(){
        return new LuxuryBody();
    }
    public:
    LuxuryCarFactory();
    Car* buildWholeCar(){
        Car* c = new Car("Luxury Car");
        c->setTire(this->buildTire());
        c->setBody(this->buildBody());
        return c;
    }
};