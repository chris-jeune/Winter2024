#ifndef POINT_H_
#define POINT_H_

class Point{
private:
    int x;
    int y;

public:
    Point(int,int);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
};


#endif // POINT_H_