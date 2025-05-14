#include <iostream>
#include <string.h>
using namespace std;

class Hero
{
private:
    int health;

public:
    char level;
    char *name;
    static int timeToComplete;

    Hero()
    {
        name = new char[100];
        // cout << "Simple Constructor called!" << endl;
    }

    // Copy constructor
    Hero(Hero &temp)
    {
        char *ch = new char[strlen(temp.name)];
        strcpy(ch, temp.name);
        this->health = temp.health;
        this->level = temp.level;
        this->name = ch;
    }

    Hero(int health)
    {
        // this->health = health;
        level = ' ';
        (*this).health = health;
    }
    Hero(int health, char level)
    {
        // (*this).health = health;
        this->health = health;
        this->level = level;
    }

    int getHealth()
    {
        return health;
    }
    char getLevel()
    {
        return level;
    }

    void setHealth(int h)
    {
        health = h;
    }

    void setLevel(char ch)
    {
        level = ch;
    }
    void print()
    {
        cout << endl;
        cout << "[ Name: " << name << " ,";
        cout << "Health: " << health << " ,";
        cout << "Level " << level << " ]";
    }
    void setName(char name[])
    {
        strcpy(this->name, name);
    }

    static int random()
    {
        return timeToComplete;
    }

    ~Hero()
    {
        // cout << "Destructor called!" << endl;
    }
};

int Hero::timeToComplete = 5;

int main()
{

    cout << Hero::timeToComplete << endl;

    Hero a;
    cout << a.timeToComplete << endl;

    Hero b;
    b.timeToComplete = 10;
    cout << b.timeToComplete << endl;
    cout << Hero::random() << endl;

    // // Static
    // Hero a;

    // // Dynamic
    // Hero *b = new Hero;
    // delete b; // destructor manually call karna padega

    // Hero hero1;
    // hero1.setHealth(12);
    // hero1.setLevel('D');
    // char name[8] = "Shubham";
    // hero1.setName(name);

    // // hero1.print();

    // // use default copy constructor (Shallow copy hora hai)
    // // use user defined copy constructor (deep copy)
    // Hero hero2(hero1);
    // // hero2.print();
    // // Hero hero2 = hero1;

    // hero1.name[0] = 'G';
    // hero1.print();
    // hero2.print();

    // hero1 = hero2;
    // hero1.print();
    // hero2.print();

    // Hero S(70, 'C');

    // // Copy Constructor (apne aap generate hojata h)
    // Hero R(S);
    // R.print();

    // cout << "Hii" << endl;
    // Hero ramesh(10,'B'); // Constructor called
    // // ramesh.setHealth(30);
    // cout << "Level is : " << ramesh.getLevel() << endl;
    // cout << "Health is : " << ramesh.getHealth() << endl;

    // Hero a;
    // a.setHealth(10);
    // a.setLevel('1');
    // cout << "Level is : " << a.getLevel() << endl;
    // cout << "Health is : " << a.getHealth() << endl;

    // cout << endl;

    // Hero *b = new Hero;
    // (*b).setHealth(20);
    // b->setLevel('2');

    // cout << "Level is : " << b->getLevel() << endl;
    // cout << "Health is : " << b->getHealth() << endl;

    return 0;
}