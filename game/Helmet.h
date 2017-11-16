#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Error.h"
#include "Item.h"
#include "Player.h"
#include "Character.h"
using namespace std;

class Helmet : public Item
{
    int helmetDefence;

public:
    Helmet ()
    {
        helmetDefence = 10;
        cout << "Zalozono helm \n";
    }
    Helmet (int hd, int w, string n) : Item(w, n)
    {
        helmetDefence = hd;
        cout << "Zalozono helm \n";
    }
    Helmet (const Helmet &w)
    {
        helmetDefence = w.helmetDefence;
        cout << "Zalozono helm \n";
    }
    ~Helmet (){}

    int getHelmetDefence()
    {
        return helmetDefence;
    }

    bool repeat = false;

    void setHelmetDefence(Player *p)
    {
        int _helmetDefence;
        do
        {
            try
            {
                cout << "Podaj obrone helmu : ";
                cin >> _helmetDefence;
                helmetDefence = _helmetDefence;
                p->defence = p->getDefence() + helmetDefence;
                if (!cin || _helmetDefence <= 0)
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
        cout << "Helm [" << getName() << ", waga -> " << getWeight() << "]" << endl;
        cout << "Obrona :" << helmetDefence << endl;
        cout << "--------------------------------------------" << endl;
    }
};

