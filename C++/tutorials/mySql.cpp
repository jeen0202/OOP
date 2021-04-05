#include <iostream>
#include <mysql.h>

#pragma comment(lib, "libmySQL.lib")

#define DB_HOST "127.0.0.1"
#define DB_USER "root"
#define DB_PASS "111111"
#define DB_NAME "tutorials"

int main(int argc, char**argv)
{
    printf("MYSQL client version :%s\n ",mysql_get_client_info());

    MYSQL *connection=NULL, conn;
    MYSQL_RES *sql_result;
    MYSQL_ROW sql_row;
    int query_stat;

    mysql_init(&conn);

    connection = mysql_real_connect(&conn, DB_HOST,DB_USER,DB_PASS,DB_NAME,3306,(char*)NULL,0);
    if(connection==NULL)
    {
        fprintf(stderr, "Mysql connection error :%s",mysql_error(&conn));
        return 1;
    }
    char *querry = "SELECT * FROM author";
    auery_stat=mysql_query(connection,query);
    if(query_stat !=0)
    {
        fprintf(stderr, "Mysql query error : %s", mysql_error(&conn));
        return 1;
    }

    sql_result = mysql_store_result(connection);
    while((sql_row=mysql_fetch_row(sql_result))!=NULL)
    {
        printf("%2s %2s %s\n", sql_row[0],sql_row(1],sql_row[2]);        
    }
    mysql_free_result(sql_result);

    mysql_close(connection);

    return 0;
}