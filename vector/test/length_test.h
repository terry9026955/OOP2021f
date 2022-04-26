#include "../src/length.h"


                                            //  ASSERT意思就是說條件不成立就停掉
                                            //  EXPECT意思就是說"希望"你是TRUE，但FALSE的話也不會怎麼樣~

TEST(Vector, Length){                       //  Vector這個大test case集合裡面的Length(名稱)，兩個參數皆是自己定義的
    double v[2] = {3, 4};
    int len = 2;
    double result = length(v, len);
    ASSERT_NEAR(5.0, result, 0.001);        //  檢查double，參數(結果, 測試, 偏差多少內都OK)
                                            //  通常用ASSERT_EQ是檢查int數值或string
}

//  用Overloading的那個方法來測試
TEST(Vector, MathVectorLength){   
    double v[2] = {3, 4};
    int len = 2;
    MathVector mv(len, v);
    double result = length(mv);             //  只要有物件做複製的動作，就要寫copy constructor
    ASSERT_NEAR(5.0, result, 0.001);  
}

                                            /*
                                                在length_test.h的這個mv，與作為length()參數時傳進function後的v是兩個不同的東西
                                                傳進function後叫做v，而外面(mv)與裡面(v)用的是不同的記憶體空間
                                                這兩個都是物件(Object)，參數傳進來其實是做了copy，所以你在function裡面改不會影響到外面結果
                                                系統自動會copy這個mv物件進來，這沒問題，
                                                要擔心的地方是因為我建構物件的參數有double*，它做了new這件事情導致會有double free的問題!

                                                原本的外面mv中的double*是指向外面的一個array空間，
                                                mv作為參數傳進來之後，連同它本來的double*也一起copy進來，
                                                而我裡面這個物件v的double*指向的地方是外面空間那個呀!
                                                double array沒來(沒幫我複製進來)，系統幫我做的copy根本不是我想要的!
                                                上述這樣的行為，就稱為"Copy Constructor"。

                                                要是我沒在class中定義好Copy Constructor，那他就會呼叫到Default Copy Constructor，
                                                後者意思是，記憶體空間內容複製一份樣的，不管你裡面的new操作(跟一般傳int一樣的概念)。

                                                為什麼會出現"Double Free"?
                                                外面mv這個物件要被Deconstructor掉的時候會呼叫一次free()，
                                                這時外面的那個double array就變null pointer了。
                                                而裡面的v這個物件呼叫Deconstructor的時候也會呼叫一次free()，
                                                因為裡外的v跟mv的double*參數都指向同一個double array空間，
                                                因此這是對同一個空間去做了兩次free()!
                                                沒辦法對同一個空間做兩次free()，因此出現這個問題。
                                            */