#ifndef ADD_H
#define ADD_H
#include "math_vector.h"

//  先定義add function
MathVector add(MathVector u, MathVector v){ // 這邊好像也要加上const, &
    double w[u.dimension()];                
    for(int i = 0; i < u.dimension(); i++){ 
        w[i] = u.at(i) + v.at(i);
    }
    MathVector result(u.dimension(), w);    
    return result;
}
//  operator overloading of '+'
MathVector operator+ (const MathVector &u, const MathVector &v){
    return add(u, v);
}


#endif 