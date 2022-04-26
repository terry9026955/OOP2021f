#include <cmath>
#include "math_vector.h"

double length(double v[], int dim){
    double result = 0;
    for(int i = 0; i < dim; i++){
        result += v[i] * v[i];
    }
    result = sqrt(result);
    return result;
}

//  Overloading(多載): length function is overloaded
double length(MathVector v){
    double result = 0;
    for(int i = 0; i < v.dimension(); i++){
        result += v.at(i) * v.at(i);
    }
    result = sqrt(result);
    return result;
}