#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "Servant.h"

#include<vector>

class Player{
    private:
        int level;
        Servant myServ[3];
        bool ServantStatus[3];
    public:
        int getLevel();
        std::vector<Servant> getServant();
        std::vector<bool> getServantStatus();
        void setLevel(int newLevel);
        void setServantStatus(int point, bool status);
        void setServant(Servant newServant);
};

#endif