/********************************************************************************
** Form generated from reading UI file 'RetrieveForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RETRIEVEFORM_H
#define UI_RETRIEVEFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RetrieveForm
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLineEdit *directoryPath;
    QPushButton *directorySelector;
    QLabel *label_2;
    QLineEdit *fileNameInput;

    void setupUi(QDialog *RetrieveForm)
    {
        if (RetrieveForm->objectName().isEmpty())
            RetrieveForm->setObjectName(QString::fromUtf8("RetrieveForm"));
        RetrieveForm->resize(615, 321);
        buttonBox = new QDialogButtonBox(RetrieveForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(220, 260, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(RetrieveForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 66, 17));
        directoryPath = new QLineEdit(RetrieveForm);
        directoryPath->setObjectName(QString::fromUtf8("directoryPath"));
        directoryPath->setEnabled(false);
        directoryPath->setGeometry(QRect(80, 20, 401, 27));
        directorySelector = new QPushButton(RetrieveForm);
        directorySelector->setObjectName(QString::fromUtf8("directorySelector"));
        directorySelector->setGeometry(QRect(490, 20, 98, 27));
        label_2 = new QLabel(RetrieveForm);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 120, 66, 17));
        fileNameInput = new QLineEdit(RetrieveForm);
        fileNameInput->setObjectName(QString::fromUtf8("fileNameInput"));
        fileNameInput->setGeometry(QRect(80, 120, 251, 27));

        retranslateUi(RetrieveForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), RetrieveForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), RetrieveForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(RetrieveForm);
    } // setupUi

    void retranslateUi(QDialog *RetrieveForm)
    {
        RetrieveForm->setWindowTitle(QApplication::translate("RetrieveForm", "RetrieveForm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RetrieveForm", "Directory", 0, QApplication::UnicodeUTF8));
        directorySelector->setText(QApplication::translate("RetrieveForm", "Select", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("RetrieveForm", "File name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RetrieveForm: public Ui_RetrieveForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RETRIEVEFORM_H
