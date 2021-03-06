#include <iostream>
#include <string>
#include<vector>

using namespace std;

class Player{
public:
    //attributes
    string name{"Player"};
    int health{};
    int xp{};

    //methods
    void talk(string text_to_say){cout << name << " says " << text_to_say << endl; }
    bool is_dead();

};

class Account{
public:
    //attributes
    string name{"Account"};
    double balance{0.0};

    //methods
    bool deposit(double bal){balance += bal; cout << "In balance" << endl; }
    bool withdarw(double bal){balance -= bal; cout << "In withdraw" << endl; }
} ;

int main()
{
    Account naqeeb_account;
    naqeeb_account.name = "Naqeeb's account";
    naqeeb_account.balance = 5000.0;

    naqeeb_account.deposit(100.0);
    naqeeb_account.withdarw(200.0);

    Player naqeeb;
    naqeeb.name = "Naqeeb";
    naqeeb.health = 100;
    naqeeb.xp = 10;
    naqeeb.talk("Hi there");

    Player *enemy = new Player;
    (*enemy).name = "Enemy";
    (*enemy).health = 100;
    enemy->xp = 15;

    enemy->talk("I will destroy you!");

    return 0;
}
