#include <iostream>
#include <cstring>
#include "Canvas.h"
using namespace std;
int main()
{
	Canvas foaie1(100, 100);
	foaie1.DrawCircle(50, 50, 10, 'a');
	
	foaie1.Clear();
	
	foaie1.DrawCircle(40, 30, 5, 'a');
	foaie1.FillCircle(40, 50, 5, 'a');
	foaie1.DrawRect(10,60 , 30, 80, 'a');
	foaie1.FillRect(10, 20, 30, 40, 'a');
	foaie1.SetPoint(40, 80, 'a');
	foaie1.DrawLine(0, 20, 20, 0, 'a');
	foaie1.Print();

}
