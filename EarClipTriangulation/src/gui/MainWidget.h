#ifndef MAINWIDGET_H
#define	MAINWIDGET_H

#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include "src/gui/Drawer.h"
#include "src/algo/Graph.h"

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
