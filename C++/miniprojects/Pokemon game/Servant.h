#ifndef SERVANT_H_INCLUDED
#define SERVANT_H_INCLUDED

#define MAXSKILL 4

#include "Skill.h";
#include <string>
#include <vector>
class Servant{
    private:
        std::string name;
        float hitPoints;
        int level;
        Skill skills[MAXSKILL];
        int skillLevels[MAXSKILL];
    
    public:
        Servant();

        std::vector <int> getSkillLevels();
        std::vector <std::string> getSkills();
        std::string getName();
        int getHitPoints();
        void setName(std::string name);        
        void isAttacked(int damage);
        
};

#endif