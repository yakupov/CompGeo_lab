#include "Graph.h"

Graph::Graph(std::string filename) {
    std::ifstream inp (filename.c_str());

    while (inp.peek() != EOF) {
        int x, y;
        inp >> x >> y;

        vertices.push_back(Point2D (x, y));
        edges.push_back(std::pair<int, int> (vertices.size() - 1, vertices.size()));
    }

    vertices.pop_back();
    edges.erase(edges.end() - 2, edges.end());
    edges.push_back(std::pair<int, int> (vertices.size() - 1, 0));
}


Graph::Graph (const Graph &arg) :
    vertices (arg.vertices),
    edges (arg.edges) {
}


void Graph::addEdge(unsigned int a, unsigned int b) {
    edges.push_back(std::pair<int, int>(a, b));
}


Point2D Graph::getVertex (unsigned int i) const {
    assert (i < vertices.size());
    return vertices[i];
}


std::pair <int, int> Graph::getEdge (unsigned int i) const {
    assert (i < edges.size());
    return edges[i];
}
