#ifndef DB_CONNECT_H_INCLUDED
#define DB_CONNECT_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "mysql_error.h"
#include <cppconn/resultset.h>

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "111111"
#define DB_NAME "tutorials"

class db_connect
{
private:
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;
public:
    db_connect(/* args */);
    
    ~db_connect();
};

db_connect::db_connect(/* args */)
{
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect(DB_HOST,DB_USER,DB_PASS);
}

db_connect::~db_connect()
{
    delete res;
	delete conn;
    delete stmt;
}

#endif