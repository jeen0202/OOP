#include "Skill.h"
using namespace std;


Skill::Skill(string newName, float dmg, float acc, short lv)
{
    name = newName;
    damage = dmg;
    accuracy = acc;
    level = lv;
}

string Skill::getName()
{
    return name;
}
void Skill::setName(string newName)
{
    name = newName;
}

short Skill::getLevel()
{
    return level;
}

void Skill::setLevel(short newLevel)
{
    level = newLevel;
}
float Skill::getDamage(){
    return damage;
}

void Skill::setDamage(float newDamage){
    damage = newDamage;
}

float Skill::getAccuracy()
{
    return accuracy;
}

void Skill::setAccuracy(float newAccuracy)
{
    accuracy = newAccuracy;
}