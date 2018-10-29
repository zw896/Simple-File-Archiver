/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLineEdit *filePath;
    QPushButton *fileSelector;
    QLabel *label_2;
    QTableView *tableView;
    QPushButton *saveCurrent;
    QPushButton *retrieveVersion;
    QPushButton *setReference;
    QPushButton *showComment;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(724, 569);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(30, 27, 31, 20));
        filePath = new QLineEdit(centralwidget);
        filePath->setObjectName(QString::fromUtf8("filePath"));
        filePath->setEnabled(false);
        filePath->setGeometry(QRect(70, 30, 511, 27));
        fileSelector = new QPushButton(centralwidget);
        fileSelector->setObjectName(QString::fromUtf8("fileSelector"));
        fileSelector->setGeometry(QRect(610, 30, 98, 27));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(30, 110, 101, 17));
        tableView = new QTableView(centralwidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(30, 150, 491, 331));
        saveCurrent = new QPushButton(centralwidget);
        saveCurrent->setObjectName(QString::fromUtf8("saveCurrent"));
        saveCurrent->setGeometry(QRect(550, 150, 131, 27));
        retrieveVersion = new QPushButton(centralwidget);
        retrieveVersion->setObjectName(QString::fromUtf8("retrieveVersion"));
        retrieveVersion->setGeometry(QRect(550, 210, 131, 27));
        setReference = new QPushButton(centralwidget);
        setReference->setObjectName(QString::fromUtf8("setReference"));
        setReference->setGeometry(QRect(550, 280, 131, 27));
        showComment = new QPushButton(centralwidget);
        showComment->setObjectName(QString::fromUtf8("showComment"));
        showComment->setGeometry(QRect(550, 350, 131, 27));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        fileSelector->setText(QApplication::translate("MainWindow", "Select File ", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:12pt;\">Version Data</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        saveCurrent->setText(QApplication::translate("MainWindow", "Save Current", 0, QApplication::UnicodeUTF8));
        retrieveVersion->setText(QApplication::translate("MainWindow", "Retrieve Version", 0, QApplication::UnicodeUTF8));
        setReference->setText(QApplication::translate("MainWindow", "Set as reference", 0, QApplication::UnicodeUTF8));
        showComment->setText(QApplication::translate("MainWindow", "Show comment", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
