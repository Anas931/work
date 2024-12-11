/********************************************************************************
** Form generated from reading UI file 'commandewindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDEWINDOW_H
#define UI_COMMANDEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandeWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QComboBox *Etat;
    QPushButton *AjoutCo;
    QDateEdit *DL;
    QLabel *label_3;
    QDateEdit *DC;
    QLabel *label;
    QLabel *label_4;
    QLabel *label_2;
    QLineEdit *QC;
    QWidget *tab_2;
    QTableView *Commandelist;
    QPushButton *supco;
    QLineEdit *idsup;
    QPushButton *chercherC;
    QPushButton *statistique;
    QComboBox *comboBox;
    QPushButton *exportpdf;
    QWidget *tab_3;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QDateEdit *DCM;
    QLineEdit *QCM;
    QDateEdit *DLM;
    QComboBox *EtatM;
    QPushButton *pushButton;
    QLineEdit *idam;
    QLabel *label_9;
    QWidget *tab_4;
    QPushButton *pushButton_2;
    QLabel *label_10;
    QLineEdit *idmodetat;
    QPushButton *etatmodifier;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CommandeWindow)
    {
        if (CommandeWindow->objectName().isEmpty())
            CommandeWindow->setObjectName("CommandeWindow");
        CommandeWindow->resize(1249, 689);
        centralwidget = new QWidget(CommandeWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(50, 20, 1121, 561));
        tab = new QWidget();
        tab->setObjectName("tab");
        Etat = new QComboBox(tab);
        Etat->addItem(QString());
        Etat->setObjectName("Etat");
        Etat->setGeometry(QRect(230, 260, 101, 22));
        AjoutCo = new QPushButton(tab);
        AjoutCo->setObjectName("AjoutCo");
        AjoutCo->setGeometry(QRect(790, 360, 93, 28));
        DL = new QDateEdit(tab);
        DL->setObjectName("DL");
        DL->setGeometry(QRect(230, 210, 110, 22));
        label_3 = new QLabel(tab);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 210, 121, 20));
        DC = new QDateEdit(tab);
        DC->setObjectName("DC");
        DC->setGeometry(QRect(230, 110, 110, 22));
        label = new QLabel(tab);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 110, 141, 20));
        label_4 = new QLabel(tab);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 260, 71, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 160, 161, 20));
        QC = new QLineEdit(tab);
        QC->setObjectName("QC");
        QC->setGeometry(QRect(230, 160, 113, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        Commandelist = new QTableView(tab_2);
        Commandelist->setObjectName("Commandelist");
        Commandelist->setGeometry(QRect(50, 150, 881, 351));
        supco = new QPushButton(tab_2);
        supco->setObjectName("supco");
        supco->setGeometry(QRect(310, 110, 93, 28));
        idsup = new QLineEdit(tab_2);
        idsup->setObjectName("idsup");
        idsup->setGeometry(QRect(60, 110, 231, 21));
        chercherC = new QPushButton(tab_2);
        chercherC->setObjectName("chercherC");
        chercherC->setGeometry(QRect(430, 110, 93, 28));
        statistique = new QPushButton(tab_2);
        statistique->setObjectName("statistique");
        statistique->setGeometry(QRect(550, 110, 93, 28));
        comboBox = new QComboBox(tab_2);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(710, 110, 151, 22));
        exportpdf = new QPushButton(tab_2);
        exportpdf->setObjectName("exportpdf");
        exportpdf->setGeometry(QRect(740, 50, 93, 28));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName("tab_3");
        label_5 = new QLabel(tab_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(130, 80, 141, 20));
        label_6 = new QLabel(tab_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(140, 140, 171, 16));
        label_7 = new QLabel(tab_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(140, 200, 121, 16));
        label_8 = new QLabel(tab_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(140, 280, 71, 16));
        DCM = new QDateEdit(tab_3);
        DCM->setObjectName("DCM");
        DCM->setGeometry(QRect(340, 80, 110, 22));
        QCM = new QLineEdit(tab_3);
        QCM->setObjectName("QCM");
        QCM->setGeometry(QRect(330, 140, 113, 20));
        DLM = new QDateEdit(tab_3);
        DLM->setObjectName("DLM");
        DLM->setGeometry(QRect(330, 200, 110, 22));
        EtatM = new QComboBox(tab_3);
        EtatM->addItem(QString());
        EtatM->addItem(QString());
        EtatM->setObjectName("EtatM");
        EtatM->setGeometry(QRect(330, 270, 101, 22));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(660, 340, 93, 28));
        idam = new QLineEdit(tab_3);
        idam->setObjectName("idam");
        idam->setGeometry(QRect(740, 40, 113, 20));
        label_9 = new QLabel(tab_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(566, 44, 151, 20));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName("tab_4");
        pushButton_2 = new QPushButton(tab_4);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(610, 320, 151, 28));
        label_10 = new QLabel(tab_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(60, 120, 241, 20));
        idmodetat = new QLineEdit(tab_4);
        idmodetat->setObjectName("idmodetat");
        idmodetat->setGeometry(QRect(330, 120, 113, 20));
        etatmodifier = new QPushButton(tab_4);
        etatmodifier->setObjectName("etatmodifier");
        etatmodifier->setGeometry(QRect(160, 210, 121, 28));
        tabWidget->addTab(tab_4, QString());
        CommandeWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CommandeWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1249, 26));
        CommandeWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(CommandeWindow);
        statusbar->setObjectName("statusbar");
        CommandeWindow->setStatusBar(statusbar);

        retranslateUi(CommandeWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(CommandeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *CommandeWindow)
    {
        CommandeWindow->setWindowTitle(QCoreApplication::translate("CommandeWindow", "CommandeWindow", nullptr));
        Etat->setItemText(0, QCoreApplication::translate("CommandeWindow", "Non livree", nullptr));

        AjoutCo->setText(QCoreApplication::translate("CommandeWindow", "Ajouter", nullptr));
        label_3->setText(QCoreApplication::translate("CommandeWindow", "Date de livraison ", nullptr));
        label->setText(QCoreApplication::translate("CommandeWindow", "Date de commande", nullptr));
        label_4->setText(QCoreApplication::translate("CommandeWindow", "Etat", nullptr));
        label_2->setText(QCoreApplication::translate("CommandeWindow", "Quantit\303\251 de commande", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("CommandeWindow", "Ajout Commande", nullptr));
        supco->setText(QCoreApplication::translate("CommandeWindow", "supprimer", nullptr));
        idsup->setText(QString());
        chercherC->setText(QCoreApplication::translate("CommandeWindow", "chercher", nullptr));
        statistique->setText(QCoreApplication::translate("CommandeWindow", "Statistique", nullptr));
        comboBox->setItemText(0, QString());
        comboBox->setItemText(1, QCoreApplication::translate("CommandeWindow", "Date commande ascendant", nullptr));
        comboBox->setItemText(2, QCoreApplication::translate("CommandeWindow", "Date commande descandant", nullptr));
        comboBox->setItemText(3, QCoreApplication::translate("CommandeWindow", "Date de livraison ascendant", nullptr));
        comboBox->setItemText(4, QCoreApplication::translate("CommandeWindow", "Date de livraison descandant", nullptr));

        exportpdf->setText(QCoreApplication::translate("CommandeWindow", "Exporter PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("CommandeWindow", "Liste de Commandes", nullptr));
        label_5->setText(QCoreApplication::translate("CommandeWindow", "Date de commande", nullptr));
        label_6->setText(QCoreApplication::translate("CommandeWindow", "Quantit\303\251 de commande", nullptr));
        label_7->setText(QCoreApplication::translate("CommandeWindow", "Date de livraison ", nullptr));
        label_8->setText(QCoreApplication::translate("CommandeWindow", "Etat", nullptr));
        EtatM->setItemText(0, QCoreApplication::translate("CommandeWindow", "en cours", nullptr));
        EtatM->setItemText(1, QCoreApplication::translate("CommandeWindow", "livree", nullptr));

        pushButton->setText(QCoreApplication::translate("CommandeWindow", "Modifier", nullptr));
        label_9->setText(QCoreApplication::translate("CommandeWindow", "Reference a modifier", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QCoreApplication::translate("CommandeWindow", "Modifier Commande", nullptr));
        pushButton_2->setText(QCoreApplication::translate("CommandeWindow", "Generation du bilan", nullptr));
        label_10->setText(QCoreApplication::translate("CommandeWindow", "id commande a modifier son etat", nullptr));
        etatmodifier->setText(QCoreApplication::translate("CommandeWindow", "modifier letat", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QCoreApplication::translate("CommandeWindow", "metier1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CommandeWindow: public Ui_CommandeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDEWINDOW_H
