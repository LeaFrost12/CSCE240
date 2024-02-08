/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/
#include "../headers/Triangle.h"

void Triangle::setDimensions(double s1, double s2, double s3)
{
    side1 = s1;
    side2 = s2;
    side3 = s3;
}

void Triangle::calculateArea()
{
    double s = (side1 + side2 + side3)/2;
    area = sqrt(s*(s-side1)*(s-side2)*(s-side3));
}

void Triangle::calculatePerimeter()
{
    perimeter = side1 + side2 + side3;
}

void Triangle::findError()
{
    if(side1==0 || side2 == 0 || side3==0)
    {
        errorMessage = "Not enough information to calculate";
    }
}