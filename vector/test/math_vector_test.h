#include "../src/math_vector.h"

TEST(Vector, MathVector){
    int dim = 2;
    double v[2] = {3, 4};
    //宣告物件
    MathVector mv(dim, v);
    ASSERT_NEAR(5, mv.length(), 0.01);  //(期望，statement, 差距)
}

TEST(Vector, MathVectorIndex){
    int dim = 2;
    double v[2] = {3, 4};
    MathVector mv(dim, v);
    ASSERT_NEAR(3, mv.at(0), 0.01);  
    ASSERT_NEAR(4, mv.at(1), 0.01);
}

TEST(Vector, MathVectorSet){
    int dim = 2;
    double v[2] = {3, 4};
    MathVector mv(dim, v);
    
    //做互換
    mv.setIndex(0, 4);
    mv.setIndex(1, 3);

    ASSERT_NEAR(4, mv.at(0), 0.01);  
    ASSERT_NEAR(3, mv.at(1), 0.01);
}

TEST(Vector, MathVectorSetException){
    int dim = 2;
    double v[2] = {3, 4};
    MathVector mv(dim, v);
    ASSERT_THROW(mv.setIndex(2, 4), std::string);    //出錯的function擺第一個  
}
