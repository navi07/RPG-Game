#pragma once
#include <iostream>
#include <string>
#include <cctype>
#include "Error.h"
using namespace std;

class Item
{
friend class Sword;
friend class Armor;
friend class Helmet;

    int weight;
    string name;

public:
    Item()
    {
        weight = 1;
        name = "Item";
    }
    Item(int w, string n)
    {
        weight = w;
        name = n;
    }
    Item(const Item &w)
    {
        weight = w.weight;
        name = w.name;
    }
    ~Item(){}

    string getName()
    {
        return name;
    }
    int getWeight()
    {
        return weight;
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

    void setWeight()
        {
            int _weight;
            do
            {
                try
                {
                    cout << "Podaj wage : ";
                    cin >> _weight;
                    weight = _weight;
                    if (!cin || _weight <= 0)
                    {
                        cin.clear();
                        cin.ignore(256, '\n');
                        throw Error(Error::_weight);
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
        cout << "Item [" << getName() << ", waga -> " << getWeight() << "]" << endl;
        cout << "--------------------------------------------" << endl;
    }
};