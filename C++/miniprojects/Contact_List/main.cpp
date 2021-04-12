#include <iostream>
#include "db_connect.h"
using namespace std;
int main()
{
    db_connect db;
    int id;
    db.showList();
    db.addMember("test","test","test");
    cout << "A F T E R A D D" << endl;
    db.showList();
    id = db.searchID("test");
    cout << "result : " << id << endl;
    db.deleteMember(id);
    cout << "A F T E R D E L T E\n";
    db.showList();
}