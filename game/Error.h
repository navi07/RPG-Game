#ifndef Error_h
#define Error_h
#include "Item.h"
#include <iostream>

using namespace std;

class Error
{
    int noError;
public:
    enum {_weight, _name, _attack, _defence, _helmetDefence, _rodzaj, _hp, _atrybut};
    Error(int e)
    {
        noError = e;
    };
    void what()
    {
        switch(noError)
        {
            case _weight:
                cout<<"Bledna waga!"<<endl;
                break;
            case _name:
                cout<<"Bledna nazwa!"<<endl;
                break;
            case _attack:
                cout<<"Bledny atak!"<<endl;
                break;
            case _defence:
                cout<<"Bledna obrona!"<<endl;
                break;
            case _helmetDefence:
                cout<<"Bledna obrona!"<<endl;
                break;
            case _rodzaj:
                cout<<"Bledny type!"<<endl;
                break;
            case _hp:
                cout<<"Bledna ilosc zycia!"<<endl;
                break;
            case _atrybut:
                cout<<"Bledny atrybut!"<<endl;
                break;
            default:
                cout<<"Inny blad!"<<endl;
        }
    }
};

#endif
