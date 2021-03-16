#include <string>
using namespace std;
class Product
{
    private :
        int last_code();
        void delete_recode(int);
        void mofiry_record(int);
        void display_recode(int);
        int item_found(int);
        int recordno(int);
        void sort(void);

        int itemcode ;
        string itemname;
        float itemcost, itemprice;
    public :
        void add_item();
        void delete_item();
        void modify_item();
        void lost_of_item();
        void purchase();
};
class Account
{
    private :
        int code,billno,length;
        int dd,mm,yy;
        float cost,price,quantity;
        string name;
};
class Menu
{
    private :
    void edit_menu();
    static char ch;   

    public :
        void main_menu();
        static void setCh(char);

};

