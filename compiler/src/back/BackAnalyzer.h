#ifndef BACKANALYZER_H
#define BACKANALYZER_H
#include <string>
#include "SymbolTable/StableHead.h"
#include "SymbolTable/StableItem.h"
#include "SymbolTable/AtableHead.h"
#include "SymbolTable/AtableItem.h"
#include "SymbolTable/SymbolTable.h"
#include <fstream>
#include "../Token/Token.h"
#include "../MyTree/MyTree.h"
using namespace std;

class BackAnalyzer
{
private:
    fstream dataFile;
    MyTree * StartNode;
    bool ifDebug;
    SymbolTable symbolTable;
    int blockLev;
    string asmStr;
    bool ifInMainFun;
    
    //分配算法相关
    StableHead RValue[7];
    int regSelector;
    int spSpace;

    void AnaCompUnit(MyTree * Node);
    void AnaDecl(MyTree * Node);
    void AnaVarDecl(MyTree * Node);
    void AnaConstDecl(MyTree * Node);
    void AnaVarDef(MyTree * Node);
    void AnaVarDeclRepeat(MyTree * Node);
    string AnaVarDefRepeat(MyTree * Node);
    string AnaVarDefRepeatHelp(MyTree * Node, MyTree * varArrayNode);

    void AnaInitVal(MyTree * Node, MyTree * varTreeNode);

    int AnaConstExp(MyTree * Node);

    void AnaFuncDefHelp(MyTree * Node);
    void AnaFuncDefInt(MyTree * Node);

    void AnaBlock(MyTree * Node);
    void AnaBlockRepeat(MyTree * Node);
    void AnaBlockItem(MyTree * Node);
    void AnaStmt(MyTree * Node);
    void AnaReturnStmt(MyTree * Node);
    void AnaAssignStmt(MyTree * Node);

    string AnaExpHelp(MyTree * Node, string preReg);
    string AnaLVal(MyTree * Node, string preReg);
    void AnaLValSave(MyTree * Node, string objReg);
    string AnaPrimaryExp(MyTree * Node, string preReg);
    string AnaExp(MyTree * Node, string preReg);
    string Anaadd(MyTree * Node, string preReg);
    string Anasub(MyTree * Node, string preReg);
    string Anamul(MyTree * Node, string preReg);
    string Anadiv(MyTree * Node, string preReg);
    string Anamod(MyTree * Node, string preReg);
    string Ananon(MyTree * Node, string preReg);
    string AnaUnaryExpFun(MyTree * Node, string preReg);
    string AnaUnaryExpFunWithPara(MyTree * Node, string preReg);

    int AnaNumber(MyTree * Node);
    int AnaNumberDec(MyTree * Node);
    int AnaNumberHex(MyTree * Node);
    int AnaNumberOct(MyTree * Node);

    //寄存器分配算法
    string getReg();
    string getReg(string preReg);
public:
    BackAnalyzer(char * objectDir, MyTree * StartNode,bool ifDebug);
    ~BackAnalyzer();
    bool analyze();
};


#endif 