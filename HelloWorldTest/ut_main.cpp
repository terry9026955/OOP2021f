#include <gtest/gtest.h>
#include "HelloWorld.h"

TEST(HELLOWORLD, PrintHello){
    string output = printHello();
    string compare = "Hello world\n";
    ASSERT_EQ(output, compare);
}

int main(int argc,char **argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}