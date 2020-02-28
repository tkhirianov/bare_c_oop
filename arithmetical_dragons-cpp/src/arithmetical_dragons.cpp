#include <iostream>
#include <sstream>
#include <cstdlib>
#include <list>

#include "unit.h"
#include "hero.h"
#include "dragon.h"

using namespace std;


void showHealth(const Hero &hero, const Dragon &dragon)
{
    cout << "Hero health: " << hero.getHealth()
        << ", Dragon health: " << dragon.getHealth() << endl;
}

list<Dragon*> generateDragonList()
{
    list<Dragon*> competitors;
    competitors.push_back(new GreenDragon());
    //competitors.push_back(new RedDragon());
    //competitors.push_back(new BlackDragon());

    return competitors;
}


bool playGame(Hero &hero, list<Dragon*> &dragons)
{
    bool gameOver = false;

    for (auto & dragon: dragons)
    {
        cout << "You have met a new " << dragon->color() << " dragon. Fight!" << endl;

        while (dragon->isAlive() && hero.isAlive())
        {
            hero.attack(*dragon);
        }
        if (!hero.isAlive())
        {
            gameOver = true;
            break;
        }
        else // dragon was killed!
        {
            cout << "Ough! You have killed a dragon!" << endl;
        }
    }
    return gameOver;
}


void clearDragonList(list<Dragon*> dragons)
{
    for(auto &dragon: dragons)
        delete dragon;
}

int main()
{
    Hero hero;
    list<Dragon*> dragons = generateDragonList();
    bool gameResult = playGame(hero, dragons);

    if (gameResult)
    {
        cout << "Game over!" << endl;
    }
    else
    {
        cout << "You win!" << endl;
    }
    clearDragonList(dragons);
    return 0;
}
