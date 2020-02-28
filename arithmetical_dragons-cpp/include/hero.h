#ifndef HERO_H_INCLUDED
#define HERO_H_INCLUDED

#include <string>
#include <iostream>

#include "dragon.h"

class Hero: public Unit
{
public:
    static const int default_health = 100;
    static const int default_attackForce = 20;

    Hero(int health = default_health, int aForce = default_attackForce)
        :Unit(health, aForce)
    {}
    void attack (Dragon &drago)
    {
        std::string q = drago.generateQuestion();
        std::cout << "question: " << q;
        int answer;
        std::cin >> answer;
        if (drago.checkAnswer(answer))
        {
            drago.getDamage(attackForce);
            std::cout << "Hit you, dragon!" << std::endl;
        }
        else
        {
            getDamage(drago.attackForce);
            std::cout << "Hero suffers..." << std::endl;
        }
    }
};

#endif // HERO_H_INCLUDED
