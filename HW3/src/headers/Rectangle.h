/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/
#ifndef HEADERS_RECTANGLE_H_
#define HEADERS_RECTANGLE_H_

#include "Shape.h"

class Rectangle : public Shape 
{
protected:
    double length, width;

public:
    Rectangle(double l, double w)
    {
        setDimensions(l,w);
        calculateArea();
        calculatePerimeter();
        findError();
    }

    void setDimensions(double l, double w);

    void calculateArea();

    void calculatePerimeter();

    void findError();
};
#endif // RECTANGLE_H_