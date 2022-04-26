//  Bottom up method
#include "math_vector.h"

//  return array
double* scalarMultiply(double v[], int dim, double a){  //  parameter are: n-dimensional vector(v[]), a real number
    if(dim < 0){
        
        throw std::string("undefined.");                //  jump out this function
    }
    
    
    double *u = new double[dim];                        //  Because array size changing, so we use "new" to catch a memory space
                                                        //  new一個長度為dim的double array，目的是為了避免去改動到從外面傳進來的v[]

                                                        /*
                                                            this is wrong code, we can't put dynamic value into [], it need a predefined value to put inside []
                                                            double u[dim];   (X)
                                                        */
    for(int i = 0; i < dim; i++){
        u[i] = v[i] * a;
    }
    return u;                                           //  回傳一個指向長度為dim的double array
}


//  Overloading
MathVector scalarMultiply(MathVector mv, double a){     //  傳入mv(物件)，copy constructor被呼叫了，function內外的世界是分開來的
    double *u = new double[mv.dimension()];   
    for(int i = 0; i < mv.dimension(); i++){
        u[i] = mv.at(i) * a;
    }
    MathVector result(mv.dimension(), u);  
    return result;                                      //  copy of result is returned，but there is a copy ellision will avoid this return copy
                                                        //  其實Copy constructor不只在呼叫物件，甚至是回傳物件時都會呼叫到。
}                                                       
                                                        

//  Operator overloading
MathVector operator*(double a, MathVector mv){          //  當看到一個double和一個MathVector相乘時，會做以下的行為
    return scalarMultiply(mv, a);
}
