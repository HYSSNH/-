#ifndef HEAD_H
#define HEAD_H

#include "node.h"

#include <QString>
#include <QDebug>
#include <QObject>
#include <QWidget>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QTableView>
#include <QHeaderView>
#include <QStandardItemModel>
#include <QPushButton>
#include <QInputDialog>
#include <QMessageBox>
#include <QVBoxLayout>


typedef struct
{
 QString name;
 int number;
 QString age;
 QString starts;
} players;

#define MaxSize 23

#endif // HEAD_H
