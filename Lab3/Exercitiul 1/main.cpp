#include <iostream>
#include "Math.h"
using namespace std;
int main()
{
    
    cout << Math::Add(2, 3)<<endl;
    cout << Math::Add(2, 3, 4)<<endl;
    cout << Math::Add(2.5, 3.5)<<endl;
    cout << Math::Add(2.3, 2.5, 2.2)<<endl;
    cout << Math::Mul(2, 3)<<endl;
    cout << Math::Mul(2, 3, 4)<<endl;
    cout << Math::Mul(2.5, 2.2)<<endl;
    cout << Math::Mul(2.5, 2.5, 4.2)<<endl;
    cout << Math::Add(3, 1, 2, 3)<<endl;
    cout << Math::Add("calin,tudor si nati", "sunt praf");

}
