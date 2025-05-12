#define _CRT_SECURE_NO_WARNINGS 
#include <cstring>
#include <stdlib.h>
#include <cstdarg>	
#include "Math.h"


int Math::Add(int x, int y)
{
	return x + y;
}

int Math::Add(int x, int y, int z)
{
	return x + y + z;
}
int Math::Add(double x, double y)
{
	return x + y;
}
int Math::Add(double x, double y, double z)
{
	return x + y + z;
}
int Math::Mul(int x, int y)
{
	return x * y;
}
int Math::Mul(int x, int y, int z)
{
	return x * y * z;

}
int Math::Mul(double x, double y)
{
	return x * y;
}
int Math::Mul(double x, double y, double z)
{
	return x * y * z;
}
int Math::Add(int count, ...)
{
	va_list p;
	va_start(p, count);
	int rez = 0;
	while (count)
	{
		int nr = va_arg(p, int);
		rez = rez + nr;
		count--;
	}
	va_end(p);
	return rez;
}

char* Math::Add(const char* a, const char* b)
{
	char* s= (char*) malloc(strlen(a)+strlen(b)+1);
	*s = '\0';
	strcat(s, a);
	strcat(s, b);
	
	return s;
}
