
#include <iostream>

using namespace std;

void swapNumbersReference(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swapNumbersPointers(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 2;
    int b = 3;
    swapNumbersReference(a, b);
    cout << a << endl;
    cout << b << endl;

    int x = 10;
    int y = 20;
    swapNumbersPointers(&x, &y);
    cout << x << endl;
    cout << y << endl;
}