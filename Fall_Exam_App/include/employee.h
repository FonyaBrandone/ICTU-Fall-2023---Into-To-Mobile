#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <QFileInfo>
#include <QSql>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include "Database.h"


class Employee{
public:
    QString age, phone;
    QString name;
    //Actualise the database needed:
    Employee(const QString& emp_name, const QString& emp_age, const QString& emp_phone){
        age = emp_age;
        phone = emp_phone;
        name = emp_name;
    }
    bool existStaff(){
        //Checks if Staff is already enrolled
        QSqlQuery query;
        query.prepare("SELECT name FROM Employee WHERE phone=(:Phone)");
        query.bindValue(":Phone", phone);
        if(query.exec()){
            if(query.next()){
                return true;
            }else{
                return false;
            }
        }else{
           qDebug()<<"Error occured: "<<query.lastError();
            return false;
        }

    }

    bool addEmp(){
        //Insert employee method:
        bool cntrl = true; //if staff does not exist
        if(cntrl == true){
            QSqlQuery query;
            query.prepare("INSERT INTO Employee(name,phone,age) VALUES(:Name,:Phone,:Age)");
            query.bindValue(":Name",name);
            query.bindValue(":Phone",phone.toInt());
            query.bindValue(":Age",age.toInt());
            bool result = query.exec();
            if(result){
                qDebug()<<"Successfully Inserted Values!";
                return true;
            }else{
                qDebug()<<"Error: "<<query.lastError();
                return false;
            }
        }else{
            qDebug()<<"Sorry This person is already a registered Employee!!";
            return false;
        }

    }

};
#endif // EMPLOYEE_H
