#include <iostream> 
#include <cstdarg>
#include "Math.h"
using namespace std;

 int Math::Add(int x, int y) {
	return x + y;
}

 int Math::Add(int x, int y, int z) {
	return x + y + z;
}

 int Math::Add(double x, double y) {
	return x + y;
}

 int Math::Math::Add(double x, double y, double z) {
	return x + y + z;
}

 int Math::Mul(int x, int y) {
	return x * y;
}

 int Math::Mul(int x, int y, int z) {
	return x * y * z;
}

 int Math::Mul(double x, double y) {
	return x * y;
}

 int Math::Mul(double x, double y, double z) {
	return x * y * z;
}

 int Math::Add(int count, ...)
 {
	 va_list args;          // Declaram o variabilă de tip va_list
	 va_start(args, count); // Inițializăm lista de argumente variabile

	 int sum = 0;
	 for (int i = 0; i < count; i++)
	 {
		 sum += va_arg(args, int); // Extragem următorul argument de tip int
	 }

///	 va_end(args); // Încheiem utilizarea listei de argumente
	 return sum;
 }

 char* Math::Add(const char* a, const char* b){
	
	 if (a == nullptr || b == nullptr)
		 return nullptr;
	 
	 else {
		 int lungimeA = strlen(a);
		 int lungimeB = strlen(b);
		 char* rezultat = new char[lungimeA + lungimeB + 1]; //+1 pentru \0
		 strcpy(rezultat, a);
		 strcat(rezultat, b);
		 return rezultat;
	 }

}