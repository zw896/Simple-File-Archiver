/********************************************************************************
** Form generated from reading UI file 'GetCommentForm.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCOMMENTFORM_H
#define UI_GETCOMMENTFORM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_GetCommentForm
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QTextEdit *commentInput;

    void setupUi(QDialog *GetCommentForm)
    {
        if (GetCommentForm->objectName().isEmpty())
            GetCommentForm->setObjectName(QString::fromUtf8("GetCommentForm"));
        GetCommentForm->resize(400, 300);
        buttonBox = new QDialogButtonBox(GetCommentForm);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(GetCommentForm);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 20, 281, 17));
        commentInput = new QTextEdit(GetCommentForm);
        commentInput->setObjectName(QString::fromUtf8("commentInput"));
        commentInput->setGeometry(QRect(20, 60, 351, 151));

        retranslateUi(GetCommentForm);
        QObject::connect(buttonBox, SIGNAL(accepted()), GetCommentForm, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GetCommentForm, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetCommentForm);
    } // setupUi

    void retranslateUi(QDialog *GetCommentForm)
    {
        GetCommentForm->setWindowTitle(QApplication::translate("GetCommentForm", "GetCommentForm", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GetCommentForm", "Comment to go with version of file:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GetCommentForm: public Ui_GetCommentForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETCOMMENTFORM_H
