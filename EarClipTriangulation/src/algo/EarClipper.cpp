#include "EarClipper.h"

Graph EarClipper::triangulate(const Graph &arg) {
    Graph result (arg);
    std::vector<bool> cutOff (arg.getVertexCount(), false);
    int vertexRemaining = arg.getVertexCount();

    unsigned int a = 0; //first of three vertexes, which create a corner
    while (vertexRemaining > 3) {
        bool isEar = true;
        a = a % arg.getVertexCount();
        unsigned int b = 0;
        unsigned int c = 0;
        unsigned int currentVertex = a + 1;

        while (true) { //b will be next unused vertex
            currentVertex = currentVertex % arg.getVertexCount(); //cycle vertexes
            if (!cutOff[currentVertex]) {
                b = currentVertex++;
                break;
            }
            ++currentVertex;
        }

        while (true) { //c will be next unused vertex
            currentVertex = currentVertex % arg.getVertexCount();
            if (!cutOff[currentVertex]) {
                c = currentVertex++;
                break;
            }
            ++currentVertex;
        }

        Vector2D va(arg.getVertex(a), arg.getVertex(b));
        Vector2D vb(arg.getVertex(b), arg.getVertex(c));

        if (va.orientation(vb) > 0) {
            ++a;
            continue;
        }

        for (unsigned int i = 0; i < arg.getVertexCount(); ++i) {
            if (i == a || i == b || i == c || cutOff[i]) {
                continue;
            }

            Vector2D va(arg.getVertex(a), arg.getVertex(i));
            Vector2D vb(arg.getVertex(i), arg.getVertex(c));

            if (va.orientation(vb) < 0) {
                isEar = false;
                //std::cout << a << ' ' << b << ' ' << c << ' ' << i << " - not ear\n";
                break;
            }
        }

        if (isEar) {
            --vertexRemaining;
            cutOff[b] = true;
            result.addEdge(a, c);
            //std::cout << a << ' ' << c << " - edge added\n";
        } else {
            ++a;
        }
    }

    return result;
}
