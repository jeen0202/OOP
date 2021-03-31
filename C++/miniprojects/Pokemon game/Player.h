#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Servant.h"

#include<vector>

class Player{
    private:
        std::string name;
        //short level;
        vector<Servant> myServ;
        //Servant myServ[MAXSERVANT];
        short ServantStatus[MAXSERVANT];
    public:
        Player();
        Player(std::string name);
        std::string getName();
        //int getLevel();
        std::vector<Servant> getServant();
        std::vector<short> getServantStatus();
        void setName(std::string newName);
        //void setLevel(short newLevel);
        void setServantStatus(int point, short status);
        void setServant(vector<Servant> newServant);
};

#endif