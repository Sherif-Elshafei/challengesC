#include "abstractFactoryClasses.h"

int main(){
    CarFactory* factory = new SimpleCarFactory();
    Car* c = factory->buildWholeCar();
    c->showCarDetails();
    return 0; 
}