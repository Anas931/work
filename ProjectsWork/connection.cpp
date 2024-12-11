#include "connection.h"
#include <QSqlError>
#include <QMessageBox>
#include <QtDebug>

connection::connection()
{
    // Initialize the database connection in the constructor
    db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("PROJECT_WORK");  // Replace with your actual database name
    db.setUserName("ANASS");         // Replace with your actual username
    db.setPassword("kharamantt");      // Replace with your actual password
}

bool connection::ouvrirconnexion()
{
    if (!db.isOpen()) {
        if (db.open()) {
            qDebug() << "Database connection opened successfully!";
            return true;
        } else {
            qDebug() << "Error: Unable to open database - " << db.lastError().text();
            QMessageBox::critical(nullptr, QObject::tr("Database Error"),
                                  QObject::tr("Unable to connect to the database: %1")
                                  .arg(db.lastError().text()));
            return false;
        }
    }
    return true; // If already open
}

void connection::fermerconnexion()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database connection closed!";
    }
}
