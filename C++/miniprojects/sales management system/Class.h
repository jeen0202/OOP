#include <string>
class Product
{
    private :
        int last_code();
        void delete_record(int);
        void modify_record(int);
        void display_record(int);
        int item_found(int);
        int recordno(int);
        void sort();

        int itemcode ;
        string itemname;
        float itemcost, itemprice;
    public :
        void add_item();
        void delete_item();
        void modify_item();
        void list_of_item();
        void purchase();
};
class Account
{
    private :
        int code,billno,length;
        int dd,mm,yy;
        float cost,price,quantity;
        string name;
    public :
        void bill_list();
        void prepare_bill();
        int last_billno();
        void add_bill(int, int i_itemcode, string t_itemname, float t_qty, float t_cose);
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

