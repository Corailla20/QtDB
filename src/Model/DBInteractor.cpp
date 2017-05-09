#include "DBInteractor.h"
#include <fstream>

bool DBInteractor::instanceFlag = false;
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
 * @param tableName Table on which the SELECT Operation will be performed.
 * @param columnValueMappingForSelect List of Column & Value pair into clause WHERE.
 * @return Final generated INSERT SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQuerySelect(String tableName, Map<String, String> columnValueMappingForSelect)
{
	StringBuilder selectSQLBuilder = new StringBuilder();
	selectSQLBuilder.append("SELECT * FROM ").append(tableName).append(" WHERE ");

	columnValueMappingForSelect = RemovingNullOrBlankMappValue(columnValueMappingForSelect);

	if (!columnValueMappingForSelect.isEmpty()) {
		int currentElement = 0;
		int nbOfElement = columnValueMappingForSelect.size();
        for (Map.Entry<String, String> entry : columnValueMappingForSelect.entrySet()) {
            selectSQLBuilder.append(entry.getKey()).append(" = ").append(entry.getValue());
			if(currentElement !=  nbOfElement){
				selectSQLBuilder.append(" AND ");
			}
        }
    }

    selectSQLBuilder = new StringBuilder(selectSQLBuilder.subSequence(0, selectSQLBuilder.length() - 1));
	cout << selectSQLBuilder.toString() << endl;
    return selectSQLBuilder.toString();
}


/**
 * Methode for prepare, generate and execute an INSERT query
 * It is a generic function. It can be use for any DB Table
 * @param tableName Table on which the INSERT Operation will be performed.
 * @param columnValueMappingForInsert List of Column & Value pair to Insert.
 * @return Final generated INSERT SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQueryInsert(String tableName, Map<String, String> columnValueMappingForInsert) 
{  
	StringBuilder insertSQLBuilder = new StringBuilder();
	insertSQLBuilder.append("INSERT INTO ").append(tableName).append("( ").append(tableName).append("(");

	columnValueMappingForInsert = RemovingNullOrBlankMappValue(columnValueMappingForInsert);

    if (!columnValueMappingForInsert.isEmpty()) {
        for (Map.Entry<String, String> entry : columnValueMappingForInsert.entrySet()) {
            insertSQLBuilder.append(entry.getKey()).append(",");
        }
    }

    insertSQLBuilder = new StringBuilder(insertSQLBuilder.subSequence(0, insertSQLBuilder.length() - 1));
    insertSQLBuilder.append(") VALUES(");

    if (!columnValueMappingForInsert.isEmpty()) {
        for (Map.Entry<String, String> entry : columnValueMappingForInsert.entrySet()) {
            insertSQLBuilder.append(entry.getValue()).append(",");
        }
    }

    insertSQLBuilder = new StringBuilder(insertSQLBuilder.subSequence(0, insertSQLBuilder.length() - 1));
    insertSQLBuilder.append(")");
	cout << insertSQLBuilder.toString() << endl;
    return insertSQLBuilder.toString();
}



/**
 * Methode for prepare, generate and execute an UPDATE query
 * It is a generic function. It can be use for any DB Table
 * @param tableName Table on which the UPDATE Operation will be performed.
 * @param columnValueMappingForSet List of Column & Value pair to Update.
 * @param columnValueMappingForCondition List of Column & Value pair for WHERE clause.
 * @return Final generated UPDATE SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQueryUpdate(String tableName, Map<String, String> columnValueMappingForSet, Map<String, String> columnValueMappingForCondition) 
{
    StringBuilder updateQueryBuilder = new StringBuilder();

	columnValueMappingForSet = RemovingNullOrBlankMappValue(columnValueMappingForSet);
	columnValueMappingForCondition = RemovingNullOrBlankMappValue(columnValueMappingForCondition);

    updateQueryBuilder.append("UPDATE ").append(tableName).append(" SET "); //Making the UPDATE Query

    if (!columnValueMappingForSet.isEmpty()) {
        for (Map.Entry<String, String> entry : columnValueMappingForSet.entrySet()) {
            updateQueryBuilder.append(entry.getKey()).append("=").append(entry.getValue()).append(",");
        }
    }

    updateQueryBuilder = new StringBuilder(updateQueryBuilder.subSequence(0, updateQueryBuilder.length() - 1));
    updateQueryBuilder.append(" WHERE ");

    if (!columnValueMappingForCondition.isEmpty()) {
        for (Map.Entry<String, String> entry : columnValueMappingForCondition.entrySet()) {
            updateQueryBuilder.append(entry.getKey()).append("=").append(entry.getValue());
            updateQueryBuilder.append(",");
        }
    }

    updateQueryBuilder = new StringBuilder(updateQueryBuilder.subSequence(0, updateQueryBuilder.length() - 1));
	cout << updateQueryBuilder.toString() << endl;
    return updateQueryBuilder.toString();  
}


/**
 * Methode for prepare, generate and execute a DELETE query
 * It is a generic function. It can be use for any DB Table.
 * @param tableName Table on which the DELETE Operation will be performed.
 * @param columnValueMappingForCondition List of Column & Value pair for WHERE clause.
 * @return Final generated DELETE SQL Statement.
 */
void DBInteractor::PrepareAndExecuteQueryDelete(String tableName, Map<String, String> columnValueMappingForCondition) 
{
    StringBuilder deleteSQLBuilder = new StringBuilder();
	deleteSQLBuilder.append("DELETE FROM ").append(tableName).append(" WHERE ");

	columnValueMappingForCondition = RemovingNullOrBlankMappValue(columnValueMappingForCondition);

    if (!columnValueMappingForCondition.isEmpty()) {
        for (Map.Entry<String, String> entry : columnValueMappingForCondition.entrySet()) {
            deleteSQLBuilder.append(entry.getKey()).append("=").append(entry.getValue()).append(" AND ");
        }
    }

    deleteSQLBuilder = new StringBuilder(deleteSQLBuilder.subSequence(0, deleteSQLBuilder.length() - 5));
	cout << deleteSQLBuilder.toString() << endl;
    return deleteSQLBuilder.toString(); 
}

/**
 * Methode for Removing column that holds NULL value or Blank value
 * It is a generic function.
 * @param columnValueMapping List of Column & Value pair to process removing null or empty values
 * @return Final generated Map<String, String>
 */
map<string, string> RemovingNullOrBlankMappValue(columnValueMapping)
{
	if (!columnValueMapping.isEmpty()) {
        for (Map.Entry<String, String> entry : columnValueMapping.entrySet()) {
            if(entry.getValue() == null || entry.getValue().equals("")) {
                columnValueMapping.remove(entry.getKey());
            }
        }
    }
	return columnValueMapping;
}


/**
 * Methode for execute SQL query String
 * It is a generic function.
 * @param queryString the sql query string
 */
void DBInteractor::ExecuteQuery(string queryString)
{
	QSqlQuery query(sqlQueryString, db);

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
    if(fichier) {
		string line;
		while(getline(file, line)) {
			cout << line << endl;
			ExecuteQuery(line);
		}
	} else {
		cerr << "Impossible d'ouvrir le fichier !" << endl;
	}
}




