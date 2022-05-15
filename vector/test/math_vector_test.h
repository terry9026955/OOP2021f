#include "../src/math_vector.h"
//#include "../src/add.h"                           // 要確定呼叫到的是我要的函式

TEST(Vector, MathVector){
    int dim = 2;
    double v[2] = {3, 4};
    //宣告物件
    MathVector mv(dim, v);
    ASSERT_NEAR(5, mv.length(), 0.01);              //  (期望，statement, 差距)
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
    ASSERT_THROW(mv.setIndex(2, 4), std::string);    // 出錯的function擺第一個  
}

TEST(Vector, AddMathVector){   
    double v[2] = {3, 4};
    double v1[2] = {5, 6};
    int dim = 2;
    MathVector mv(dim, v);
    MathVector mv1(dim, v1);

    MathVector result = mv + mv1;    // 原本是寫成 add(mv, mv1)          
    ASSERT_NEAR(8.0, result.at(0), 0.001);  
    ASSERT_NEAR(10.0, result.at(1), 0.001);
    ASSERT_EQ(2, result.dimension());
}

/*
TEST(Vector, AddMathVectorDiff){   
    double v[2] = {3, 4};
    double v1[3] = {5, 6, 7};
    int dim = 2;
    int dim1 = 3;
    MathVector mv(dim, v);
    MathVector mv1(dim1, v1);

    MathVector result = add(mv, mv1);              
    ASSERT_NEAR(8.0, result.at(0), 0.001);  
    ASSERT_NEAR(10.0, result.at(1), 0.001);
    ASSERT_NEAR(7.0, result.at(2), 0.001);
    ASSERT_EQ(2, result.dimension());
}
*/