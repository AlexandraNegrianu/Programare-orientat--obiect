#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Canvas.h"

using namespace std;
Canvas::Canvas(int width, int height)
{
	this->matrice = new char* [height];

	for (int i = 0; i < height; i++)
		this->matrice[i] = new char[width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++)
			this->matrice[i][j] = ' ';
		this->matrice[i][width] = '\0';
	}
	this->w = width;
	this->h = height;

}
void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int x1 = x;
	int y1 = y + ray;

	for (int i = x1 - ray / 2; i <= x1 + ray / 2; i++)
		matrice[i][y1] = ch;


	int x2 = x - ray;
	int y2 = y;

	for (int i = y2 - ray / 2; i <= y2 + ray / 2; i++)
		matrice[x2][i] = ch;

	int x3 = x;
	int y3 = y - ray;

	for (int i = x3 - ray / 2; i <= x3 + ray / 2; i++)
		matrice[i][y3] = ch;

	int x4 = x + ray;
	int y4 = y;

	for (int i = y4 - ray / 2; i <= y4 + ray / 2; i++)
		matrice[x4][i] = ch;



	for (int i = x1 - ray / 2, j = y1; i >= x2 && j > y2; i--, j--)
		matrice[i][j] = ch;
	for (int i = x2, j = y2 - ray / 2; i <= x3 && j > y3; i++, j--)
		matrice[i][j] = ch;
	for (int i = x3 + ray / 2, j = y3; i <= x4 && j <= y4; i++, j++)
		matrice[i][j] = ch;

	for (int i = x4, j = y4 + ray / 2; i >= x1 && j <= y1; i--, j++)
		matrice[i][j] = ch;

	

}
void Canvas::Print()
{
	for (int i = 0; i < h; i++)
		cout << this->matrice[i] << endl;
}
void Canvas::Clear()
{
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			matrice[i][j] = ' ';
}
void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int st = x - ray / 2;
	int dr = x + ray / 2;
	int y3 = y - ray;
	int y1 = y + ray;
	
	for (int j = 1; j <= ray; j++) {
		for (int i = st; i <= dr; i++) 
		{
			matrice[i][y3] = ch;
			matrice[i][y1] = ch;
		}
		if(st > x - ray)
			st--;
		if(dr<x+ray)
			dr++;

		y3++;
		y1--;
	}
	
	for (int i = x - ray; i <= x + ray; i++)
		matrice[i][y] = ch;

}
void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
	{
		matrice[i][top] = ch;
		matrice[i][bottom] = ch;
	}
	for (int i = top; i <= bottom; i++)
	{
		matrice[left][i] = ch;
		matrice[right][i] = ch;
	}
}
void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = left; i <= right; i++)
		for (int j = top; j <= bottom; j++)
			matrice[i][j] = ch;
}
void Canvas::SetPoint(int x, int y, char ch)
{
	matrice[x][y] = ch;
}
void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int maxi1 = 0, maxi2 = 0;
	if (x1 > x2)
		maxi1 = x1;
	else
		maxi1 = x2;
	if (y1 > y2)
		maxi2 = y1;
	else
		maxi2 = y2;

	for (int i = (x1 + x2) - maxi1; i <= maxi1; i++)
		for (int j = (y1 + y2) - maxi2; j <= maxi2; j++)
			if ((j - y1) * (x2 - x1) == (y2 - y1) * (i - x1))
				matrice[i][j] = ch;

}
