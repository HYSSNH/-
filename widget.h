#ifndef WIDGET_H
#define WIDGET_H

#include "head.h"
#include "Linklist.h"

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    void defWindow();
    void defData();

private:
    Ui::Widget *ui;
    Linklist<players>* playerlist;
    QTableView *tableView;
    QStandardItemModel* model;

public slots:
    void findplayer();
    void find(int i);
    void insertplayer();
    void deleteplayer();
    void reverseplayer();
};
#endif // WIDGET_H
