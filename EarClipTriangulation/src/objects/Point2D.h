#ifndef POINT2D_H
#define POINT2D_H

class Point2D {
public:
    Point2D ();
    Point2D (int, int);
    Point2D (const Point2D &arg);

    Point2D& operator = (const Point2D &arg);
    Point2D operator - (const Point2D &arg);
    Point2D& operator -= (const Point2D &arg);
    bool operator < (const Point2D &arg);

    int getX () {return x;}
    int getY () {return y;}

protected:
    int x;
    int y;
};

#endif // POINT2D_H
