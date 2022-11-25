#ifndef __includes__
#define __includes__
using namespace std;
#endif

class Toy{
    //this is an abstract class
    private:
    string name;
    float price;
    public:
    void virtual prepareParts()=0;
    void virtual combineParts()=0;
    void virtual assembleParts()=0;
    void virtual applyLabel()=0;
    void virtual showProduct()=0;
};

class Car:public Toy{
    public:
    void prepareParts(){cout<<"preparing car parts"<<endl;}
    void combineParts(){cout<<"combining car parts"<<endl;}
    void assembleParts(){cout<<"assembling car parts"<<endl;}
    void applyLabel(){cout<<"applying car label"<<endl;}
    void showProduct(){cout<<"showing car product"<<endl;}
};

class Bike:public Toy{
    public:
    void prepareParts(){cout<<"preparing bike parts"<<endl;}
    void combineParts(){cout<<"combining bike parts"<<endl;}
    void assembleParts(){cout<<"assembling bike parts"<<endl;}
    void applyLabel(){cout<<"applying bike label"<<endl;}
    void showProduct(){cout<<"showing bike product"<<endl;}
};

class ToyFactory{
    public: 
    static Toy* createToy(int type){
        Toy* pToy=NULL;
        switch(type){
            case 1: pToy = new Car();
                    break;
            case 2: pToy = new Bike();
                    break;
            default:cout<<"not a valid number, please try again"<<endl;
                    return NULL;
        }
        pToy->prepareParts();
        pToy->combineParts();
        pToy->assembleParts();
        pToy->applyLabel();
        return pToy;
    }
};