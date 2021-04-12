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
    int searchID(std::string name);
    void addMember(std::string name, std::string address,std::string phone);
    void deleteMember(int id);
    ~db_connect();
};

db_connect::db_connect(/* args */)
{
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect(DB_HOST,DB_USER,DB_PASS);    
    stmt = conn->createStatement(); 
    stmt->execute("Use "DB_NAME);
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
int db_connect::searchID(std::string name)
{
    int result;
    try{
        psmt = conn->prepareStatement("Select * from contact_list WHERE name=?");
        psmt->setString(1,name);
        res = psmt->executeQuery();
        if(res->next())
        {
            result = res->getInt("id");
            std::cout << "\t... Seleted data: \n";
            std:: cout << "이름\t\t주소\t\t전화번호\n";
            std::cout << res->getString("name") << " " << res->getString("address")  
            << " " << res->getString("phone") << std::endl;
        }       
    }catch(sql::SQLException &e)
    {
        std::cout << "# ERR : SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ <<") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code : " << e.getErrorCode();
        std::cout << ", SQLState : " << e.getSQLState() << " )" << std::endl;
    }
     return result;     
}
void db_connect::addMember(std::string name, std::string address,std::string phone)
{
    try{
        psmt = conn->prepareStatement("INSERT INTO contact_list(name,address,phone) value(?,?,?)");
        psmt->setString(1,name);
        psmt->setString(2,address);
        psmt->setString(3,phone);
        if(!psmt->execute())    
            std::cout << "데이터 추가 완료\n";   
        else
            std::cout << "데이터 추가 실패\n";         
    }catch(sql::SQLException &e)
    {
        std::cout << "# ERR : SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ <<") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code : " << e.getErrorCode();
        std::cout << ", SQLState : " << e.getSQLState() << " )" << std::endl;
    }
}
void db_connect::deleteMember(int id)
{
    try{
        psmt = conn->prepareStatement("DELETE FROM contact_list WHERE id = ?");
        psmt->setInt(1,id);
        if(!psmt->execute())
            std::cout <<"데이터 삭제 완료\n";
        else
            std::cout <<"데이터 삭제 실패\n";    
    }catch(sql::SQLException &e){
        std::cout << "# ERR : SQLException in " << __FILE__;
        std::cout << "(" << __FUNCTION__ <<") on line " << __LINE__ << std::endl;
        std::cout << "# ERR: " << e.what();
        std::cout << " (MySQL error code : " << e.getErrorCode();
        std::cout << ", SQLState : " << e.getSQLState() << " )" << std::endl;        
    }
}
db_connect::~db_connect()
{
    delete res;
	delete conn;
    delete stmt;
    //delete psmt;
}

#endif