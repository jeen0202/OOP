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

// bool Dbconn::auth(std:: string inputId, std::string inputPass)
// {
//     res= stmt->executeQ
// }
Dbconn::~Dbconn()
{
    delete res;
	delete conn;
    delete stmt;
    delete psmt;
}
// int main(int argc, char**argv)
// {
//     cout << endl;
//     cout << "Running 'SELECT *from contact_list'..." << endl;

//     //err 파악을 위해 try-catch문으로 작성  
//     try{    
//     sql::mysql::MySQL_Driver *driver;
//     sql::Connection *conn;
//     sql::Statement *stmt;
//     sql::PreparedStatement *psmt;
//     sql::ResultSet *res;
//     // connection create
//     driver = sql::mysql::get_mysql_driver_instance();
//     conn = driver->connect(DB_HOST,DB_USER,DB_PASS);

//     //statement 작성 및 실행
//     stmt = conn->createStatement();    
//     stmt->execute("USE "DB_NAME);
//     //table 초기화
//     // int pmt = stmt->execute(RESET);
//     // pmt = stmt->execute(CREATE);
//     //Read 기능
//     res = stmt->executeQuery(SELECT_ALL);
//     while(res->next())
//     {
//         cout << "\t... MYSQL replies: ";
//         cout << res->getInt("id") << " " << res->getString("name") << " " << res->getString("address")  
//         << " " << res->getString("phone") << endl;
        
//     }
//     //Create 기능
//     string name,address,phone;
//     name = "test";
//     address = "목포시 기업지원센터";
//     phone = "01073775773";
//     psmt = conn->prepareStatement("INSERT INTO contact_list(name,address,phone) value(?,?,?)");
//     psmt->setString(1,name);
//     psmt->setString(2,address);
//     psmt->setString(3,phone);
//     psmt->execute();
//     cout << "Running 'SELECT *from contact_list' after insert..." << endl;
//     res = stmt->executeQuery(SELECT_ALL);
//     while(res->next())
//     {
//         cout << "\t... MYSQL replies: ";
//         cout << res->getInt("id") << " " << res->getString("name") << " " << res->getString("address")  
//         << " " << res->getString("phone") << endl;
        
//     }
//     //Update 기능
//     psmt = conn->prepareStatement("Update contact_list SET name='updated' where name=?");
//     psmt->setString(1,name);
//     psmt->execute();
//     cout << "Running 'SELECT *from contact_list' after Update..." << endl;
//     res = stmt->executeQuery(SELECT_ALL);
//         while(res->next())
//     {
//         cout << "\t... MYSQL replies: ";
//         cout << res->getInt("id") << " " << res->getString("name") << " " << res->getString("address")  
//         << " " << res->getString("phone") << endl;
        
//     }
//     //Delete 기능
//     psmt = conn->prepareStatement("Delete from contact_list where name=?");
//     psmt->setString(1,name);
//     psmt->execute();
//     cout << "Running 'SELECT *from contact_list' after delete " << endl;
//     res = stmt->executeQuery(SELECT_ALL);
//     while(res->next())
//     {
//         cout << "\t... MYSQL replies: ";
//         cout << res->getInt("id") << " " << res->getString("name") << " " << res->getString("address")  
//         << " " << res->getString("phone") << endl;
        
//     }
//     //DB 사용 이후 pointer 해제    
//     delete res;
// 	delete conn;
//     delete stmt;
//     delete psmt;
//     } catch (sql::SQLException &e)
//     {   //예외처리
//         cout << "# ERR : SQLException in " << __FILE__;
//         cout << "(" << __FUNCTION__ <<") on line " << __LINE__ << endl;
//         cout << "# ERR: " << e.what();
//         cout << " (MySQL error code : " << e.getErrorCode();
//         cout << ", SQLState : " << e.getSQLState() << " )" << endl;
//     }
//         cout << endl;
//     	return 0;
// }

#endif