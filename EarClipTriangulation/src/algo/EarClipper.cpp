#include "EarClipper.h"

Graph <Point2D> EarClipper::triangulate(const Graph <Point2D> &arg, std::vector <Triangle2D> *triangles) {
    Graph <Point2D> result (arg);
    std::vector<bool> cutOff (arg.getVertexCount(), false);
    int vertexRemaining = arg.getVertexCount();

    unsigned long long stepsElapsed = 0;
    short direction = 1;
    unsigned int a = 0; //first of three vertexes, which create a corner

    while (vertexRemaining > 3) {
        if (++stepsElapsed > arg.getVertexCount() * arg.getVertexCount()) {
            result.connectVertices();
            triangles->clear();

            if (direction == -1) {
                std::cerr << "Impossoble to triangulate\n";
                return result;
            } else {
                direction = -1;
                stepsElapsed = 0;
                a = 0;
                cutOff.assign(arg.getVertexCount(), false);
                vertexRemaining = arg.getVertexCount();
            }
        }

        bool isEar = true;
        unsigned int b = findNextVertex(a, cutOff, arg);
        unsigned int c = findNextVertex(b, cutOff, arg);

        Vector2D va(arg.getVertex(a), arg.getVertex(b));
        Vector2D vb(arg.getVertex(b), arg.getVertex(c));

        if (va.orientation(vb) * direction > 0) {
            a = findNextVertex(a, cutOff, arg);
            continue;
        }

        for (unsigned int i = 0; i < arg.getVertexCount(); ++i) {
            if (i == a || i == b || i == c || cutOff[i]) {
                continue;
            }

            if (isInsideOfTriangle(arg.getVertex(b), arg.getVertex(a), arg.getVertex(c), arg.getVertex(i))) {
                isEar = false;
                //std::cout << a << ' ' << b << ' ' << c << ' ' << i << " - not ear\n";
                break;
            }
        }

        if (isEar) {
            --vertexRemaining;
            cutOff[b] = true;
            result.addEdge(a, c);
            if (triangles != 0) {
                triangles->push_back(Triangle2D(arg.getVertex(a), arg.getVertex(b), arg.getVertex(c)));
            }
            //std::cout << a << ' ' << c << " - edge added\n";
        } else {
            a = findNextVertex(a, cutOff, arg);
        }
    }

    return result;
}


//cutOff - map, which shows, which vertices can not be valid answer
unsigned int EarClipper::findNextVertex(unsigned int curr, const std::vector<bool> &cutOff, const Graph<Point2D> &poly) {
    int res = curr + 1;
    res %= poly.getVertexCount(); //cycle vertices

    int triesRemaining = poly.getVertexCount() + 2;
    while (cutOff[res]) {
        assert (--triesRemaining > 0);

        ++res;
        res %= poly.getVertexCount();
    }

    return res;
}


bool EarClipper::isInsideOfTriangle(Point2D a, Point2D b, Point2D c, Point2D i) {
    Vector2D vai(a, i);
    Vector2D vic(i, c);
    Vector2D vib(i, b);
    Vector2D vci(c, i);

    return ((vai.orientation(vic) < 0 && vai.orientation(vib) > 0 && vci.orientation(vib) < 0) ||
            (vai.orientation(vic) > 0 && vai.orientation(vib) < 0 && vci.orientation(vib) > 0));
}
