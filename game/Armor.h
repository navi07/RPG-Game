#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Error.h"
#include "Item.h"
#include "Player.h"
#include "Character.h"
using namespace std;

class Armor : public Item
{
    int defence;

public:
    Armor ()
    {
        defence = 10;
        cout << "Zalozono zbroje \n";
    }
    Armor (int d, int w, string n) : Item(w, n)
    {
        defence = d;
        cout << "Zalozono zbroje \n";
    }
    Armor (const Armor  &w)
    {
        defence = w.defence;
        cout << "Zalozono zbroje \n";
    }
    ~Armor (){}

    int getdefense()
    {
        return defence;
    }

    bool repeat = false;

    void setDefence(Player *p)
    {
        int _defence;
        do
        {
            try
            {
                cout << "Podaj obrone : ";
                cin >> _defence;
                defence = _defence;
                p->defence = p->getDefence() + defence;
                if (!cin || _defence <= 0)
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    throw Error(Error::_defence);
                }
                repeat = false;
            }
            catch (Error &e)
            {
                e.what();
                repeat = true;
            }
        }while(repeat);
    }

    void show()
    {
        cout << "Zbroja [" << getName() << ", waga -> " << getWeight() << "]" << endl;
        cout << "Obrona :" << defence << endl;
        cout << "--------------------------------------------" << endl;
    }
};