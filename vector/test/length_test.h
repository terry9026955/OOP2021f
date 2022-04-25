#include "../src/length.h"


//ASSERT意思就是說條件不成立就停掉
//EXPECT意思就是說"希望"你是TRUE，但FALSE的話也不會怎麼樣~

TEST(Vector, Length){   //Vector這個大test case集合裡面的Length(名稱)，兩個參數皆是自己定義的
    double v[2] = {3, 4};
    int len = 2;
    double result = length(v, len);
    ASSERT_NEAR(5.0, result, 0.001);  //檢查double，參數(結果, 測試, 偏差多少內都OK)
    //通常用ASSERT_EQ是檢查int數值或string
}