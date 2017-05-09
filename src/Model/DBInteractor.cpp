#include "DBInteractor.h"

bool DBInteractor::instanceFlag = false;
DBInteractor* DBInteractor::db_instance = NULL;
QSqlDatabase DBInteractor::db;

const string DBInteractor::HOST_NAME = "localhost";
const string DBInteractor::DATABASE_NAME = "techmed";
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
* Methode to create and instantiate a database interaction
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
* Methode for execute a query
* Params : A string query
*/
void ExecuteQuery(string query_string)
{
	
}

/**
* Methode for prepare, generate and execute an insert query
*/
void DBInteractor::InsertDefaultData(string file_name) 
{
	cout << "No implement yet" << endl;
}

/**
* Methode for prepare, generate and execute a SELECT query
*/
void DBInteractor::PrepareAndExecuteQuerySelect()
{
	cout << "No implement yet" << endl;
}

/**
* Methode for prepare, generate and execute an INSERT query
*/
void DBInteractor::PrepareAndExecuteQueryInsert()
{
	cout << "No implement yet" << endl;
}

/**
* Methode for prepare, generate and execute an UPDATE query
*/
void DBInteractor::PrepareAndExecuteQueryUpdate()
{
	cout << "No implement yet" << endl;
}

/**
* Methode for prepare, generate and execute a DELETE query
*/
void DBInteractor::PrepareAndExecuteQueryDelete()
{
	cout << "No implement yet" << endl;
}




