/*
 * File:   MainWindow.cpp
 * Author: duo
 *
 * Created on August 26, 2015, 9:12 PM
 */

#include "MainWindow.h"
using namespace std;
typedef FileRec* RecordPtr;
vector<RecordPtr> g_comment;

MainWindow::MainWindow(vector<RecordInfo> *theData) {
    data = theData;
    widget.setupUi(this);
    
    const char* dbname = "archiver.filerec";
    archiver = new FileArchiver(dbname);
    
    tablemodel = new MyTableModel(0);
    tablemodel->addTheData(theData);
    
    widget.tableView->setModel(tablemodel);
    widget.tableView->resizeRowsToContents();
    widget.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    
    disablebutton();
    
    //We have to put in the event handling links
    connect(widget.fileSelector, SIGNAL(clicked()), this, SLOT(chooseFile()));
    connect(widget.saveCurrent, SIGNAL(clicked()), this, SLOT(saveCurrent()));
    connect(widget.retrieveVersion, SIGNAL(clicked()), this, SLOT(retrieveVersion()));
    connect(widget.setReference, SIGNAL(clicked()), this, SLOT(setReference()));
    connect(widget.showComment, SIGNAL(clicked()), this, SLOT(showComment()));
    connect(widget.tableView, SIGNAL(clicked(const QModelIndex& )), this, SLOT(itemSelection(const QModelIndex& )));
           
}

MainWindow::~MainWindow() {
}

void MainWindow::chooseFile(){
    // Display a standard file dialog and let user select a file
    QString qfileName = QFileDialog::getOpenFileName(this, "Select file", ".", "Files (*)");
    string filename = qfileName.toStdString();
    //if the file doesn't exist
        if(!qfileName.isEmpty()){
        // A file was picked, set the filePath to match
        widget.filePath->setText(qfileName); 
        
    }
    
    if (archiver->exists(filename)) {
        std::cout<<"----------Had Records!----------------"<<endl;
        std::cout<<"--------------------------------------"<<endl;
        this->retrieveVersionDataForFile(filename);
        enableallbutton();
    } else {
        this->createFirstVersion(filename);
        enablebutton();
    }
    
}
void MainWindow::saveCurrent(){
    bool ok = true;
    string problems;
    QString qfilename = widget.filePath->text().trimmed();
    string filename = qfilename.toStdString();
    if (qfilename.isEmpty()) {
        ok = false;
        problems.append(" You didn't choose a file.");
    }
    if (!archiver->differs(filename)) {
        ok = false;
        problems.append(" Already have a record.");
    } else {
        ok = true;
        GetCommentForm *comment = new GetCommentForm();
        comment->exec();
        std::string comments = comment->Getcomment();
        if(comments.empty()) return;
        if(comment->close()){
        cout<<"Update! 001"<<endl;
        archiver->update(filename,comments);
        }
    }
    if (!ok) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText(problems.c_str());
        msgBox.exec();
        return;
    }  
    this->retrieveVersionDataForFile(filename);
}
void MainWindow::showComment(){
    QString qfilename = widget.filePath->text().trimmed();
    string filename = qfilename.toStdString();
    string temp = archiver->getComment(filename,current);
    QString qstr = QString::fromStdString(temp);
    QMessageBox msgBox;
    msgBox.setWindowTitle("comment");
    msgBox.setText(qstr);
    msgBox.exec();
}
void MainWindow::retrieveVersion(){
    //string MESSAGE = "do you want retrieve this version?";
    RetrieveForm *retrieve = new RetrieveForm();
    retrieve->exec();
    std::string retrievedname = retrieve->GetRetrieve();
    QString qfilename = widget.filePath->text().trimmed();
    std::string filename = qfilename.toStdString();
    cout<<"Retrive -------------->"<<retrievedname<<endl;
    cout<<"Filename -------------->"<<filename<<endl;
    if(retrievedname.empty()) return;
    if(retrieve->close()){
        cout<<"FILENAME:"<<retrievedname<<endl;
    }
    archiver->retriveversion(current,filename,retrievedname);

}
void MainWindow::setReference(){
        QString qfilename = widget.filePath->text().trimmed();
        string filename = qfilename.toStdString();
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this,"Set reference version","Set reference version",QMessageBox::Yes | QMessageBox::Cancel);
        if (reply == QMessageBox::Yes) {
            GetCommentForm *comment = new GetCommentForm();
            comment->exec();
            std::string comments = comment->Getcomment();
//            if(comments.empty()) return;
            if(comment->close()){
                archiver->retriveversion(current,filename,filename);
                archiver->setReference(filename,current,comments);
                this->retrieveVersionDataForFile(filename);
            }
        } else {
            return;
        }
}

void MainWindow::retrieveVersionDataForFile(string filename){   
    cout<<"Re :"<<filename<<endl;
    
    tablemodel->refreshall();
    tablemodel->addTheData(archiver->getVersionInfo(filename));
    cout<<"Test 003 :"<<tablemodel->rowCount()<<endl;
    widget.tableView->setModel(tablemodel);
}
void MainWindow::createFirstVersion(string filename){
    cout<<"MainWindow::createFirstVersion :"<<filename<<endl;
    std::cout<<"*****************************************"<<endl;
    GetCommentForm *comment = new GetCommentForm();
    comment->exec();
    std::string comments = comment->Getcomment();
//    if(comments.empty()) return;
    if(comment->close()){
        QMessageBox msgBox;
        msgBox.setWindowTitle("First Version");
        msgBox.setText("Creating first version in archive");
        msgBox.exec();
        archiver->insertNew(filename,comments);
    }
    this->retrieveVersionDataForFile(filename);
}
void MainWindow::disablebutton(){
    widget.saveCurrent->setEnabled(false);
    widget.retrieveVersion->setEnabled(false);
    widget.setReference->setEnabled(false);
    widget.showComment->setEnabled(false); 
}
void MainWindow::enableallbutton(){
    
    widget.saveCurrent->setEnabled(true);
    widget.retrieveVersion->setEnabled(true);
    widget.setReference->setEnabled(true);
    widget.showComment->setEnabled(true); 
}
void MainWindow::enablebutton(){
    widget.saveCurrent->setEnabled(false);
    widget.retrieveVersion->setEnabled(true);
    widget.setReference->setEnabled(true);
    widget.showComment->setEnabled(true); 
}

void MainWindow::itemSelection(const QModelIndex& index) {
    int row = index.row();
    QString name = index.sibling(row, 0).data().toString();
    this->current = name.toInt();
}
