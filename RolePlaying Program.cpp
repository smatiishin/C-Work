#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Creature {

protected:
    int type;
    int strength;
    int hitpoints;
    string getSpecies;

public:
    Creature();
    Creature(int newType, int newStrength, int newHit, string newSpecies);
    virtual int getDamage();
};
Creature::Creature()
{
    type = 0;
    strength = 10;
    hitpoints = 10;
    getSpecies = "human";
}
Creature::Creature(int newType, int newStrength, int newHit, string newSpecies)
{
    type = newType;
    strength = newStrength;
    hitpoints = newHit;
    getSpecies = newSpecies;
}
int Creature::getDamage()
{
    int damage = (rand() % strength) + 1;
    cout << "Creature attacks for " << damage << " points!" << endl;

    return damage;
}
//End of Creature
/*================================================================================*/
class Demon :public Creature
{
protected:
    int damage;
public:
    Demon();
    Demon(int newType, int newStrength, int newHit, string newSpecies);
    virtual int getDamage();
};
Demon::Demon() :Creature()
{

}
Demon::Demon(int newType, int newStrength, int newHit, string newSpecies)
    : Creature(newType, newStrength, newHit, newSpecies)
{

}
int Demon::getDamage()
{
    damage = (rand() % strength) + 1;
    cout << "Demon attacks for " << damage << " points!" << endl;

    return damage;
}
//end of Demon class
/*========================================================================================*/
class Elf : public Creature
{
private:
    int damage;
public:
    Elf();
    Elf(int newType, int newStrength, int newHit, string newSpecies);
    int getDamage();
};

Elf::Elf() : Creature()
{

}
Elf::Elf(int newType, int newStrength, int newHit, string newSpecies)
    : Creature(newType, newStrength, newHit, newSpecies)
{

}
int Elf::getDamage()
{
    damage = (rand() % strength) + 1;
    cout << "Elf attacks for " << damage << " points!" << endl;
    if (rand() % 10 == 0)
    {
        cout << "Megical attack inflicts " << damage <<
            " additional damage points!" << endl;
        damage = damage * 2;
    }
    return damage;
}
//end of Elf class
/*=============================================================*/
class Human :public Creature
{
private:
    int damage;
public:
    Human();
    Human(int newType, int newStrength, int newHit, string newSpecies);
    int getDamage();
};
Human::Human() : Creature()
{

}
Human::Human(int newType, int newStrength, int newHit, string newSpecies)
    : Creature(newType, newStrength, newHit, newSpecies)
{

}
int Human::getDamage()
{
    damage = (rand() % strength) + 1;
    cout << "Human attacks for " << damage << " points!" << endl;

    return damage;
}
//end of Human class
/*=============================================================*/
class Cyberdemon : public Demon
{
public:
    Cyberdemon();
    Cyberdemon(int newType, int newStrength, int newHit, string newSpecies);
    int getDamage();
};

Cyberdemon::Cyberdemon() : Demon()
{

}
Cyberdemon::Cyberdemon(int newType, int newStrength, int newHit, string newSpecies)
    : Demon(newType, newStrength, newHit, newSpecies)
{

}
int Cyberdemon::getDamage()
{
    damage = (rand() % strength) + 1;
    cout << "Cyberdemon attacks for " << damage << " points!" << endl;
    if ((rand() % 100) < 5)
    {
        damage = damage + 50;
        cout << "Cyberdemon attack inflicts 50 additional additional damage Points!" << endl;
    }
    return damage;
}
//end of Cyberdemon class
/*==============================================================*/
class Balrog :public Demon
{
private:
    int damage2;
public:
    Balrog();
    Balrog(int newType, int newStrength, int newHit, string newSpecies);
    int getDamage();
};
Balrog::Balrog() : Demon()
{

}
Balrog::Balrog(int newType, int newStrength, int newHit, string newSpecies)
    : Demon(newType, newStrength, newHit, newSpecies)
{

}
int Balrog::getDamage()
{
    damage = (rand() % strength) + 1;
    cout << "Balrog attacks for " << damage << " points!" << endl;
    if ((rand() % 100) < 5)
    {
        damage = damage + 50;
        cout << "Balrog attack inflicts 50 additional additional damage Points!" << endl;
    }
    damage2 = (rand() % strength) + 1;
    cout << "Balrog speed attack inflicts " << damage2 << " additional damage points!" << endl;
    damage += damage2;
    return damage;
}
//end of Balrog class
/*==============================================================*/

//main() function

int main()
{
    //Initialize random number
    srand(time(NULL));

    Human human(0, 65, 75, "Huamn");
    Elf elf(3, 20, 30, "Elf");
    Balrog balrog(2, 30, 40, "Balrog");
    Cyberdemon cyberDemon;
    //call get damage
    cout << "Human Damage: " << human.getDamage() << endl;
    cout << "Cyberdemon Damage: " << cyberDemon.getDamage() << endl;
    cout << "Balrog Damage: " << balrog.getDamage() << endl;
    cout << "Elf Damage: " << elf.getDamage() << endl;
    return 0;
}
//end of main
