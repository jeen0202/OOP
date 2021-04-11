#include <iostream>
#include "db_connect.h"
using namespace std;
int main()
{
    db_connect db;
    db.showList();
    int id = db.searchID("관리자");
    cout << "result : " << id << endl;
}