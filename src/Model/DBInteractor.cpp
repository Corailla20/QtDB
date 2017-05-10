#include "DBInteractor.h"
#include <fstream>
#include <QSqlQuery>
#include <QSqlError>
#include <qvariant.h>
#include <sstream>

bool DBInteractor::instanceFlag = false;
bool DBInteractor::error = false;
DBInteractor* DBInteractor::db_instance = NULL;
QSqlDatabase DBInteractor::db;

const string DBInteractor::HOST_NAME = "localhost";
const string DBInteractor::DATABASE_NAME = "tech_pax";
const string DBInteractor::USER_NAME = "techmed";
const string DBInteractor::PASSWORD = "master";
const string DBInteractor::QSQL_DATABASE = "QSQLITE";

/**
* Methode for get or create a database instance access
* Return a database instance
*/
DBInteractor* DBInteractor::getInstance() 
{
	if(!instanceFlag) 
	{
		db_instance = new DBInteractor();
		instanceFlag = true;
		return db_instance;
	} 
	else 
	{
		return db_instance;
	}
}

/**
* Methode to create and instantiate a database interaction singleton
*/
DBInteractor::DBInteractor()
{
	cout<<"Creation of the database instance"<<endl;
    db = QSqlDatabase::addDatabase(QSQL_DATABASE.c_str());
    db.setHostName(HOST_NAME.c_str());
    db.setDatabaseName(DATABASE_NAME.c_str());
    db.setUserName(USER_NAME.c_str());
    db.setPassword(PASSWORD.c_str());
	error = db.open();

	QSqlQuery query(db);
	
	if (!query.exec("PRAGMA foreign_keys = ON")){
		std::cout << "Impossible d'activer les clés étrangères" << std::endl;
		instanceFlag = false;
	}
	if(instanceFlag == false){
		std::cout << "Errors" << std::endl;
	}
}

/**
 * Methode for prepare, generate and execute a SELECT query
 * It is a generic function. It can be use for any DB Table
 * @param tableName map Table on which the SELECT Operation will be performed.
 * @param columnValueMappingForSelect List of Column & Value pair into clause WHERE.
 * @return Final generated INSERT SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQuerySelect(map<string, string> tableName, map<string, string> columnValueMappingForSelect)
{
    std::stringstream selectSQLBuilder;
    selectSQLBuilder << "SELECT * FROM ";

    if (!tableName.empty()) {
        int currentElement = 0;
        int nbOfElement = tableName.size();
        for (map<string, string>::iterator entry = tableName.begin(); entry != tableName.end(); ++entry) {
            selectSQLBuilder << entry->first << " = " << entry->second;
            if(currentElement !=  nbOfElement){
                selectSQLBuilder << ",";
            }
            currentElement++;
        }
    }

    selectSQLBuilder << " WHERE ";

    if (!columnValueMappingForSelect.empty()) {
		int currentElement = 0;
		int nbOfElement = columnValueMappingForSelect.size();

        for (map<string, string>::iterator entry = columnValueMappingForSelect.begin(); entry != columnValueMappingForSelect.end(); ++entry) {
            selectSQLBuilder << entry->first << " = " << entry->second;
			if(currentElement !=  nbOfElement){
                selectSQLBuilder << " AND ";
			}
            currentElement++;
        }
    }

    cout << selectSQLBuilder.str() << endl;
    //return selectSQLBuilder.toString();
}


/**
 * Methode for prepare, generate and execute an INSERT query
 * It is a generic function. It can be use for any DB Table
 * @param tableName Table on which the INSERT Operation will be performed.
 * @param columnValueMappingForInsert List of Column & Value pair to Insert.
 * @return Final generated INSERT SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQueryInsert(string tableName, map<string, string> columnValueMappingForInsert)
{  
    std::stringstream insertSQLBuilder;
    insertSQLBuilder << "INSERT INTO " << tableName << "( " << tableName << "(";

    if (!columnValueMappingForInsert.empty()) {
        for (map<string, string>::iterator entry = columnValueMappingForInsert.begin(); entry != columnValueMappingForInsert.end(); ++entry) {
            insertSQLBuilder << entry->first << ",";
        }

        insertSQLBuilder << ") VALUES(";

        for (map<string, string>::iterator entry = columnValueMappingForInsert.begin(); entry != columnValueMappingForInsert.end(); ++entry) {
            insertSQLBuilder << entry->second << ",";
        }
    }
    insertSQLBuilder << ")";

    cout << insertSQLBuilder.str() << endl;
    //return insertSQLBuilder.toString();
}



/**
 * Methode for prepare, generate and execute an UPDATE query
 * It is a generic function. It can be use for any DB Table
 * @param tableName Table on which the UPDATE Operation will be performed.
 * @param columnValueMappingForSet List of Column & Value pair to Update.
 * @param columnValueMappingForCondition List of Column & Value pair for WHERE clause.
 * @return Final generated UPDATE SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQueryUpdate(string tableName, map<string, string> columnValueMappingForSet, map<string, string> columnValueMappingForCondition)
{
    std::stringstream updateQueryBuilder;

    updateQueryBuilder << "UPDATE " << tableName << " SET ";

    if (!columnValueMappingForSet.empty()) {
        int currentElement = 0;
        int nbOfElement = columnValueMappingForSet.size()-1;

        for (map<string, string>::iterator entry = columnValueMappingForSet.begin(); entry != columnValueMappingForSet.end(); ++entry) {
            updateQueryBuilder << entry->first << " = " << entry->second ;
            if(currentElement < nbOfElement){
                updateQueryBuilder << ",";;
            }
            currentElement++;
        }
    }

    updateQueryBuilder << " WHERE ";

    if (!columnValueMappingForCondition.empty()) {
        int currentElement = 0;
        int nbOfElement = columnValueMappingForCondition.size()-1;
        for (map<string, string>::iterator entry = columnValueMappingForCondition.begin(); entry != columnValueMappingForCondition.end(); ++entry) {
            updateQueryBuilder << entry->first << " = " << entry->second ;
            if(currentElement < nbOfElement){
                updateQueryBuilder << ",";;
            }
            currentElement++;
        }
    }

    cout << updateQueryBuilder.str() << endl;
    //return updateQueryBuilder.toString();  
}


/**
 * Methode for prepare, generate and execute a DELETE query
 * It is a generic function. It can be use for any DB Table.
 * @param tableName Table on which the DELETE Operation will be performed.
 * @param columnValueMappingForCondition List of Column & Value pair for WHERE clause.
 * @return Final generated DELETE SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQueryDelete(string tableName, map<string, string> columnValueMappingForCondition)
{
    std::stringstream deleteSQLBuilder;
    deleteSQLBuilder << "DELETE FROM " << tableName << " WHERE ";

    if (!columnValueMappingForCondition.empty()) {
        for (map<string, string>::iterator entry = columnValueMappingForCondition.begin(); entry != columnValueMappingForCondition.end(); ++entry) {
            deleteSQLBuilder << entry->first << "=" << entry->second << " AND ";
        }
    }

    cout << deleteSQLBuilder.str() << endl;
    //return deleteSQLBuilder.toString(); 
}


/**
 * Methode for execute SQL query String
 * It is a generic function.
 * @param queryString the sql query string
 */
void DBInteractor::ExecuteQuery(string sqlQueryString)
{
    QSqlQuery query(QString::fromStdString(sqlQueryString), db);

    if(!query.exec()) {
        std::cout << "Une erreur s'est produite" << std::endl;
    }

	while (query.next()) {
        QString test = query.value(0).toString();
        std::cout << "Il y a " << test.toStdString() << std::endl;
    }
}

/**
 * Methode for execute step by step, line by line a sql file
 * It is a function to execute each line of a sql document into the databse
 * @param pathFileName the path of the file
 */
void DBInteractor::InsertDefaultData(string pathFileName) 
{
	ifstream file(pathFileName, ios::in);
    if(file) {
		string line;
		while(getline(file, line)) {
			cout << line << endl;
			ExecuteQuery(line);
		}
	} else {
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}
