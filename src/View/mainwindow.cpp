#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Model/DBInteractor.h"
<<<<<<< HEAD
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <qvariant.h>
=======

using namespace std;

>>>>>>> 35360abcffe8b7f005542052dea02b01201b4f7b

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

<<<<<<< HEAD
void MainWindow::initialization()
{
    ui->CB_Pathologie->addItem("");
    ui->CB_Modalite->addItem("");
    ui->CB_Patient->addItem("");
    ui->CB_Region->addItem("");
}

void MainWindow::getDataFromDB()
{
    QSqlDatabase db;

    const string HOST_NAME = "localhost";
    const string DATABASE_NAME = "tech_pax";
    const string USER_NAME = "techmed";
    const string PASSWORD = "master";
    const string QSQL_DATABASE = "QSQLITE";

    db = QSqlDatabase::addDatabase(QSQL_DATABASE.c_str());
    db.setHostName(HOST_NAME.c_str());
    db.setDatabaseName(DATABASE_NAME.c_str());
    db.setUserName(USER_NAME.c_str());
    db.setPassword(PASSWORD.c_str());
    bool ok = db.open();

    QSqlQuery query("SELECT nom FROM patient", db);

    while (query.next()) {
        QString name = query.value(0).toString();
        ui->CB_Patient->addItem(name);
    }
}
=======
void MainWindow::on_Button_Rechercher_clicked()
{
    string patient_text = ui->CB_Patient->currentText();
    string modalite_text = ui->CB_Modalite->currentText();
    string pathologie_text = ui->CB_Pathologie->currentText();
    string region_text = ui->CB_Region->currentText();

    cout << "Patient : " << patient_text << endl;
    cout << "Modalite : " << modalite_text << endl;
    cout << "Pathologie : " << pathologie_text << endl;
    cout << "Region : " << region_text << endl;
>>>>>>> 35360abcffe8b7f005542052dea02b01201b4f7b

    map<string, string> columnValueMappingForCondition;

    if(patient_text != "")
    {
        columnValueMappingForCondition.put("patient.nom", patient_text);
    }
    if(modalite_text != "")
    {
        columnValueMappingForCondition.put("type_acquisition.modalite", modalite_text);
    }
    if(pathologie_text != "")
    {
        //columnValueMappingForCondition.put("Pathologie.nom", pathologie_text);
    }
    if(region_text != "")
    {
        columnValueMappingForCondition.put("region_anatomique.nom", region_text);
    }

    columnValueMappingForCondition.put("patient.patient_id", "etude.patient_id");
    columnValueMappingForCondition.put("region.region_id", "etude.region_id");
    columnValueMappingForCondition.put("serie.type_acquisition_id", "type_acquisition.type_acquisition_id");
    columnValueMappingForCondition.put("serie.etude_id", "etude.etude_id");
    // SELECT
    //DBInteractor::getInstance()->PrepareAndExecuteQuerySelect("patient", columnValueMappingForCondition);
}
