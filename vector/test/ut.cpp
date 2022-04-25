#include <gtest/gtest.h>  
#include "length_test.h"
#include "scalar_multi_test.h"
#include "math_vector_test.h"

//有新增.h檔就要include進來

int main(int argc, char *argv[]){
    testing::InitGoogleTest(&argc, argv);   //也可以寫using namespace testing，就不用前面打::了
    return RUN_ALL_TESTS();
    //盡量把每一包test case放在不同.h檔裡面
}

