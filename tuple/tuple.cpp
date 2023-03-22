#include "tuple.h"
#include <iostream>

int main(){
    tuple<int, char, double> t(1, 'a', 0.0);
    std::cout << t << std::endl;
    auto it = t;
    std::cout << it << std::endl;
    return 0;
}