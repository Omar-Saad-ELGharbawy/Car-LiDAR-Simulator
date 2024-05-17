#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cmath>
#include <iostream>
using namespace std;
#define MY_PI 3.14159265

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    void paintEvent(QPaintEvent * event);
    MainWindow(QWidget *parent = nullptr);
    /*******************************************************************************
    *                      Structure  Data Types                                  *
    *****************************************************************************/
    typedef struct
    {
        float x;
        float y;
    }PosType;

    typedef struct
    {
        PosType position;
        float heading; //Angle
        float Range;  // R
    }SensorType;

    typedef struct  {
        PosType vertices[10];
        int numberOfVertices;
    }PolygonType;

    /*******************************************************************************
    *                      Functions Prototypes                                   *
    *****************************************************************************/
    double calculateAngle(PosType * point_1, PosType * point_2);
    bool isInFov(SensorType sensorDescription, PosType minDistPtToPolygon);

    float calculateDist(SensorType * sensorDescription, PosType minDistPtToPolygon);

    void drawSensor(SensorType sensorDescription);
    void drawPolygon(QPainter* painter,PolygonType* poly);
    PosType getMinDistPt(SensorType sensorDescription, PolygonType polygonDescription);
    float calculateDist(SensorType sensorDescription, PosType minDistPtToPolygon);

    ~MainWindow();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
