#ifndef MAINWIDGET_H
#define	MAINWIDGET_H

#include <string>
#include <iostream>
#include <QWidget>
#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QTabWidget>
#include <QFileDialog>
#include "src/algo/PolygonInputParser.h"
#include "src/algo/EarClipper.h"
#include "src/gui/Drawer.h"
#include "src/objects/Graph.h"
#include "src/objects/Triangle2D.h"

class MainWidget : public QWidget {
    Q_OBJECT
    
protected:
    QTabWidget tabs;
    QWidget controlWidget;

    QFileDialog openFile;

    QGridLayout mainLay;
    QGridLayout controlWidgetLay;

    QPushButton clearButton;
    QPushButton exitButton;
    QPushButton exportToFileButton;
    QPushButton importFromFileButton;
    QPushButton processButton;
    QPushButton showOpenFileDialogButton;

    QLabel spacer1;
    QLabel spacer2;

    QLineEdit selectedFileName;

    Drawer visualizer;

    Graph<Point2D> poly;

public:
    MainWidget();
    
public slots:
    void addPoint (Point2D);
    void clickedClearButton();
    void clickedExitButton();
    void clickedExportToFileButton();
    void clickedImportFromFileButton();
    void clickedProcessButton();
    void removePoint (unsigned int);

signals:
    void performExitButtonAction();
};

#endif	/* MAINWIDGET_H */
