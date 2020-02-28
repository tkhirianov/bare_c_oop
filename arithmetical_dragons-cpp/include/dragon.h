#ifndef DRAGON_H_INCLUDED
#define DRAGON_H_INCLUDED

#include <string>
#include <sstream>

class Dragon: public Unit
{
protected:
    int my_answer;
    std::string my_color;
public:

    Dragon(std::string color, int start_health, int _attackForce)
        :Unit(start_health, _attackForce), my_color(color)
    {}

    virtual std::string generateQuestion() = 0;

    bool checkAnswer(int answer) const
    {
        return answer == my_answer;
    }
    std::string color() const
    {
        return my_color;
    }
};

class GreenDragon: public Dragon
{
    static const int c_greenDragonHealth = 50;
    static const int c_greenDragonAttackForce = 5;
public:

    GreenDragon()
        :Dragon("Green", c_greenDragonHealth,
                 c_greenDragonAttackForce)
    {}
    std::string generateQuestion()
    {
        int left = 1 + rand()%100;
        int right = 1 + rand()%100;

        std::stringstream question;
        question << left << " + " << right << ": ";
        my_answer = left + right;
        return question.str();
    }
};

//class RedDragon;

//class BlackDragon;


#endif // DRAGON_H_INCLUDED
