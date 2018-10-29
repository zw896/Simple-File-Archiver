/*
 * File:   GetCommentForm.cpp
 * Author: duo
 *
 * Created on August 26, 2015, 9:48 PM
 */

#include "MainWindow.h"
#include "MyTableModel.h"
#include "FileRec.h"
#include "GetCommentForm.h"
GetCommentForm::GetCommentForm(/*vector<RecordPtr> *Comment*/) {
    widget.setupUi(this);
    connect(widget.buttonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(dialogButtonClicked(QAbstractButton*)));
}

GetCommentForm::~GetCommentForm() {
}
void GetCommentForm::dialogButtonClicked(QAbstractButton *button) {
    std::string b = button->text().toStdString();
    if(b == "&OK") {
        std::string comment = widget.commentInput->toPlainText().toStdString();
        Setcomment(comment);
        close();
    } else {
        close();
    }
}
