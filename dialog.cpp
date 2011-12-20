#include "dialog.h"
#include "ui_dialog.h"
#include <QtGui>
#include <QtSql>
#include <QRadioButton>

Dialog::Dialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::Dialog)
{


    ui->setupUi(this);
    ui->groupBox->hide();
    QFile file("Calendar.s3db") ;
    QSqlDatabase db;
    if (file.exists())
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Calendar.s3db");
        db.open();
        QSqlQuery query;
        query.exec("CREATE TABLE Dannie ("
                   "ID INTEGER  NOT NULL PRIMARY KEY AUTOINCREMENT,"
                   "Data DATE  NULL,"
                   "Vremyanachala TIME  NULL,"
                   "Vremyakonca TIME  NULL,"
                   "Sobitie TEXT  NULL,"
                   "comment TEXT  NULL)");
    }
    else
    {
        db = QSqlDatabase::addDatabase("QSQLITE");
        db.setDatabaseName("Calendar.s3db");
        db.open();
    }


    model = new QSqlTableModel(this);
    model->setTable("Dannie");
   model->select();
    model->setFilter("");
     ui->tableView1->selectRow(0);
    ui->tableView1->setModel(model);
    //     ui->tableView1->hideColumn(0);
    //ui->tableView1->hideColumn(1);

    QDateTime  finishTime = QDateTime::currentDateTime();

    ui->timeEdit->setTime(QTime(finishTime.time().hour(), 0 ));
    ui->timeEdit_2->setTime(QTime(finishTime.time().hour(), 0 ));
    QDateTime dateTime=QDateTime::currentDateTime();
    ui-> dateEdit->setDate(dateTime.date());
    ui->dateEdit->setDate(dateTime.date());
    connect(ui->tableView1,SIGNAL(clicked(QModelIndex)),this,SLOT(on_cliked(QModelIndex)));

   connect(ui->pushButton_2,SIGNAL(clicked()),this,SLOT(delete1()));
  connect(ui->radioButton,SIGNAL(clicked()),this,SLOT(plu()));

   // connect(ui->pushButton,SIGNAL(clicked()),this, SLOT(on_pushButton_clicked()));

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_cliked(QModelIndex index)
{
    qDebug()<<"onclick";
     QString str;

    id= model->record(index.row()).value("ID").toInt();
    currentid = id;
    str = model->record(index.row()).value(1).toString();

    // ui->comment->setText("<span><a href=\"http://m.tut.by/news/economics/259932.html\">Лукашенко не хочет вновь наступать на грабли \"шоковой терапии\" 90-х годов&nbsp;<img src=\"http://img.tyt.by/pda/icon/pda_vpav_vid.gif\" border=\"0\" alt=\"Видео\" width=\"14\" height=\"10\" /></a></span><br>retuieotuio");

}


void Dialog::on_pushButton_clicked()
{

    QString text;

    text = ui->textEdit->toPlainText();

    QString comment;

    comment = ui->textEdit_2->toPlainText();
    QTime time;
    time = ui->timeEdit->time();
    QTime time1;
    time1 = ui->timeEdit_2->time();

    QString t=time.toString();
    QString t2=time1.toString();
    QDate date;
    date= ui->calendarWidget->selectedDate();
    QString d=date.toString("yyyy-MM-dd");
    qDebug()<<d;
    QSqlQuery query;

   // qDebug()<<"date"<<date.toString();


   query.exec("INSERT INTO Dannie ( Data, Vremyanachala, Vremyakonca, Sobitie, comment)  VALUES('"+d+"','"+t+"','"+t2+"','"+text+"','"+comment+"')");

    model->select();
    if(ui->radioButton->isChecked())
    {
        QDate dat1 = ui->calendarWidget->selectedDate();
        QDate dat2 = ui->dateEdit->date();

        while (dat2 > dat1)
        {
            QString text;

            text = ui->textEdit->toPlainText();
            QString comment;
            comment = ui->textEdit_2->toPlainText();
            QTime time;
            time = ui->timeEdit->time();
            QTime time1;
            time1 = ui->timeEdit_2->time();
            QString t=time.toString();
            QString t2=time1.toString();
         dat1 = dat1.addDays(1);
         QString dat3 = dat1.toString("yyyy-MM-dd");
            qDebug()<<dat3;
          QSqlQuery query;
         query.exec("INSERT INTO Dannie ( Data, Vremyanachala, Vremyakonca, Sobitie, comment)  VALUES('"+dat3+"','"+t+"','"+t2+"','"+text+"','"+comment+"')");
     model->select();
     }
    }
    if(ui->radioButton_2->isChecked())
    {
        QDate dat1 = ui->calendarWidget->selectedDate();
        QDate dat2 = ui->dateEdit->date();
        while (dat2 > dat1)
        {
            QString text;

            text = ui->textEdit->toPlainText();
            QString comment;
            comment = ui->textEdit_2->toPlainText();
            QTime time;
            time = ui->timeEdit->time();
            QTime time1;
            time1 = ui->timeEdit_2->time();
            QString t=time.toString();
            QString t2=time1.toString();
         dat1 = dat1.addDays(7);
         QString dat3 = dat1.toString("yyyy-MM-dd");
            qDebug()<<dat3;
          QSqlQuery query;
         query.exec("INSERT INTO Dannie ( Data, Vremyanachala, Vremyakonca, Sobitie, comment)  VALUES('"+dat3+"','"+t+"','"+t2+"','"+text+"','"+comment+"')");
     model->select();
     }
    }
    if(ui->radioButton_3->isChecked())
    {
        QDate dat1 = ui->calendarWidget->selectedDate();
        QDate dat2 = ui->dateEdit->date();
        while (dat1 < dat2)
        {
            QString text;

            text = ui->textEdit->toPlainText();
            QString comment;
            comment = ui->textEdit_2->toPlainText();
            QTime time;
            time = ui->timeEdit->time();
            QTime time1;
            time1 = ui->timeEdit_2->time();
            QString t=time.toString();
            QString t2=time1.toString();
         dat1 = dat1.addMonths(1);
         QString dat3 = dat1.toString("yyyy-MM-dd");
            qDebug()<<dat3;
          QSqlQuery query;
         query.exec("INSERT INTO Dannie ( Data, Vremyanachala, Vremyakonca, Sobitie, comment)  VALUES('"+dat3+"','"+t+"','"+t2+"','"+text+"','"+comment+"')");
     model->select();
     }
    }

}

void Dialog::delete1()
{
QSqlQuery quer;
qDebug()<<currentid;
quer.exec(QString("DELETE FROM Dannie WHERE ID = '%1'").arg(currentid));
model->select();

}


void Dialog::on_calendarWidget_clicked(QDate date)
{
    model ->setFilter(QString("Data = '%1'").arg(date.toString("yyyy-MM-dd")));
}



void Dialog::on_checkBox_stateChanged(int arg1)
{
    if(arg1 == Qt::Unchecked)
    {
        ui->groupBox->hide();
    }
    else
    {
        ui->groupBox->show();

    }
}







