#include <stdio.h>
#include <iostream>
#include <string>

#include "vector.hpp"

int main()
{
    Vector<int> x (4);
    cout << x(3) << endl;
    x(3) = 3;
    cout << x(3) << endl;
    return 0;
}
