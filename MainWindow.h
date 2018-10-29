/* 
 * File:   MainWindow.h
 * Author: duo
 *
 * Created on August 26, 2015, 9:12 PM
 */

#ifndef _MAINWINDOW_H
#define	_MAINWINDOW_H

#include "ui_MainWindow.h"
#include "FileArchiver.h"
#include "FileRec.h"
#include "MyTableModel.h"
#include "GetCommentForm.h"
#include "qmessagebox.h"
#include "RetrieveForm.h"
using namespace std;
typedef FileRec* RecordPtr;

//extern FileArchiver* archiver;
class MainWindow : public QMainWindow {
    Q_OBJECT
    
public:
    MainWindow(vector<RecordInfo> *theData);
    virtual ~MainWindow();
public slots:
    void chooseFile();
    void saveCurrent();
    void showComment();
    void retrieveVersion();
    void setReference();
    void retrieveVersionDataForFile(string filename);
    void createFirstVersion(string filename);
    void disablebutton();
    void enableallbutton();
    void enablebutton();
    void itemSelection(const QModelIndex& index);
private:
    Ui::MainWindow widget;
    FileArchiver* archiver;
    vector<RecordInfo> *data;
    MyTableModel *tablemodel;
    int current; 
};

#endif	/* _MAINWINDOW_H */


