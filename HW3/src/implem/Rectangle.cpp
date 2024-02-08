/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/
#include "../headers/Rectangle.h"

void Rectangle::setDimensions(double l, double w)
{
    length = l;
    width = w;
}

void Rectangle::calculateArea()
{
    area = length * width;
}

void Rectangle::calculatePerimeter()
{
    perimeter = 2 * (length+width);
}

void Rectangle::findError()
{
    if(length==0 || width == 0)
    {
        errorMessage = "Not enough information to calculate";
    }
}