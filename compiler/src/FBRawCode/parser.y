%{
#include <stdio.h>
#include <iostream>
#include <string>
#include "../Token/Token.h"
#include "../MyTree/MyTree.h"
#define YYSTYPE MyTree *
void yyerror(const char* msg) {}
MyTree * FunCompUnit(MyTree * Decl);
MyTree * FunDecl(MyTree * VarDecl);
MyTree * FunVarDecl(MyTree * BType,MyTree * T_identifier_node,MyTree *ANIDEN);
MyTree * FunBType(MyTree * T_int_node);
MyTree * FunANIDEN(MyTree * T_identifier_node, MyTree *ANIDEN);

MyTree * CompUnitNode;
using namespace std;
%}

%token T_identifier
%token T_int

%%

/*测试一下注释*/
CompUnit    :   Decl    {$$=FunCompUnit($1);CompUnitNode=$$;}
            ;

Decl        :   VarDecl { $$=FunDecl($1);  }
            ;

VarDecl     :   BType T_identifier ANIDEN ';'   { $$=FunVarDecl($1,$2,$3); }
            ;

BType       :   T_int                           { $$=FunBType($1); }
            ;

ANIDEN      :   ',' T_identifier ANIDEN         { $$=FunANIDEN($2,$3);}
            |                                   { $$=NULL; }
            ;

%%

// int main() {
//     return yyparse();
// }

MyTree * FunCompUnit(MyTree * Decl)
{
    cout<<"Reducing CompUnit\n";
    MyTree * Temp=new MyTree("CompUnit");
    Temp->newChild(Decl);
    return Temp;
}

MyTree * FunDecl(MyTree * VarDecl)
{
    cout<<"Reducing Decl\n";
    MyTree * Temp=new MyTree("Decl");
    Temp->newChild(VarDecl);
    return Temp;
}

MyTree * FunVarDecl(MyTree * BType,MyTree * T_identifier_node,MyTree *ANIDEN)
{
    cout<<"Reducing VarDecl\n";
    MyTree * Temp=new MyTree("VarDecl");
    Temp->newChild(BType);
    Temp->newChild(T_identifier_node);
    Temp->newChild(ANIDEN);
    return Temp;
}

MyTree * FunBType(MyTree * T_int_node)
{
    cout<<"Reducing BType\n";
    MyTree * Temp=new MyTree("BType");
    Temp->newChild(T_int_node);
    return Temp;
}

MyTree * FunANIDEN(MyTree * T_identifier_node, MyTree *ANIDEN)
{
    cout<<"Reducing ANIDEN\n";
    MyTree * Temp=new MyTree("ANIDEN");
    Temp->newChild(T_identifier_node);
    if(ANIDEN!=NULL)
        Temp->newChild(ANIDEN);
    return Temp;

}