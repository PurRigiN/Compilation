/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "src/FBRawCode/parser.y"

#include <stdio.h>
#include <iostream>
#include <string>
#include "../Token/Token.h"
#include "../MyTree/MyTree.h"
#define YYSTYPE MyTree *
extern int yylex(void);
void yyerror(const char* msg) {}
/* debug 开关*/
bool parserDebug=false;
MyTree * FunCompUnit1(MyTree * NodeDeclOrFuncDef);
MyTree * FunCompUnit2(MyTree * CompUnit, MyTree * NodeDeclOrFuncDef);
MyTree * FunDecl(MyTree * VarDeclOrConstDecl);
MyTree * FunConstDecl(MyTree * NodeConstDeclStmt);
MyTree * FunConstDeclStmt(MyTree * Node1, MyTree * Node2);
MyTree * FunBType();
MyTree * FunConstDef(MyTree * NodeIdentifier, MyTree * NodeConstDefArrayRepeat, MyTree * ConstInitVal);
MyTree * FunConstDefArrayRepeat(MyTree * NodeConstExp, MyTree * NodeConstDefArrayRepeat);
MyTree * FunConstInitVal();
MyTree * FunConstInitVal(MyTree * Node1);
MyTree * FunConstInitVal(MyTree * Node1, MyTree * Node2);
MyTree * FunConstInitValRepeat(MyTree * NodeConstInitVal, MyTree * NodeConstInitValRepeat);
MyTree * FunVarDecl(MyTree * NodeBType, MyTree * NodeVarDef, MyTree * NodeVarDeclRepeat);
MyTree * FunVarDeclRepeat(MyTree * NodeVarDef, MyTree * NodeVarDeclRepeat);
MyTree * FunVarDef(MyTree * NodeVarDefRepeat);
MyTree * FunVarDef(MyTree * NodeVarDefRepeat, MyTree * NodenitVal);
MyTree * FunVarDefRepeat(MyTree * NodeIdentifier);
MyTree * FunVarDefRepeat(MyTree * NodeVarDefRepeat, MyTree * NodeConstExp);

//InitVal
MyTree * FunInitVal();
MyTree * FunInitVal(MyTree * Node1);
MyTree * FunInitVal(MyTree * Node1, MyTree * Node2);

//InitValRepeat
MyTree * FunInitValRepeat(MyTree * NodeInitVal, MyTree * NodeInitValRepeat);

//FuncDef
MyTree * FunFuncDefVoid(MyTree * NodeTident, MyTree * NodeBlock);
MyTree * FunFuncDefInt(MyTree * NodeTident, MyTree * NodeBlock);
MyTree * FunFuncDefVoidWithPara(MyTree * NodeTident, MyTree * NodeFuncFParams, MyTree * NodeBlock);
MyTree * FunFuncDefIntWithPara(MyTree * NodeTident, MyTree * NodeFuncFParams, MyTree * NodeBlock);

//FuncFParams
MyTree * FunFuncFParams(MyTree * NodeFuncFParam, MyTree * NodeFuncFParamsRepeat);

//FuncFParamsRepeat
MyTree * FunFuncFParamsRepeat(MyTree * NodeFuncFParam, MyTree * NodeFuncFParamsRepeat);

//FuncFParam
MyTree * FunFuncFParam(MyTree * NodeTident);
MyTree * FunFuncFParamWithBra(MyTree * NodeTident, MyTree * NodeFuncFParamRepeat);

//FuncFParamRepeat
MyTree * FunFuncFParamRepeat(MyTree * NodeExp, MyTree * NodeFuncFParamRepeat);

//Block
MyTree * FunBlock(MyTree * NodeBlockRepeat);

//BlockRepeat
MyTree * FunBlockRepeat(MyTree * NodeBlockItem, MyTree * NodeBlockRepeat);

//BlockItem
MyTree * FunBlockItem(MyTree * Node);

//Stmt
MyTree * FunStmt();
MyTree * FunStmt(MyTree * Node);
MyTree * FunStmtTbreak();
MyTree * FunStmtTcontinue();

//AssignStmt
MyTree * FunAssignStmt(MyTree * NodeLVal, MyTree * NodeExp);

//IfStmt
MyTree * FunIfStmt(MyTree * NodeCond, MyTree * NodeStmt, MyTree * NodeIfStmtnext);

//IfStmtnext
MyTree * FunIfStmtnext(MyTree * NodeStmt);

//WhileStmt
MyTree * FunWhileStmt(MyTree * NodeCond, MyTree * NodeStmt);

//ReturnStmt
MyTree * FunReturnStmt(MyTree * NodeExp);
MyTree * FunReturnStmt();

//Exp
MyTree * FunExp(MyTree * NodeAddExp);

//Cond
MyTree * FunCond(MyTree * NodeLOrExp);

//LVal
MyTree * FunLVal(MyTree * NodeTident);
MyTree * FunLVal(MyTree * NodeLVal, MyTree * NodeExp);

//PrimaryExp
MyTree * FunPrimaryExp(MyTree * Node);

//Number
MyTree * FunNumber(MyTree * NodeTconstint);

//IntConst
MyTree * FunIntConstTdec(MyTree * NodeTdec);
MyTree * FunIntConstThex(MyTree * NodeThex);
MyTree * FunIntConstToct(MyTree * NodeToct);

//UnaryExp
MyTree * FunUnaryExp(MyTree * NodePrimaryExp);
MyTree * FunUnaryExpFun(MyTree * NodeTident);
MyTree * FunUnaryExpFunWithPara(MyTree * NodeTident, MyTree * NodeFuncRParams);
MyTree * FunUnaryExpOp(MyTree * NodeUnaryOp, MyTree * NodeUnaryExp);

//FuncRParams
MyTree * FunFuncRParams(MyTree * NodeFuncRParams, MyTree * NodeExp);
MyTree * FunFuncRParams(MyTree * NodeExp);
MyTree * FunFuncRParamsStr(MyTree * NodeTformatStr);

//乘除模表达式
MyTree * FunMulExp_mul(MyTree * NodeMulExp, MyTree * NodeUnaryExp);
MyTree * FunMulExp_div(MyTree * NodeMulExp, MyTree * NodeUnaryExp);
MyTree * FunMulExp_mod(MyTree * NodeMulExp, MyTree * NodeUnaryExp);

//加减表达式
MyTree * FunAddExp_add(MyTree * NodeAddExp, MyTree * NodeMulExp);
MyTree * FunAddExp_sub(MyTree * NodeAddExp, MyTree * NodeMulExp);

//RelExp
MyTree * FunRelExp_Add(MyTree * NodeAddExp);
MyTree * FunRelExp_TGT(MyTree * NodeRelExp, MyTree * NodeAddExp);
MyTree * FunRelExp_TLT(MyTree * NodeRelExp, MyTree * NodeAddExp);
MyTree * FunRelExp_TGE(MyTree * NodeRelExp, MyTree * NodeAddExp);
MyTree * FunRelExp_TLE(MyTree * NodeRelExp, MyTree * NodeAddExp);

//EqExp
MyTree * FunEqExp_Rel(MyTree * NodeRelExp);
MyTree * FunEqExp_isEqual(MyTree * NodeEqExp, MyTree * NodeRelExp);
MyTree * FunEqExp_notEqual(MyTree * NodeEqExp, MyTree * NodeRelExp);

//LAndExp
MyTree * FunLAndExp_EqExp(MyTree * NodeEqExp);
MyTree * FunLAndExp_And(MyTree * NodeLAndExp, MyTree * NodeEqExp);

//LOrExp
MyTree * FunLOrExp_And(MyTree * NodeLAndExp);
MyTree * FunLOrExp_Or(MyTree * NodeLOrExp, MyTree * NodeLAndExp);

//常量表达式
MyTree * FunConstExp(MyTree * NodeAddExp);


MyTree * CompUnitStartNode;
using namespace std;

#line 227 "src/FBGenerateCode/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  13
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   243

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  189

#define YYUNDEFTOK  2
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   169,   169,   170,   171,   172,   175,   176,   179,   182,
     183,   186,   189,   192,   193,   196,   197,   198,   201,   202,
     205,   208,   209,   212,   213,   216,   217,   220,   221,   222,
     225,   226,   229,   230,   231,   232,   236,   239,   240,   243,
     244,   247,   248,   251,   254,   255,   258,   259,   262,   263,
     264,   265,   266,   267,   268,   269,   270,   273,   276,   279,
     280,   283,   286,   287,   290,   293,   296,   297,   300,   301,
     302,   305,   307,   308,   309,   311,   312,   313,   314,   317,
     318,   319,   322,   323,   324,   327,   328,   329,   330,   333,
     334,   335,   338,   339,   340,   341,   342,   345,   346,   347,
     350,   351,   354,   355,   358
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_int", "T_break", "T_const",
  "T_continue", "T_default", "T_do", "T_else", "T_for", "T_goto", "T_if",
  "T_return", "T_static", "T_void", "T_while", "T_add", "T_sub", "T_mul",
  "T_div", "T_assign", "T_mod", "T_not", "T_and", "T_or", "T_isEqual",
  "T_notEqual", "T_GT", "T_LT", "T_GE", "T_LE", "T_comma", "T_sem",
  "T_leftPar", "T_rightPar", "T_leftBra", "T_rightBra", "T_leftCur",
  "T_rightCur", "T_dec", "T_hex", "T_oct", "T_rowCom", "T_leftCom",
  "T_rightCom", "T_ident", "T_IntConst", "T_singleNote", "T_multiNote",
  "T_formatStr", "T_error", "$accept", "CompUnit", "Decl", "ConstDecl",
  "ConstDeclStmt", "BType", "ConstDef", "ConstDefArrayRepeat",
  "ConstInitVal", "ConstInitValRepeat", "VarDecl", "VarDeclRepeat",
  "VarDef", "VarDefRepeat", "InitVal", "InitValRepeat", "FuncDef",
  "FuncFParams", "FuncFParamsRepeat", "FuncFParam", "FuncFParamRepeat",
  "Block", "BlockRepeat", "BlockItem", "Stmt", "AssignStmt", "IfStmt",
  "IfStmtnext", "WhileStmt", "ReturnStmt", "Exp", "Cond", "LVal",
  "PrimaryExp", "Number", "IntConst", "UnaryExp", "UnaryOp", "FuncRParams",
  "MulExp", "AddExp", "RelExp", "EqExp", "LAndExp", "LOrExp", "ConstExp", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      76,  -145,    10,   -17,   164,  -145,  -145,    29,   -11,  -145,
    -145,     4,    22,  -145,  -145,  -145,     4,  -145,    32,    31,
     -13,    38,  -145,     7,  -145,     8,    52,    35,    -2,   182,
     182,    56,    64,    67,    84,    90,    64,    94,  -145,    31,
    -145,  -145,  -145,  -145,   182,   134,  -145,  -145,  -145,   109,
    -145,  -145,    96,  -145,  -145,  -145,  -145,   182,    11,    68,
      68,   107,   110,   169,    42,  -145,   117,    64,    10,  -145,
    -145,    64,  -145,   120,  -145,   113,    55,   182,  -145,   182,
     182,   182,   182,   182,  -145,    38,   143,  -145,  -145,   123,
     125,   128,   179,   129,  -145,  -145,    52,  -145,   126,    42,
    -145,  -145,  -145,  -145,  -145,   137,    -9,   122,  -145,    90,
    -145,  -145,    -2,   132,  -145,  -145,  -145,   -10,   141,  -145,
    -145,  -145,    11,    11,  -145,  -145,   156,  -145,  -145,   182,
    -145,   157,   182,  -145,  -145,  -145,   182,   155,  -145,   113,
    -145,   182,  -145,  -145,   169,   154,   159,    68,   201,    80,
     171,   173,  -145,   166,   175,   182,  -145,  -145,  -145,   156,
    -145,   108,   182,   182,   182,   182,   182,   182,   182,   182,
     108,  -145,   167,  -145,   197,    68,    68,    68,    68,   201,
     201,    80,   171,  -145,   155,   108,  -145,  -145,  -145
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    11,     0,     0,     0,     4,     7,     0,     0,     6,
       5,     0,     0,     1,     2,     3,     0,     8,    26,    22,
      23,    14,     9,     0,    10,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    38,     0,     0,    26,    22,
      20,    79,    80,    81,     0,     0,    72,    73,    74,    66,
      24,    27,    69,    75,    70,    71,    85,     0,    89,    64,
     104,     0,     0,     0,    45,    32,    39,     0,     0,    36,
      33,     0,    21,     0,    28,    31,     0,     0,    78,     0,
       0,     0,     0,     0,    25,    14,     0,    12,    15,     0,
       0,     0,     0,     0,    50,    46,     0,    51,     0,    45,
      47,    48,    52,    53,    56,     0,    69,     0,    34,    38,
      35,    68,     0,     0,    76,    84,    83,     0,     0,    86,
      87,    88,    90,    91,    13,    16,    19,    54,    55,     0,
      63,     0,     0,    43,    44,    49,     0,    42,    37,    31,
      29,     0,    77,    67,     0,     0,     0,    92,    97,   100,
     102,    65,    62,     0,     0,     0,    40,    30,    82,    19,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    18,    60,    93,    94,    95,    96,    98,
      99,   101,   103,    61,    42,     0,    58,    41,    59
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,    24,  -145,  -145,     5,   198,   133,   -80,    58,
    -145,   187,   207,  -145,   -41,    88,   230,   210,   127,   170,
      53,   -18,   140,  -145,  -144,  -145,  -145,  -145,  -145,  -145,
     -25,   111,   -62,  -145,  -145,  -145,    13,  -145,  -145,    27,
     -29,   -49,    72,    73,  -145,    98
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     4,    95,     6,     7,    33,    22,    31,    87,   145,
       9,    27,    19,    20,    50,   113,    10,    34,    69,    35,
     156,    97,    98,    99,   100,   101,   102,   186,   103,   104,
     105,   146,    52,    53,    54,    55,    56,    57,   117,    58,
      59,   148,   149,   150,   151,    88
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      60,    60,   106,    51,    75,     8,   126,    11,    28,     8,
       1,     1,   136,     1,    65,    41,    42,   174,    70,    73,
      51,    43,   141,    29,     5,   142,   183,    77,    14,    12,
      79,    80,    44,    81,    60,    18,    45,   106,    46,    47,
      48,   188,    32,    36,    49,     1,    89,     2,    90,   108,
      21,   116,   118,   110,    91,    92,    23,    60,    93,    41,
      42,    16,    17,    26,   159,    43,    25,   131,    40,    96,
      78,   139,    41,    42,    30,    94,    44,    63,    43,     1,
      64,     2,    46,    47,    48,    82,    83,    51,    49,    44,
     114,     3,   119,   120,   121,    46,    47,    48,    38,   106,
     147,    49,    64,   147,    96,   115,   166,   167,   106,   122,
     123,   154,    89,    66,    90,    60,   158,   179,   180,    67,
      91,    92,    68,   106,    93,    41,    42,    61,    62,    71,
     172,    43,    77,   175,   176,   177,   178,   147,   147,   147,
     147,    94,    44,    76,    84,   112,    64,    85,    46,    47,
      48,    41,    42,   107,    49,   111,   127,    43,   128,   137,
      41,    42,   129,   132,    13,   133,    43,     1,    44,     2,
     135,   140,    45,    74,    46,    47,    48,    44,   143,     3,
      49,    86,   125,    46,    47,    48,    41,    42,   144,    49,
     152,   155,    43,   160,   161,   168,    41,    42,   169,    41,
      42,   170,    43,    44,   184,    43,   185,    86,   171,    46,
      47,    48,   130,    44,    24,    49,    44,   173,   124,    46,
      47,    48,    46,    47,    48,    49,    72,   157,    49,   162,
     163,   164,   165,    39,    15,    37,   138,   187,   109,   134,
     181,     0,   182,   153
};

static const yytype_int16 yycheck[] =
{
      29,    30,    64,    28,    45,     0,    86,     2,    21,     4,
       3,     3,    21,     3,    32,    17,    18,   161,    36,    44,
      45,    23,    32,    36,     0,    35,   170,    36,     4,    46,
      19,    20,    34,    22,    63,    46,    38,    99,    40,    41,
      42,   185,    35,    35,    46,     3,     4,     5,     6,    67,
      46,    76,    77,    71,    12,    13,    34,    86,    16,    17,
      18,    32,    33,    32,   144,    23,    34,    92,    33,    64,
      57,   112,    17,    18,    36,    33,    34,    21,    23,     3,
      38,     5,    40,    41,    42,    17,    18,   112,    46,    34,
      35,    15,    79,    80,    81,    40,    41,    42,    46,   161,
     129,    46,    38,   132,    99,    50,    26,    27,   170,    82,
      83,   136,     4,    46,     6,   144,   141,   166,   167,    35,
      12,    13,    32,   185,    16,    17,    18,    29,    30,    35,
     155,    23,    36,   162,   163,   164,   165,   166,   167,   168,
     169,    33,    34,    34,    37,    32,    38,    37,    40,    41,
      42,    17,    18,    36,    46,    35,    33,    23,    33,    37,
      17,    18,    34,    34,     0,    39,    23,     3,    34,     5,
      33,    39,    38,    39,    40,    41,    42,    34,    37,    15,
      46,    38,    39,    40,    41,    42,    17,    18,    32,    46,
      33,    36,    23,    39,    35,    24,    17,    18,    25,    17,
      18,    35,    23,    34,    37,    23,     9,    38,    33,    40,
      41,    42,    33,    34,    16,    46,    34,   159,    85,    40,
      41,    42,    40,    41,    42,    46,    39,   139,    46,    28,
      29,    30,    31,    26,     4,    25,   109,   184,    68,    99,
     168,    -1,   169,   132
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,    15,    53,    54,    55,    56,    57,    62,
      68,    57,    46,     0,    54,    68,    32,    33,    46,    64,
      65,    46,    58,    34,    58,    34,    32,    63,    21,    36,
      36,    59,    35,    57,    69,    71,    35,    69,    46,    64,
      33,    17,    18,    23,    34,    38,    40,    41,    42,    46,
      66,    82,    84,    85,    86,    87,    88,    89,    91,    92,
      92,    97,    97,    21,    38,    73,    46,    35,    32,    70,
      73,    35,    63,    82,    39,    66,    34,    36,    88,    19,
      20,    22,    17,    18,    37,    37,    38,    60,    97,     4,
       6,    12,    13,    16,    33,    54,    57,    73,    74,    75,
      76,    77,    78,    80,    81,    82,    84,    36,    73,    71,
      73,    35,    32,    67,    35,    50,    82,    90,    82,    88,
      88,    88,    91,    91,    59,    39,    60,    33,    33,    34,
      33,    82,    34,    39,    74,    33,    21,    37,    70,    66,
      39,    32,    35,    37,    32,    61,    83,    92,    93,    94,
      95,    96,    33,    83,    82,    36,    72,    67,    82,    60,
      39,    35,    28,    29,    30,    31,    26,    27,    24,    25,
      35,    33,    82,    61,    76,    92,    92,    92,    92,    93,
      93,    94,    95,    76,    37,     9,    79,    72,    76
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    53,    53,    53,    54,    54,    55,    56,
      56,    57,    58,    59,    59,    60,    60,    60,    61,    61,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      67,    67,    68,    68,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    73,    74,    74,    75,    75,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    77,    78,    79,
      79,    80,    81,    81,    82,    83,    84,    84,    85,    85,
      85,    86,    87,    87,    87,    88,    88,    88,    88,    89,
      89,    89,    90,    90,    90,    91,    91,    91,    91,    92,
      92,    92,    93,    93,    93,    93,    93,    94,    94,    94,
      95,    95,    96,    96,    97
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     1,     1,     1,     2,     3,
       3,     1,     4,     4,     0,     1,     2,     4,     3,     0,
       4,     3,     0,     1,     3,     4,     1,     1,     2,     4,
       3,     0,     5,     5,     6,     6,     2,     3,     0,     2,
       5,     4,     0,     3,     2,     0,     1,     1,     1,     2,
       1,     1,     1,     1,     2,     2,     1,     4,     6,     2,
       0,     5,     3,     2,     1,     1,     1,     4,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     4,     2,     1,
       1,     1,     3,     1,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 169 "src/FBRawCode/parser.y"
                                                {yyval=FunCompUnit2(yyvsp[-1], yyvsp[0]);	}
#line 1703 "src/FBGenerateCode/parser.tab.c"
    break;

  case 3:
#line 170 "src/FBRawCode/parser.y"
                                                        {yyval=FunCompUnit2(yyvsp[-1], yyvsp[0]);	}
#line 1709 "src/FBGenerateCode/parser.tab.c"
    break;

  case 4:
#line 171 "src/FBRawCode/parser.y"
                                                                {yyval=FunCompUnit1(yyvsp[0]);		}
#line 1715 "src/FBGenerateCode/parser.tab.c"
    break;

  case 5:
#line 172 "src/FBRawCode/parser.y"
                                                                {yyval=FunCompUnit1(yyvsp[0]);		}
#line 1721 "src/FBGenerateCode/parser.tab.c"
    break;

  case 6:
#line 175 "src/FBRawCode/parser.y"
                                                        {yyval=FunDecl(yyvsp[0]);			}
#line 1727 "src/FBGenerateCode/parser.tab.c"
    break;

  case 7:
#line 176 "src/FBRawCode/parser.y"
                                                                {yyval=FunDecl(yyvsp[0]);			}
#line 1733 "src/FBGenerateCode/parser.tab.c"
    break;

  case 8:
#line 179 "src/FBRawCode/parser.y"
                                                {yyval=FunConstDecl(yyvsp[-1]);		}
#line 1739 "src/FBGenerateCode/parser.tab.c"
    break;

  case 9:
#line 182 "src/FBRawCode/parser.y"
                                                                {yyval=FunConstDeclStmt(yyvsp[-1], yyvsp[0]);		}
#line 1745 "src/FBGenerateCode/parser.tab.c"
    break;

  case 10:
#line 183 "src/FBRawCode/parser.y"
                                                                        {yyval=FunConstDeclStmt(yyvsp[-2], yyvsp[0]);		}
#line 1751 "src/FBGenerateCode/parser.tab.c"
    break;

  case 11:
#line 186 "src/FBRawCode/parser.y"
                                                                {yyval=FunBType();						}
#line 1757 "src/FBGenerateCode/parser.tab.c"
    break;

  case 12:
#line 189 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunConstDef(yyvsp[-3], yyvsp[-2], yyvsp[0]);		}
#line 1763 "src/FBGenerateCode/parser.tab.c"
    break;

  case 13:
#line 192 "src/FBRawCode/parser.y"
                                                                                {yyval=FunConstDefArrayRepeat(yyvsp[-2], yyvsp[0]);	}
#line 1769 "src/FBGenerateCode/parser.tab.c"
    break;

  case 14:
#line 193 "src/FBRawCode/parser.y"
                                                                                                                                                {yyval=NULL;							}
#line 1775 "src/FBGenerateCode/parser.tab.c"
    break;

  case 15:
#line 196 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunConstInitVal(yyvsp[0]);			}
#line 1781 "src/FBGenerateCode/parser.tab.c"
    break;

  case 16:
#line 197 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunConstInitVal();				}
#line 1787 "src/FBGenerateCode/parser.tab.c"
    break;

  case 17:
#line 198 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunConstInitVal(yyvsp[-2], yyvsp[-1]);		}
#line 1793 "src/FBGenerateCode/parser.tab.c"
    break;

  case 18:
#line 201 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunConstInitValRepeat(yyvsp[-1], yyvsp[0]);	}
#line 1799 "src/FBGenerateCode/parser.tab.c"
    break;

  case 19:
#line 202 "src/FBRawCode/parser.y"
                                                                                                                                                {yyval=NULL;}
#line 1805 "src/FBGenerateCode/parser.tab.c"
    break;

  case 20:
#line 205 "src/FBRawCode/parser.y"
                                                                                        {yyval=FunVarDecl(yyvsp[-3], yyvsp[-2], yyvsp[-1]);			}
#line 1811 "src/FBGenerateCode/parser.tab.c"
    break;

  case 21:
#line 208 "src/FBRawCode/parser.y"
                                                                                {yyval=FunVarDeclRepeat(yyvsp[-1], yyvsp[0]);}
#line 1817 "src/FBGenerateCode/parser.tab.c"
    break;

  case 22:
#line 209 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=NULL;							}
#line 1823 "src/FBGenerateCode/parser.tab.c"
    break;

  case 23:
#line 212 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunVarDef(yyvsp[0]);					}
#line 1829 "src/FBGenerateCode/parser.tab.c"
    break;

  case 24:
#line 213 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunVarDef(yyvsp[-2], yyvsp[0]);				}
#line 1835 "src/FBGenerateCode/parser.tab.c"
    break;

  case 25:
#line 216 "src/FBRawCode/parser.y"
                                                                        {yyval=FunVarDefRepeat(yyvsp[-3], yyvsp[-1]);		}
#line 1841 "src/FBGenerateCode/parser.tab.c"
    break;

  case 26:
#line 217 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunVarDefRepeat(yyvsp[0]);			}
#line 1847 "src/FBGenerateCode/parser.tab.c"
    break;

  case 27:
#line 220 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunInitVal(yyvsp[0]);					}
#line 1853 "src/FBGenerateCode/parser.tab.c"
    break;

  case 28:
#line 221 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunInitVal();					}
#line 1859 "src/FBGenerateCode/parser.tab.c"
    break;

  case 29:
#line 222 "src/FBRawCode/parser.y"
                                                                                        {yyval=FunInitVal(yyvsp[-2], yyvsp[-1]);				}
#line 1865 "src/FBGenerateCode/parser.tab.c"
    break;

  case 30:
#line 225 "src/FBRawCode/parser.y"
                                                                                {yyval=FunInitValRepeat(yyvsp[-1], yyvsp[0]);		}
#line 1871 "src/FBGenerateCode/parser.tab.c"
    break;

  case 31:
#line 226 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=NULL;							}
#line 1877 "src/FBGenerateCode/parser.tab.c"
    break;

  case 32:
#line 229 "src/FBRawCode/parser.y"
                                                                                        {yyval=FunFuncDefVoid(yyvsp[-3], yyvsp[0]);				}
#line 1883 "src/FBGenerateCode/parser.tab.c"
    break;

  case 33:
#line 230 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunFuncDefInt(yyvsp[-3], yyvsp[0]);				}
#line 1889 "src/FBGenerateCode/parser.tab.c"
    break;

  case 34:
#line 231 "src/FBRawCode/parser.y"
                                                                                {yyval=FunFuncDefVoidWithPara(yyvsp[-4], yyvsp[-2], yyvsp[0]);	}
#line 1895 "src/FBGenerateCode/parser.tab.c"
    break;

  case 35:
#line 232 "src/FBRawCode/parser.y"
                                                                                {yyval=FunFuncDefIntWithPara(yyvsp[-4], yyvsp[-2], yyvsp[0]);	}
#line 1901 "src/FBGenerateCode/parser.tab.c"
    break;

  case 36:
#line 236 "src/FBRawCode/parser.y"
                                                                                        {yyval=FunFuncFParams(yyvsp[-1], yyvsp[0]);			}
#line 1907 "src/FBGenerateCode/parser.tab.c"
    break;

  case 37:
#line 239 "src/FBRawCode/parser.y"
                                                                                {yyval=FunFuncFParamsRepeat(yyvsp[-1], yyvsp[0]);	}
#line 1913 "src/FBGenerateCode/parser.tab.c"
    break;

  case 38:
#line 240 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=NULL;							}
#line 1919 "src/FBGenerateCode/parser.tab.c"
    break;

  case 39:
#line 243 "src/FBRawCode/parser.y"
                                                                                                                {yyval=FunFuncFParam(yyvsp[0]);				}
#line 1925 "src/FBGenerateCode/parser.tab.c"
    break;

  case 40:
#line 244 "src/FBRawCode/parser.y"
                                                                                        {yyval=FunFuncFParamWithBra(yyvsp[-3], yyvsp[0]);	}
#line 1931 "src/FBGenerateCode/parser.tab.c"
    break;

  case 41:
#line 247 "src/FBRawCode/parser.y"
                                                                                {yyval=FunFuncFParamRepeat(yyvsp[-2], yyvsp[0]);	}
#line 1937 "src/FBGenerateCode/parser.tab.c"
    break;

  case 42:
#line 248 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=NULL;							}
#line 1943 "src/FBGenerateCode/parser.tab.c"
    break;

  case 43:
#line 251 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunBlock(yyvsp[-1]);					}
#line 1949 "src/FBGenerateCode/parser.tab.c"
    break;

  case 44:
#line 254 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunBlockRepeat(yyvsp[-1], yyvsp[0]);			}
#line 1955 "src/FBGenerateCode/parser.tab.c"
    break;

  case 45:
#line 255 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=NULL;							}
#line 1961 "src/FBGenerateCode/parser.tab.c"
    break;

  case 46:
#line 258 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunBlockItem(yyvsp[0]);				}
#line 1967 "src/FBGenerateCode/parser.tab.c"
    break;

  case 47:
#line 259 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunBlockItem(yyvsp[0]);				}
#line 1973 "src/FBGenerateCode/parser.tab.c"
    break;

  case 48:
#line 262 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunStmt(yyvsp[0]);					}
#line 1979 "src/FBGenerateCode/parser.tab.c"
    break;

  case 49:
#line 263 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunStmt(yyvsp[-1]);					}
#line 1985 "src/FBGenerateCode/parser.tab.c"
    break;

  case 50:
#line 264 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunStmt();						}
#line 1991 "src/FBGenerateCode/parser.tab.c"
    break;

  case 51:
#line 265 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunStmt(yyvsp[0]);					}
#line 1997 "src/FBGenerateCode/parser.tab.c"
    break;

  case 52:
#line 266 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunStmt(yyvsp[0]);					}
#line 2003 "src/FBGenerateCode/parser.tab.c"
    break;

  case 53:
#line 267 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunStmt(yyvsp[0]);					}
#line 2009 "src/FBGenerateCode/parser.tab.c"
    break;

  case 54:
#line 268 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunStmtTbreak();				}
#line 2015 "src/FBGenerateCode/parser.tab.c"
    break;

  case 55:
#line 269 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunStmtTcontinue();				}
#line 2021 "src/FBGenerateCode/parser.tab.c"
    break;

  case 56:
#line 270 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=FunStmt(yyvsp[0]);					}
#line 2027 "src/FBGenerateCode/parser.tab.c"
    break;

  case 57:
#line 273 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunAssignStmt(yyvsp[-3], yyvsp[-1]);			}
#line 2033 "src/FBGenerateCode/parser.tab.c"
    break;

  case 58:
#line 276 "src/FBRawCode/parser.y"
                                                                                {yyval=FunIfStmt(yyvsp[-3], yyvsp[-1], yyvsp[0]);			}
#line 2039 "src/FBGenerateCode/parser.tab.c"
    break;

  case 59:
#line 279 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunIfStmtnext(yyvsp[0]);				}
#line 2045 "src/FBGenerateCode/parser.tab.c"
    break;

  case 60:
#line 280 "src/FBRawCode/parser.y"
                                                                                                                                {yyval=NULL;							}
#line 2051 "src/FBGenerateCode/parser.tab.c"
    break;

  case 61:
#line 283 "src/FBRawCode/parser.y"
                                                                                        {yyval=FunWhileStmt(yyvsp[-2], yyvsp[0]);			}
#line 2057 "src/FBGenerateCode/parser.tab.c"
    break;

  case 62:
#line 286 "src/FBRawCode/parser.y"
                                                                                                                {yyval=FunReturnStmt(yyvsp[-1]);				}
#line 2063 "src/FBGenerateCode/parser.tab.c"
    break;

  case 63:
#line 287 "src/FBRawCode/parser.y"
                                                                                                                        {yyval=FunReturnStmt();				}
#line 2069 "src/FBGenerateCode/parser.tab.c"
    break;

  case 64:
#line 290 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunExp(yyvsp[0]);						}
#line 2075 "src/FBGenerateCode/parser.tab.c"
    break;

  case 65:
#line 293 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunCond(yyvsp[0]);					}
#line 2081 "src/FBGenerateCode/parser.tab.c"
    break;

  case 66:
#line 296 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunLVal(yyvsp[0]);					}
#line 2087 "src/FBGenerateCode/parser.tab.c"
    break;

  case 67:
#line 297 "src/FBRawCode/parser.y"
                                                                                {yyval=FunLVal(yyvsp[-3], yyvsp[-1]);				}
#line 2093 "src/FBGenerateCode/parser.tab.c"
    break;

  case 68:
#line 300 "src/FBRawCode/parser.y"
                                                                                {yyval=FunPrimaryExp(yyvsp[-1]);				}
#line 2099 "src/FBGenerateCode/parser.tab.c"
    break;

  case 69:
#line 301 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunPrimaryExp(yyvsp[0]);				}
#line 2105 "src/FBGenerateCode/parser.tab.c"
    break;

  case 70:
#line 302 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunPrimaryExp(yyvsp[0]);				}
#line 2111 "src/FBGenerateCode/parser.tab.c"
    break;

  case 71:
#line 305 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunNumber(yyvsp[0]);					}
#line 2117 "src/FBGenerateCode/parser.tab.c"
    break;

  case 72:
#line 307 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunIntConstTdec(yyvsp[0]);			}
#line 2123 "src/FBGenerateCode/parser.tab.c"
    break;

  case 73:
#line 308 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunIntConstThex(yyvsp[0]);			}
#line 2129 "src/FBGenerateCode/parser.tab.c"
    break;

  case 74:
#line 309 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunIntConstToct(yyvsp[0]);			}
#line 2135 "src/FBGenerateCode/parser.tab.c"
    break;

  case 75:
#line 311 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunUnaryExp(yyvsp[0]);				}
#line 2141 "src/FBGenerateCode/parser.tab.c"
    break;

  case 76:
#line 312 "src/FBRawCode/parser.y"
                                                                                {yyval=FunUnaryExpFun(yyvsp[-2]);				}
#line 2147 "src/FBGenerateCode/parser.tab.c"
    break;

  case 77:
#line 313 "src/FBRawCode/parser.y"
                                                                        {yyval=FunUnaryExpFunWithPara(yyvsp[-3], yyvsp[-1]);	}
#line 2153 "src/FBGenerateCode/parser.tab.c"
    break;

  case 78:
#line 314 "src/FBRawCode/parser.y"
                                                                                                {yyval=FunUnaryExpOp(yyvsp[-1], yyvsp[0]);			}
#line 2159 "src/FBGenerateCode/parser.tab.c"
    break;

  case 79:
#line 317 "src/FBRawCode/parser.y"
                                                                                                {yyval=new MyTree("+");				}
#line 2165 "src/FBGenerateCode/parser.tab.c"
    break;

  case 80:
#line 318 "src/FBRawCode/parser.y"
                                                                                                        {yyval=new MyTree("-");				}
#line 2171 "src/FBGenerateCode/parser.tab.c"
    break;

  case 81:
#line 319 "src/FBRawCode/parser.y"
                                                                                                        {yyval=new MyTree("!");				}
#line 2177 "src/FBGenerateCode/parser.tab.c"
    break;

  case 82:
#line 322 "src/FBRawCode/parser.y"
                                                                                {yyval=FunFuncRParams(yyvsp[-2], yyvsp[0]);			}
#line 2183 "src/FBGenerateCode/parser.tab.c"
    break;

  case 83:
#line 323 "src/FBRawCode/parser.y"
                                                                                                                {yyval=FunFuncRParams(yyvsp[0]);				}
#line 2189 "src/FBGenerateCode/parser.tab.c"
    break;

  case 84:
#line 324 "src/FBRawCode/parser.y"
                                                                                                        {yyval=FunFuncRParamsStr(yyvsp[0]);			}
#line 2195 "src/FBGenerateCode/parser.tab.c"
    break;

  case 85:
#line 327 "src/FBRawCode/parser.y"
                                                                {yyval=yyvsp[0];								}
#line 2201 "src/FBGenerateCode/parser.tab.c"
    break;

  case 86:
#line 328 "src/FBRawCode/parser.y"
                                                        {yyval=FunMulExp_mul(yyvsp[-2], yyvsp[0]);			}
#line 2207 "src/FBGenerateCode/parser.tab.c"
    break;

  case 87:
#line 329 "src/FBRawCode/parser.y"
                                                        {yyval=FunMulExp_div(yyvsp[-2], yyvsp[0]);			}
#line 2213 "src/FBGenerateCode/parser.tab.c"
    break;

  case 88:
#line 330 "src/FBRawCode/parser.y"
                                                        {yyval=FunMulExp_mod(yyvsp[-2], yyvsp[0]);			}
#line 2219 "src/FBGenerateCode/parser.tab.c"
    break;

  case 89:
#line 333 "src/FBRawCode/parser.y"
                                                                {yyval=yyvsp[0];								}
#line 2225 "src/FBGenerateCode/parser.tab.c"
    break;

  case 90:
#line 334 "src/FBRawCode/parser.y"
                                                                {yyval=FunAddExp_add(yyvsp[-2], yyvsp[0]);			}
#line 2231 "src/FBGenerateCode/parser.tab.c"
    break;

  case 91:
#line 335 "src/FBRawCode/parser.y"
                                                                {yyval=FunAddExp_sub(yyvsp[-2], yyvsp[0]);			}
#line 2237 "src/FBGenerateCode/parser.tab.c"
    break;

  case 92:
#line 338 "src/FBRawCode/parser.y"
                                                                {yyval=FunRelExp_Add(yyvsp[0]);				}
#line 2243 "src/FBGenerateCode/parser.tab.c"
    break;

  case 93:
#line 339 "src/FBRawCode/parser.y"
                                                                {yyval=FunRelExp_TGT(yyvsp[-2], yyvsp[0]);			}
#line 2249 "src/FBGenerateCode/parser.tab.c"
    break;

  case 94:
#line 340 "src/FBRawCode/parser.y"
                                                                {yyval=FunRelExp_TLT(yyvsp[-2], yyvsp[0]);			}
#line 2255 "src/FBGenerateCode/parser.tab.c"
    break;

  case 95:
#line 341 "src/FBRawCode/parser.y"
                                                                {yyval=FunRelExp_TGE(yyvsp[-2], yyvsp[0]);			}
#line 2261 "src/FBGenerateCode/parser.tab.c"
    break;

  case 96:
#line 342 "src/FBRawCode/parser.y"
                                                                {yyval=FunRelExp_TLE(yyvsp[-2], yyvsp[0]);			}
#line 2267 "src/FBGenerateCode/parser.tab.c"
    break;

  case 97:
#line 345 "src/FBRawCode/parser.y"
                                                                {yyval=FunEqExp_Rel(yyvsp[0]);				}
#line 2273 "src/FBGenerateCode/parser.tab.c"
    break;

  case 98:
#line 346 "src/FBRawCode/parser.y"
                                                        {yyval=FunEqExp_isEqual(yyvsp[-2], yyvsp[0]);		}
#line 2279 "src/FBGenerateCode/parser.tab.c"
    break;

  case 99:
#line 347 "src/FBRawCode/parser.y"
                                                        {yyval=FunEqExp_notEqual(yyvsp[-2], yyvsp[0]);		}
#line 2285 "src/FBGenerateCode/parser.tab.c"
    break;

  case 100:
#line 350 "src/FBRawCode/parser.y"
                                                                {yyval=FunLAndExp_EqExp(yyvsp[0]);			}
#line 2291 "src/FBGenerateCode/parser.tab.c"
    break;

  case 101:
#line 351 "src/FBRawCode/parser.y"
                                                                {yyval=FunLAndExp_And(yyvsp[-2], yyvsp[0]);			}
#line 2297 "src/FBGenerateCode/parser.tab.c"
    break;

  case 102:
#line 354 "src/FBRawCode/parser.y"
                                                                {yyval=FunLOrExp_And(yyvsp[0]);				}
#line 2303 "src/FBGenerateCode/parser.tab.c"
    break;

  case 103:
#line 355 "src/FBRawCode/parser.y"
                                                                {yyval=FunLOrExp_Or(yyvsp[-2], yyvsp[0]);			}
#line 2309 "src/FBGenerateCode/parser.tab.c"
    break;

  case 104:
#line 358 "src/FBRawCode/parser.y"
                                                                {yyval=FunConstExp(yyvsp[0]);				}
#line 2315 "src/FBGenerateCode/parser.tab.c"
    break;


#line 2319 "src/FBGenerateCode/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 361 "src/FBRawCode/parser.y"


// int main() {
//     return yyparse();
// }

MyTree * FunCompUnit1(MyTree * NodeDeclOrFuncDef)
{
	if(parserDebug)
		cout<<"Reducing CompUnit\n";
    MyTree * Temp=new MyTree("CompUnit");
    Temp->newChild(NodeDeclOrFuncDef);
	CompUnitStartNode=Temp;
    return Temp;
}
MyTree * FunCompUnit2(MyTree * NodeCompUnit, MyTree * NodeDeclOrFuncDef)
{
    if(parserDebug)
		cout<<"Reducing CompUnit\n";
    MyTree * Temp=new MyTree("CompUnit");
	Temp->newChild(NodeCompUnit);
    Temp->newChild(NodeDeclOrFuncDef);
	CompUnitStartNode=Temp;
    return Temp;
}

MyTree * FunDecl(MyTree * VarDeclOrConstDecl)
{
    if(parserDebug)
		cout<<"Reducing Decl\n";
    MyTree * Temp=new MyTree("Decl");
    Temp->newChild(VarDeclOrConstDecl);
    return Temp;
}

MyTree * FunConstDecl(MyTree * NodeConstDeclStmt)
{
	if(parserDebug)
		cout<<"Reducing ConstDecl\n";
    MyTree * Temp=new MyTree("ConstDecl");
    Temp->newChild(NodeConstDeclStmt);
    return Temp;
}

MyTree * FunConstDeclStmt(MyTree * Node1, MyTree * Node2)
{
	if(parserDebug)
		cout<<"Reducing ConstDeclStmt\n";
    MyTree * Temp=new MyTree("ConstDeclStmt");
    Temp->newChild(Node1);
	Temp->newChild(Node2);
    return Temp;
}

MyTree * FunBType()
{
	if(parserDebug)
		cout<<"Reducing BType\n";
    MyTree * Temp=new MyTree("BType");
	MyTree * Temp2=new MyTree("int");
    Temp->newChild(Temp2);
    return Temp;
}

MyTree * FunConstDef(MyTree * NodeIdentifier, MyTree * NodeConstDefArrayRepeat, MyTree * ConstInitVal)
{
	if(parserDebug)
		cout<<"Reducing ConstDef\n";
    MyTree * Temp=new MyTree("ConstDef");
    Temp->newChild(NodeIdentifier);
	if(NodeConstDefArrayRepeat!=NULL)
		Temp->newChild(NodeConstDefArrayRepeat);
	Temp->newChild(ConstInitVal);
    return Temp;
}

MyTree * FunConstDefArrayRepeat(MyTree * NodeConstExp, MyTree * NodeConstDefArrayRepeat)
{
	if(parserDebug)
		cout<<"Reducing ConstDefArrayRepeat\n";
    MyTree * Temp=new MyTree("ConstDefArrayRepeat");
    Temp->newChild(NodeConstExp);
	if(NodeConstDefArrayRepeat!=NULL)
		Temp->newChild(NodeConstDefArrayRepeat);
    return Temp;
}
/**
 * @brief 初始化为空数组用函数
 * 
 * @return MyTree* 
 */
MyTree * FunConstInitVal()
{
	if(parserDebug)
		cout<<"Reducing ConstInitVal\n";
    MyTree * Temp=new MyTree("ConstInitVal");
	MyTree * Temp2=new MyTree("EmptyArray");
    Temp->newChild(Temp2);
    return Temp;
}

/**
 * @brief 初始化为表达式用函数
 * 
 * @return MyTree* 
 */
MyTree * FunConstInitVal(MyTree * Node1)
{
	if(parserDebug)
		cout<<"Reducing ConstInitVal\n";
    MyTree * Temp=new MyTree("ConstInitVal");
    Temp->newChild(Node1);
    return Temp;
}

/**
 * @brief 初始化为非空数组用函数
 * 
 * @return MyTree* 
 */
MyTree * FunConstInitVal(MyTree * Node1, MyTree * Node2)
{
	if(parserDebug)
		cout<<"Reducing ConstInitVal\n";
    MyTree * Temp=new MyTree("ConstInitVal");
    Temp->newChild(Node1);
	Temp->newChild(Node2);
    return Temp;
}

MyTree * FunConstInitValRepeat(MyTree * NodeConstInitVal, MyTree * NodeConstInitValRepeat)
{
	if(parserDebug)
		cout<<"Reducing ConstInitValRepeat\n";
    MyTree * Temp=new MyTree("ConstInitValRepeat");
    Temp->newChild(NodeConstInitVal);
	if(NodeConstInitValRepeat!=NULL)
		Temp->newChild(NodeConstInitValRepeat);
    return Temp;
}

MyTree * FunVarDecl(MyTree * NodeBType, MyTree * NodeVarDef, MyTree * NodeVarDeclRepeat)
{
	if(parserDebug)
		cout<<"Reducing VarDecl\n";
    MyTree * Temp=new MyTree("VarDecl");
    Temp->newChild(NodeBType);
	Temp->newChild(NodeVarDef);
	if(NodeVarDeclRepeat!=NULL)
		Temp->newChild(NodeVarDeclRepeat);
    return Temp;
}

MyTree * FunVarDeclRepeat(MyTree * NodeVarDef, MyTree * NodeVarDeclRepeat)
{
	if(parserDebug)
		cout<<"Reducing VarDeclRepeat\n";
    MyTree * Temp=new MyTree("VarDeclRepeat");
    Temp->newChild(NodeVarDef);
	if(NodeVarDeclRepeat!=NULL)
		Temp->newChild(NodeVarDeclRepeat);
    return Temp;
}

MyTree * FunVarDef(MyTree * NodeVarDefRepeat)
{
	if(parserDebug)
		cout<<"Reducing VarDef\n";
    MyTree * Temp=new MyTree("VarDef");
    Temp->newChild(NodeVarDefRepeat);
    return Temp;
}
MyTree * FunVarDef(MyTree * NodeVarDefRepeat, MyTree * NodenitVal)
{
	if(parserDebug)
		cout<<"Reducing VarDef\n";
    MyTree * Temp=new MyTree("VarDef");
    Temp->newChild(NodeVarDefRepeat);
	Temp->newChild(NodenitVal);
    return Temp;
}

MyTree * FunVarDefRepeat(MyTree * NodeIdentifier)
{
	if(parserDebug)
		cout<<"Reducing VarDefRepeat\n";
    MyTree * Temp=new MyTree("VarDefRepeat");
    Temp->newChild(NodeIdentifier);
    return Temp;
}

MyTree * FunVarDefRepeat(MyTree * NodeVarDefRepeat, MyTree * NodeConstExp)
{
	if(parserDebug)
		cout<<"Reducing VarDefRepeat\n";
    MyTree * Temp=new MyTree("VarDefRepeat");
    Temp->newChild(NodeVarDefRepeat);
	Temp->newChild(NodeConstExp);
    return Temp;
}

//------------------------InitVal------------------------
/**
 * @brief 初始化为空数组用函数
 * 
 * @return MyTree* 
 */
MyTree * FunInitVal()
{
	if(parserDebug)
		cout<<"Reducing InitVal\n";
    MyTree * Temp=new MyTree("InitVal");
	MyTree * Temp2=new MyTree("EmptyArray");
    Temp->newChild(Temp2);
    return Temp;
}

/**
 * @brief 初始化为表达式用函数
 * 
 * @return MyTree* 
 */
MyTree * FunInitVal(MyTree * Node1)
{
	if(parserDebug)
		cout<<"Reducing InitVal\n";
    MyTree * Temp=new MyTree("InitVal");
    Temp->newChild(Node1);
    return Temp;
}

/**
 * @brief 初始化为非空数组用函数
 * 
 * @return MyTree* 
 */
MyTree * FunInitVal(MyTree * Node1, MyTree * Node2)
{
	if(parserDebug)
		cout<<"Reducing InitVal\n";
    MyTree * Temp=new MyTree("InitVal");
    Temp->newChild(Node1);
	if(Node2!=NULL)
		Temp->newChild(Node2);
    return Temp;
}
//------------------------InitVal------------------------

//------------------------InitValRepeat------------------------
MyTree * FunInitValRepeat(MyTree * NodeInitVal, MyTree * NodeInitValRepeat)
{
	if(parserDebug)
		cout<<"Reducing InitValRepeat\n";
    MyTree * Temp=new MyTree("InitValRepeat");
    Temp->newChild(NodeInitVal);
	if(NodeInitValRepeat!=NULL)
		Temp->newChild(NodeInitValRepeat);
    return Temp;
}
//------------------------InitValRepeat------------------------

//------------------------FuncDef------------------------
MyTree * FunFuncDefVoid(MyTree * NodeTident, MyTree * NodeBlock)
{
	if(parserDebug)
		cout<<"Reducing FuncDefVoid\n";
    MyTree * Temp=new MyTree("FuncDefVoid");
	MyTree * Temp2=new MyTree("void");
	Temp->newChild(Temp2);
    Temp->newChild(NodeTident);
	Temp->newChild(NodeBlock);
    return Temp;
}
MyTree * FunFuncDefInt(MyTree * NodeTident, MyTree * NodeBlock)
{
	if(parserDebug)
		cout<<"Reducing FuncDefInt\n";
    MyTree * Temp=new MyTree("FuncDefInt");
	MyTree * Temp2=new MyTree("int");
	Temp->newChild(Temp2);
    Temp->newChild(NodeTident);
	Temp->newChild(NodeBlock);
    return Temp;
}
MyTree * FunFuncDefVoidWithPara(MyTree * NodeTident, MyTree * NodeFuncFParams, MyTree * NodeBlock)
{
	if(parserDebug)
		cout<<"Reducing FuncDefVoidWithPara\n";
    MyTree * Temp=new MyTree("FuncDefVoidWithPara");
	MyTree * Temp2=new MyTree("void");
	Temp->newChild(Temp2);
    Temp->newChild(NodeTident);
	Temp->newChild(NodeFuncFParams);
	Temp->newChild(NodeBlock);
    return Temp;
}
MyTree * FunFuncDefIntWithPara(MyTree * NodeTident, MyTree * NodeFuncFParams, MyTree * NodeBlock)
{
	if(parserDebug)
		cout<<"Reducing FuncDefIntWithPara\n";
    MyTree * Temp=new MyTree("FuncDefIntWithPara");
	MyTree * Temp2=new MyTree("int");
	Temp->newChild(Temp2);
    Temp->newChild(NodeTident);
	Temp->newChild(NodeFuncFParams);
	Temp->newChild(NodeBlock);
    return Temp;
}
//------------------------FuncDef------------------------

//------------------------FuncFParams------------------------
MyTree * FunFuncFParams(MyTree * NodeFuncFParam, MyTree * NodeFuncFParamsRepeat)
{
	if(parserDebug)
		cout<<"Reducing FuncFParams\n";
    MyTree * Temp=new MyTree("FuncFParams");
    Temp->newChild(NodeFuncFParam);
	if(NodeFuncFParamsRepeat!=NULL)
		Temp->newChild(NodeFuncFParamsRepeat);
    return Temp;
}
//------------------------FuncFParams------------------------

//------------------------FuncFParamsRepeat------------------------
MyTree * FunFuncFParamsRepeat(MyTree * NodeFuncFParam, MyTree * NodeFuncFParamsRepeat)
{
	if(parserDebug)
		cout<<"Reducing FuncFParamsRepeat\n";
    MyTree * Temp=new MyTree("FuncFParamsRepeat");
    Temp->newChild(NodeFuncFParam);
	if(NodeFuncFParamsRepeat!=NULL)
		Temp->newChild(NodeFuncFParamsRepeat);
    return Temp;
}
//------------------------FuncFParamsRepeat------------------------

//------------------------FuncFParam------------------------
MyTree * FunFuncFParam(MyTree * NodeTident)
{
	if(parserDebug)
		cout<<"Reducing FuncFParam\n";
    MyTree * Temp=new MyTree("FuncFParam");
    Temp->newChild(NodeTident);
    return Temp;
}
MyTree * FunFuncFParamWithBra(MyTree * NodeTident, MyTree * NodeFuncFParamRepeat)
{
	if(parserDebug)
		cout<<"Reducing FuncFParamWithBra\n";
    MyTree * Temp=new MyTree("FuncFParamWithBra");
    Temp->newChild(NodeTident);
	if(NodeFuncFParamRepeat!=NULL)
		Temp->newChild(NodeFuncFParamRepeat);
    return Temp;
}
//------------------------FuncFParam------------------------

//------------------------FuncFParamRepeat------------------------
MyTree * FunFuncFParamRepeat(MyTree * NodeExp, MyTree * NodeFuncFParamRepeat)
{
	if(parserDebug)
		cout<<"Reducing FuncFParamRepeat\n";
    MyTree * Temp=new MyTree("FuncFParamRepeat");
    Temp->newChild(NodeExp);
	if(NodeFuncFParamRepeat!=NULL)
		Temp->newChild(NodeFuncFParamRepeat);
    return Temp;
}
//------------------------FuncFParamRepeat------------------------

//------------------------Block------------------------
MyTree * FunBlock(MyTree * NodeBlockRepeat)
{
	if(parserDebug)
		cout<<"Reducing Block\n";
    MyTree * Temp=new MyTree("Block");
	if(NodeBlockRepeat!=NULL)
    	Temp->newChild(NodeBlockRepeat);
    return Temp;
}
//------------------------Block------------------------

//------------------------BlockRepeat------------------------
MyTree * FunBlockRepeat(MyTree * NodeBlockItem, MyTree * NodeBlockRepeat)
{
	if(parserDebug)
		cout<<"Reducing BlockRepeat\n";
    MyTree * Temp=new MyTree("BlockRepeat");
	Temp->newChild(NodeBlockItem);
	if(NodeBlockRepeat!=NULL)
    	Temp->newChild(NodeBlockRepeat);
    return Temp;
}
//------------------------BlockRepeat------------------------

//------------------------BlockItem------------------------
MyTree * FunBlockItem(MyTree * Node)
{
	if(parserDebug)
		cout<<"Reducing BlockItem\n";
    MyTree * Temp=new MyTree("BlockItem");
	Temp->newChild(Node);
    return Temp;
}
//------------------------BlockItem------------------------

//------------------------Stmt------------------------
MyTree * FunStmt()
{
	if(parserDebug)
		cout<<"Reducing Stmt\n";
    MyTree * Temp=new MyTree("Stmt");
    return Temp;
}
MyTree * FunStmt(MyTree * Node)
{
	if(parserDebug)
		cout<<"Reducing Stmt\n";
    MyTree * Temp=new MyTree("Stmt");
    Temp->newChild(Node);
    return Temp;
}
MyTree * FunStmtTbreak()
{
	if(parserDebug)
		cout<<"Reducing StmtTbreak\n";
    MyTree * Temp=new MyTree("StmtTbreak");
    return Temp;
}
MyTree * FunStmtTcontinue()
{
	if(parserDebug)
		cout<<"Reducing StmtTcontinue\n";
    MyTree * Temp=new MyTree("StmtTcontinue");
    return Temp;
}
//------------------------Stmt------------------------

//------------------------AssignStmt------------------------
MyTree * FunAssignStmt(MyTree * NodeLVal, MyTree * NodeExp)
{
	if(parserDebug)
		cout<<"Reducing AssignStmt\n";
    MyTree * Temp=new MyTree("AssignStmt");
	Temp->newChild(NodeLVal);
	Temp->newChild(NodeExp);
    return Temp;
}
//------------------------AssignStmt------------------------

//------------------------IfStmt------------------------
MyTree * FunIfStmt(MyTree * NodeCond, MyTree * NodeStmt, MyTree * NodeIfStmtnext)
{
	if(parserDebug)
		cout<<"Reducing IfStmt\n";
    MyTree * Temp=new MyTree("IfStmt");
	Temp->newChild(NodeCond);
	Temp->newChild(NodeStmt);
	if(NodeIfStmtnext!=NULL)
		Temp->newChild(NodeIfStmtnext);
    return Temp;
}
//------------------------IfStmt------------------------

//------------------------IfStmtnext------------------------
MyTree * FunIfStmtnext(MyTree * NodeStmt)
{
	if(parserDebug)
		cout<<"Reducing IfStmtnext\n";
    MyTree * Temp=new MyTree("IfStmtnext");
	Temp->newChild(NodeStmt);
    return Temp;
}
//------------------------IfStmtnext------------------------

//------------------------WhileStmt------------------------
MyTree * FunWhileStmt(MyTree * NodeCond, MyTree * NodeStmt)
{
	if(parserDebug)
		cout<<"Reducing WhileStmt\n";
    MyTree * Temp=new MyTree("WhileStmt");
	Temp->newChild(NodeCond);
	Temp->newChild(NodeStmt);
	return Temp;
}
//------------------------WhileStmt------------------------

//------------------------ReturnStmt------------------------
MyTree * FunReturnStmt(MyTree * NodeExp)
{
	if(parserDebug)
		cout<<"Reducing ReturnStmt\n";
    MyTree * Temp=new MyTree("ReturnStmt");
	Temp->newChild(NodeExp);
	return Temp;
}
MyTree * FunReturnStmt()
{
	if(parserDebug)
		cout<<"Reducing ReturnStmt\n";
    MyTree * Temp=new MyTree("ReturnStmt");
	return Temp;
}
//------------------------ReturnStmt------------------------

//------------------------Exp------------------------
MyTree * FunExp(MyTree * NodeAddExp)
{
	if(parserDebug)
		cout<<"Reducing Exp\n";
    MyTree * Temp=new MyTree("Exp");
    Temp->newChild(NodeAddExp);
    return Temp;
}
//------------------------Exp------------------------

//------------------------Cond------------------------
MyTree * FunCond(MyTree * NodeLOrExp)
{
	if(parserDebug)
		cout<<"Reducing Cond\n";
    MyTree * Temp=new MyTree("Cond");
    Temp->newChild(NodeLOrExp);
    return Temp;
}
//------------------------Cond------------------------

//------------------------LVal------------------------
MyTree * FunLVal(MyTree * NodeTident)
{
	if(parserDebug)
		cout<<"Reducing LVal\n";
    MyTree * Temp=new MyTree("LVal");
    Temp->newChild(NodeTident);
    return Temp;
}
MyTree * FunLVal(MyTree * NodeLVal, MyTree * NodeExp)
{
	if(parserDebug)
		cout<<"Reducing LVal\n";
    MyTree * Temp=new MyTree("LVal");
    Temp->newChild(NodeLVal);
	Temp->newChild(NodeExp);
    return Temp;
}
//------------------------LVal------------------------

//------------------------PrimaryExp------------------------
MyTree * FunPrimaryExp(MyTree * Node)
{
	if(parserDebug)
		cout<<"Reducing PrimaryExp\n";
    MyTree * Temp=new MyTree("PrimaryExp");
    Temp->newChild(Node);
    return Temp;
}
//------------------------PrimaryExp------------------------

//------------------------Number------------------------
MyTree * FunNumber(MyTree * NodeTconstint)
{
	if(parserDebug)
		cout<<"Reducing Number\n";
    MyTree * Temp=new MyTree("Number");
    Temp->newChild(NodeTconstint);
    return Temp;
}
//------------------------Number------------------------

//------------------------IntConst------------------------
MyTree * FunIntConstTdec(MyTree * NodeTdec)
{
	if(parserDebug)
		cout<<"Reducing IntConstTdec\n";
    MyTree * Temp=new MyTree("Tdec");
    Temp->newChild(NodeTdec);
    return Temp;
}
MyTree * FunIntConstThex(MyTree * NodeThex)
{
	if(parserDebug)
		cout<<"Reducing IntConstThex\n";
    MyTree * Temp=new MyTree("Thex");
    Temp->newChild(NodeThex);
    return Temp;
}
MyTree * FunIntConstToct(MyTree * NodeToct)
{
	if(parserDebug)
		cout<<"Reducing IntConstToct\n";
    MyTree * Temp=new MyTree("Toct");
    Temp->newChild(NodeToct);
    return Temp;
}
//------------------------IntConst------------------------

//------------------------一元表达式------------------------
MyTree * FunUnaryExp(MyTree * NodePrimaryExp)
{
	if(parserDebug)
		cout<<"Reducing UnaryExp\n";
    return NodePrimaryExp;
}
MyTree * FunUnaryExpFun(MyTree * NodeTident)
{
	if(parserDebug)
		cout<<"Reducing UnaryExpFun\n";
	MyTree * Temp=new MyTree("UnaryExpFun");
    Temp->newChild(NodeTident);
	return Temp;
}
MyTree * FunUnaryExpFunWithPara(MyTree * NodeTident, MyTree * NodeFuncRParams)
{
	if(parserDebug)
		cout<<"Reducing UnaryExpFunWithPara\n";
	MyTree * Temp=new MyTree("UnaryExpFunWithPara");
    Temp->newChild(NodeTident);
	Temp->newChild(NodeFuncRParams);
	return Temp;
}
MyTree * FunUnaryExpOp(MyTree * NodeUnaryOp, MyTree * NodeUnaryExp)
{
	if(parserDebug)
		cout<<"Reducing UnaryExpOp\n";
	NodeUnaryOp->newChild(NodeUnaryExp);
	return NodeUnaryOp;
}
//------------------------一元表达式------------------------

//------------------------FuncRParams------------------------
MyTree * FunFuncRParams(MyTree * NodeFuncRParams, MyTree * NodeExp)
{
	if(parserDebug)
		cout<<"Reducing FuncRParams\n";
	MyTree * Temp=new MyTree("FuncRParams");
    Temp->newChild(NodeFuncRParams);
	Temp->newChild(NodeExp);
	return Temp;
}
MyTree * FunFuncRParams(MyTree * NodeExp)
{
	if(parserDebug)
		cout<<"Reducing FuncRParams\n";
	MyTree * Temp=new MyTree("FuncRParams");
	Temp->newChild(NodeExp);
	return Temp;
}
MyTree * FunFuncRParamsStr(MyTree * NodeTformatStr)
{
	if(parserDebug)
		cout<<"Reducing FuncRParamsStr\n";
	MyTree * Temp=new MyTree("FuncRParamsStr");
	Temp->newChild(NodeTformatStr);
	return Temp;
}
//------------------------FuncRParams------------------------

//------------------------乘除模表达式------------------------
MyTree * FunMulExp_mul(MyTree * NodeMulExp, MyTree * NodeUnaryExp)
{
	if(parserDebug)
		cout<<"Reducing MulExp_mul\n";
    MyTree * Temp=new MyTree("*");
    Temp->newChild(NodeMulExp);
	Temp->newChild(NodeUnaryExp);
    return Temp;
}
MyTree * FunMulExp_div(MyTree * NodeMulExp, MyTree * NodeUnaryExp)
{
	if(parserDebug)
		cout<<"Reducing MulExp_div\n";
    MyTree * Temp=new MyTree("/");
    Temp->newChild(NodeMulExp);
	Temp->newChild(NodeUnaryExp);
    return Temp;
}
MyTree * FunMulExp_mod(MyTree * NodeMulExp, MyTree * NodeUnaryExp)
{
	if(parserDebug)
		cout<<"Reducing MulExp_mod\n";
    MyTree * Temp=new MyTree("%");
    Temp->newChild(NodeMulExp);
	Temp->newChild(NodeUnaryExp);
    return Temp;
}
//------------------------乘除模表达式------------------------


//------------------------加法表达式------------------------
MyTree * FunAddExp_add(MyTree * NodeAddExp, MyTree * NodeMulExp)
{
	if(parserDebug)
		cout<<"Reducing AddExp_add\n";
    MyTree * Temp=new MyTree("+");
    Temp->newChild(NodeAddExp);
	Temp->newChild(NodeMulExp);
    return Temp;
}

MyTree * FunAddExp_sub(MyTree * NodeAddExp, MyTree * NodeMulExp)
{
	if(parserDebug)
		cout<<"Reducing AddExp_sub\n";
    MyTree * Temp=new MyTree("-");
    Temp->newChild(NodeAddExp);
	Temp->newChild(NodeMulExp);
    return Temp;
}
//------------------------加法表达式------------------------

//------------------------RelExp------------------------
MyTree * FunRelExp_Add(MyTree * NodeAddExp)
{
	if(parserDebug)
		cout<<"Reducing RelExp_Add\n";
	return NodeAddExp;
}
MyTree * FunRelExp_TGT(MyTree * NodeRelExp, MyTree * NodeAddExp)
{
	if(parserDebug)
		cout<<"Reducing RelExp_TGT\n";
    MyTree * Temp=new MyTree(">");
    Temp->newChild(NodeRelExp);
	Temp->newChild(NodeAddExp);
    return Temp;
}
MyTree * FunRelExp_TLT(MyTree * NodeRelExp, MyTree * NodeAddExp)
{
	if(parserDebug)
		cout<<"Reducing RelExp_TLT\n";
    MyTree * Temp=new MyTree("<");
    Temp->newChild(NodeRelExp);
	Temp->newChild(NodeAddExp);
    return Temp;
}
MyTree * FunRelExp_TGE(MyTree * NodeRelExp, MyTree * NodeAddExp)
{
	if(parserDebug)
		cout<<"Reducing RelExp_TGE\n";
    MyTree * Temp=new MyTree(">=");
    Temp->newChild(NodeRelExp);
	Temp->newChild(NodeAddExp);
    return Temp;
}
MyTree * FunRelExp_TLE(MyTree * NodeRelExp, MyTree * NodeAddExp)
{
	if(parserDebug)
		cout<<"Reducing RelExp_TLE\n";
    MyTree * Temp=new MyTree("<=");
    Temp->newChild(NodeRelExp);
	Temp->newChild(NodeAddExp);
    return Temp;
}
//------------------------RelExp------------------------

//------------------------EqExp------------------------
MyTree * FunEqExp_Rel(MyTree * NodeRelExp)
{
	if(parserDebug)
		cout<<"Reducing EqExp_Rel\n";
	return NodeRelExp;
}
MyTree * FunEqExp_isEqual(MyTree * NodeEqExp, MyTree * NodeRelExp)
{
	if(parserDebug)
		cout<<"Reducing EqExp_isEqual\n";
    MyTree * Temp=new MyTree("==");
    Temp->newChild(NodeEqExp);
	Temp->newChild(NodeRelExp);
    return Temp;
}
MyTree * FunEqExp_notEqual(MyTree * NodeEqExp, MyTree * NodeRelExp)
{
	if(parserDebug)
		cout<<"Reducing EqExp_notEqual\n";
    MyTree * Temp=new MyTree("!=");
    Temp->newChild(NodeEqExp);
	Temp->newChild(NodeRelExp);
    return Temp;
}
//------------------------EqExp------------------------

//------------------------LAndExp------------------------
MyTree * FunLAndExp_EqExp(MyTree * NodeEqExp)
{
	if(parserDebug)
		cout<<"Reducing LAndExp_EqExp\n";
    return NodeEqExp;
}
MyTree * FunLAndExp_And(MyTree * NodeLAndExp, MyTree * NodeEqExp)
{
	if(parserDebug)
		cout<<"Reducing LAndExp_And\n";
    MyTree * Temp=new MyTree("&&");
    Temp->newChild(NodeLAndExp);
	Temp->newChild(NodeEqExp);
    return Temp;
}
//------------------------LAndExp------------------------

//------------------------LOrExp------------------------
MyTree * FunLOrExp_And(MyTree * NodeLAndExp)
{
	if(parserDebug)
		cout<<"Reducing LOrExp_And\n";
    return NodeLAndExp;
}
MyTree * FunLOrExp_Or(MyTree * NodeLOrExp, MyTree * NodeLAndExp)
{
	if(parserDebug)
		cout<<"Reducing LOrExp_Or\n";
    MyTree * Temp=new MyTree("||");
    Temp->newChild(NodeLOrExp);
	Temp->newChild(NodeLAndExp);
    return Temp;
}
//------------------------LOrExp------------------------


MyTree * FunConstExp(MyTree * NodeAddExp)
{
	if(parserDebug)
		cout<<"Reducing ConstExp\n";
    MyTree * Temp=new MyTree("ConstExp");
    Temp->newChild(NodeAddExp);
    return Temp;
}
