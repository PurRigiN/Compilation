
// #include "FBGenerateCode/lex.yy.c"
#include "FBGenerateCode/parser.tab.h"
// #include "FBGenerateCode/parser.h"
#include "Token/Token.h"
#include "back/BackAnalyzer.h"
#include "stdio.h"
#include <iostream>
#include <fstream>
#include <string>
extern int debug ;
extern bool parserDebug;
extern FILE * yyin;
extern MyTree * CompUnitStartNode;
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
    char * objectDir;
    
    //读取各个参数，做准备工作
    for(int i=0;i<argc;i++)
    {
        string arguStr=string(argv[i]);
        //非'-'开头的参数
        if(arguStr.substr(0,1)!="-")
        {
            if (! (yyin = fopen(argv[i], "r" ) ))
            {
                perror(argv[i]);
                return 1;
            }
        }
        //'-'开头的参数
        else
        {
            if(arguStr=="-debug")
            {
                debug = 1;
                parserDebug=true;
                continue;
            }
            else if(arguStr=="-O1")
            {
                continue;
            }
            else if(arguStr=="-S")
            {
                continue;
            }
            else if(arguStr=="-o")
            {
                if(i+1<argc)
                {
                    fstream dataFile;
                    dataFile.open(string(argv[i+1]),ios::out);
                    if(dataFile)
                    {
                        dataFile.close();
                        objectDir=argv[i+1];
                        i++;
                        continue;
                    }
                    else
                    {
                        cout<<"Failed to open file:"<<string(argv[i+1])<<endl;
                        return 0;
                    }
                    
                }
                //无参数
                else
                {
                    cout<<"No para for option '-o'\n";
                    return 0;
                }
            }
        }
    }
    
    //开始分析
    int parseResult = yyparse();
    if (parseResult == 0){
        cout<<"Syntax analysis succeed!\n";
        if(debug==1)
            cout<<CompUnitStartNode->treeToString()<<endl;
        cout<<"Starting Back analysis.\n";
        BackAnalyzer analyzer(objectDir,CompUnitStartNode,parserDebug);
        bool ifBackSucc=analyzer.analyze();
        if(ifBackSucc)
            cout<<"Back analysis succeed!\n";
        else    
            cout<<"Back analysis failed.\n"<<endl;
        
        //----
        // string numberStr="0xf";
        // int number=strtol(numberStr.c_str(),nullptr,16);
        // if(number<=0xffff);
        // cout<<number<<endl;
        //----
        return 0;
    }
    else
    {
        cout<<"Syntax analysis failed.\n"<<endl;
        return 0;
    }

    // if ( argc > 1 ) 
    // {
    //     if (! (yyin = fopen(argv[1], "r" ) ))
    //     {
    //         perror(argv[1]);
    //         return 1;
    //     }
    //     if ( argc > 2 && strcmp(argv[2],"-debug") == 0)
    //     {
    //         debug = 1;
    //         parserDebug=true;
    //     } 
    //     printf("[I]>>>Read data from file:%s\n", argv[1]);
    //     int parseResult = yyparse();
    //     if (parseResult == 0){
    //         cout<<"succeed!\n";
    //         if(debug==1)
    //             cout<<CompUnitStartNode->treeToString()<<endl;
    //     }
    //     else
    //     {
    //         cout<<"failed\n"<<endl;
    //     }
    // }
    // else
    // {
    //     printf("[I]>>>Read data from stdin.\n");
    // }

}