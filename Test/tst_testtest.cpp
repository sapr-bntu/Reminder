#include <QtCore/QString>
#include <QtTest/QtTest>
#include <QTest>
#include <QtCore>
#include <QtGui/QApplication>
#include <QDialog>
#include <QtGui>
#include <QtSql>
#include "../../Reminder/dialog.h";


class TestTest : public QObject
{
    Q_OBJECT
    
public:
    TestTest();
    
private Q_SLOTS:
 void testCase1();
 void testCase2();
 void testCase3();
 void testCase4();
 void testCase5();
 void testCase6();
 void testCase7();
 void testCase8();
 void testCase9();
           //     void testCase10();
 void testCase11();
 void testCase12();
};

TestTest::TestTest()
{
}

void TestTest::testCase1()
{
    QVERIFY2(true, "Failure");
}

void TestTest::testCase2()
{
    Dialog dlg;
    bool flag = dlg.delete1();
  //  QVERIFY2(flag);
    QCOMPARE(true, flag);
}


void TestTest::testCase3()
{
    Dialog dlg;
    bool flag = dlg.on_pushButton_clicked();
  //  QVERIFY2(flag);
    QCOMPARE(true, flag);
}
void TestTest::testCase4()
{
    Dialog dlg;
    bool flag = dlg.reader();
    QCOMPARE(true, flag);
}
void TestTest::testCase5()
{
    Dialog dlg;
    bool flag = dlg.INSERT();
    QCOMPARE(true, flag);
}
void TestTest::testCase6()
{
    Dialog dlg;
    bool flag = dlg.on_calendarWidget_clicked(QDate::fromString("2012-06-02"));
    QCOMPARE(true, flag);
}
void TestTest::testCase7()
{
    Dialog dlg;
    bool flag = dlg.on_checkBox_stateChanged(1);
    QCOMPARE(true, flag);
}
void TestTest::testCase8()
{
    Dialog dlg;
    bool flag = dlg.DB_create();
    QCOMPARE(true, flag);
}
void TestTest::testCase9()
{
    Dialog dlg;
    bool flag = dlg.table_create();
    QCOMPARE(true, flag);
}
//void TestTest::testCase10()
//{
//    Dialog dlg;
//    bool flag = dlg.on_cliked(event);
//    QCOMPARE(true, flag);
//}
void TestTest::testCase11()
{
    Dialog dlg;
    bool flag = dlg.every_day();
    QCOMPARE(true, flag);
}
void TestTest::testCase12()
{
    Dialog dlg;
    bool flag = dlg.every_week();
    QCOMPARE(true, flag);
}

QTEST_MAIN(TestTest)

#include "tst_testtest.moc"
