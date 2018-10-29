/* 
 * File:   MyTableModel.cpp
 * Author: duo
 * 
 * Created on August 26, 2015, 10:17 PM
 */

#include <boost/foreach.hpp>
#include <string>
#include "MyTableModel.h"
#include "FileRec.h"
#include "VersionInfoRecord.h"
using namespace std;

MyTableModel::MyTableModel(QObject* parent)
        :QAbstractTableModel(parent)
{}

int MyTableModel::rowCount(const QModelIndex& /*parent*/) const
{   
    return recordsCollection->size();
}

int MyTableModel::columnCount(const QModelIndex& /*parent*/) const
{
    return 3;
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole){
        if(orientation == Qt::Horizontal){
            switch(section){
                case 0:
                    return QString("Version#");
                case 1:
                    return QString("Date");
                case 2:
                    return QString("Size");
            }
        }
    }
    return QVariant();
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if(role==Qt::DisplayRole){
        // role = DisplayRole : return any string data
        if(index.column() == 0){
            // column 0 is for images, so just return placeholder
            //return QVariant("test1");
            int i = recordsCollection->at(index.row())->getVersion();
            QString s = QString::number(i);
            return s;
        }
        
        if(index.column() == 1)
            return QString(recordsCollection->at(index.row())->getModifyTime().c_str());
            //return QVariant("test2");
        
        if(index.column() == 2){
            unsigned int i = recordsCollection->at(index.row())->getLength();
            QString s = QString::number(i);
            return s;
        }
    }
    else if( (role == Qt::DecorationRole) && (index.column() == 0) ){
       /*string imagedata = recordsCollection->at(index.row())->getImage();
        QByteArray imagebytes = QByteArray::fromBase64(imagedata.c_str());
        QImage img = QImage::fromData(imagebytes);
        return img;*/
        return QVariant();
    }
    return QVariant();
}

bool MyTableModel::insertRows(int /*position*/, int /*rows*/, const QModelIndex &/*index*/){
    //  Q_UNUSED(index);
    //  beginInsertRows(QModelIndex(), position, position+rows-1);
    
      //Add a row
    //  endInsertRows();
    //  return true;
    //cout << "In insertRows - which isn't implemented" << endl;
    return true;
}

bool MyTableModel::removeRows(int /*position*/, int /*rows*/, const QModelIndex &/*index*/){
    //...7 lines
    return true;
}

bool MyTableModel::setData(const QModelIndex &/*index*/, const QVariant &/*value*/, int /*role*/){
    //...9 lines
    return false;
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const{
    if(!index.isValid())
        return Qt::ItemIsEnabled;
    
    //return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
    
    return QAbstractTableModel::flags(index) | Qt::ItemIsSelectable;
}

void MyTableModel::addRecord(/*RecordPtr newone*/){
    
    //...
    
    int position = recordsCollection->size();
    beginInsertRows(QModelIndex(), position, position);
    //recordsCollection->push_back(newone);
    endInsertRows();
    emit(dataChanged(QModelIndex(), QModelIndex()));
}
void MyTableModel::refreshall() {
    this->resetInternalData();
    this->reset();
}

