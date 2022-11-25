#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <string>
#include "factoryPatternClasses.h"

int main(){
    int type;
    while(1){
        cout<<"enter type 0 to exit"<<endl;
        cin >> type;
        if(!type){
            break;
        }
        Toy* v = ToyFactory::createToy(type);
        if(v){
            v->showProduct();
            delete v;
        }
    }
    cout<<"Exit.."<<endl;
    return 0;
}

// int main (){
//     int type;
//     while(1){
//         cout<<"enter type 0 to exit"<<endl;
//         cin >> type;
//         if(!type){
//             break;
//         }
//         else if (type==1){
//             Toy* pToy = new Car();
//         }

// }


