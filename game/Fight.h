#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include "Item.h"

using namespace std;

void Fight(Player &_player, Monster &_monster)
{
    srand(time(0));
    int hpM = _monster.getHP();
    int hpP = _player.getHP();
    cout << "Walka rozpoczyna sie! \n";
    cout << "Zycie gracza: " << hpP << ", Zycie potwora: "<< hpM << endl;
    int tmp1;
    int tmp2;
    while(hpP>0 && hpM>0)
    {
        tmp1 = rand()%3+1;
        tmp2 = rand()%2+1;

        if(_player.getAttack()*tmp1-_monster.getDefence()*tmp2>0)
            hpM=hpM-(_player.getAttack()*tmp1-_monster.getDefence()*tmp2);

        if(_monster.getAttack()*tmp2-_player.getDefence()*tmp1>0)
            hpP=hpP-(_monster.getAttack()*tmp2-_player.getDefence()*tmp1);

        cout << "Zycie gracza: " << hpP << ", Zycie potwora: "<< hpM << endl;
    }

    _player.setHpFight(hpP);
    _monster.setHpFight(hpM);
    if(hpP<=0) cout << "Przegrales" << endl;
    if(hpM<=0) cout << "Wygrales" << endl;
}