#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Error.h"
#include "Item.h"
#include "Player.h"
#include "Character.h"
using namespace std;

class Sword : public Item
{
    int attack;

public:
    Sword()
    {
        attack = 10;
        cout << "Zalozono miecz \n";
    }
    Sword(int a, int w, string n) : Item(w, n)
    {
        attack = a;
        cout << "Zalozono miecz \n";

    }
    Sword(const Sword &w)
    {
        attack = w.attack;
        cout << "Zalozono miecz \n";
    }
    ~Sword(){}

    int getAttack()
    {
        return attack;
    }

    bool repeat = false;

    void setAttack(Player *p)
        {
            int _attack;
            do
            {
                try
                {
                    cout << "Podaj atak : ";
                    cin >> _attack;
                    attack = _attack;
                    p->attack = p->getAttack() + attack;
                    if (cin.fail() || _attack <=0)
                    throw Error(Error::_attack);
                    repeat = false;
                }
                 catch(Error &e)
                    {
                        e.what();
                        repeat = true;
                    }
            }while(repeat);
        }

    void wypisz()
    {
        cout << "Miecz [" << getName() << ", waga -> " << getWeight() << "]" << endl;
        cout << "Atak :" << attack << endl;
        cout << "--------------------------------------------" << endl;
    }
};