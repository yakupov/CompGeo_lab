#ifndef DRAWER_H
#define DRAWER_H

#include <sstream>
#include <cmath>
#include <algorithm>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include "src/objects/Graph.h"
#include "src/objects/Point2D.h"


class Drawer : public QWidget {
    Q_OBJECT

public:
    Drawer(QWidget *parent = 0);
    Drawer(QWidget *parent, const Graph <Point2D> &poly);

    void paintEvent(QPaintEvent *event);
    void replacePoly (const Graph <Point2D> &poly);

protected:
    Graph <Point2D> poly;
};

#endif // DRAWER_H
