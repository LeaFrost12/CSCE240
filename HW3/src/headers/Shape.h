/*
Lea Frost
CSCE 240
HW 3
2/7/2024
*/
#ifndef HEADERS_SHAPE_H_
#define HEADERS_SHAPE_H_

#include <string>
using namespace std;

class Shape {
protected:
    double area, perimeter;
    string errorMessage;

public:

    double getArea();
    double getPerimeter();
    string getErrorMessage(); 

};
#endif