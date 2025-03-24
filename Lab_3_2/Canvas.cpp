#include <iostream>
#include "Canvas.h"
using namespace std;	

Canvas::Canvas(int width, int height)
{
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			a[i][j] = ' '; //creează un canvas gol
}

void Canvas::DrawCircle(int x, int y, int ray, char ch)
{
	int centruX = x + ray, centruY = y + ray; //centruY și centruX reprezintă centrul cercului

	for (int i = x;i <= x + 2 * ray;i++)
		for (int j = y;j <= y + 2 * ray;j++)
			if (abs((i - centruX) * (i - centruX) + (j - centruY) * (j - centruY) - ray * ray) <= ray / 2) //Calculează ecuația cercului în coordonatele carteziene și o desenează folosind caracterul dat, adică ch. Calculează pătratul distanței de la punctul (i, j) la centrul cercului. Dacă este îndeplinită condiția înseamnă că punctul este înăuntrul cercului
				a[i][j] = ch;

}

void Canvas::FillCircle(int x, int y, int ray, char ch)
{
	int centruX = x + ray, centruY = y + ray;
	for (int i = x;i <= x + 2 * ray;i++)
		for (int j = y;j <= y + 2 * ray;j++)
			if ((i - centruX) * (i - centruX) + (j - centruY) * (j - centruY) <= ray  * ray )
				a[i][j] = ch;
}

void Canvas::DrawRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top;i <= bottom;i++) {
		// desenează laturile dreptunghiului, adica marginea de pe verticală
		a[i][left] = ch;
		a[i][right] = ch;
	}
	for (int i = left;i <= right;i++) {
		// desenează laturile dreptunghiului, adica marginea de pe orizontală
		a[top][i] = ch;
		a[bottom][i] = ch;
	}
}

void Canvas::FillRect(int left, int top, int right, int bottom, char ch)
{
	for (int i = top+1;i < bottom;i++)
		for (int j = left+1;j <right;j++)
			a[i][j] = ch; //umple interiorul dreptunghiului cu caracterul ch
}

void Canvas::SetPoint(int x, int y, char ch)
{
	//setează un punct ch la coordonatele x și y 
	a[x][y] = ch;
}

void Canvas::DrawLine(int x1, int y1, int x2, int y2, char ch)
{
	int dx = abs(x2 - x1), dy = -abs(y2 - y1); //reprezintă diferența dintre coordonatele x și y ale punctelor finale și de start
	int sx = x1 < x2 ? 1 : -1, sy = y1 < y2 ? 1 : -1; //determină direcția în care se va desena linia
	int eroare = dx + dy, eroare2; //calculează eroarea care va fi folosită pentru a determina dacă următorul punct va fi pe orizontală sau pe verticală
	while (true) {
		a[x1][y1] = ch; //desenează punctul
		if (x1 == x2 && y1 == y2) break; //daca am ajuns la punctul final, ne oprim
		eroare2 = 2 * eroare; //calculăm eroarea
		if (eroare2 >= dy) { //dacă eroarea este mai mare sau egală cu dy, atunci următorul punct va fi pe orizontală
			eroare += dy;
			x1 += sx;
		}
		if (eroare2 <= dx) { //dacă eroarea este mai mică sau egală cu dx, atunci următorul punct va fi pe verticală
			eroare += dx;
			y1 += sy;
		}
}
}

void Canvas::Print()
{
	//afișează canvasul
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++)
			cout << a[i][j]<<' ';
		cout << endl;
	}
}

void Canvas::Clear()
{
	//golește canvasul
	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++)
			a[i][j] = ' ';
}

/*
Algoritmul lui Bresenham

1. Se începe de la un punct inițial(x1, y1)
2. Se dorește să se ajungă la punctul final(x2, y2)
3. Se calculează diferența dintre x2 și x1 și y2 și y1
4. Se determină direcția în care se va desena linia : sx și sy
5. Se calculează eroarea care va fi folosită pentru a determina dacă următorul punct va fi pe orizontală sau pe verticală
6. Se desenează punctul
7. Se verifică dacă am ajuns la punctul final
8. Se calculează eroarea
9. Dacă eroarea este mai mare sau egală cu dy, atunci următorul punct va fi pe orizontală
10. Dacă eroarea este mai mică sau egală cu dx, atunci următorul punct va fi pe verticală
11. Se repetă până când se ajunge la punctul final
*/