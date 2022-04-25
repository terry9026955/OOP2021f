//class method
#ifndef MATH_VECTOR_H   //檢查有沒有人定義過這個label
#define MATH_VECTOR_H   //沒有的話我現在就定義它
//下次在編譯的過程中如果又再進來一次(因為label已經定義過了)
//則我這邊ifndef到endif這段就不會執行，因此不會出現重複define的問題

#include <cmath>

class MathVector{
private:
    int _dim;
    double* _vec;  
public:
    //Default constructor
    MathVector(){

    }
    //Constructor
    MathVector(int dim, double* v){ //其實這邊v存的是一個address，其指向一個內容為{3, 4}的array
        _dim = dim;
        _vec = new double[dim];

        

       //把傳進來的v的內容複製到_vec裡面
       for(int i = 0; i < dim; i++){
           _vec[i] = v[i];
       }
    }

    //Member function
    double length(){
        double result = 0;
        for(int i = 0; i < _dim; i++){
            result += _vec[i] * _vec[i];
        }
        result = sqrt(result);
        return result;
    }

    //Getter
    double at(int index){
        return _vec[index];
    }

    //Setter
    void setIndex(int index, double input){
        if(index >= _dim){  //超出長度的話
            throw std::string("undefined.");
        }
        _vec[index] = input;
    } 
};

#endif 

/*
    這個寫法錯誤!!!!!
    外面世界的v是指向一個同樣在外界的{3, 4} array，
    而我這邊如果讓裡面世界的_vec指向外面世界v所指向的外界資料，
    這對物件導向來說是不能接受的事情!!!!!
            
    _vec = v;   (X)
            
    你如果寫的是function，可以故意從裡面的function去更改外面世界的記憶體內容，
    但class不能這樣搞，因為class擁有的記憶體空間是完全屬於自己的，
    在設計上，你不可以有一個class，他所擁有的記憶體空間是屬於外面的世界!
    所以在寫class的時候，只要你有處理到pointer(maybe指向array)，就一定要非常小心!

    所以我應該做的是，在初始化的過程中，跟他說我要準備一塊新的記憶體位址
    把外面世界的那個array做一個複製的動作到我裡面世界來，
    那我就會正確的指向我裡面世界的那個array了，裡外世界就毫無相關了。
*/

//假如有個function在很多地方被define過，會有multi definition問題
//通常是因為自己定義的.h檔在他編譯的過程中、在不同的地方被重複拉進來
//所以他會跟你說我找到兩個某function的定義，他會不知道要用哪一個
//所以每個.h檔前面都要加上這個保護
//#ifndef後面加上的那個label沒有被定義過的時候，我才能執行下面的內容
//標籤通通大寫
