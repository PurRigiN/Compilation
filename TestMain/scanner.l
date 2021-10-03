%{
#define YYSTYPE char *
#include "y.tab.h"
%}

IDENTIFIER      ([_a-zA-Z][_a-zA-Z0-9]*)
WHITESPACE      [ \t]*

%%
"int"                       { printf("Recognize int\n"); return T_int;  }
{IDENTIFIER}                { printf("Recognize IDENTIFIER\n"); yylval = strdup(yytext); return T_identifier; }
,                           { printf("Recognize ,\n"); return yytext[0];}
;                           { printf("Recognize ;\n"); return yytext[0];}
{WHITESPACE}                { printf("Recognize space\n"); /* do nothing */ }
.                           { return 0;/* do nothing */ }
%%

int yywrap(void) { 
    return 1;
}
