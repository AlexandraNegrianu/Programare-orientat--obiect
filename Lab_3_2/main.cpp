#include <iostream>
#include "Canvas.h"
using namespace std;

int main() {

	Canvas c(50, 50);
	c.DrawCircle(30, 30, 5, '*');
	c.FillCircle(30, 30, 5, 'k');
	c.DrawRect(20, 20, 30, 30, '#');
    c.FillRect(20, 20, 30, 30, 'i');
    c.DrawLine(1, 4, 10, 15, '+');
	c.SetPoint(10, 45, 'y');
	c.Print();

	return 0;
}
