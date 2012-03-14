#ifndef MAINWIDGET_H
#define	MAINWIDGET_H

#include <iostream>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include "src/algo/PolygonInputParser.h"
#include "src/algo/EarClipper.h"
#include "src/gui/Drawer.h"
#include "src/objects/Graph.h"
#include "src/objects/Triangle2D.h"

class MainWidget : public QWidget {
    Q_OBJECT
    
protected:
    QGridLayout mainLay;

    QPushButton exitButton;
    QPushButton processButton;

    Drawer visualizer;

public:
    MainWidget();
    //~MainWidget();
    
public slots:
    void clickedExitButton();
    void clickedProcessButton();

signals:
    void performExitButtonAction();
};

#endif	/* MAINWIDGET_H */
