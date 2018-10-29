/* 
 * File:   RetrieveForm.h
 * Author: duo
 *
 * Created on August 26, 2015, 9:42 PM
 */

#ifndef _RETRIEVEFORM_H
#define	_RETRIEVEFORM_H

#include "ui_RetrieveForm.h"
#include "MainWindow.h"
class FileRec;
typedef FileRec* RecordPtr;

class RetrieveForm : public QDialog {
    Q_OBJECT
public:
    RetrieveForm();
    virtual ~RetrieveForm();
    std::string GetRetrieve() {return this->retrieve; }
    void Setretrieve(std::string in){this->retrieve=in; }

public slots:
    void dialogButton(QAbstractButton *button);
    void chooseFile();
private:
    Ui::RetrieveForm widget;
    std::string retrieve;
};

#endif	/* _RETRIEVEFORM_H */

