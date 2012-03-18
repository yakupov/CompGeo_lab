#include "EarClipper.h"

Graph <Point2D> EarClipper::triangulate(const Graph <Point2D> &arg, std::vector <Triangle2D> *triangles) {
    Graph <Point2D> result (arg);
    std::vector<bool> vertexStatus (arg.getVertexCount(), false); //1 - ear, 0 - not ear
    std::list<int> remainingVertices;
    short direction = determineDirection(arg);

    for (unsigned int i = 0; i < arg.getVertexCount(); ++i) {
        remainingVertices.push_back(i);
    }

    for (std::list<int>::iterator it = remainingVertices.begin(); it != remainingVertices.end(); ++it) {
        vertexStatus[*it] = isEar(arg, remainingVertices, it, direction);
    }

    std::list<int>::iterator currentVertex = remainingVertices.begin();
    while (remainingVertices.size() > 3) {
        bool earFound = false;

        for (unsigned int i = remainingVertices.size(); i > 0 && remainingVertices.size() > 3; --i) {
            if (vertexStatus[*currentVertex] == 1) {
                earFound = true;
                addTriangle(result, remainingVertices, currentVertex, triangles);

                std::list<int>::iterator vertexToRemove = currentVertex;

                if (++currentVertex == remainingVertices.end()) {
                    currentVertex = remainingVertices.begin();
                }
                remainingVertices.erase(vertexToRemove);
                vertexStatus[*currentVertex] = isEar(arg, remainingVertices, currentVertex, direction);

                if (currentVertex == remainingVertices.begin()) {
                    currentVertex = --remainingVertices.end();
                } else {
                    --currentVertex;
                }
                vertexStatus[*currentVertex] = isEar(arg, remainingVertices, currentVertex, direction);
            } else {
                if (++currentVertex == remainingVertices.end()) {
                    currentVertex = remainingVertices.begin();
                }
            }
        }

        if (!earFound) {
            result.connectVertices();
            triangles->clear();

            std::cerr << "Impossoble to triangulate\n";
            return result;
        }
    }

    if (triangles != 0 && remainingVertices.size() == 3) { //add remains to triangulation
        triangles->push_back(Triangle2D(arg.getVertex(*remainingVertices.begin()), arg.getVertex(*++remainingVertices.begin()),
                                        arg.getVertex(*--remainingVertices.end())));
    }

    return result;
}



void EarClipper::addTriangle(Graph<Point2D> &poly, const std::list<int>& remainingVertices, std::list<int>::iterator vertex, std::vector<Triangle2D> *triangles) {
    assert (remainingVertices.size() > 2);
    unsigned int a, b, c;

    b = *vertex;
    if (vertex == remainingVertices.begin()) {
        a = remainingVertices.back();
        c = *++vertex;
        --vertex;
    } else if (vertex == --remainingVertices.end()) {
        a = *--vertex;
        c = remainingVertices.front();
        ++vertex;
    } else {
        a = *--vertex;
        c = *++++vertex;
    }

    assert (a < poly.getVertexCount() && b < poly.getVertexCount() && c < poly.getVertexCount());

    poly.addEdge(a, c);
    std::cout << "Edge added: " << a << ' ' << c << ", ear clipped: " << b << std::endl;
    if (triangles != 0) {
        triangles->push_back(Triangle2D(poly.getVertex(a), poly.getVertex(b), poly.getVertex(c)));
    }
}


short EarClipper::determineDirection(const Graph<Point2D> &poly) {
    if (poly.getVertexCount() < 3) {
        return 1;
    }

    int minVertex = 0;
    for (unsigned int i = 0; i < poly.getVertexCount(); ++i) {
        if (poly.getVertex(i) < poly.getVertex(minVertex)) {
            minVertex = (int) i;
        }
    }
    int minVertexLeft = minVertex - 1;
    if (minVertexLeft < 0) {
        minVertexLeft = (int) poly.getVertexCount() - 1;
    }
    int minVertexRight = (minVertex + 1) % (int) poly.getVertexCount();

    Vector2D vMV1 (poly.getVertex(minVertexLeft), poly.getVertex(minVertex));
    Vector2D vMV2 (poly.getVertex(minVertex), poly.getVertex(minVertexRight));
    if (vMV1.orientation(vMV2) > 0) {
        return -1;
    }
    return 1;
}


bool EarClipper::isEar(const Graph<Point2D> &poly, std::list<int>& remainingVertices, std::list<int>::iterator vertex, short direction) {
    assert (remainingVertices.size() > 2);
    unsigned int a, b, c;

    b = *vertex;
    if (vertex == remainingVertices.begin()) {
        a = remainingVertices.back();
        c = *++vertex;
        --vertex;
    } else if (vertex == --remainingVertices.end()) {
        a = *--vertex;
        c = remainingVertices.front();
        ++vertex;
    } else {
        a = *--vertex;
        c = *++++vertex;
    }

    assert (a < poly.getVertexCount() && b < poly.getVertexCount() && c < poly.getVertexCount());

    Vector2D va (poly.getVertex(a), poly.getVertex(b));
    Vector2D vb (poly.getVertex(b), poly.getVertex(c));
    if (va.orientation(vb) * direction > 0) {
        return false;
    }

    for (std::list<int>::iterator it = remainingVertices.begin(); it != remainingVertices.end(); ++it) {
        if (*it == (int)a || *it == (int)b || *it == (int)c) {
            continue;
        }

        if (isInsideOfTriangle(poly.getVertex(a), poly.getVertex(b), poly.getVertex(c), poly.getVertex(*it))) {
            return false;
        }
    }

    std::cout << a << ' ' << b << ' ' << c << " - ear\n";
    return true;
}


bool EarClipper::isInsideOfTriangle(Point2D a, Point2D b, Point2D c, Point2D i) {
    Vector2D vai(a, i);
    Vector2D vic(i, c);
    Vector2D vib(i, b);
    Vector2D vci(c, i);

    return ((vai.orientation(vic) < 0 && vai.orientation(vib) > 0 && vci.orientation(vib) < 0) ||
            (vai.orientation(vic) > 0 && vai.orientation(vib) < 0 && vci.orientation(vib) > 0));
}
