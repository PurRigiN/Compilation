%{
#include "../MyTree/MyTree.h"
#define YYSTYPE MyTree *
#include "../FBGenerateCode/parser.tab.h"
/* debug开关 */
int debug = 0;
/* 词法分析结束判断 */
static int end_file = 0;
/* 是否遇到错误 */
static int is_error = 0;
int column = 1;
int row = 1;
void log(char[]);
void logError(char[]);
%}
SINGAL_NOTE     ([/][/][^\n]*)
MULTI_NOTE      ([/][*](.|\n)*[*][/])
HEX_INTEGER     (0[xX][0-9a-fA-F]+)
LETTER          ([a-zA-Z_][a-zA-Z0-9_]*)
DIGIT           [0-9]
IDENT           {LETTER}({LETTER}|{DIGIT})*
KEYWORD         ("if"|"else"|"while"|"break"|"continue"|"return"|"int"|"void"|"const")
OPT             ([+]|[-]|[*]|[/])
RELOP           [<]|[<][=]|[>]|[>][=]|[=][=]|[!][=]
OCT_INTEGER     ([0][0-7][0-7]*)
DEC_INTEGER     ([1-9][0-9]*)|[0]
ERR_IDENT       ([0-9]+{IDENT}])
ERR_INTEGER     ([0][0-7]*[8-9]+[0-7]*)
STR             (\042[^\042\n]*\042)
%%
[\n]                { row++; column = 1;}
[ \t\r\a]+          { /* do nothing with spaces */ }
{MULTI_NOTE}        {log(yytext);/*yylval = new MyTree(string(strdup(yytext))); return T_multiNote;*/}
"=="                {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_isEqual;}
"<"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_LT;}
">"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_GT;}
">="                {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_GE;}
"<="                {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_LE;}
"!="                {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_notEqual;}
"if"                {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_if;}
"else"              {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_else;}
"while"             {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_while;}
"break"             {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_break;}
"continue"          {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_continue;}
"return"            {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_return;}
"int"               {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_int;}
"static"            {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_static;}
"const"             {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_const;}
"void"              {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_void;}
{IDENT}             {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_ident;}
"("                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_leftPar;}
")"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_rightPar;}
"["                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_leftBra;}
"]"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_rightBra;}
"{"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_leftCur;}
"}"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_rightCur;}
";"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_sem;}
"+"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_add;}
"-"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_sub;}
"*"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_mul;}
"/"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_div;}
"="                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_assign;}
"&&"                {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_and;}
"||"                {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_or;}
"%"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_mod;}
"!"                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_not;}
","                 {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_comma;}
{OCT_INTEGER}       {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_oct;}
{DEC_INTEGER}       {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_dec;}
{HEX_INTEGER}       {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_hex;}  
{STR}               {log(yytext); yylval = new MyTree(string(strdup(yytext))); column++; return T_formatStr;}
{SINGAL_NOTE}       {/*yylval = new MyTree(string(strdup(yytext))); row++; column = 1; return T_singleNote;*/}
{ERR_IDENT}         {logError(yytext); end_file = 1; is_error = 1; return T_error;}          
{ERR_INTEGER}       {logError(yytext); end_file = 1; is_error = 1; return T_error;}
<<EOF>>             {yylval = new MyTree(string(strdup(yytext))); end_file = 1; is_error = 1; return 0;}
%%
 
int yywrap() { 
    return 1;
}

void log(char text[]) {
    if(debug == 1){
        printf("Recognize %s\n", text);
    }
}

void logError(char text[]){
    if(debug == 1){
        printf("Find a error %s at row:%d  column:%d \n", text, row, column);
    }
}

