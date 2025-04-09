#include <iostream>
#include "Tree.h"

float operator"" _Kelvin(long double Celsius) {
    return static_cast<float>(Celsius - 273.15);
}

float operator"" _Fahrenheit(long double Celsius) {
    return static_cast<float>((Celsius - 32) / 1.8);
}
using namespace std;
int main() {

    float a = 300.0_Kelvin;
    float b = 120.0_Fahrenheit;

    cout << "300K = " << a << 'C' << endl << "120F = " << b << 'C' << endl;


    Tree<int> copac;
    copac.add_node(nullptr, 1);
    copac.add_node(copac.root, 4);
    copac.add_node(copac.root, 3);
    copac.add_node(copac.root, 2);
    copac.add_node(copac.find_node(4), 5);
    copac.add_node(copac.find_node(5), 6);
    copac.add_node(copac.find_node(5), 7);

    copac.printChildren(copac.root);

    copac.sort(copac.root, compara);

    copac.printChildren(copac.root);

    copac.find(8);

    copac.printTree(copac.root);
    
    return 0;
}
