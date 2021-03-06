# Compilation

### 介绍
- 这是一个我们小组参加编译系统大赛所完成的一个代码，但是由于时间的原因，后端功能极其不全，前端一些部分也没有使用一些良好的编程模式，仅供参考
- [原仓库](https://gitlab.com/PurRigiN/compilation)

### 代码梳理
- 目标
  - 总而言之，就是将规定的语言，翻译成目标平台汇编代码，具体要求可以查看第二届比赛[官网](https://compiler.educg.net/)
- 环境
  - 这份代码应该能在通常的ubuntu系统上运行，当然前提是安装好一些必要工具，比如`g++`, `clang++`, `flex`, `bison`等
  - 而生成出来的汇编代码，则需要到指定平台才能运行
  - 运行命令可以查看下面的[makefile](#makefile)栏
  - 这份代码是C++语言，使用了`flex`和`bison`工具，在这次比赛里面，可以使用JAVA语言，在JAVA中也有各种前端代码生成工具，可以查找资料学习
- 前端
  - 使用了`flex`和`bison`工具生成部分代码
  - 我们小组在[自己动手写编译器](https://pandolia.net/tinyc/ch13_bison.html)这个网站里学习了这两个工具的使用
  - 学习这两个工具的使用后，尝试写了两个例子，在`Demo`分支里，有关于这两个工具使用的学习例子，建议到这个分支里查看，结合上面的网站学习
  - 再往后，我们根据比赛的输入要求，对Demo进行修改，尝试写出了一个能识别部分语句的代码，就是在`Demo`分支中的`compiler`文件夹的代码
  - 在那基础之上，我们补充完善各个语句，就能完成前端的识别
- 后端
  - 后端写得实在是差，只是单纯地遍历生成好的语法树，直接生成汇编代码，不建议查看学习


### makefile
- makefile的编写比较简单，学习后很容易理解`makefile`里面的各个命令做了什么，这里只列出各个命令的作用
- 需要cd到`makefile`所在目录才能执行以下命令
- 命令
  - `make`, `make build`: 编译出可执行文件`compiler`，在`obj`目录下
  - `make run`: 使用可执行文件`compiler`，读取`testcode/testcase.sy`代码文件，以生成汇编代码到`asm`文件夹下
  - `make debug`: 功能同make run，另外生成一些debug信息，比如输出字符串表示语法树，将输出的语法树字符串复制到上面的[网址](http://ironcreek.net/syntaxtree/)就能可视化（该网站有点缺陷，叶子节点不能为纯数字，否则无法显示）
  - `make clean`: 删除编译好的各个文件
  - `make lex`: 生成词法分析的代码
  - `make bison`: 读取`parser.y`文件，生成语法分析的代码
- `makefile`里面被注释的两个命令，是启动编写好的脚本，脚本作用是尝试使用可执行文件`compiler`，批量地编译各个测试代码，因为`compiler`功能不全，处理到一定程度会一定报错，所以注释掉了

## 心得

### PurRigiN
- 尽早尽早学完后端的知识，建议是能对一个简单的语言，用**正规的流程**，开发出一个编译器，之后再参加比赛
- 开发某个东西，于我而言，一个有用的办法是，先写出一个“麻雀虽小，五脏俱全”的样例，写完后再完善这个例子。先完整做完前面一个部分，再往后做的这种方法，实在是不好把握。

### sheryl
- PurRigiN说的对

### eason
- PurRigiN说的对

### 饮一盏岁月留香
- PurRigiN说的对