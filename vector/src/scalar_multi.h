//bottom up method
#include "math_vector.h"

//return array
//parameter are: n-dimensional vector(v[]), a real number
double* scalarMultiple(double v[], int dim, double a){
    if(dim < 0){
        //jump out this function
        throw std::string("undefined.");
    }
    
    //Because array size changing, so we use "new" to catch a memory space
    //new一個長度為dim的double array，目的是為了避免去改動到從外面傳進來的v[]
    double *u = new double[dim];   

    //this is wrong code, we can't put dynamic value into [], it need a predefined value to put inside []
    //double u[dim];   

    for(int i = 0; i < dim; i++){
        u[i] = v[i] * a;
    }
    return u;   //回傳一個指向長度為dim的double array
}


//Overloading
MathVector scalarMultiple(MathVector mv, double a){ //傳入mv(物件)，copy constructor被呼叫了，function內外的世界是分開來的
    double *u = new double[mv.dimension()];   
    for(int i = 0; i < mv.dimension(); i++){
        u[i] = mv.at(i) * a;
    }
    MathVector result(mv.dimension(), u);  
    return result;   //copy of result is returned
}
//Copy constructor不只在呼叫物件，甚至是回傳物件時都會呼叫到。