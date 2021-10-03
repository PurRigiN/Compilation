### 代码作用
- 这是一个能够识别声明变量语句的程序
    - .l文件和.y文件都写了
- 这个代码用来测试他们之间怎么工作的
- 发现flex和bison之间，不是先全部识别完token再进行规约，而是交替着的，这点要注意

### 使用方法
cd 到该目录下在命令行使用如下命令
- `make` :编译文件
- `make clean` :清理文件
- `make run` :运行文件。将使用编译好的文件，读取testcase.sy文件中的代码，进行分析
- `make lex.yy.c` :先生成y.tab.c再生成lex.yy.c
- `make y.tab.c` :单独生成y.tab.c