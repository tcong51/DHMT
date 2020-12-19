#include "graphics.h"
#include <QPainter>
#include <QPoint>
#include <math.h>
graphics::graphics(QWidget *parent) :
    QWidget(parent)
{
    position=0;
    timerId=startTimer(500);
    positionBoat=0;
    positionXMoon=100;
    positionYMoon=500;
    positionXSun=100;
    positionYSun=300;
    positionXBrid=200;
    positionYBrid=200;
}
void graphics::timerEvent(QTimerEvent *){
    int h= height();
    int w= width();
    int r= 100;
    positionBoat+=50;
    positionYMoon+=50;
    positionXMoon-=20;
    if(positionXMoon==-20)positionXMoon=100;
    if(positionYMoon==800)positionYMoon=500;
    positionXSun+=10;
    positionYSun-=20;
    if(positionYSun==200)positionYSun=200;

    repaint();
}

void graphics::paintEvent(QPaintEvent *){
    QPainter painter(this);
//     painter.setPen(Qt::white);

    cloudBig(painter,300,130,70,50);
    cloudSmall(painter,650,200,20*1.4,20);
    Mountain(painter);
    cloudBig(painter,50,50,70,50);
    Sea(painter);
    painter.setRenderHint(QPainter::Antialiasing);
    Boat(painter);
    Moon(painter);
    Sun(painter);
    Brid(painter);

}

QPoint graphics::quay(QPoint p,QPoint c,int deta){
    QPoint pnew;
    double goc=deta*3.14/180;
    pnew.setX(c.x()+(p.x()-c.x())*cos(goc)-(p.y()-c.y())*sin(goc));
    pnew.setY(c.y()+(p.x()-c.x())*sin(goc)-(p.y()-c.y())*cos(goc));
    return pnew;
}
QPoint graphics::tinhtien(QPoint p,int tx,int ty){
    QPoint pnew;
    pnew.setX(p.x()+tx);
    pnew.setY(p.y()+ty);
    return pnew;
}
QPoint graphics::doixungy(QPoint p){
    QPoint pnew;
    pnew.setX(-p.x());
    pnew.setY(p.y());
    return pnew;
}
QPoint graphics::doixungx(QPoint p){
    QPoint pnew;
    pnew.setX(p.x());
    pnew.setY(-p.y());
    return pnew;
}

void graphics::Mountain(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#b40000"));

    QString filename= "C:/xampp/htdocs/GitHub/DHMT/mountain.png";
    painter.drawPixmap(position,130,w,h/2,QPixmap(filename));
}
void graphics::Boat(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("#b40000"));
//Chạy tới vị trí 300 là kiểm tra điều kiện
//    if(positionBoat!=300)positionBoat+=50; else positionBoat-=50;
    QString filename = "C:/xampp/htdocs/GitHub/DHMT/boat.png";
    painter.drawPixmap(positionBoat,300,100*1.7,100,QPixmap(filename));


 }

void graphics::Sea(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("blue"));
    painter.setPen(Qt::blue);
    painter.drawRect(0,325,w,100);
}

void graphics::Moon(QPainter &painter){
    int r= 100;
    int h= height();
    int w= width();
    painter.setPen(Qt::yellow);
    painter.setBrush(QBrush("#b40000"));
    QString filename = "C:/xampp/htdocs/GitHub/DHMT/moon.png";
    painter.drawPixmap(positionYMoon,positionXMoon,30*1.85,40,QPixmap(filename));

}
void graphics::cloudBig(QPainter &painter,double x, double y,double sx,double sy){
    int r= 100;
    int h= height();
    int w= width();
    painter.setBrush(QBrush("white"));
    painter.setPen(Qt::white);
    //vị trí mặc định là 100,100
    QPoint pointCloud(x,y);
    //sx =70,sy=50
    //vẽ bằng ellipse
    painter.drawEllipse(pointCloud.x(),pointCloud.y(),sx,sy);
    //sx1=100.,sy1=50
    painter.drawEllipse(pointCloud.x()+35,pointCloud.y()-25,100,sy);
    painter.drawEllipse(pointCloud.x()+100,pointCloud.y(),sx,sy);
    painter.drawEllipse(pointCloud.x()+35,pointCloud.y()+25,100,sy);
    //vẽ bằng drawChord nữa cung tròn
     //    painter.drawChord(pointCould.x(),pointCould.y(),sx,sy,(90*16),(180*16));//nữa hình tròn
     //    painter.drawChord(pointCould.x(),pointCould.y(),sx,sy,(90*16),-(180*16));//nữa hình tròn
     //    painter.drawChord(pointCloud.x()+35,pointCloud.y()-25,100,sy,0,(180*16));
     //     painter.drawChord(pointCloud.x()+35,pointCloud.y()-25,100,sy,0,-(180*16));
     //    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),-(180*16));
     //    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),+(180*16));
     //    painter.drawChord(pointCloud.x()+35,pointCloud.y()+25,100,sy,0,-(180*16));
     //    painter.drawChord(pointCloud.x()+35,pointCloud.y()+25,100,sy,0,+(180*16));
}
void graphics::cloudSmall(QPainter &painter,double x, double y,double sx,double sy){

    //vị trí mặc định là 100,100
    QPoint pointCloud(x,y);
    //sx =70,sy=50
    painter.drawEllipse(pointCloud.x(),pointCloud.y(),sx,sy);
//    painter.drawChord(pointCloud.x(),pointCloud.y(),sx,sy,(90*16),(180*16));//nữa hình tròn
//    painter.drawChord(pointCloud.x(),pointCloud.y(),sx,sy,(90*16),-(180*16));
    painter.drawEllipse(pointCloud.x()+15,pointCloud.y()-10,80,sy);
//    painter.drawChord(pointCloud.x()+15,pointCloud.y()-10,100,sy,0,(180*16));
//    painter.drawChord(pointCloud.x()+15,pointCloud.y()-10,100,sy,0,-(180*16));
    painter.drawEllipse(pointCloud.x()+80,pointCloud.y(),sx,sy);
//    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),-(180*16));
//    painter.drawChord(pointCloud.x()+100,pointCloud.y(),sx,sy,(90*16),(180*16));
    painter.drawEllipse(pointCloud.x()+15,pointCloud.y()+10,80,sy);
//    painter.drawChord(pointCloud.x()+15,pointCloud.y()+10,100,sy,0,-(180*16));
//     painter.drawChord(pointCloud.x()+15,pointCloud.y()+10,100,sy,0,(180*16));

}
void graphics::Sun(QPainter& painter){
    int r= 100;
    int h= height();
    int w= width();
    QPoint pcenter;
    painter.setBrush(QBrush("yellow"));
    pcenter.setX(positionXSun);
    pcenter.setY(positionYSun);
    painter.drawEllipse(pcenter,20,20);
}
void graphics::Brid(QPainter& painter){
    QPoint P(positionXBrid,positionYBrid);
    QString filename = "C:/xampp/htdocs/GitHub/DHMT/wing.png";
    painter.drawPixmap(P.x(),P.y(),20*(258/183),20,QPixmap(filename));
}
