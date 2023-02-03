#include <QMessageBox>
#include "../include/mainwindow.h"
#include "ui_mainwindow.h"
#include "../include/Database.h"
#include "../include/employee.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_saveBtn_clicked()
{
 SQLite_db1 myDB("C:/Users/LENOVO/Desktop/SOFTWARE ENGINEERING CONTENTS/Software Engineering - Top-Up/Fall Semester/Fall - Examination/Fall_Exam_App/assets/Fall_exam.db");
 const QString Name = ui->nameInp->text();
 const QString Age = ui->ageInp->text();
 const QString Phone = ui->phoneInp->text();

 Employee emp(Name, Age, Phone);
 bool rs = emp.addEmp();
 if(rs == true){
     QMessageBox pop;
     pop.information(this, "Success", "Successfully Added Employee!");
 }
}

