#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Error.h"
#include "Item.h"
#include "Player.h"
#include "Character.h"
using namespace std;

class Material : public Item
{
    string type;

public:
    Material()
    {
        type = "podstawowy";
    }
    Material(string r, int w, string n) : Item(w, n)
    {
        type = r;
    }
    Material(const Material &w)
    {
        type = w.type;
    }
    ~Material(){}

    string getType()
    {
        return type;
    }

    bool repeat = false;

    void setType()
        {
            string _type;
            do
            {
                try
                {
                    cout << "Podaj type : ";
                    cin >> _type;
                    type = _type;
                    for (int i = 0; i < _type.length(); i++)
                    if (isdigit(_type[i])) throw Error(Error::_rodzaj);
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
        cout << "Material [" << getName() << ", waga -> " << getWeight() << "]" << endl;
        cout << "Rodzaj :" << type << endl;
        cout << "--------------------------------------------" << endl;
    }

    Sword createSword(Player *p)
    {
        repeat = false;
        do {
            try
            {
                if (type == "diamentowy")
                {
                    Sword *_sword = new Sword();
                    p->attack = p->getAttack() + 20;
                    return *_sword;
                }
                if (type == "zloty")
                {
                    Sword *_sword = new Sword();
                    p->attack = p->getAttack() + 10;
                    return *_sword;
                }
                if (type == "stalowy")
                {
                    Sword *_sword = new Sword();
                    p->attack = p->getAttack() + 5;
                    return *_sword;
                }
                throw Error(Error::_rodzaj);
            }
            catch (Error &e)
            {
                e.what();
                repeat = true;
            }
        }while(repeat);
    }

    Armor createArmor(Player *p)
    {
        repeat = false;
        do {
            try
            {
                if (type == "diamentowa")
                {
                    Armor *_armor = new Armor();
                    p->defence = p->getDefence() + 20;
                    return *_armor;
                }
                if (type == "zlota")
                {
                    Armor *_armor = new Armor();
                    p->defence = p->getDefence() + 10;
                    return *_armor;
                }
                if (type == "stalowa")
                {
                    Armor *_armor = new Armor();
                    p->defence = p->getDefence() + 5;
                    return *_armor;
                }
                throw Error(Error::_rodzaj);
            }
            catch (Error &e)
            {
                e.what();
                repeat = true;
            }
        }while(repeat);
    }
    Helmet createHelmet(Player *p)
    {
        repeat = false;
        do
        {
            try
            {
                if (type == "diamentowy")
                {
                    Helmet *_helmet = new Helmet();
                    p->defence = p->getDefence() + 20;
                    return *_helmet;
                }
                if (type == "zloty")
                {
                    Helmet *_helmet = new Helmet();
                    p->defence = p->getDefence() + 10;
                    return *_helmet;
                }
                if (type == "stalowy")
                {
                    Helmet *_helmet = new Helmet();
                    p->defence = p->getDefence() + 5;
                    return *_helmet;
                }
                throw Error(Error::_rodzaj);
            }
            catch (Error &e)
            {
                e.what();
                repeat = true;
            }
        }while(repeat);
    }
};