#include <iostream>
#include "db_connect.h"
using namespace std;
int main()
{
    db_connect db;
    int id;
    db.showList();
    db.addMember("test","test","test");
    cout << "\tAFTER ADD" << endl;
    db.showList();
    id = db.searchID("test");
    cout << "\tresult : " << id << endl;    
    db.updateAddress(id,"광주광역시");
    db.updatePhone(id,"01073775773");
    cout << "\tAFTER UPDATE\n";
    db.showList();
    db.deleteMember(id);
    cout << "\tAFTER DELETE\n";
    db.showList();
}