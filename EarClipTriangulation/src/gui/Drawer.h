#ifndef DRAWER_H
#define DRAWER_H

#include <sstream>
#include <cmath>
#include <algorithm>
#include <QWidget>
#include <QPainter>
#include <QFont>
#include "src/algo/Graph.h"
#include "src/algo/EarClipper.h"


class Drawer : public QWidget {
    Q_OBJECT

public:
    Drawer(QWidget *parent = 0);
    Drawer(QWidget *parent, const Graph& poly);

    void paintEvent(QPaintEvent *event);
    void replacePoly (const Graph& poly);

protected:
    Graph poly;
};

#endif // DRAWER_H
