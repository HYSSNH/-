#include "widget.h"
#include "ui_widget.h"


#include "Linklist.h"
#include "player.h"
#include "Linklist.cpp"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    defData();
    defWindow();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::defData()
{
    players data1 = {"Declan Rice   ",41,"24","36"};
    players data2 = {"Moisés Caicedo",25,"21","34"};
    players data3 = {"Wataru Endo   ",3,"30","33"};
    players data4 = {"Rodri         ",16,"26","34"};
    players data5 = {"Casemiro      ",18,"31","24"};
    players data[23] = {data1,data2,data3,data4,data5};
    playerlist = new Linklist<players>(data,5);
}

void Widget::defWindow()
{
    this->setWindowTitle("playerManager");

    tableView = new QTableView;

    /* 设置表格视图大小 */
    this->setFixedSize(1000,400);
    tableView->resize(1000, 400);

    /* 创建数据模型 */
    model = new QStandardItemModel();
    model->setHorizontalHeaderLabels({"Name","Number","Age","Starts"});

    /* 自适应所有列，让它布满空间 */
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    /* 加载共length行数据，并每行有4列数据 */
    for (int i = 0; i < playerlist->getLength(); i++)
    {
        /* 加载数据 */
        model->setItem(i, 0, new QStandardItem(QString(playerlist->getItem(i+1).name)));
        model->setItem(i, 1, new QStandardItem(QString("%1").arg(playerlist->getItem(i+1).number)));
        model->setItem(i, 2, new QStandardItem(QString(playerlist->getItem(i+1).age)));
        model->setItem(i, 3, new QStandardItem(QString(playerlist->getItem(i+1).starts)));
    }

    /* 设置表格视图数据 */
    tableView->setModel(model);

    //设置按钮
    QPushButton* btnA = new QPushButton("查找");
    QPushButton* btnB = new QPushButton("插入");
    QPushButton* btnC = new QPushButton("删除");
    QPushButton* btnD = new QPushButton("逆序");
    btnA->setParent(tableView);
    btnB->setParent(tableView);
    btnC->setParent(tableView);
    btnD->setParent(tableView);
    btnA->move(150,350);
    btnB->move(350,350);
    btnC->move(550,350);
    btnD->move(750,350);
    connect(btnA, &QPushButton::clicked, this, &Widget::findplayer);
    connect(btnB, &QPushButton::clicked, this, &Widget::insertplayer);
    connect(btnC, &QPushButton::clicked, this, &Widget::deleteplayer);
    connect(btnD, &QPushButton::clicked, this, &Widget::reverseplayer);

    tableView->setParent(this);

}

void Widget::findplayer()
{
    bool ok;
    bool numok;
    QString text = QInputDialog::getText(this, "the player", "序号", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty())
    {
        int number = text.toInt(&numok);
        qDebug()<<number;
        if(numok)   find(number);     // 调用带参数的槽函数
        else QMessageBox::warning(this,"错误","输入不能为空或必须为整数!");
    }
}

void Widget::insertplayer()
{
    bool ok,numok1,numok2;
    int pos1,number1;
    players temp;
    QString text0,text1, text2, text3, text4;

    // 弹出插入序号输入框
    text0 = QInputDialog::getText(this, "Position", "Position");
    pos1 = text0.toInt(&numok1);

    // 弹出第一个输入框
    text1 = QInputDialog::getText(this, "name", "name");
    // 弹出第二个输入框
    text2 = QInputDialog::getText(this, "number", "number");
    number1 = text2.toInt(&numok2);
    // 弹出第三个输入框
    text3 = QInputDialog::getText(this, "age", "age");
    // 弹出第四个输入框
    text4 = QInputDialog::getText(this, "starts", "starts", QLineEdit::Normal, "", &ok);

    QMessageBox msgBox;
    msgBox.setText("You entered: \n" + text1 + "\n" + text2+ "\n" + text3+ "\n"+ text4);
    msgBox.exec();

    if(ok && numok1 && numok2)
    {
        temp.name = text1;
        temp.number = text2.toInt();
        temp.age = text3;
        temp.starts = text4;
        playerlist->insert(pos1,temp);
        model->insertRow(pos1-1);
        model->setItem(pos1-1, 0, new QStandardItem(text1));
        model->setItem(pos1-1, 1, new QStandardItem(text2));
        model->setItem(pos1-1, 2, new QStandardItem(text3));
        model->setItem(pos1-1, 3, new QStandardItem(text4));

    }
    else QMessageBox::warning(this,"错误","检查");
}

void Widget::deleteplayer()
{
    bool ok;
    bool numok;
    QString text = QInputDialog::getText(this, "delete a player", "序号", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty())
    {
        int number = text.toInt(&numok);
        qDebug()<<number;
        if(numok)
        {
            playerlist->remove(number);
            model->removeRow(number-1);
        }
        else QMessageBox::warning(this,"错误","输入不能为空或必须为整数!");
    }
}

void Widget::reverseplayer()
{
    playerlist->reversePrint();


//    model->setItem(0, 0, new QStandardItem(QString(playerlist->getItem(0).name)));
//    model->setItem(0, 1, new QStandardItem(QString("%1").arg(playerlist->getItem(0).number)));
//    model->setItem(0, 2, new QStandardItem(QString(playerlist->getItem(0).age)));
//    model->setItem(0, 3, new QStandardItem(QString(playerlist->getItem(0).starts)));


    /* 加载共length行数据，并每行有4列数据 */
//    qDebug()<<playerlist->getLength()<<"head";
    for (int i = playerlist->getLength()-1; i >= 0; i--)
    {
        int index = playerlist->getLength() - i ;
        if(index != 5)
        {
            {
                /* 加载数据 */
                model->setItem(index, 0, new QStandardItem(QString(playerlist->getItem(index+1).name)));
                model->setItem(index, 1, new QStandardItem(QString("%1").arg(playerlist->getItem(index+1).number)));
                model->setItem(index, 2, new QStandardItem(QString(playerlist->getItem(index+1).age)));
                model->setItem(index, 3, new QStandardItem(QString(playerlist->getItem(index+1).starts)));

           }/*
        qDebug()<<playerlist->getItem(0).name;
        qDebug()<<playerlist->getItem(1).name;
        qDebug()<<playerlist->getItem(2).name;
        qDebug()<<playerlist->getItem(3).name;
        qDebug()<<playerlist->getItem(4).name;
        qDebug()<<playerlist->getItem(5).name;*/


        }
//        else
//        {
//                model->setItem(4, 0, new QStandardItem(QString(playerlist->getItem(5).name)));
//                model->setItem(4, 1, new QStandardItem(QString("%1").arg(playerlist->getItem(5).number)));
//                model->setItem(4, 2, new QStandardItem(QString(playerlist->getItem(5).age)));
//                model->setItem(4, 3, new QStandardItem(QString(playerlist->getItem(5).starts)));
//        }
    }
//    qDebug()<<playerlist->getLength()<<"rear";
}


void Widget::find(int num1)
{
    players temp = playerlist->getItem(num1);
    QString Number = QString::number(playerlist->getItem(num1).number);
    QString strData = "Name: " + temp.name + "Number: " + Number + "Age: " + temp.age + "Starts: " + temp.starts;
    QMessageBox msgBox;
    msgBox.setText(strData);
    msgBox.exec();
}
