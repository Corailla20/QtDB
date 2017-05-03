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
    static DBIntecractor *db_instance;

    DBIntecractor()
    {
        cout<<"Creation de l'instance"<<endl;
        QSqlDatabase db_instance = QSqlDatabase::addDatabase("QSQLITE");
        db_instance.setHostName("localhost");
        db_instance.setDatabaseName("techmed");
        db_instance.setUserName("techmed");
        db_instance.setPassword("master");
        instanceFlag = db_instance.open();

        QSqlQuery query(db_instance);
        if (!query.exec("PRAGMA foreign_keys = ON")){
            std::cout << "Impossible d'activer les clés étrangères" << std::endl;
            instanceFlag = false;
        }
        if(instanceFlag == false){
            std::cout << "Errors" << std::endl;
        }
    }

public:
    static DBIntecractor* getInstance();

    void InsertDefaultData(string file_name);

    ~DBIntecractor()
    {
        instanceFlag = false;
    }
};
