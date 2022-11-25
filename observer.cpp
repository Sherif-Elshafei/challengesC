#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

class Observer;
class Car;

class Car{
    std::vector<class Observer*> _observerList;
    int position;

    public:
    Car(){}
    void registerObserver(Observer* _o){
        _observerList.push_back(_o);
    }
    void unregisterObserver(Observer* _o){
        std::vector<Observer*>::iterator itr;
        itr = find(_observerList.begin(),_observerList.end(),_o);
        if ( itr != _observerList.end() ){
            _observerList.erase(itr);
        }
    }
    void notify();

    void setPosition(int p){
        position=p;
        notify();
    }
    int getPosition(){
        return position;
    }
};

class Observer{
    protected:
    Car* _car;
    public:
    Observer(Car* car):_car(car){
        //_car=car;
        _car->registerObserver(this);
    }
    virtual void update()=0;
    Car* getCar(){
        return _car; //get the car you are registered on
    } 
};

void Car::notify(){
    for (int i=0; i<_observerList.size(); i++){
        _observerList[i]->update();
    }
}

class LeftObserver: public Observer{
    public:
    LeftObserver(Car* car):Observer(car){}
    void update(){
        int pos = _car->getPosition();
        std::cout<<pos<<std::endl;
    }
};

class RightObserver:public Observer{
    public:
    RightObserver(Car* car):Observer(car){};
    void update(){
        int pos = _car->getPosition();
        std::cout<<pos<<std::endl;
    }
};

int main(){
    Car* car = new Car();
    Observer* leftobserver = new LeftObserver(car);
    Observer* rightobserver = new RightObserver(car);
    //car->registerObserver(leftobserver);
    //car->registerObserver(rightobserver);
    car->setPosition(1060);
    return 0;
}