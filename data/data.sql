DELETE FROM referent_etude_utilisateur;
DELETE FROM source_resultat_resultat;
DELETE FROM source_resultat_serie;
DELETE FROM resultat;
DELETE FROM note;
DELETE FROM donnee;
DELETE FROM serie;
DELETE FROM etude;
DELETE FROM utilisateur;
DELETE FROM patient;
DELETE FROM region_anatomique;
DELETE FROM role;
DELETE FROM type_acquisition;

INSERT INTO patient(patient_id,date_naissance,sexe,nom,prenom,coordonnees) VALUES(1,'27/05/1989','F','Martin','Julie','');
INSERT INTO patient(patient_id,date_naissance,sexe,nom,prenom,coordonnees) VALUES(2,'12/01/1967','M','Dubois','Paul','');
INSERT INTO patient(patient_id,date_naissance,sexe,nom,prenom,coordonnees) VALUES(3,'04/10/1998','M','Dumas','Enzo','');
INSERT INTO patient(patient_id,date_naissance,sexe,nom,prenom,coordonnees) VALUES(4,'19/09/1991','F','Vincent','Lucie','');

INSERT INTO region_anatomique(region_id,nom) VALUES (1,'Coeur');
INSERT INTO region_anatomique(region_id,nom) VALUES (2,'Poumon');
INSERT INTO region_anatomique(region_id,nom) VALUES (3,'Cerveau');
INSERT INTO region_anatomique(region_id,nom) VALUES (4,'Foie');
INSERT INTO region_anatomique(region_id,nom) VALUES (5,'Intestin');
INSERT INTO region_anatomique(region_id,nom) VALUES (6,'Estomac');
INSERT INTO region_anatomique(region_id,nom) VALUES (7,'Dorsale');

INSERT INTO type_acquisition(type_acquisition_id,appareil,modalite) VALUES (1,'Scanner','PetScan');
INSERT INTO type_acquisition(type_acquisition_id,appareil,modalite) VALUES (2,'IRM','T2');

INSERT INTO etude(etude_id,dateAcquisition,notes,patient_id,region_id) VALUES (1,'03/05/2017','',1,2);
INSERT INTO etude(etude_id,dateAcquisition,notes,patient_id,region_id) VALUES (2,'14/02/2015','',1,1);
INSERT INTO etude(etude_id,dateAcquisition,notes,patient_id,region_id) VALUES (3,'09/07/2012','',2,3);
INSERT INTO etude(etude_id,dateAcquisition,notes,patient_id,region_id) VALUES (4,'12/04/2009','',3,6);
INSERT INTO etude(etude_id,dateAcquisition,notes,patient_id,region_id) VALUES (5,'29/11/2016','',3,4);
INSERT INTO etude(etude_id,dateAcquisition,notes,patient_id,region_id) VALUES (6,'24/12/2011','',4,7);

INSERT INTO serie(serie_id,type_acquisition_id,etude_id) VALUES(1,1,1);
INSERT INTO serie(serie_id,type_acquisition_id,etude_id) VALUES(2,2,2);
INSERT INTO serie(serie_id,type_acquisition_id,etude_id) VALUES(3,2,3);
INSERT INTO serie(serie_id,type_acquisition_id,etude_id) VALUES(4,1,4);
INSERT INTO serie(serie_id,type_acquisition_id,etude_id) VALUES(5,2,5);
INSERT INTO serie(serie_id,type_acquisition_id,etude_id) VALUES(6,1,6);

INSERT INTO donnee(donnee_id,nom_fichier,heure,serie_id) VALUES (1,'exam001.jpg','10:03:00',1);

INSERT INTO role(role_id,nom,description) VALUES (1,'Médecin','');
INSERT INTO role(role_id,nom,description) VALUES (2,'Chercheur','');

INSERT INTO utilisateur(login,password,email,nom,prenom,coordonnees,role_id) VALUES('jgilles','jgilles','jacques_gilles@gmail.fr','Gilles','Jacques','',1);
INSERT INTO utilisateur(login,password,email,nom,prenom,coordonnees,role_id) VALUES('gcharles','gcharles','gaelle_charles@gmail.fr','Charles','Gaelle','',1);
INSERT INTO utilisateur(login,password,email,nom,prenom,coordonnees,role_id) VALUES('pRota','pRota','philippe_rota@gmail.fr','Rota','Philippe','',2);

INSERT INTO resultat(resultat_id,nom_fichier,description,type,auteur) VALUES (1,'bl','','',1);
