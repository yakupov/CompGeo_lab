#ifndef EARCLIPPER_H
#define EARCLIPPER_H

#include <cmath>
#include <cassert>
#include <utility>
#include <vector>
#include <iostream>
#include <list>
#include "src/objects/Graph.h"
#include "src/objects/Vector2D.h"
#include "src/objects/Triangle2D.h"
#include "src/objects/Point2D.h"

class EarClipper {
public:
    static Graph <Point2D> triangulate (const Graph <Point2D> &arg, std::vector <Triangle2D> *triangles = 0);

private:
    static void addTriangle (Graph<Point2D> &poly, const std::list<int> &remainingVertices, std::list<int>::iterator vertex, std::vector <Triangle2D> *triangles = 0);
    static short determineDirection (const Graph<Point2D> &poly);
    static bool isEar (const Graph<Point2D> &poly, std::list<int> &RremainingVertices, std::list<int>::iterator vertex, short direction);
    static bool isInsideOfTriangle (Point2D a, Point2D b, Point2D c, Point2D i); //i inside abc?
};

#endif // EARCLIPPER_H
