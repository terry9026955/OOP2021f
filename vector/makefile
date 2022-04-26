# 有makefile就能告訴compiler說要怎麼去編譯
# 這邊教了 .PHONY, all, clean



# 保留字"all"要加上.PHONY
# 看到有all的話會先來執行這個all指定的target，否則makefile只會執行第一個target的內容
# all寫在最上面，clean寫在最下面
.PHONY: all
all: bin/test



# 同一個程式有兩個main()，要執行誰、要如何編譯，就是得告訴compiler
# 為了讓vector.cpp裡面的main()跑起來
# 吃的檔案是src/vector.cpp，輸出為bin/vector，不需要加上後面兩個是因為他是正常檔案而非gtest的檔案
bin/vector: src/vector.cpp src/length.h
	g++ src/vector.cpp -o bin/vector



# target為bin/test，跑test的先決條件為test/ut.cpp(讓main跑起來)、test/length_test.h(用的到)
# bin target加上去做第三個先決條件，意思就是說無論你在幹嘛之前，你就先把bin這個folder創出來
# 編譯test/ut.cpp成可執行的檔案叫作bin/test，後面吃(-lgtest -lpthread)這兩個東西
bin/test: test/ut.cpp test/length_test.h bin
	g++ test/ut.cpp -o bin/ut_all -lgtest -lpthread
# -fno-elide-constructors -g



# 可能會跟檔案名稱重複的話就加上.PHONY
# 代表我後面這個是'target的名稱'而不是一個'檔案'，才不會因名稱跟外面folder一樣而搞混
# makefile就會去compile這個target，而不是那個同名的檔案
# 1. 創建一個bin的folder， 2. 或是確保bin folder會在那邊(選後者)
# -p 是當我已經有bin這個資料夾存在時，我就不會再強制去創造了；反之就去創建
.PHONY: bin
bin:	
	mkdir -p bin



# 保留字"clean"要加上.PHONY
# " make clean "就是在make之前先把你想刪除的檔案清除，要刪誰自己去指定
# -f 是強制的意思，要把bin裡面的檔案全部刪掉
.PHONY: clean
clean:
	rm -f bin/*



# 記得cd到vector裡面做編譯!
# make完之後到terminal打上:bin/ut_all



# 題外話:
# sudo(最高權限), rm(刪除), -f(強制), -r(recursive, 全部)
# 在電腦的root去下: " sudo rm -rf / " 指令，他會把你電腦全部清乾淨
# sudo rm 很危險，盡量別用!!!