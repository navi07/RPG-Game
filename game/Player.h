#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "time.h"
#include "Error.h"
#include "Character.h"
#include "Monster.h"
using namespace std;

class Player : public Character
{
    friend class Helmet;
    friend class Armor;
    friend class Sword;
    friend class Material;

    string atrybut;

public:
    Player()
    {
        atrybut = "Silny";
        cout << "Stworzono bohatera \n";
    }
    Player(string atryb, string n, int h, int att, int obr) : Character(h, att, obr, n)
    {
        atrybut = atryb;
        cout << "Stworzono bohatera \n";

    }
    Player(const Player &w)
    {
        atrybut = w.atrybut;
        cout << "Stworzono bohatera \n";
    }
    ~Player(){}

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
        cout << "Gracz [" << getName() << ", " << getAtrybut() << "]" << endl;
        cout << "HP: " << getHP() << endl;
        cout << "Atak: " << getAttack() << endl;
        cout << "Obrona: " << getDefence() << endl;
        cout << "--------------------------------------------" << endl;
    }

};