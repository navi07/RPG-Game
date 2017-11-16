#include <iostream>
#include <cstdlib>
#include "Item.h"
#include "Sword.h"
#include "Armor.h"
#include "Helmet.h"
#include "Material.h"
#include "Character.h"
#include "Player.h"
#include "File.h"
#include "Fight.h"
using namespace std;


int main()
{
    cout << "[GRA RPG] \n\n";
    cout << "*************************************\n";
    Player p;
    Monster m;
    Item i;
    int x;
    cout << "Wybierz dzialanie \n\n";

    do
    {
        cout << "*************************************\n";
        cout << "1. Stworz  wlasnego bohatera \n";
        cout << "2. Stworz  wlasngo potwora \n";
        cout << "3. Stworz helm \n";
        cout << "4. Stworz miecz \n";
        cout << "5. Stworz zbroje \n";
        cout << "6. Stworz przedmiot z materialu \n";
        cout << "7. Walka \n";
        cout << "8. Zapis do pliku \n";
        cout << "9. Odczyt z pliku \n";
        cout << "10. Statyski postaci \n";
        cout << "0. Wyjdz z gry \n";
        cout << "Twoj wybor: ";
        cin >> x;
        system("cls");
        cout << "*************************************\n";
        if (x == 1)
        {
            p.setName();
            p.setAtrybut();
            p.setHP();
            p.setAttack();
            p.setDefence();
            p.show();
        }
     else if (x == 2)
        {
            m.setName();
            m.setAtrybut();
            m.setHP();
            m.setAttack();
            m.setDefence();
            m.show();
        }
        else if (x == 3)
        {
            cout << "Tworzenie helmu \n";
            Helmet h;
            h.setHelmetDefence(&p);
            h.setWeight();
            h.setName();
            cout << "Stworzono i zalozono helm \nTwoja obrona wzrosla o : " << h.getHelmetDefence() << "pkt." << endl;
        }
        else if (x == 4)
        {
            cout << "Tworzenie miecza \n";
            Sword s;
            s.setAttack(&p);
            s.setWeight();
            s.setName();
            cout << "Stworzono i zalozono miecz \nTwoj atak wzrosl o : " << s.getAttack() << "pkt." << endl;
        }
        else if (x == 5)
        {
            cout << "Tworzenie zbroi \n";
            Armor a;
            a.setDefence(&p);
            a.setWeight();
            a.setName();
            cout << "Stworzono i zalozono zbroje \nTwoja obrona wzrosla o : " << a.getdefense() << "pkt." << endl;
        }
        else if (x == 6)
        {
            cout << "Stworz: \n";
            cout << "1. Miecz \n";
            cout << "2. Zbroja \n";
            cout << "3. Helm \n";
            int y;
            cin >> y;
            if (y == 1)
            {
                cout << "Rodzaj: \n";
                cout << "1. diamentowy \n";
                cout << "2. zloty \n";
                cout << "3. stalowy \n";
                int z;
                cin >> z;
                if(z == 1)
                {
                    Material *material = new Material("diamentowy", 20, "1");
                    Sword _sword = material->createSword(&p);
                }
                if(z == 2)
                {
                    Material *material = new Material("zloty", 10, "1");
                    Sword _sword = material->createSword(&p);
                }
                if(z == 3)
                {
                    Material *material = new Material("stalowy", 5, "1");
                    Sword _sword = material->createSword(&p);
                }
            };
            if (y == 2)
            {
                cout << "Rodzaj: \n";
                cout << "1. diamentowa \n";
                cout << "2. zlota \n";
                cout << "3. stalowa \n";
                int z;
                cin >> z;
                if(z == 1)
                {
                    Material *material = new Material("diamentowa", 20, "1");
                    Armor _armor = material->createArmor(&p);
                }
                if(z == 2)
                {
                    Material *material = new Material("zlota", 10, "1");
                    Armor _armor = material->createArmor(&p);
                }
                if(z == 3)
                {
                    Material *material = new Material("stalowa", 5, "1");
                    Armor _armor = material->createArmor(&p);
                }
            }
            if (y == 3)
            {
                cout << "Rodzaj: \n";
                cout << "1. diamentowy \n";
                cout << "2. zloty \n";
                cout << "3. stalowy \n";
                int z;
                cin >> z;
                if(z == 1)
                {
                    Material *material = new Material("diamentowy", 20, "1");
                    Helmet _helmet = material->createHelmet(&p);
                }
                if(z == 2)
                {
                    Material *material = new Material("zloty", 10, "1");
                    Helmet _helmet = material->createHelmet(&p);
                }
                if(z == 3)
                {
                    Material *material = new Material("stalowy", 5, "1");
                    Helmet _helmet = material->createHelmet(&p);
                }
            }
        }
        else if (x == 7) Fight(p, m);
        else if (x == 8) write(i, p, m);
        else if (x == 9) read();
        else if (x == 10) cout << p << "\n" << m;
        else cout<<"Podaj inna wartosc \n";
    }while(x!=0);

    return 0;
}
