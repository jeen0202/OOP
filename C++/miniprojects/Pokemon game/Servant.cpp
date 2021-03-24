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

vector<string> Servant::getSkills(){
    vector<string> temp;
    for(int i =0;i<(sizeof(skills)/sizeof(string));i++)
    {
        temp.push_back(skills[i]);
    };
    return temp;
}

void Servant::setSkills(string skill, int point)
{
    point--;    
    skills[point] = skill;
}

vector<int> Servant::getSkillLevels()
{
    vector<int> temp;
    for(int i = 0;i<(sizeof(skillLevels)/sizeof(int));i++)
    {
        temp.push_back(skillLevels[i]);
    };
    return temp;
}

void Servant::setSkillLevel(int point, int level)
{
    point--;
    skillLevels[point] = level;
};

