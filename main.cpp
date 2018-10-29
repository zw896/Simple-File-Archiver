/*
 * File:   main.cpp
 * Author: duo
 *
 * Created on August 26, 2015, 9:10 PM
 */

#include <QApplication>
#include <vector>
#include "GetCommentForm.h"
#include "FileArchiver.h"
#include "MainWindow.h"
#include "FileRec.h"


typedef FileRec* RecordPtr;
vector<RecordPtr> g_theRecords;
typedef VersionInfoRecord* RecordInfo;
vector<RecordInfo> g_RecordInfo;
int main(int argc, char *argv[]) {
    // initialize resources, if needed
    // Q_INIT_RESOURCE(resfile);
    mongo::client::initialize();
    QApplication app(argc, argv);
    MainWindow win(&g_RecordInfo);
    win.show();
    

    // create and show your widgets here

    return app.exec();
}
