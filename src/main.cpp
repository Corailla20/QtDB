#include <iostream>
#include <string>
#include <map>
#include "Model/DBInteractor.h"

using namespace std;

int main()
{
    
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

    */

	// EXAMPLE UPDATE

    map<string, string> columnValueMappingForSet;
    columnValueMappingForSet["FIRST_NAME"] = "'DEBOPAM'";
    columnValueMappingForSet["LAST_NAME"] = "'PAL'";
    columnValueMappingForSet["DESIGNATION"] = "'Software Developer'";
    columnValueMappingForSet["ORGANIZATION"] = "'NIC'";

    map<string, string> columnValueMappingForCondition;
    columnValueMappingForCondition["COLUMN1"] = "LAIEHDOA ZUFH";

    DBInteractor::getInstance()->PrepareAndExecuteQueryUpdate("TEST", columnValueMappingForSet, columnValueMappingForCondition);

}
