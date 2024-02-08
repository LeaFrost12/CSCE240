/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/
#ifndef HEADERS_TRIANGLE_H_
#define HEADERS_TRIANGLE_H_

#include "Shape.h"

class Triangle : public Shape 
{
protected:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3)
    {
        setDimensions(s1, s2, s3);
        calculateArea();
        calculatePerimeter();
        findError();
    }

    void setDimensions(double s1, double s2, double s3);

    void calculateArea();

    void calculatePerimeter();

    void findError();


};
#endif