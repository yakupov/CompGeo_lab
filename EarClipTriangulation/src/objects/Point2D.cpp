#include "Point2D.h"

Point2D::Point2D ()  :
    x(0),
    y(0) {
}


Point2D::Point2D (int x, int y) :
    x (x),
    y (y) {
}


Point2D::Point2D (const Point2D &arg) :
    x (arg.x),
    y (arg.y) {
}


Point2D& Point2D::operator= (const Point2D &arg) {
    x = arg.x;
    y = arg.y;

    return *this;
}


Point2D Point2D::operator - (const Point2D &arg) {
    Point2D res (*this);
    return res -= arg;
}


Point2D& Point2D::operator -= (const Point2D &arg) {
    x -= arg.x;
    y -= arg.y;

    return *this;
}


bool Point2D::operator < (const Point2D &arg) {
    if (this->x < arg.x) {
        return true;
    }
    if (this->x > arg.x) {
        return false;
    }
    return (this->y < arg.y);
}


bool Point2D::operator == (const Point2D &arg) {
    return (this->x == arg.x && this->y == arg.y);
}

