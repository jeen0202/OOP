#include <iostream>
#include <stdlib.h>
//#include <mysql.h>
#include "mysql_driver.h"
#include "mysql_connection.h"
#include "mysql_error.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
//#include "mysql_connection.h"
//#pragma comment(lib, "libmySQL.lib")

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "111111"
#define DB_NAME "tutorials"

using namespace std;

#define SELECT_ALL "SELECT * FROM AUTHOR"
int main(int argc, char**argv)
{
    cout << endl;
    cout << "Running 'SELECT *from author'..." << endl;

	// mysql::MySQL_Driver *driver;
	// Connection *conn;
    // sql::Statement *stmt;    
	// driver = mysql::get_mysql_driver_instance();    
	// conn = driver->connect(DB_HOST,DB_USER,DB_PASS);
    try{
    // sql::Driver *driver;
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *conn;
    sql::Statement *stmt;
    sql::ResultSet *res;
    // connection create
    driver = sql::mysql::get_mysql_driver_instance();
    conn = driver->connect(DB_HOST,DB_USER,DB_PASS);

    stmt = conn->createStatement();
    stmt->execute("USE tutorials");
    res = stmt->executeQuery("SELECT * from author");
    while(res->next())
    {
        cout << "\t... MYSQL replies: ";
        cout << res->getInt("id") << " " << res->getString("name") << " " << res->getString("profile") << endl;
        
    }
    // stmt->execute("USE tutorials");
    // stmt->execute("DROP TABLE IF EXISTS test");
    // stmt->execute("CREATE TABLE test(id INT, label CHAR(1))")
    
    delete res;
	delete conn;
    delete stmt;
    } catch (sql::SQLException &e)
    {
        cout << "# ERR : SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ <<") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code : " << e.getErrorCode();
        cout << ", SQLState : " << e.getSQLState() << " )" << endl;
    }
        cout << endl;
    	return 0;
}
