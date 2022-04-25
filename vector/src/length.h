#include <cmath>

double length(double v[], int dim){
    double result = 0;
    for(int i = 0; i < dim; i++){
        result += v[i] * v[i];
    }
    result = sqrt(result);
    return result;
}