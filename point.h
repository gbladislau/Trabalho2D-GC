#ifndef POINT_H
#define POINT_H 

class Point2D
{
private:
    double x = 0.0;
    double y = 0.0;

public:
    Point2D(double x, double y){
        this->x = x;
        this->y = y;
    }
    Point2D(){
        this->x = 0.0;
        this->y = 0.0;
    }

    void setX(double x){this->x = x;}
    void setY(double y){this->y = y;}
    double getX(){ return this->x; }
    double getY(){ return this->y; }

    void RotateZ(double angle);

    void Translate (double dx, double dy);
    float AngleBeetwen(Point2D p1, Point2D p2);
};
#endif // !POINT_H