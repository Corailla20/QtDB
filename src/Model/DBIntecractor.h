/**
 * Class DBIntecractor : Generic class for connect and interact with a database: CRUD (Singleton)
 * host_name        = The Sql name host
 * database_name    = The database name
 * user_name        = The user name
 * password         = The user name password
 * q_sql_database   = The QSqlDatabase 
 * @author Pierre CHARLES - TechMed.
 */

#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <qvariant.h>
#include <string>

using namespace std;

class DBInteractor
{
private:

    static bool instanceFlag;
    static bool error;
    static DBInteractor *db_instance;
    static QSqlDatabase db;
	
    string host_name = "localhost";
    string database_name = "techmed";
    string user_name = "techmed";
    string password = "master";
    string q_sql_database = "QSQLITE";

    DBInteractor();
	
	void ExecuteQuery(string query_string);

public:

    static DBInteractor* getInstance();
	
    void InsertDefaultData(string file_name);
	void PrepareAndExecuteQuerySelect();
	void PrepareAndExecuteQueryInsert();
	void PrepareAndExecuteQueryUpdate();
	void PrepareAndExecuteQueryDelete();

    ~DBInteractor():
};
