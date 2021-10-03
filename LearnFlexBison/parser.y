%{
#include <stdio.h>
#define YYSTYPE char *
void yyerror(const char* msg) {}
%}

%token T_identifier
%token T_int

%%

CompUnit    :   Decl    { printf("Reducing CompUnit\n");  }
            ;

Decl        :   VarDecl { printf("Reducing Decl\n");  }
            ;

VarDecl     :   BType T_identifier ANIDEN ';'   { printf("T_identifier : %s\n", $2);printf("Reducing VarDecl\n"); }
            ;

BType       :   T_int                           { printf("Reducing BType\n"); }
            ;

ANIDEN      :   ',' T_identifier ANIDEN         { printf("T_identifier : %s\n", $2); printf("Reducing ANIDEN\n");}
            |                                   { /* empty */ }
            ;

%%

int main() {
    return yyparse();
}