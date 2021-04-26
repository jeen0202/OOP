#ifndef Dbconn_CLASS
#define Dbconn_CLASS

#include <iostream>
#include <stdlib.h>

#include "mysql_driver.h"
#include "mysql_connection.h"
#include "mysql_error.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>

//Mysql 연동을 위한 정보 정의
#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "111111"
#define DB_NAME "oop"
#define TABLE_NAME "member"

using namespace std;

#define SELECT_ALL "SELECT * FROM contact_list"
#define RESET "DROP TABLE IF EXISTS conn_test"
#define CREATE "CREATE TABLE IF NOT EXISTS conn_test(id int, name varchar(20))"
#define INSERT "INSERT INTO contact_list values("

class Dbconn
{
    private:
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *conn;
        sql::Statement *stmt;
        sql::PreparedStatement *psmt;
        sql::ResultSet *res;
    public:
        Dbconn();
        bool auth(std::string id,std::string pass);
        ~Dbconn();
};
Dbconn::Dbconn()
{
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect(DB_HOST,DB_USER,DB_PASS);
    stmt = conn->createStatement();    
    stmt->execute("USE "DB_NAME);
};

bool Dbconn::auth(std:: string inputId, std::string inputPass)
{
    bool result;
    std::string resId,resPass;
    psmt = conn->prepareStatement("Select * from member where id = ?");
    psmt->setString(1,inputId);
    res = psmt->executeQuery();
    if(res->next())
    {
        resId = res->getString("username");
        resPass = res->getString("password");
    }else{
        result = false;
    }
    if(resPass.compare(inputPass)==0)
        result = true;
    else
        result = false;
    return result;    
}
Dbconn::~Dbconn()
{
    delete res;
	delete conn;
    delete stmt;
    delete psmt;
}

#endif