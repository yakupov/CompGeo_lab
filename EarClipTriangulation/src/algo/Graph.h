#ifndef GRAPH_H
#define GRAPH_H

#include <cassert>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include "src/algo/Point2D.h"

class Graph {
public:
    Graph() {}
    Graph(std::string filename);    //read as a polygon
    Graph(const Graph& arg);

    void addEdge (unsigned int a, unsigned int b);
    Point2D getVertex (unsigned int i) const;
    unsigned int getVertexCount () const {return vertices.size();}
    std::pair <int, int> getEdge (unsigned int i) const;
    unsigned int getEdgeCount () const {return edges.size();}

protected:
    std::vector <Point2D> vertices;
    std::vector <std::pair<int, int> > edges;    //pair contains numbers of two incident vertexes
};

#endif // GRAPH_H
