%{
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
%}

%token T_int T_break T_const T_continue T_default T_do T_else T_for T_goto T_if T_return T_static T_void T_while
%token T_add T_sub T_mul T_div T_assign T_mod T_not T_and T_or T_isEqual T_notEqual T_GT T_LT T_GE T_LE
%token T_comma T_sem T_leftPar T_rightPar T_leftBra T_rightBra T_leftCur T_rightCur
%token T_dec T_hex T_oct
%token T_rowCom T_leftCom T_rightCom
%token T_ident T_IntConst
%token T_singleNote T_multiNote
%token T_formatStr
%token T_error
%%

CompUnit:   CompUnit Decl			{$$=FunCompUnit2($1, $2);	}
		|	CompUnit FuncDef		{$$=FunCompUnit2($1, $2);	}
		|	Decl					{$$=FunCompUnit1($1);		}
		|	FuncDef					{$$=FunCompUnit1($1);		}
        ;

Decl:   VarDecl						{$$=FunDecl($1);			}
	|	ConstDecl					{$$=FunDecl($1);			}
    ;

ConstDecl:	ConstDeclStmt T_sem		{$$=FunConstDecl($1);		}
		;

ConstDeclStmt:	T_const BType ConstDef				{$$=FunConstDeclStmt($2, $3);		}
			|	ConstDeclStmt T_comma ConstDef		{$$=FunConstDeclStmt($1, $3);		}
			;	

BType:   T_int                           			{$$=FunBType();						}
	;

ConstDef:	T_ident ConstDefArrayRepeat T_assign ConstInitVal				{$$=FunConstDef($1, $2, $4);		}	
		;

ConstDefArrayRepeat:	T_leftBra ConstExp T_rightBra ConstDefArrayRepeat	{$$=FunConstDefArrayRepeat($2, $4);	}
				|	/* empty */												{$$=NULL;							}
				;

ConstInitVal:	ConstExp													{$$=FunConstInitVal($1);			}
			|	T_leftCur T_rightCur										{$$=FunConstInitVal();				}
			| 	T_leftCur ConstInitVal ConstInitValRepeat T_rightCur		{$$=FunConstInitVal($2, $3);		}
			;

ConstInitValRepeat:	T_comma ConstInitVal ConstInitValRepeat					{$$=FunConstInitValRepeat($2, $3);	}
				|	/* empty */												{$$=NULL;}
				;

VarDecl:	BType VarDef VarDeclRepeat T_sem					{$$=FunVarDecl($1, $2, $3);			}
		;

VarDeclRepeat:	T_comma VarDef VarDeclRepeat					{$$=FunVarDeclRepeat($2, $3);}
			|	/* empty */										{$$=NULL;							}
			;

VarDef:	VarDefRepeat											{$$=FunVarDef($1);					}
	|	VarDefRepeat T_assign InitVal							{$$=FunVarDef($1, $3);				}
	;

VarDefRepeat:	VarDefRepeat T_leftBra ConstExp T_rightBra		{$$=FunVarDefRepeat($1, $3);		}
			|	T_ident											{$$=FunVarDefRepeat($1);			}
			;

InitVal:	Exp													{$$=FunInitVal($1);					}
		|	T_leftCur T_rightCur								{$$=FunInitVal();					}
		|	T_leftCur InitVal InitValRepeat T_rightCur			{$$=FunInitVal($2, $3);				}
		;

InitValRepeat:	T_comma	InitVal InitValRepeat					{$$=FunInitValRepeat($2, $3);		}
			|	/* empty */										{$$=NULL;							}
			;

FuncDef:	T_void T_ident T_leftPar T_rightPar Block				{$$=FunFuncDefVoid($2, $5);				}
	|		BType  T_ident T_leftPar T_rightPar Block				{$$=FunFuncDefInt($2, $5);				}
	|		T_void T_ident T_leftPar FuncFParams T_rightPar Block	{$$=FunFuncDefVoidWithPara($2, $4, $6);	}
	|		BType  T_ident T_leftPar FuncFParams T_rightPar Block	{$$=FunFuncDefIntWithPara($2, $4, $6);	}
	;


FuncFParams:	FuncFParam FuncFParamsRepeat						{$$=FunFuncFParams($1, $2);			}
		;

FuncFParamsRepeat:	T_comma	FuncFParam FuncFParamsRepeat			{$$=FunFuncFParamsRepeat($2, $3);	}
				|	/* empty */										{$$=NULL;							}
				;

FuncFParam:	BType T_ident											{$$=FunFuncFParam($2);				}
		|	BType T_ident T_leftBra T_rightBra FuncFParamRepeat		{$$=FunFuncFParamWithBra($2, $5);	}
		;	

FuncFParamRepeat:	T_leftBra Exp T_rightBra FuncFParamRepeat		{$$=FunFuncFParamRepeat($2, $4);	}
				|	/* empty */										{$$=NULL;							}
				;

Block:	T_leftCur BlockRepeat T_rightCur							{$$=FunBlock($2);					}
	;

BlockRepeat:	BlockItem BlockRepeat								{$$=FunBlockRepeat($1, $2);			}
		|	/* empty */												{$$=NULL;							}
		;

BlockItem:	Decl													{$$=FunBlockItem($1);				}
		|	Stmt													{$$=FunBlockItem($1);				}
		;

Stmt:	AssignStmt													{$$=FunStmt($1);					}
	|	Exp T_sem													{$$=FunStmt($1);					}
	|	T_sem														{$$=FunStmt();						}
	|	Block														{$$=FunStmt($1);					}
	|	IfStmt														{$$=FunStmt($1);					}
	|	WhileStmt													{$$=FunStmt($1);					}
	|	T_break T_sem												{$$=FunStmtTbreak();				}
	|	T_continue T_sem											{$$=FunStmtTcontinue();				}
	|	ReturnStmt													{$$=FunStmt($1);					}
	;

AssignStmt:	LVal T_assign Exp T_sem									{$$=FunAssignStmt($1, $3);			}
		;

IfStmt:	T_if T_leftPar Cond T_rightPar Stmt IfStmtnext				{$$=FunIfStmt($3, $5, $6);			}
	;

IfStmtnext:	T_else Stmt												{$$=FunIfStmtnext($2);				}
		|	/* empty */												{$$=NULL;							}
		;

WhileStmt:	T_while T_leftPar Cond T_rightPar Stmt					{$$=FunWhileStmt($3, $5);			}
		;

ReturnStmt:	T_return Exp T_sem										{$$=FunReturnStmt($2);				}
		|	T_return T_sem											{$$=FunReturnStmt();				}	
		;

Exp:	AddExp											{$$=FunExp($1);						}
	;

Cond:	LOrExp											{$$=FunCond($1);					}
	;

LVal:	T_ident											{$$=FunLVal($1);					}
	|	LVal T_leftBra Exp T_rightBra					{$$=FunLVal($1, $3);				}
	;

PrimaryExp:	T_leftPar Exp T_rightPar					{$$=FunPrimaryExp($2);				}
		|	LVal										{$$=FunPrimaryExp($1);				}
		|	Number										{$$=FunPrimaryExp($1);				}
		;

Number:	IntConst										{$$=FunNumber($1);					}
	;
IntConst:	T_dec										{$$=FunIntConstTdec($1);			}
		|	T_hex										{$$=FunIntConstThex($1);			}
		|	T_oct										{$$=FunIntConstToct($1);			}
		;
UnaryExp:	PrimaryExp									{$$=FunUnaryExp($1);				}
		|	T_ident T_leftPar T_rightPar				{$$=FunUnaryExpFun($1);				}
		|	T_ident T_leftPar FuncRParams T_rightPar	{$$=FunUnaryExpFunWithPara($1, $3);	}
		|	UnaryOp UnaryExp							{$$=FunUnaryExpOp($1, $2);			}
		;

UnaryOp:	T_add										{$$=new MyTree("+");				}
	|	T_sub											{$$=new MyTree("-");				}
	|	T_not											{$$=new MyTree("!");				}
	;

FuncRParams:	FuncRParams	T_comma	Exp					{$$=FunFuncRParams($1, $3);			}
		|	Exp											{$$=FunFuncRParams($1);				}
		|	T_formatStr									{$$=FunFuncRParamsStr($1);			}	
		;

MulExp:	UnaryExp						{$$=$1;								}
	|	MulExp T_mul UnaryExp			{$$=FunMulExp_mul($1, $3);			}
	|	MulExp T_div UnaryExp			{$$=FunMulExp_div($1, $3);			}
	|	MulExp T_mod UnaryExp			{$$=FunMulExp_mod($1, $3);			}
	;

AddExp:	MulExp							{$$=$1;								}
	|	AddExp T_add MulExp				{$$=FunAddExp_add($1, $3);			}
	|	AddExp T_sub MulExp				{$$=FunAddExp_sub($1, $3);			}
	;

RelExp:	AddExp							{$$=FunRelExp_Add($1);				}
	|	RelExp T_GT AddExp				{$$=FunRelExp_TGT($1, $3);			}
	|	RelExp T_LT AddExp				{$$=FunRelExp_TLT($1, $3);			}
	|	RelExp T_GE AddExp				{$$=FunRelExp_TGE($1, $3);			}
	|	RelExp T_LE AddExp				{$$=FunRelExp_TLE($1, $3);			}
	;

EqExp:	RelExp							{$$=FunEqExp_Rel($1);				}
	|	EqExp T_isEqual RelExp			{$$=FunEqExp_isEqual($1, $3);		}
	|	EqExp T_notEqual RelExp			{$$=FunEqExp_notEqual($1, $3);		}
	;

LAndExp:	EqExp						{$$=FunLAndExp_EqExp($1);			}
	|	LAndExp T_and EqExp				{$$=FunLAndExp_And($1, $3);			}
	;

LOrExp:	LAndExp							{$$=FunLOrExp_And($1);				}
	|	LOrExp T_or LAndExp				{$$=FunLOrExp_Or($1, $3);			}
	;

ConstExp:	AddExp						{$$=FunConstExp($1);				}
		;

%%

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