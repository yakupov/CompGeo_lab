#ifndef GRAPH_H
#define GRAPH_H

#include <cassert>
#include <utility>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

template <class Point>
class Graph {
public:
    Graph() {}

    Graph(std::vector <Point> data) :
        vertices (data) {
    }

    Graph (std::vector <Point> vertices, std::vector <std::pair<int, int> > edges) :
        vertices (vertices),
        edges (edges) {
    }

    Graph (const Graph<Point> &arg) :
        vertices (arg.vertices),
        edges (arg.edges) {
    }

    void addEdge (unsigned int a, unsigned int b) {
        edges.push_back(std::pair<int, int>(a, b));
    }

    //become a polygon
    void connectVertices() {
        edges.clear();

        for (unsigned int i = 0; i < vertices.size(); ++i) {
            edges.push_back(std::pair<int, int> (i, i + 1));
        }

        edges.pop_back();
        edges.push_back(std::pair<int, int> (vertices.size() - 1, 0));
    }

    Point getVertex (unsigned int i) const {
        assert (i < vertices.size());
        return vertices[i];
    }

    unsigned int getVertexCount () const {
        return vertices.size();
    }

    std::pair <int, int> getEdge (unsigned int i) const {
        assert (i < edges.size());
        return edges[i];
    }

    unsigned int getEdgeCount () const {
        return edges.size();
    }

protected:
    std::vector <Point> vertices;
    std::vector <std::pair<int, int> > edges;    //pair contains numbers of two incident vertexes
};

#endif // GRAPH_H
