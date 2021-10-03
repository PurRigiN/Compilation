%{
#include <stdio.h>
#include <iostream>
#include <string>
#define YYSTYPE char *
void yyerror(const char* msg) {}
void cout_test();
void cout_test2(char *);
using namespace std;
%}

%token T_identifier
%token T_int

%%

/*测试一下注释*/
CompUnit    :   Decl    { printf("Reducing CompUnit\n");  cout_test();}
            ;

Decl        :   VarDecl { printf("Reducing Decl\n");  }
            ;

VarDecl     :   BType T_identifier ANIDEN ';'   { printf("T_identifier : %s\n", $2);cout_test2($2);printf("Reducing VarDecl\n"); }
            ;

BType       :   T_int                           { printf("Reducing BType\n"); }
            ;

ANIDEN      :   ',' T_identifier ANIDEN         { printf("T_identifier : %s\n", $2); printf("Reducing ANIDEN\n");}
            |                                   { /* empty */ }
            ;

%%

// int main() {
//     return yyparse();
// }
void cout_test()
{
    cout<<"Hello World"<<endl;
}

/*
 *这个函数我是用来测试能不能用string类
 *（如果不能用string的话我直接自杀
 *发现只要在语义规则的括号里传好参数就可以了
 *如果在函数定义的内部使用'$x'的写法就会报错
 *'$'的类型是char *
 */
void cout_test2(char * ch)
{
    string temp=ch;
    cout<<"---------\n"<<temp<<"\n------\n";
}