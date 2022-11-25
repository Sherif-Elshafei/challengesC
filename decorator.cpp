#include <string>
#include <iostream>
using namespace std;

class Beverage {
    private:
    double cost;
    string description;
    public:
    Beverage(){}
    virtual string getDescription()=0;
    virtual double getCost()=0;
};

class HouseBlend : public Beverage {
    private:
    double cost = 1.50;
    string description = "House_Blend";
    public:
    HouseBlend(){}
    string getDescription(){return this->description;}
    double getCost(){return this->cost;}
};

class Condiment : public Beverage {
    private:
    Beverage *pbeverage;
    string description;
    double cost;
    public:
    Condiment(){}
    ~Condiment(){};
    virtual string getDescription()=0;
    virtual double getCost()=0;
};

class Milk : public Condiment{
    private:
    Beverage* pbeverage; //or make it protected in Condiment
    double cost = 0.50;
    string description = "Milk";
    public:
    Milk(Beverage* pbeverage1){
        this->pbeverage = pbeverage1;
        }
    string getDescription(){return pbeverage->getDescription() + " + "+ description ;}
    double getCost(){return this->cost + pbeverage->getCost();}
};

int main() {
    Beverage *pbeverage1;
    int x, y;
    while(1){
        std::cout<<"|*****Welcome to our shop*****|\n";
        std::cout<< "Please select a drink (1: House Blend) (2: Roasted Coffee)"<<endl;
        cin>> x;
        switch (x){
            case 1: pbeverage1 = new HouseBlend();
                    break;
            // case 2: pbeverage1 = new RoastedCoffee();
            //         break;
            default:
                    break;
        }
        bool t=1;
        while(t) {
            std::cout<<"Would you like any condiment with your beverage? (1: Milk) (2: Whipped Cream) (0: Checkout)"<<endl;
            cin>> y;
            switch (y){
                case 1: pbeverage1 = new Milk(pbeverage1);
                    break;
                // case 2: pbeverage1 = new WhippedCream(pbeverage1);
                //     break;
                case 0: t=0;
                default:
                    break;
            }
        }
        std::cout << "Thank you ** Your order: " << pbeverage1->getDescription()<<endl;
        std::cout << "Total cost = "<< pbeverage1->getCost() << " EGP. Please proceed to checkout"<< endl<<endl;
        
    }
    return 0;
}