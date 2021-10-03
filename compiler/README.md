### 使用方法
cd 到该目录下在命令行使用如下命令
- `make` :编译文件
- `make clean` :清理文件
- `make run` :运行文件。将使用编译好的文件，读取testcase.sy文件中的代码，进行分析
- `make funtest`: 依次读取功能测试的样例运行
- `make pretest`: 依次读取性能测试的样例运行
- `make flex` :先生成y.tab.c再生成lex.yy.c
- `make bison` :单独生成y.tab.c
### fix: 刚拉下来的工程中没有FBGenerateCode文件夹和obj文件夹，直接make会报错，先运行:
- `make`
### feat: 将run分为run和run_debug  debug模式下词法分析会打印识别的token
- `make debug`
### feat: clean_all将obj文件夹和generate文件夹删除，重制工程后push
- `make clean`

### 调试方法
- 我上传了.vscode文件夹，`make`完成之后，直接按F5即可调试，无需打开指定的文件

