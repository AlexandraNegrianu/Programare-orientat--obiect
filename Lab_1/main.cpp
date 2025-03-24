#include <iostream>
#include "Math.h"
using namespace std;

int main() {

    Math mate;
    int x1, x2, x3;
    double x11, x22, x33;
    char a[10], b[10];

    cin >> x1 >> x2 >> x3 >> x11 >> x22 >> x33;
    cin.get(a, 10);
    cin.get(b, 10);
    cout << a << " " << b;

    cout << mate.Add(x1, x2) <<" " << mate.Add(x1, x2, x3) <<" "<< mate.Add(x11, x22) <<" "<< mate.Add(x11, x22, x33)<<endl;
    cout << mate.Mul(x1, x2) <<" "<< mate.Mul(x1, x2, x3) <<" "<< mate.Mul(x11, x22) <<" "<< mate.Mul(x11, x22, x33)<<endl;
    cout << mate.Add(a, b)<<endl;
    cout << mate.Add(4, 1,2,3,4);
    
    return 0;
}