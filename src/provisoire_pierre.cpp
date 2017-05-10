




#include <iostream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <qvariant.h>
#include <string>

void create_tables(QSqlDatabase & db){
    QSqlQuery query1("CREATE TABLE IF NOT EXISTS Groupe(nom VARCHAR(32), group_id INTEGER, PRIMARY KEY(group_id))", db);
    QSqlQuery query2("CREATE TABLE IF NOT EXISTS Utilisateur(nom VARCHAR(64), user_id INTEGER, group_id INTEGER NOT NULL, PRIMARY KEY(user_id), FOREIGN KEY(group_id) REFERENCES Groupe(group_id))", db);
    QSqlQuery query3("CREATE TABLE IF NOT EXISTS Salle(numero VARCHAR(32), salle_id INTEGER, capacite INTEGER, emplacement VARCHAR(64), PRIMARY KEY(salle_id))", db);
    QSqlQuery query4("CREATE TABLE IF NOT EXISTS Reservation(libelle VARCHAR(64), reservation_id INTEGER, debut DATETIME, salle_id INTEGER NOT NULL, user_id INTEGER NOT NULL, fin DATETIME, PRIMARY KEY(reservation_id), FOREIGN KEY(salle_id) REFERENCES Salle(salle_id), FOREIGN KEY(user_id) REFERENCES Utilisateur(user_id))", db);
    QSqlQuery query5("CREATE TABLE IF NOT EXISTS Materiel(nom VARCHAR(32), materiel_id INTEGER, PRIMARY KEY(materiel_id))", db);
    QSqlQuery query6("CREATE TABLE IF NOT EXISTS Equipee(nombre INTEGER, materiel_id INTEGER NOT NULL, salle_id INTEGER NOT NULL, FOREIGN KEY(salle_id) REFERENCES Salle(salle_id), FOREIGN KEY(materiel_id) REFERENCES Materiel(materiel_id)", db);


    if(!query1.exec()){
        std::cout << "Impossible de cr?er la table Groupe" << std::endl;
    }
    if(!query2.exec()){
        std::cout << "Impossible de cr?er la table Utilisateur" << std::endl;
    }
    if(!query3.exec()){
        std::cout << "Impossible de cr?er la table Salle" << std::endl;
    }
    if(!query4.exec()){
        std::cout << "Impossible de cr?er la table Reservation" << query4.lastError().text().toStdString() << std::endl;
    }
    if(!query5.exec()){
        std::cout << "Impossible de cr?er la table Materiel" << std::endl;
    }
}

void addData(QSqlDatabase & db){
    QSqlQuery queryAdd1("INSERT INTO Utilisateur VALUES('Nils',1,1)", db);
    QSqlQuery queryAdd2("INSERT INTO Groupe VALUES('Groupe de Nils',1)", db);
    QSqlQuery queryAdd3("INSERT INTO Utilisateur VALUES('Baptiste',2,2)", db);
    QSqlQuery queryAdd4("INSERT INTO Groupe VALUES('Invocateurs du d?mon',2)", db);
    QSqlQuery queryAdd5("INSERT INTO Salle VALUES('643', 1, 16, 'R3')", db);
    queryAdd1.exec();
    queryAdd2.exec();
}

/*
DBInteractor::DBInteractor()
{
    cout<<"Creation de l'instance"<<endl;
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("techmed");
    db.setUserName("techmed");
    db.setPassword("master");
    bool ok = db.open();
}

DBInteractor::~DBInteractor()
{
    cout<<"Destruction de l'instance"<<endl;
}

DBInteractor& DBInteractor::Instance()
{
    return db_instance;
}

int main() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("techmed");
    db.setUserName("techmed");
    db.setPassword("master");
    bool ok = db.open();

    QSqlQuery query(db);
    if (!query.exec("PRAGMA foreign_keys = ON")){
        std::cout << "Impossible d'activer les cl?s ?trang?res" << std::endl;
        return 2;
    }

    create_tables(db);
    addData(db);

    if (!ok) {
        std::cout << "error" << std::endl;
        return 1;
    }
    else {
        std::cout << "ok" << std::endl;
       // return 0;
    }

    QSqlQuery querySelect1("SELECT Utilisateur.nom, Groupe.nom FROM Utilisateur, Groupe WHERE Utilisateur.group_id = Groupe.group_id", db);

    //querySelect1.exec();
    while (querySelect1.next()){
        QString user = querySelect1.value(0).toString();
        QString group = querySelect1.value(1).toString();
        std::cout << user.toStdString() << "  " << group.toStdString() << std::endl;
    }

    QSqlQuery querySelect2("SELECT count(*) from Salle", db);

    while (querySelect2.next()){
        QString nbSalles = querySelect2.value(0).toString();
        std::cout << "Il y a " << nbSalles.toStdString() << " salle(s)." << std::endl;
    }
    char reponse;
    std::cout << "Voulez-vous ajouter une personne dans la base ? (y/n)" << std::endl;
    std::cin >> reponse;
    if(&reponse != "n"){

        std::string newName;
        std::string newGroup;
        std::cout << "Nom ?" << std::endl;
        std::cin >> newName;
        std::cout << "Groupe ?" << std::endl;
        std::cin >> newGroup;

        QSqlQuery query(db);
        query.prepare("INSERT INTO Utilisateur(nom, group_id) VALUES (:nom, :groupe)");
        query.bindValue(":nom", newName.c_str());
        query.bindValue(":groupe", newGroup.c_str());

        query.exec();
    }

}
*/
