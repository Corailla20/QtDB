#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Model/DBInteractor.h"

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
