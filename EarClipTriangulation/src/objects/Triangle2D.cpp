#include "Triangle2D.h"

Triangle2D::Triangle2D() {
}


Triangle2D::Triangle2D(Point2D a, Point2D b, Point2D c) :
    a(a),
    b(b),
    c(c) {
}


Triangle2D::Triangle2D(const Triangle2D &arg) :
    a(arg.a),
    b(arg.b),
    c(arg.c) {
}


Triangle2D& Triangle2D::operator = (const Triangle2D &arg) {
    a = arg.a;
    b = arg.b;
    c = arg.c;

    return *this;
}


bool Triangle2D::hasCommonEdge(const Triangle2D &arg) {
    short commonVertices = 0;
    if (this->a == arg.a || this->a == arg.b || this->a == arg.c) {
        ++commonVertices;
    }
    if (this->b == arg.a || this->b == arg.b || this->b == arg.c) {
        ++commonVertices;
    }
    if (this->c == arg.a || this->c == arg.b || this->c == arg.c) {
        ++commonVertices;
    }

    return (commonVertices >= 2);
}
