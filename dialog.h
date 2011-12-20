#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtSql>

namespace Ui {
    class Dialog;

}
class QSqlTableModel;
class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();
    QModelIndex index;
       int curentIndex;

private:
    Ui::Dialog *ui;
    QSqlTableModel *model;
    int currentid;
    int id;

private slots:



    void on_calendarWidget_clicked(QDate date);
    void on_cliked (QModelIndex index );
    void on_pushButton_clicked();

      void delete1();
      void on_checkBox_stateChanged(int arg1);




};

#endif // DIALOG_H
