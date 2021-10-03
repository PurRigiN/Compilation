/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_FBGENERATECODE_PARSER_TAB_H_INCLUDED
# define YY_YY_SRC_FBGENERATECODE_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_int = 258,
    T_break = 259,
    T_const = 260,
    T_continue = 261,
    T_default = 262,
    T_do = 263,
    T_else = 264,
    T_for = 265,
    T_goto = 266,
    T_if = 267,
    T_return = 268,
    T_static = 269,
    T_void = 270,
    T_while = 271,
    T_add = 272,
    T_sub = 273,
    T_mul = 274,
    T_div = 275,
    T_assign = 276,
    T_mod = 277,
    T_not = 278,
    T_and = 279,
    T_or = 280,
    T_isEqual = 281,
    T_notEqual = 282,
    T_GT = 283,
    T_LT = 284,
    T_GE = 285,
    T_LE = 286,
    T_comma = 287,
    T_sem = 288,
    T_leftPar = 289,
    T_rightPar = 290,
    T_leftBra = 291,
    T_rightBra = 292,
    T_leftCur = 293,
    T_rightCur = 294,
    T_dec = 295,
    T_hex = 296,
    T_oct = 297,
    T_rowCom = 298,
    T_leftCom = 299,
    T_rightCom = 300,
    T_ident = 301,
    T_IntConst = 302,
    T_singleNote = 303,
    T_multiNote = 304,
    T_formatStr = 305,
    T_error = 306
  };
#endif
/* Tokens.  */
#define T_int 258
#define T_break 259
#define T_const 260
#define T_continue 261
#define T_default 262
#define T_do 263
#define T_else 264
#define T_for 265
#define T_goto 266
#define T_if 267
#define T_return 268
#define T_static 269
#define T_void 270
#define T_while 271
#define T_add 272
#define T_sub 273
#define T_mul 274
#define T_div 275
#define T_assign 276
#define T_mod 277
#define T_not 278
#define T_and 279
#define T_or 280
#define T_isEqual 281
#define T_notEqual 282
#define T_GT 283
#define T_LT 284
#define T_GE 285
#define T_LE 286
#define T_comma 287
#define T_sem 288
#define T_leftPar 289
#define T_rightPar 290
#define T_leftBra 291
#define T_rightBra 292
#define T_leftCur 293
#define T_rightCur 294
#define T_dec 295
#define T_hex 296
#define T_oct 297
#define T_rowCom 298
#define T_leftCom 299
#define T_rightCom 300
#define T_ident 301
#define T_IntConst 302
#define T_singleNote 303
#define T_multiNote 304
#define T_formatStr 305
#define T_error 306

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_FBGENERATECODE_PARSER_TAB_H_INCLUDED  */
