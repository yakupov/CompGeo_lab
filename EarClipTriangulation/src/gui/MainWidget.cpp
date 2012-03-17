#include "MainWidget.h"

MainWidget::MainWidget()
    :   clearButton ("Clear graph"),
        exitButton ("Exit"),
        exportToFileButton ("Export poly to file"),
        importFromFileButton ("Import poly from file"),
        processButton ("Triangulate"),
        showOpenFileDialogButton ("Select file"),
        selectedFileName ("input.txt"),
        visualizer (this) {

    tabs.addTab(&visualizer, "Visualizer");

    mainLay.addWidget(&tabs, 0, 0);
    mainLay.addWidget(&controlWidget, 0, 1);
    this->setLayout(&mainLay);

    controlWidgetLay.addWidget(&showOpenFileDialogButton, 0, 0);
    controlWidgetLay.addWidget(&selectedFileName, 1, 0);
    controlWidgetLay.addWidget(&importFromFileButton, 2, 0);
    controlWidgetLay.addWidget(&exportToFileButton, 3, 0);
    controlWidgetLay.addWidget(&spacer1, 4, 0);
    controlWidgetLay.addWidget(&processButton, 5, 0);
    controlWidgetLay.addWidget(&clearButton, 6, 0);
    controlWidgetLay.addWidget(&spacer2, 7, 0);
    controlWidgetLay.addWidget(&exitButton, 8, 0);
    //controlWidgetLay.setAlignment(Qt::AlignTop);

    controlWidget.setLayout(&controlWidgetLay);
    controlWidget.setMaximumWidth(200);

    visualizer.setMinimumSize(600, 400);

    QObject::connect(&clearButton, SIGNAL(clicked()), this, SLOT(clickedClearButton()));
    QObject::connect(&exitButton, SIGNAL(clicked()), this, SLOT(clickedExitButton()));
    QObject::connect(&processButton, SIGNAL(clicked()), this, SLOT(clickedProcessButton()));
    QObject::connect(&showOpenFileDialogButton, SIGNAL(clicked()), &openFile, SLOT(show()));
    QObject::connect(&openFile, SIGNAL(fileSelected(QString)), &selectedFileName, SLOT(setText(const QString &)));
    QObject::connect(&exportToFileButton, SIGNAL(clicked()), this, SLOT(clickedExportToFileButton()));
    QObject::connect(&importFromFileButton, SIGNAL(clicked()), this, SLOT(clickedImportFromFileButton()));
    QObject::connect(&visualizer, SIGNAL(pointAdded(Point2D)), this, SLOT(addPoint(Point2D)));
    QObject::connect(&visualizer, SIGNAL(pointRemoved(unsigned int)), this, SLOT(removePoint(unsigned int)));
}


void MainWidget::addPoint(Point2D arg) {
    poly.addVertex(arg);
    poly.connectVertices();
    visualizer.replacePoly(poly);
    visualizer.update();
}


void MainWidget::clickedClearButton() {
    poly.clear();
    visualizer.replacePoly(poly);
}


void MainWidget::clickedExitButton() {
    emit performExitButtonAction();
}


void MainWidget::clickedExportToFileButton() {
    poly.dumpVertices(selectedFileName.text().toStdString());
}


void MainWidget::clickedImportFromFileButton() {
    poly = Graph <Point2D> (PolygonInputParser::parseFile(selectedFileName.text().toStdString()));
    poly.connectVertices();
    visualizer.replacePoly(poly);
    visualizer.update();
}


void MainWidget::clickedProcessButton() {
    poly.connectVertices();
    std::vector <Triangle2D> triangles;
    visualizer.replacePoly(EarClipper::triangulate(poly, &triangles));
    visualizer.update();

    for (unsigned int i = 0; i < triangles.size(); ++i) {
        std::cout << triangles[i].getA().getX() << ' ' << triangles[i].getA().getY() << '\t';
        std::cout << triangles[i].getB().getX() << ' ' << triangles[i].getB().getY() << '\t';
        std::cout << triangles[i].getC().getX() << ' ' << triangles[i].getC().getY() << std::endl;
    }
}


void MainWidget::removePoint(unsigned int index) {
    poly.removePoint(index);
    visualizer.replacePoly(poly);
}
