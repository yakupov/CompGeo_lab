#include "MainWidget.h"

MainWidget::MainWidget()
      : exitButton ("Exit"),
        processButton ("Do it"),
        visualizer (this) {

    mainLay.addWidget(&visualizer, 0, 0);
    mainLay.addWidget(&processButton, 1, 0);
    mainLay.addWidget(&exitButton, 2, 0);

    this->setLayout(&mainLay);
    this->setMinimumSize(600, 400);

    QObject::connect(&exitButton, SIGNAL(clicked()), this, SLOT(clickedExitButton()));
    QObject::connect(&processButton, SIGNAL(clicked()), this, SLOT(clickedProcessButton()));


    Graph g ("input.txt");
    visualizer.replacePoly(g);
}


void MainWidget::clickedExitButton() {
    emit performExitButtonAction();
}


void MainWidget::clickedProcessButton() {
    Graph g ("input.txt");
    visualizer.replacePoly(EarClipper::triangulate(g));
}
