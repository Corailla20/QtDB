#include "DBInteractor.h"

bool DBInteractor::instanceFlag = false;
DBInteractor* DBInteractor::db_instance = NULL;

/**
* Methode to get or create a database instance access
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
	db = QSqlDatabase::addDatabase(q_sql_database);
	db.setHostName(host_name);
	db.setDatabaseName(database_name);
	db.setUserName(user_name);
	db.setPassword(password);
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
* Methode for destroy an database instance
*/
DBInteractor::~DBInteractor()
{
	instanceFlag = false;
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




