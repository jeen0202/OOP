#include "Servant.h"

class Menu
{
    private :
        void serv_menu();
        void battle_menu();
        bool on_battle(Servant pServ, Servant eServ);
        bool on_AutoBattle(Servant pServ, Servant eServ);
    public :
        void main_menu();
        void list_of_servant();    
        
};