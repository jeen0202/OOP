#ifndef SKILL_H_INCLUDED
#define SKILL_H_INCLUDED

#include<string>

class Skill{
    private:
        std::string name;
        short level;
        float damage;
        float accuracy;
    public:
        std::string getName();
        short getLevel();
        float getDamage();
        float getAccuracy();
        void setName(std::string newName);
        void setLevel(short newLevel);
        void setDamage(float newDamage);
};

#endif