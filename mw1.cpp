#include "mw1.h"
#include "ui_mw1.h"
#include "icon.h"

#include <map>
#include <iostream>
#include <QTimer>
#include <ctime>

using namespace std;

MW1::MW1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MW1)
{
    ui->setupUi(this);

    timer2 = new QTimer(this);
    connect(timer2,SIGNAL(timeout()),this,SLOT(movedmonster()));//timeoutslot()为自定义槽
    timer2->start(500);


    //init game world
    _game.initWorld("");//TODO 应该是输入有效的地图文件
}

MW1::~MW1()
{
    delete ui;
    delete timer2;
}

void MW1::paintEvent(QPaintEvent *e){
    QPainter *pa;
    pa = new QPainter();

    pa->begin(this);
    this->_game.show(pa);
    //this->_game.getmonster().show(pa);
    pa->end();
    delete pa;
}

void MW1::keyPressEvent(QKeyEvent *e)
{
    //direction = 1,2,3,4 for 上下左右
    if(e->key() == Qt::Key_A)
    {
        this->_game.handlePlayerMove(3,1);
    }
    else if(e->key() == Qt::Key_D)
    {
        this->_game.handlePlayerMove(4,1);
    }
    else if(e->key() == Qt::Key_W)
    {
        this->_game.handlePlayerMove(1,1);
    }
    else if(e->key() == Qt::Key_S)
    {
         this->_game.handlePlayerMove(2,1);
    }
    this->repaint();
}

void MW1::movedmonster(){
   /* static int i=1;
    i=i+1;
    _game.getmonster().setPosY(8);
    _game.getmonster().setPosX(4+i);

    if(_game.getmonster().pong()==true){
        qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
        i = rand()%20;
        _game.getmonster().setPosX(4+i);
    }
    this->repaint();*/

    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    int i = rand()%60;

    if(i<15)
    {
        _game.handleMonsterMove(2,1);
    }
    if(i>=15&&i<30)
    {
        _game.handleMonsterMove(3,4);
    }
    if(i>=30&&i<45)
    {
        _game.handleMonsterMove(1,2);
    }
    if(i>=45)
    {
        _game.handleMonsterMove(4,3);
    }
    this->repaint();
}
