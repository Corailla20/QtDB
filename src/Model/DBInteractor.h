/**
 * Class DBIntecractor : Generic class for connect and interact with a database: CRUD (Singleton)
 * HOST_NAME        = The Sql name host
 * DATABASE_NAME    = The database name
 * USER_NAME        = The user name
 * PASSWORD         = The user name password
 * QSQL_DATABASE   = The QSqlDatabase
 * @author Pierre CHARLES - TechMed.
 */

#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <qvariant.h>
#include <string>
#include <map>

using namespace std;

class DBInteractor
{
private:

    static bool instanceFlag;
    static bool error;
    static DBInteractor *db_instance;
    static QSqlDatabase db;

    static const string HOST_NAME;
    static const string DATABASE_NAME;
    static const string USER_NAME;
    static const string PASSWORD;
    static const string QSQL_DATABASE;

    DBInteractor();

public:

    static DBInteractor* getInstance();
	
    void PrepareAndExecuteQuerySelect(string tableName, map<string, string> columnValueMappingForSelect);
    void PrepareAndExecuteQueryInsert(string tableName, map<string, string> columnValueMappingForInsert);
    void PrepareAndExecuteQueryUpdate(string tableName, map<string, string> columnValueMappingForSet, map<string, string> columnValueMappingForCondition);
    void PrepareAndExecuteQueryDelete(string tableName, map<string, string> columnValueMappingForCondition);
	void ExecuteQuery(string queryString);
    void InsertDefaultData(string pathFileName);
    map<string, string> RemovingNullOrBlankMappValue(map<string, string> columnValueMapping);

    ~DBInteractor()
    {
        instanceFlag = false;
    }
};
