#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Error.h"
using namespace std;

class Character
{
    friend class Helmet;
    friend class Armor;
    friend class Sword;
    friend class Material;

    friend ostream& operator << (ostream &out, Character const& c);
    friend istream& operator >> (istream &in, Character & c);

    int hp;
    int attack;
    int defence;
    string name;

public:
    Character()
    {
        hp = 100;
        attack = 10;
        defence = 10;
        name = "Character";
    }
    Character(int h, int att, int obr, string n)
    {
        hp = h;
        attack = att;
        defence = obr;
        name = n;
    }
    Character(const Character &w)
    {
        hp = w.hp;
        attack = w.attack;
        defence = w.defence;
        name = w.name;
    }
    ~Character(){}

    Character operator = (const Character &c);

    string getName()
    {
        return name;
    }
    int getHP()
    {
        return hp;
    }
    int getAttack()
    {
        return attack;
    }
    int getDefence()
    {
        return defence;
    }

    bool repeat = false;

    void setName()
    {
        string _name;
        do
        {
            try
            {
                cout << "Podaj nazwe : ";
                cin >> _name;
                name = _name;
                for (int i = 0; i < _name.length(); i++)
                    if (isdigit(_name[i])) throw Error(Error::_name);
                repeat = false;
            }
            catch(Error &e)
            {
                e.what();
                repeat = true;
            }
        }while(repeat);
    }

    void setHpFight(int hpp)
    {
        hp = hpp;
    }

    void setHP()
    {
        int _hp;
        do
        {
            try
            {
                cout << "Podaj ilosc zycia : ";
                cin >> _hp;
                hp = _hp;
                if (!cin || _hp <= 0)
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    throw Error(Error::_hp);
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
    void setAttack()
    {
        int _attack;
        do
        {
            try
            {
                cout << "Podaj ilosc ataku : ";
                cin >> _attack;
                attack = _attack;
                if (!cin || _attack <= 0)
                {
                    cin.clear();
                    cin.ignore(256, '\n');
                    throw Error(Error::_attack);
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

    void setDefence()
    {
        int _defence;
        do
        {
            try
            {
                cout << "Podaj obrone : ";
                cin >> _defence;
                defence = _defence;
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
    virtual void show()
    {
        cout << "Postac [" << getName() << ", nazwa -> " << getName() << "]" << endl;
        cout << "HP: " << getHP() << endl;
        cout << "Atak: " << getAttack() << endl;
        cout << "Obrona: " << getDefence() << endl;
        cout << "--------------------------------------------" << endl;
    }
};

ostream& operator<< (ostream &out, Character const& c)
{
    out << "Postac: "<<c.name << "\nHP: " << c.hp << "\nAtak: " << c.attack << "\nObrona: " << c.defence << "\n";
    return out;
}

istream& operator>> (istream &in, Character & c)
{
    in >> c.hp >> c.attack >> c.defence >> c.name;
    return in;
}

Character Character :: operator = (const Character &c)
{
    name = c.name;
    hp = c.hp;
    attack = c.attack;
    defence = c.defence;
    return *this;
}