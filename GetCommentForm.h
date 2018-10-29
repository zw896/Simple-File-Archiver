/* 
 * File:   GetCommentForm.h
 * Author: duo
 *
 * Created on August 26, 2015, 9:48 PM
 */

#ifndef _GETCOMMENTFORM_H
#define	_GETCOMMENTFORM_H
#include <vector>
#include "FileRec.h"
#include "ui_GetCommentForm.h"

class FileRec;
typedef FileRec* RecordPtr;

class GetCommentForm : public QDialog {
    Q_OBJECT
public:
    GetCommentForm(/*vector<RecordPtr> *Comment*/);
    virtual ~GetCommentForm();
    std::string Getcomment() {return this->comment; }
    void Setcomment(std::string in){this->comment=in; }
public slots:
    void dialogButtonClicked(QAbstractButton *button);
    
private:
    Ui::GetCommentForm widget;
    std::string comment;
};

#endif	/* _GETCOMMENTFORM_H */
