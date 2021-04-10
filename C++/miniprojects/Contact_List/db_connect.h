#ifndef DB_CONNECT_H_INCLUDED
#define DB_CONNECT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "mysql_error.h"
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "111111"
#define DB_NAME "oop"
class db_connect
{
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::PreparedStatement *psmt;
    sql::ResultSet *res;
public:
    db_connect(/* args */);
    void showList();
    ~db_connect();
};

db_connect::db_connect(/* args */)
{
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect(DB_HOST,DB_USER,DB_PASS);
    std::string use = "Use "DB_NAME;
    stmt->execute(use);
}
void db_connect::showList()
{
    res = stmt->executeQuery("Select * FROM contact_list");
    std::cout << "ID\t이름\t주소\t전화번호" << std::endl;
    while(res->next())
    {
        std::cout << res->getInt("id") << "\t" << res->getString("name") << "\t" << res->getString("address")  
        << " " << res->getString("phone") << std::endl;
    }
}
db_connect::~db_connect()
{
    delete res;
	delete conn;
    delete stmt;
    delete psmt;
}

#endif