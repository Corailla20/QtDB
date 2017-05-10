#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Model/DBInteractor.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <qvariant.h>

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


