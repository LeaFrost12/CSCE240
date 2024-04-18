/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/
#ifndef HEADERS_CIRCLE_H_
#define HEADERS_CIRCLE_H_

#include "Shape.h"

class Circle : public Shape 
{
protected:
    double radius;

public:
    Circle(double r)
    {
        setDimensions(r);
        calculateArea();
        calculatePerimeter();
    }

    void setDimensions(double r);

    void calculateArea();

    void calculatePerimeter();

    void findError();
};
#endif