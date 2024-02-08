/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/

#include "../headers/Circle.h"
#define _USE_MATH_DEFINES
#include <math.h>

void Circle::setDimensions(double r)
{
    radius = r;
}

void Circle::calculateArea()
{
    area = radius*radius * M_PI;
}

void Circle::calculatePerimeter()
{
    perimeter = 2*M_PI*radius;
}

void Circle::findError()
{
    if(radius == 0)
    {
        errorMessage = "Not enough information to calculate";
    }
}