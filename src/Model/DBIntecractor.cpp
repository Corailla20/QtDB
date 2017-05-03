#include "DBInteractor.h"

bool DBInteractor::instanceFlag = false;
DBInteractor* DBInteractor::db_instance = NULL;

DBInteractor* DBInteractor::getInstance()
{
    if(! instanceFlag)
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

void DBInteractor::InsertDefaultData(string file_name)
{
    cout << "Method for insert sql file data" << endl;
}




