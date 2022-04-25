//bottom up method

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