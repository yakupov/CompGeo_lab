#ifndef EARCLIPPER_H
#define EARCLIPPER_H

#include <cmath>
#include <cassert>
#include <utility>
#include <vector>
#include <iostream>
#include "src/objects/Graph.h"
#include "src/objects/Vector2D.h"
#include "src/objects/Triangle2D.h"
#include "src/objects/Point2D.h"

class EarClipper {
public:
    static Graph <Point2D> triangulate (const Graph <Point2D> &arg, std::vector <Triangle2D> *triangles = 0);

private:
    static unsigned int findNextVertex (unsigned int curr, const std::vector<bool> &cutOff, const Graph <Point2D> &poly);
    static bool isInsideOfTriangle (Point2D a, Point2D b, Point2D c, Point2D i); //i inside abc?
};

#endif // EARCLIPPER_H
