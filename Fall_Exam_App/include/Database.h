#ifndef DATABASE_H
#define DATABASE_H


#include <QFileInfo>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include "Database_Api.h"
using namespace std;

//Implements the C++ Database API with Sqlite3:

class SQLite_db1{
        public:
            SQLite_db1(const QString&  uri){
                QSqlDatabase SQLite_db;
                SQLite_db = QSqlDatabase::addDatabase("QSQLITE");
                SQLite_db.setDatabaseName(uri);
                if(!SQLite_db.open()){
                    qDebug()<<"Error reaching Database!";
                }else{
                    qDebug()<<"Successfully Connected!";
                }
                QSqlQuery query;
            }
};

class IntegerField: public Fields{
        public:
            IntegerField();
            IntegerField(string name, DataTypes DType = Integer);
            ~IntegerField();
};

class TextField: public Fields{
        public:
            TextField();
            TextField(string name, DataTypes DType = Text);
            ~TextField();
};

#endif //Database_H
