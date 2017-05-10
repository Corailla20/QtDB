#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Model/DBInteractor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <qvariant.h>
#include <string>

using namespace std;

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

void MainWindow::on_Button_Rechercher_clicked()
{
    string patient_text = ui->CB_Patient->currentText().toStdString();
    string modalite_text = ui->CB_Modalite->currentText().toStdString();
    string region_text = ui->CB_Region->currentText().toStdString();

    cout << "Patient : " << patient_text << endl;
    cout << "Modalite : " << modalite_text << endl;
    cout << "Region : " << region_text << endl;

    map<string, string> tableName, columnValueMappingForSelect;

    tableName["type_acquisition"] = "";
    tableName["patient"] = "";
    tableName["region_anatomique"] = "";

    if(patient_text != "")
    {
        columnValueMappingForSelect["patient.nom"] = "'" + patient_text + "'";
    }

    if(modalite_text != "")
    {
        columnValueMappingForSelect["type_acquisition.modalite"] = "'" + modalite_text + "'";
    }

    if(region_text != "")
    {
        columnValueMappingForSelect["region_anatomique.nom"] = "'" + region_text + "'";
    }

    if(patient_text != "" && region_text != "")
    {
            columnValueMappingForSelect["patient.patient_id"] = "etude.patient_id";
        columnValueMappingForSelect["region.region_id"] = "etude.region_id";
    }

    if(modalite_text != "" && patient_text != "")
    {
        columnValueMappingForSelect["serie.type_acquisition_id"] = "type_acquisition.type_acquisition_id";
        columnValueMappingForSelect["serie.etude_id"] = "etude.etude_id";
        columnValueMappingForSelect["patient.patient_id"] = "etude.patient_id";
    }

    if(region_text != "" && modalite_text != "")
    {
        columnValueMappingForSelect["region.region_id"] = "etude.region_id";
        columnValueMappingForSelect["serie.type_acquisition_id"] = "type_acquisition.type_acquisition_id";
        columnValueMappingForSelect["serie.etude_id"] = "etude.etude_id";
    }

    // SELECT
    //DBInteractor::getInstance()->PrepareAndExecuteQuerySelect(tableName, columnValueMappingForCondition);
}
