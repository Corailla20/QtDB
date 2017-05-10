#include <iostream>
#include <string>
#include <map>
#include "Model/DBInteractor.h"
#include <QApplication>
#include "View/mainwindow.h"

using namespace std;

int main(int argc, char** argv)
{

    // Affichage de la fenetre
    QApplication app(argc, argv);

    MainWindow mywindow;

    // Remplissage des combobox
    mywindow.initialization();
    mywindow.getDataFromDB();

    mywindow.show();

    return app.exec();

    /*
	//1) INSERT DATA
    //DBInteractor::getInstance()->InsertDefaultData("../data/data.sql");


    // EXAMPLE SELECT
    /*
    map<string, string> tableName, columnValueMappingForSelect;

    tableName["Personne"] = "'DEBOPAM'";
    tableName["Patient"] = "'PAL'";
    columnValueMappingForSet["DESIGNATION"] = "'Software Developer'";
    columnValueMappingForSet["ORGANIZATION"] = "'NIC'";

    map<string, string> columnValueMappingForCondition;
    columnValueMappingForCondition["COLUMN1"] = "LAIEHDOA ZUFH";

    DBInteractor::getInstance()->PrepareAndExecuteQueryUpdate("TEST", columnValueMappingForSet, columnValueMappingForCondition);

	// EXAMPLE UPDATE

    map<string, string> columnValueMappingForSet;
    columnValueMappingForSet["FIRST_NAME"] = "'DEBOPAM'";
    columnValueMappingForSet["LAST_NAME"] = "'PAL'";
    columnValueMappingForSet["DESIGNATION"] = "'Software Developer'";
    columnValueMappingForSet["ORGANIZATION"] = "'NIC'";

    map<string, string> columnValueMappingForCondition;
    columnValueMappingForCondition["COLUMN1"] = "LAIEHDOA ZUFH";

    DBInteractor::getInstance()->PrepareAndExecuteQueryUpdate("TEST", columnValueMappingForSet, columnValueMappingForCondition);

    */


}
