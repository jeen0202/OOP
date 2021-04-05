#ifndef SERVANT_H_INCLUDED
#define SERVANT_H_INCLUDED

#include "Skill.h"
#include <string>
#include <vector>
class Servant{
    private:
        std::string name;
        float hitPoints;
        int level;
        //Skill skills[MAXSKILL];        
        vector<Skill> skills;
    public:
        Servant();
        int getLevel();
        std::vector <Skill> getSkills();
        std::string getName();
        int getHitPoints();
        void setLevel(int level);
        void setName(std::string name);        
        void isAttacked(Servant serv, Skill skill);
        void setSkills(vector<Skill> newSkills);
        void setHitPoints(float lastbattle);
        std::string toString();
        
        
};

#endif