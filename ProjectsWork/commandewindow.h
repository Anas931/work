#ifndef COMMANDEWINDOW_H
#define COMMANDEWINDOW_H
#include <commande.h>
#include <QMainWindow>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class CommandeWindow; }
QT_END_NAMESPACE

class CommandeWindow : public QMainWindow
{
    Q_OBJECT

public:
    CommandeWindow(QWidget *parent = nullptr);
    ~CommandeWindow();

private slots:
    void on_AjoutCo_clicked();

    void on_supco_clicked();

    void on_pushButton_clicked();

    void on_Commandelist_activated(const QModelIndex &index);

    void on_chercherC_clicked();

    void on_statistique_clicked();

  //  void on_comboBox_activated(const QString &arg1);

    void on_exportpdf_clicked();

    void on_pushButton_2_clicked();

    void on_etatmodifier_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

private:
    Ui::CommandeWindow *ui;
    Commande CL;
    QSqlTableModel *model;
};
#endif // COMMANDEWINDOW_H
