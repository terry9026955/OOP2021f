#include <iostream>
#include "length.h"
//#include "scalar_multi.h"


int main(){
    double v[2] = {3, 4};
    int len = 2;
    double result = length(v, len);
    std::cout << result << std::endl;
    return 0;
}

/*
int main(){
    double v[2] = {3, 4};
    int len = 2;
    double a = 3.0;
    double* result = scalarMultiply(v, len, a);
    std::cout << result[0] << std::endl;
    std::cout << result[1] << std::endl;
    return 0;
}
*/