#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent * event){
    QPainter painter(this);
    int gridSize=50;
    for (int x = 0; x < width(); x += gridSize) {
        painter.drawLine(x, 0, x, height());
    }

    for (int y = 0; y < height(); y += gridSize) {
        painter.drawLine(0, y, width(), y);
    }

    /*******************************************************************************
    *                      Structure  Initializations                             *
    *****************************************************************************/
    PolygonType polygon1 ={ { {500, 500} , {650, 450}, {1000, 800}, {1000, 900}, {800, 1100}, {580, 1000} }, 6};
    PolygonType polygon2 ={{ {500, 300} , {600, 300}, {700, 300}, {800, 300}, {1000, 300}, {150, 450}, {100, 400}}, 7};

     SensorType sensor1 = { {400,760}, -160, 600 };
    PosType min_point = {30,35};

//    SensorType sensor1 = { {150,150}, 0, 100 };
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(10);
    painter.setPen(pen);
    painter.drawPoint(30,35);
    drawSensor(sensor1);
    float dist;
    dist = calculateDist(&sensor1 , min_point);
    cout<< "Distance is is " << dist << endl;
    bool FOV = isInFov(sensor1,min_point);
    cout << FOV << endl;
    if(FOV){
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        QPen pen(Qt::green);
        painter.setPen(pen);
        drawPolygon(&painter,&polygon1);
    }else{
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        QPen pen(Qt::red);
        painter.setPen(pen);
        drawPolygon(&painter,&polygon1);
    }
}
void MainWindow::drawSensor(SensorType mainSensor)
{
    QPainter painter(this);
    QPen pen;
    pen.setColor(Qt::black);
    pen.setWidth(5);
    painter.setPen(pen);
    qreal radius = mainSensor.Range;
    int spanAngle = 140;
    int startAngle = mainSensor.heading;
    int xpos = mainSensor.position.x;
    int ypos= mainSensor.position.y;
    painter.translate(xpos, ypos);
    QRect rect(-radius,-radius,2*radius,2*radius);
    painter.drawArc(rect, (startAngle*16)-(spanAngle*8),spanAngle*16);
    painter.rotate( -0.5 * spanAngle-startAngle);
    painter.drawLine(0,0, radius, 0);
    painter.drawEllipse (QPoint(0,0), 5, 5);
    painter.rotate (spanAngle);
    painter.drawLine(0, 0, radius, 0);
}
void MainWindow::drawPolygon(QPainter* painter,PolygonType* poly)
{
    // Set the brush and pen properties for drawing the polygon
    //painter.setBrush(Qt::SolidPattern); // You can choose the fill pattern
    // Create a QPolygonF to store the vertices of the polygon
    QPolygonF qPolygon;

    // Populate qPolygon with the vertices from the polygon struct
    for (int i = 0; i < poly->numberOfVertices; ++i) {
        QPointF point(poly->vertices[i].x, poly->vertices[i].y);
        qPolygon << point;
    }

    // Draw the polygon
    painter->drawPolygon(qPolygon);
}

/*******************************************************************************
 *                      Functions Definitions                                 *
 *****************************************************************************/
double MainWindow::calculateAngle(PosType * point_1, PosType * point_2) {
    double deltaX = point_2->x - point_1->x;
    double deltaY = point_2->y - point_1->y;
    double angle = atan2(deltaY, deltaX) * 180 / MY_PI;
    return angle;
}

bool MainWindow::isInFov(SensorType sensorDescription, PosType minDistPtToPolygon){
    double angle = calculateAngle(& sensorDescription.position,& minDistPtToPolygon);
    cout << "Angle = : " << angle << " degrees." << endl;
    if ( (angle < sensorDescription.heading + 70) && (angle > sensorDescription.heading - 70) ){
        return true;
    }
    else{
        return false;
    }
}

float MainWindow::calculateDist(SensorType * sensorDescription, PosType minDistPtToPolygon) {
    float result;

    result = sqrt( pow((sensorDescription->position.x - minDistPtToPolygon.x),2) + pow((sensorDescription->position.y - minDistPtToPolygon.y),2) );
    return result;
}
