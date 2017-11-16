#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "Item.h"
#include "Player.h"

using namespace std;

void write(Item &i, Player &p, Monster &m)
{
    fstream file;
    file.open("file.csv", ios::app);
    if(file.good())
    {
        file<<" ->Postac: \n";
        file<<"Nazwa: " << p.getName() << endl;
        file<<"Atrybut: " << p.getAtrybut() << endl;
        file<<"HP: " << p.getHP() << endl;
        file<<"Obrona: " << p.getDefence() << endl;
        file<<"Atak: " << p.getAttack() << endl;
        file<< "\n";
        file<<" ->Potwor: \n";
        file<<"Nazwa: " << m.getName() << endl;
        file<<"Atrybut: " << m.getAtrybut() << endl;
        file<<"HP: " << m.getHP() << endl;
        file<<"Obrona: " << m.getDefence() << endl;
        file<<"Atak: " << m.getAttack() << endl;
        file<< "\n";
        file<<" ->Item: \n";
        file<<"Nazwa: " << i.getName()<<endl;
        file<<"Waga: " << i.getWeight()<<endl;
        cout<<"Zapisano pomyslnie \n";
    }
    else
        cout<<"Blad zapisu! \n";
        file.close();
}

void read()
{
    fstream file;
    file.open("file.csv", ios::in);
    if(file.good())
    {
        string _string;
        cout<<"Zawartosc pliku : \n";
        while(!file.eof())
        {
            getline(file, _string);
            cout << _string << "\n";
        }
        file.close();
    }
    else
        cout<<"Blad odczytu! \n";
}