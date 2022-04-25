#include "../src/scalar_multi.h"

TEST(Vector, Scalar){   
    double v[2] = {3, 4};
    int dim = 2;
    int a = 3.0;    //real number
    double* result = scalarMultiple(v, dim, a); //*也是array的初始位址
    ASSERT_NEAR(9.0, result[0], 0.001);  //外界處理，把result當成一個double array來處理
    ASSERT_NEAR(12.0, result[1], 0.001);
}

TEST(Vector, ScalarException){   
    double v[2] = {3, 4};
    int dim = -1;
    int a = 3.0;    //real number
    ASSERT_THROW(scalarMultiple(v, dim, a), std::string);  //給錯的數值，他會throw
}