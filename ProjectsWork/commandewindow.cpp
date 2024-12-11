#include "commandewindow.h"
#include "ui_commandewindow.h"
#include <QMessageBox>
#include <QPainter>
#include<QPdfWriter>
#include <QPieSeries>
#include <QChartView>
#include <QDebug>
#include <QSqlError>

#include <QSqlQuery>
#include  <QDebug>
#include <QRadioButton>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QFileDialog>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QVector2D>
#include <QVector>
#include <QSqlQuery>
#include<QDesktopServices>
#include <QMessageBox>
#include<QUrl>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include <QSqlError>
#include <QChart>
//#include <QRegExp>
#include <QDate>
#include <QRegularExpression>
#include <QtCharts>
#include <QtCharts/QChartView>


//using namespace QtCharts;
CommandeWindow::CommandeWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CommandeWindow)
{

    ui->setupUi(this);
    // ui->Commandelist->setModel(CL.afficher());
}

CommandeWindow::~CommandeWindow()
{
    delete ui;
}


void CommandeWindow::on_AjoutCo_clicked()
{

        QDate dateLivraison = ui->DL->date();
        int quantiteC = ui->QC->text().toInt();
        QDate dateCommande = ui->DC->date();
        QString etat = ui->Etat->currentText();


        Commande commande( dateLivraison, quantiteC, dateCommande, etat);


        bool test= commande.ajouter();
        if(test)
        {
            ui->Commandelist->setModel(CL.afficher());
            QMessageBox :: information(nullptr,QObject::tr("OK"),
                    QObject::tr("Ajout effectuer\n"
                                "click cancel to exit."),QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("Ajout non effectué.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
        }
}

void CommandeWindow::on_supco_clicked()
{
    int id=ui->idsup->text().toInt();

        bool test=CL.supprimer(id);

        if(test)
        {
            ui->Commandelist->setModel(CL.afficher());
            QMessageBox :: information(nullptr,QObject::tr("OK"),
                    QObject::tr("suppresion effectuer\n"
                                "click cancel to exit."),QMessageBox::Cancel);
        }
        else
        {
            QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                                  QObject::tr("suppresion non effectué.\n"
                                              "click cancel to exit."),QMessageBox::Cancel);
        }
}

void CommandeWindow::on_pushButton_clicked()
{


    int idam= ui->idam->text().toInt();
    int Quantite=ui->QCM->text().toInt();
    QDate datecommande=ui->DCM->date();
    QDate datelivr=ui->DLM->date();
    QString etat=ui->EtatM->currentText();

    bool test=CL.modifier(idam,datecommande,Quantite,datelivr,etat);
    if(test)
    {
    ui->Commandelist->setModel(CL.afficher());
        QMessageBox :: information(nullptr,QObject::tr("OK"),
                QObject::tr("modification effectuer\n"
                            "click cancel to exit."),QMessageBox::Cancel);
    }
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("Not OK"),
                              QObject::tr("modification non effectué.\n"
                                          "click cancel to exit."),QMessageBox::Cancel);
    }
}

void CommandeWindow::on_Commandelist_activated(const QModelIndex &index)
{
    QString val = ui->Commandelist->model()->data(index).toString();
    QSqlQuery query;


    query.prepare("SELECT IDC, DATEC, QUANC, DATECL, ETAT FROM COMMANDE WHERE IDC=:val OR QUANC=:val OR ETAT=:val");
    query.bindValue(":val", val);


    if (query.exec()) {
        while (query.next()) {

            ui->idam->setText(query.value("IDC").toString());      // ID de la commande
            ui->DCM->setDate(query.value("DATEC").toDate());       // Date de la commande
            ui->QCM->setText(query.value("QUANC").toString()); // Quantité commandée
            ui->DLM->setDate(query.value("DATECL").toDate());  // Date de livraison
            ui->EtatM->setCurrentText(query.value("ETAT").toString()); // État de la commande

        }
        int currentIndex = ui->tabWidget->currentIndex(); // Récupérer l'index de l'onglet actuel
            ui->tabWidget->setCurrentIndex(currentIndex + 1);
    } else {

        QMessageBox::critical(this, tr("Error"), query.lastError().text());
    }


}

void CommandeWindow::on_chercherC_clicked()
{
    QString idString = ui->idsup->text().trimmed();
    int idToSearch = idString.toInt();
        QSqlQueryModel * searchResultsModel = new QSqlQueryModel();
        if (idString.isEmpty()) {

            searchResultsModel = CL.afficher();
        }
        else {

            QSqlQuery query;
            query.prepare("SELECT * from COMMANDE WHERE IDC = :IDC");
            query.bindValue(":IDC", idToSearch);

            if (query.exec()) {
                searchResultsModel->setQuery(query);
            } else {

                QMessageBox::critical(this, "Error", "Failed to execute the search query.");
            }
        }

        ui->Commandelist->setModel(searchResultsModel);
}


void CommandeWindow::on_statistique_clicked()
{
    QSqlQuery query;
        query.prepare("SELECT ETAT, COUNT (*)AS  COMMANDE from COMMANDE GROUP BY ETAT");


        if (!query.exec()) {
            qDebug() << "Erreur lors de l'exécution de la requête.";

            return;
        }

        QPieSeries *series = new QPieSeries();

           while (query.next()) {
               QString type = query.value("ETAT").toString();
               int count = query.value("COMMANDE").toInt();
               series->append(type, count);
           }


           foreach (QPieSlice *slice, series->slices()) {
               QString label = QString("%1 (%2%)")
                                   .arg(slice->label())
                                   .arg(100 * slice->percentage(), 0, 'f', 1);
               slice->setLabel(label);
           }


         QChart *chart = new QChart();
           chart->addSeries(series);
           chart->setTitle("Statistics du client selon l'eat");


           chart->legend()->setAlignment(Qt::AlignRight);
           chart->setAnimationOptions(QChart::AllAnimations);


           QChartView *chartView = new QChartView(chart);

           chartView->setRenderHint(QPainter::Antialiasing);
           chartView->setMinimumSize(640, 480);
           chartView->show();

}



void CommandeWindow::on_exportpdf_clicked()
{
    QString filePath = QFileDialog::getSaveFileName(this, tr("Enregistrer PDF"), "", tr("PDF Files (*.pdf)"));
     if (filePath.isEmpty()) {
         return; // L'utilisateur a annulé l'enregistrement
     }

     QPdfWriter writer(filePath);
     writer.setPageSize(QPageSize(QPageSize::A4));
     QPainter painter(&writer);

     // Définir la police et la taille
     QFont font("Arial", 12);
     painter.setFont(font);

     // Titre
     painter.drawText(3000, 0, "Liste des Commandes");
     painter.drawLine(100, 110, 500, 110); // Ligne sous le titre

     // Récupérer les données de la base de données
     QSqlQuery query("SELECT * FROM COMMANDE");
     int y = 130; // Position de départ pour écrire les données
     int margin = 50; // Marges

     while (query.next()) {
         // Récupérer les valeurs
          int idc = query.value("IDC").toInt();
         QString datecommande = query.value("DATEC").toString();
         int Quantite = query.value("QUANC").toInt();
         QString datelivraison = query.value("DATECL").toString();
         QString etat= query.value("ETAT").toString();


         // Écrire chaque champ sur une nouvelle ligne avec un en-tête
         painter.drawText(margin, y, QString(" Id commande: %1").arg(idc));
         y += 290; // Augmenter l'espacement entre Article ID et Nom
         painter.drawText(margin, y, QString("date de commande: %1").arg(datecommande));
         y += 290;
         painter.drawText(margin, y, QString("Quantite: %1").arg(Quantite));
         y += 290;
         painter.drawText(margin, y, QString("Date de livraison: %1").arg(datelivraison));
         y += 290;
         painter.drawText(margin, y, QString("etat: %1").arg(etat));
         y += 290;

         painter.drawLine(margin, y, 500, y); // Ligne de séparation entre les articles
         y += 290; // Espacement après la ligne de séparation

         // Vérifier si on dépasse la hauteur de la page
         if (y > writer.height() - 100) {
             painter.end();
             writer.newPage(); // Créer une nouvelle page si nécessaire
             painter.begin(&writer);
             painter.setFont(font); // Redéfinir la police
             y = 100; // Réinitialiser la position y
         }
     }

     painter.end();

     // Afficher un message de succès
     QMessageBox::information(this, tr("Succès"), tr("Les données ont été exportées vers le PDF avec succès."));
}

void CommandeWindow::on_pushButton_2_clicked()
{
     Commande c;
    double pourcentageEfficacite =c.calculerPourcentageEfficacite("C:/Users/Asus/OneDrive - ESPRIT/Bureau/ProjectsWork/ProjectsWork/bilan.html");

      if (pourcentageEfficacite != -1) {
          // Afficher le pourcentage d'efficacité dans une boîte de message
          QMessageBox::information(this, "Bilan d'efficacité",
                                   "Le pourcentage d'efficacité des livraisons est de " +
                                   QString::number(pourcentageEfficacite) + "%.",
                                   QMessageBox::Ok);
      }
  }


void CommandeWindow::on_etatmodifier_clicked()
{
    int idC = ui->idmodetat->text().toInt();
    QSqlQuery query;
    query.prepare("UPDATE COMMANDE SET ETAT = 'livree', DATEMODIFICATION = SYSDATE WHERE IDC = :idC");
    query.bindValue(":idC", idC);  // Lier l'ID de la commande à la requête

    // Exécuter la requête et vérifier si elle réussit
    if (!query.exec()) {
        qDebug() << "Erreur lors de la mise à jour de l'état de la commande : " << query.lastError().text();
    } else {
        qDebug() << "État de la commande mis à jour avec succès.";
    }

}

void CommandeWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if(arg1==""){
        ui->Commandelist->setModel(CL.afficher());}
    else{
        ui->Commandelist->setModel(CL.trie(arg1));
    }
}

