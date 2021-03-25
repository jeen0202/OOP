#include "Servant.h"
#include <array>
using namespace std;

Servant::Servant():hitPoints(100)
{}

string Servant::getName()
{
    return name;
}

void Servant::setName(string newName)
{
    name = newName;
}

int Servant::getHitPoints()
{
    return hitPoints;
}

void Servant::isAttacked(int damage)
{
    hitPoints -= damage;
    if (hitPoints<0)
        hitPoints = 0;
}

vector<Skill> Servant::getSkills(){
    vector<Skill> temp;
    for(int i =0;i<(sizeof(skills)/sizeof(string));i++)
    {
        temp.push_back(skills[i]);
    };
    return temp;
}

