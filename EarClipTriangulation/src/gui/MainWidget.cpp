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


    Graph <Point2D> g (PolygonInputParser::parseFile("input.txt"));
    g.connectVertices();
    visualizer.replacePoly(g);
}


void MainWidget::clickedExitButton() {
    emit performExitButtonAction();
}


void MainWidget::clickedProcessButton() {
    Graph <Point2D> g (PolygonInputParser::parseFile("input.txt"));
    g.connectVertices();
    std::vector <Triangle2D> triangles;
    visualizer.replacePoly(EarClipper::triangulate(g, &triangles));

    for (unsigned int i = 0; i < triangles.size(); ++i) {
        std::cout << triangles[i].getA().getX() << ' ' << triangles[i].getA().getY() << '\t';
        std::cout << triangles[i].getB().getX() << ' ' << triangles[i].getB().getY() << '\t';
        std::cout << triangles[i].getC().getX() << ' ' << triangles[i].getC().getY() << std::endl;
    }
}
