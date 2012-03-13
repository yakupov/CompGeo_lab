#ifndef EARCLIPPER_H
#define EARCLIPPER_H

#include <cmath>
#include <utility>
#include <vector>
#include <iostream>
#include "src/algo/Graph.h"
#include "src/algo/Vector2D.h"

//fabric, actually.
class EarClipper {
public:
    static Graph triangulate (const Graph& arg);
};

#endif // EARCLIPPER_H
