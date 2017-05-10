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

    mywindow.show();

    return app.exec();

	/** DEBUT PIERRE EN DEV**/
    /*
	//1) INSERT DATA
	DBInteractor::getInstance()->InsertDefaultData("../data/data.sql");

	// 2) 
	// EXAMPLE UPDATE
	// Preparing to call and execute function to generate UPDATE SQL request
    map<string, string> columnValueMappingForSet;
	columnValueMappingForSet.put("FIRST_NAME", "'DEBOPAM'");
	columnValueMappingForSet.put("LAST_NAME", "'PAL'");
	columnValueMappingForSet.put("DESIGNATION", "'Software Developer'");
	columnValueMappingForSet.put("ORGANIZATION", "'NIC'");

    map<string, string> columnValueMappingForCondition;
	columnValueMappingForCondition.put("COLUMN1", "LAIEHDOA ZUFH");

	// UPDATE
	DBInteractor::getInstance()->PrepareAndExecuteQueryUpdate("TESST", columnValueMappingForSet, columnValueMappingForCondition);

    */
	/** FIN PIERRE **/

}
