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

    mywindow.show();

    return app.exec();

     /*
	//1) INSERT DATA
    //DBInteractor::getInstance()->InsertDefaultData("../data/data.sql");


    // EXAMPLE SELECT

    map<string, string> tableName;
    map<string, string> columnValueMappingForSelect;

    tableName["Personne"] = "";
    tableName["Patient"] = "";
    columnValueMappingForSelect["DESIGNATION"] = "'Software Developer'";
    columnValueMappingForSelect["ORGANIZATION"] = "'NIC'";

    DBInteractor::getInstance()->PrepareAndExecuteQuerySelect(tableName, columnValueMappingForSelect);

	// EXAMPLE UPDATE
    map<string, string> columnValueMappingForSet;
    columnValueMappingForSet["FIRST_NAME"] = "'DEBOPAM'";
    columnValueMappingForSet["LAST_NAME"] = "'PAL'";
    columnValueMappingForSet["DESIGNATION"] = "'Software Developer'";
    columnValueMappingForSet["ORGANIZATION"] = "'NIC'";

    map<string, string> columnValueMappingForCondition;
    columnValueMappingForCondition["COLUMN1"] = "LAIEHDOA ZUFH";

    DBInteractor::getInstance()->PrepareAndExecuteQueryUpdate("TEST", columnValueMappingForSet, columnValueMappingForCondition);

    // EXAMPLE INSERT
    map<string, string> columnValueMappingForInsert;

    columnValueMappingForInsert["Name"] = "'Software Developer'";
    columnValueMappingForInsert["first_name"] = "'NIC'";

    DBInteractor::getInstance()->PrepareAndExecuteQueryInsert("Personne", columnValueMappingForInsert);


    // EXAMPLE DELETE
    map<string, string> columnValueMappingForCondition2;

    columnValueMappingForCondition2["name"] = "'Pierre'";
    columnValueMappingForCondition2["age"] = "'10'";

    DBInteractor::getInstance()->PrepareAndExecuteQueryDelete("Personne",columnValueMappingForCondition2);
    */
}
