#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Error.h"
#include "Character.h"
using namespace std;

class Monster : public Character
{
    string atrybut;

public:
    Monster()
    {
        atrybut = "Slaby";
        cout << "Stworzono potwora \n";
    }
    Monster(string atryb, string n, int h, int att, int obr) : Character(h, att, obr, n)
    {
        atrybut = atryb;
        cout << "Stworzono potwora \n";

    }
    Monster(const Monster &w)
    {
        atrybut = w.atrybut;
        cout << "Stworzono potwora \n";
    }
    ~Monster(){}

    string getAtrybut()
    {
        return atrybut;
    }

    bool repeat = false;

    void setAtrybut()
    {
        string _atrybut;
        do
        {
            try
            {
                cout << "Podaj atrybut : ";
                cin >> _atrybut;
                atrybut = _atrybut;
                for (int i = 0; i < _atrybut.length(); i++)
                    if (isdigit(_atrybut[i])) throw Error(Error::_atrybut);
                repeat = false;
            }
            catch(Error &e)
            {
                e.what();
                repeat = true;
            }
        }while(repeat);
    }

    void show()
    {
        cout << "Potwor [" << getName() << ", " << getAtrybut() << "]" << endl;
        cout << "HP: " << getHP() << endl;
        cout << "Atak: " << getAttack() << endl;
        cout << "Obrona: " << getDefence() << endl;
        cout << "--------------------------------------------" << endl;
    }
};