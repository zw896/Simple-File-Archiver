/* 
 * File:   MyTableModel.h
 * Author: duo
 *
 * Created on August 26, 2015, 10:17 PM
 */

#ifndef MYTABLEMODEL_H
#define	MYTABLEMODEL_H

#include <QAbstractTableModel>
#include <QtGui>
#include <vector>
#include "FileRec.h"
#include "VersionInfoRecord.h"
using namespace std;
typedef FileRec* RecordPtr;
typedef VersionInfoRecord* RecordInfo;

class MyTableModel : public QAbstractTableModel{
    Q_OBJECT
public:
    MyTableModel(QObject *parent);
    
    void addTheData(vector<RecordInfo> *data){this->recordsCollection = data;}
    
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
    bool insertRows(int position, int rows, const QModelIndex &index = QModelIndex());
    bool removeRows(int position, int rows, const QModelIndex &index = QModelIndex());
    void addRecord(/*RecordPtr newone*/);
    void refreshall();
private:
    //Don't assume ownership, don't delete on destruct
    vector<RecordInfo> *recordsCollection;
    //Disallow value operations
    MyTableModel& operator = (const MyTableModel&);
    MyTableModel(const MyTableModel& orig);
};


#endif	/* MYTABLEMODEL_H */

