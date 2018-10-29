/*
 * File:   RetrieveForm.cpp
 * Author: duo
 *
 * Created on August 26, 2015, 9:42 PM
 */

#include "RetrieveForm.h"

RetrieveForm::RetrieveForm() {
    widget.setupUi(this);
    connect(widget.buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(dialogButton(QAbstractButton*)));
    connect(widget.directorySelector, SIGNAL(clicked()), this, SLOT(chooseFile()));
    
    //QString qfileName = QFileDialog::getSaveFileName(this, "save file", "", "");
}

RetrieveForm::~RetrieveForm() {
}
void RetrieveForm::dialogButton(QAbstractButton *button) {
    bool ok = true;
    string problems;
    QString qpathname = widget.directoryPath->text().trimmed();
    string pathname = qpathname.toStdString();
    QString qfilename = widget.fileNameInput->text().trimmed();
    string filename = qfilename.toStdString();
    std::string b = button->text().toStdString();
    cout<<"Button: "<<b<<endl;
    if(b=="&Cancel") return;
    if(b=="&OK") {
        if(qfilename.isEmpty()) {
            ok = false;
            problems = "Not input a filename";
 
        } else if (qpathname.isEmpty()){
            ok = false;
            problems = "Not input a pathname";
        } else {
            ok = true;
            this->retrieve = pathname + "/" + filename;
        }
        if (!ok) {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText(problems.c_str());
        msgBox.exec();
        }
    }
}     

   // std::string filename = qfileName.toStdString();
    //if the file doesn't exist

    
 
void RetrieveForm::chooseFile(){
QString qfileName = QFileDialog::getExistingDirectory(this, tr("save file"), tr("*"));
 string filename = qfileName.toStdString();
    //if the file doesn't exist
        if(!qfileName.isEmpty()){
        // A file was picked, set the filePath to match
        widget.directoryPath->setText(qfileName); 
        
    }
    
}
