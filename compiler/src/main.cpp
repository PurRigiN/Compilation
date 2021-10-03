
#include "FBGenerateCode/lex.yy.c"
#include "FBGenerateCode/parser.tab.c"
#include "Token/Token.h"
#include "stdio.h"
#include <iostream>
using namespace std;

/**
 * @brief 主函数
 * 
 * @param argc 命令行参数个数
 * @param argv 命令行各个参数
 * @return int 返回值懂的都懂
 */
int main(int argc, char ** argv)
{
    if ( argc > 1 ) 
    {
        if (! (yyin = fopen(argv[1], "r" ) ))
        {
            perror(argv[1]);
            return 1;
        }
        printf("[I]>>>Read data from file:%s\n", argv[1]);
        cout<<"C++TestSuccess!\n";
        return yyparse();
    }
    else
    {
        printf("[I]>>>Read data from stdin.\n");
    }

}