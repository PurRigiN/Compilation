#include <string>
#include <iostream>
#include <fstream>
#include "BackAnalyzer.h"
#include "SymbolTable/StableHead.h"
#include "SymbolTable/StableItem.h"
#include "SymbolTable/AtableHead.h"
#include "SymbolTable/AtableItem.h"
#include "SymbolTable/SymbolTable.h"
#include "../Token/Token.h"
#include "../MyTree/MyTree.h"

using namespace std;

BackAnalyzer::BackAnalyzer(char * objectDir, MyTree * StartNode,bool ifDebug)
{
    dataFile.open(string(objectDir),ios::out);
    this->StartNode=StartNode;
    this->ifDebug=ifDebug;
    blockLev=0;
    asmStr="";
    ifInMainFun=false;

    //RValue初始化
    StableHead temp;
    temp.lev=0;
    temp.name="";
    for(int i=0;i<7;i++)
    {
        RValue[i]=temp;
    }
    regSelector=0;
    spSpace=0;
}
BackAnalyzer::~BackAnalyzer()
{
    dataFile.close();
    delete StartNode;
}
bool BackAnalyzer::analyze()
{
    string headStr=".arch armv7\n.arch armv7ve\n.global main\n";
    dataFile<<headStr;
    AnaCompUnit(StartNode);
    dataFile<<"\n";
    return true;
}

void BackAnalyzer::AnaCompUnit(MyTree * Node)
{
    if(Node->getchild_num()==1)
    {
        MyTree * childNode=Node->getLeftMostChild();
        if(childNode->token.str=="Decl")
        {
            AnaDecl(childNode);
        }
        else
        {
            AnaFuncDefHelp(childNode);
        }
    }
    else
    {
        MyTree * CompUnitNode_=Node->getLeftMostChild();
        AnaCompUnit(CompUnitNode_);
        MyTree * nextNode=CompUnitNode_->getRightSibling();
        if(nextNode->token.str=="Decl")
        {
            AnaDecl(nextNode);
        }
        else
        {
            AnaFuncDefHelp(nextNode);
        }

    }
}

//-----------------------Decl-----------------------
void BackAnalyzer::AnaDecl(MyTree * Node)
{
    MyTree * childNode=Node->getLeftMostChild();
    if(childNode->token.str=="VarDecl")
        AnaVarDecl(childNode);
    else
        AnaConstDecl(childNode);

}

void BackAnalyzer::AnaVarDecl(MyTree * Node)
{
    if(Node->getchild_num()==2)
    {
        MyTree * varDefNode=Node->getLeftMostChild()->getRightSibling();
        AnaVarDef(varDefNode);
    }
    else
    {
        MyTree * varDefNode=Node->getLeftMostChild()->getRightSibling();
        MyTree * varDefRepeatNode=varDefNode->getRightSibling();
        AnaVarDef(varDefNode);
        AnaVarDeclRepeat(varDefRepeatNode);
    }
}

void BackAnalyzer::AnaVarDef(MyTree * Node)
{
    string identStr="";
    MyTree * varArrayTree=new MyTree("-");
    MyTree * RepeatNode=Node->getLeftMostChild();
    identStr=AnaVarDefRepeatHelp(RepeatNode,varArrayTree);
    //是int型
    if(varArrayTree->getchild_num()==0)
    {
        StableItem item;
        item.adrVal=spSpace;
        spSpace=4+spSpace;
        item.kind=KIND_VAR;
        item.type=TYPE_INT;
        item.normal=false;
        AtableHead tempRef;
        tempRef.dimen=0;
        tempRef.lev=0;
        tempRef.name="";
        item.ref=tempRef;
        StableHead head;
        head.name=identStr;
        head.lev=blockLev;
        symbolTable.addToStable(head,item);
    }
    //是数组型
    else
    {
        //Todo
    }
    //如果有，则执行初始化函数
    if(Node->getchild_num()==2)
    {
        AnaInitVal(RepeatNode->getRightSibling(),varArrayTree);
    }
    
    delete varArrayTree;
    
}
void BackAnalyzer::AnaVarDeclRepeat(MyTree * Node)
{
    if(Node->getchild_num()==1)
    {
        AnaVarDef(Node->getLeftMostChild());
    }
    else
    {
        MyTree * VardefNode=Node->getLeftMostChild();
        MyTree * varDefRepeatNode=VardefNode->getRightSibling();
        AnaVarDef(VardefNode);
        AnaVarDeclRepeat(varDefRepeatNode);

    }
}

string BackAnalyzer::AnaVarDefRepeat(MyTree * Node)
{
    return "?";
}
string BackAnalyzer::AnaVarDefRepeatHelp(MyTree * Node, MyTree * varArrayNode)
{
    //找到了ident，写入头
    if(Node->getchild_num()==1)
    {
        varArrayNode->token.str=Node->getLeftMostChild()->token.str;
        return varArrayNode->token.str;
    }
    //到达的是数组的维数
    else
    {
        MyTree * RepeatNode=Node->getLeftMostChild();
        MyTree * ConstExpNode=RepeatNode->getRightSibling();
        //先找到ident，找到之后，将算出的各维数目添加到树中
        string identStr="";
        identStr=AnaVarDefRepeatHelp(RepeatNode,varArrayNode);
        int numberOfArray=AnaConstExp(ConstExpNode);
        Token temp;
        temp.num=numberOfArray;
        temp.str="array";
        varArrayNode->newChild(temp);
        return identStr;

    }
}

void BackAnalyzer::AnaConstDecl(MyTree * Node)
{

}
//-----------------------Decl-----------------------

void BackAnalyzer::AnaInitVal(MyTree * Node, MyTree * varTreeNode)
{   
    //一个意味着Exp或者空数组
    if(Node->getchild_num()==1)
    {
        MyTree * childNode=Node->getLeftMostChild();
        if(childNode->token.str=="Exp")
        {
            string expRegStr=AnaExp(childNode,"-");
            string identStr=varTreeNode->token.str;
            StableHead head;
            head.name=identStr;
            head.lev=blockLev;
            StableItem item=symbolTable.findStableItem(head);
            //如果变量是int类型，直接赋值
            if(item.type==TYPE_INT)
            {
                asmStr+="\tstr\t"+expRegStr+", [r7, #"+to_string(item.adrVal)+"]\n";
            }
            else if(item.type==TYPE_ARRAY)
            {

            }
        }
    }
    else
    {

    }
}

int BackAnalyzer::AnaConstExp(MyTree * Node)
{
    //Todo
    return 1;
}


//-----------------------FuncDefHelp-----------------------
void BackAnalyzer::AnaFuncDefHelp(MyTree * Node)
{
    if(Node->token.str=="FuncDefInt")
        AnaFuncDefInt(Node);
    //Todo
}
//-----------------------FuncDefHelp-----------------------

//-----------------------FuncDefInt-----------------------
void BackAnalyzer::AnaFuncDefInt(MyTree * Node)
{
    MyTree * identNode=Node->getLeftMostChild()->getRightSibling();
    //主函数
    if(identNode->token.str=="main")
    {
        ifInMainFun=true;
        asmStr+=".type\tmain, %function\n";
        asmStr+="main:\n";
        asmStr+="\tpush	{r1, r2, r3, r4, r5, r6, r7, lr}\n";
        dataFile<<asmStr;
        asmStr="";
        AnaBlock(identNode->getRightSibling());
        //由return语句释放空间并跳转
        //sub 分配空间
        if(spSpace!=0)
        {
            string temp="";
            temp+="\tsub sp, sp, #"+to_string(spSpace)+"\n";
            temp+="\tadd r7, sp ,#0\n";
            asmStr=temp+asmStr;
            spSpace=0;
        }
        dataFile<<asmStr;
        asmStr="";
        ifInMainFun=false;
    }
    else
    {
        //Todo
    }
}
//-----------------------FuncDefInt-----------------------

//-----------------------Block-----------------------
void BackAnalyzer::AnaBlock(MyTree * Node)
{
    blockLev+=1;
    AnaBlockRepeat(Node->getLeftMostChild());
    blockLev-=1;
}
void BackAnalyzer::AnaBlockRepeat(MyTree * Node)
{
    //只有一个
    if(Node->getchild_num()==1)
    {
        AnaBlockItem(Node->getLeftMostChild());
    }
    else
    {
        MyTree * itemNode=Node->getLeftMostChild();
        MyTree * repeatNode=itemNode->getRightSibling();
        AnaBlockItem(itemNode);
        AnaBlockRepeat(repeatNode);
    }
}
void BackAnalyzer::AnaBlockItem(MyTree * Node)
{
    if(Node->getLeftMostChild()->token.str=="Decl")
    {
        AnaDecl(Node->getLeftMostChild());
    }
    //Stmt
    else
    {
        AnaStmt(Node->getLeftMostChild());
    }
}
//-----------------------Block-----------------------

//-----------------------Stmt-----------------------
void BackAnalyzer::AnaStmt(MyTree * Node)
{
    MyTree * childNode=Node->getLeftMostChild();
    if(childNode->token.str=="ReturnStmt")
    {
        AnaReturnStmt(childNode);
    }
    else if(childNode->token.str=="AssignStmt")
    {
        AnaAssignStmt(childNode);
    }
    //Todo
}
//-----------------------Stmt-----------------------

//-----------------------ReturnStmt-----------------------
void BackAnalyzer::AnaReturnStmt(MyTree * Node)
{
    if(!ifInMainFun)
    {
        if(Node->getchild_num()==0)
        {
            if(spSpace!=0)
            {
                asmStr+="\tadd\tr7, r7, #"+to_string(spSpace)+"\n";
                asmStr+="\tmov	sp, r7\n";
            }
            asmStr+="\tbx lr\n";
        }
        else
        {
            string regStr=AnaExp(Node->getLeftMostChild(),"-");
            if(spSpace!=0)
            {
                asmStr+="\tadd\tr7, r7, #"+to_string(spSpace)+"\n";
                asmStr+="\tmov	sp, r7\n";
            }
            if(regStr!="r0")
            {
                asmStr+="\tmov r0, "+regStr+"\n";
                asmStr+="\tbx lr\n";
            }
            else
            {
                asmStr+="\tbx lr\n";
            }
                
        }
    }
    else
    {
        if(Node->getchild_num()==0)
        {
            if(spSpace!=0)
            {
                asmStr+="\tadd\tr7, r7, #"+to_string(spSpace)+"\n";
                asmStr+="\tmov	sp, r7\n";
            }
            asmStr+="\tpop	{r1, r2, r3, r4, r5, r6, r7, pc}\n";
        }
        else
        {
            string regStr=AnaExp(Node->getLeftMostChild(),"-");
            if(spSpace!=0)
            {
                asmStr+="\tadd\tr7, r7, #"+to_string(spSpace)+"\n";
                asmStr+="\tmov	sp, r7\n";
            }
            if(regStr!="r0")
            {
                asmStr+="\tmov r0, "+regStr+"\n";
                asmStr+="\tpop	{r1, r2, r3, r4, r5, r6, r7, pc}\n";
            }
            else
            {
                asmStr+="\tpop	{r1, r2, r3, r4, r5, r6, r7, pc}\n";
            }
                
        }
    }
}
//-----------------------ReturnStmt-----------------------

void BackAnalyzer::AnaAssignStmt(MyTree * Node)
{
    MyTree * LValNode=Node->getLeftMostChild();
    MyTree * ExpNode=LValNode->getRightSibling();
    string expRegStr=AnaExp(ExpNode,"-");
    AnaLValSave(LValNode,expRegStr);
}

//-----------------------ExpHelp-----------------------
string BackAnalyzer::AnaExpHelp(MyTree * Node, string preReg)
{
    string nodeStr=Node->token.str;
    if(nodeStr=="+")
    {
        return Anaadd(Node,preReg);
    }
    else if(nodeStr=="-")
    {
        return Anasub(Node,preReg);
    }
    else if(nodeStr=="*")
    {
        return Anamul(Node, preReg);
    }
    else if(nodeStr=="/")
    {
        return Anadiv(Node, preReg);
    }
    else if(nodeStr=="%")
    {
        return Anamod(Node, preReg);
    }
    else if(nodeStr=="UnaryExpFun")
    {
        return AnaUnaryExpFun(Node, preReg);
    }
    else if(nodeStr=="UnaryExpFunWithPara")
    {
        return AnaUnaryExpFunWithPara(Node, preReg);
    }
    else if (nodeStr=="PrimaryExp")
    {
        return AnaPrimaryExp(Node, preReg);  
    }
    else if (nodeStr=="!")
    {
        return Ananon(Node, preReg);  
    }
    else
    {
        cout<<"Error: can not find fun for "+nodeStr<<endl;
        return "0";
    }
}
//-----------------------ExpHelp-----------------------

string BackAnalyzer::AnaLVal(MyTree * Node, string preReg)
{
    //只有一个，只是变量名
    if(Node->getchild_num()==1)
    {
        string identStr=Node->getLeftMostChild()->token.str;
        StableHead head;
        head.name=identStr;
        head.lev=blockLev;
        StableItem item=symbolTable.findStableItem(head);
        if(item.kind==KIND_VAR)
        {
            string regStr=getReg(preReg);
            asmStr+="\tldr\t"+regStr+", [r7, #"+to_string(item.adrVal)+"]\n";
            return  regStr;
        }
        else if(item.kind==KIND_CONST)
        {
            string regStr=getReg(preReg);
            if( item.adrVal<=0xffff&&item.adrVal>-0xffff)
            {
                asmStr+="\tmov\t"+regStr+", #"+to_string(item.adrVal)+"\n";
                return regStr;
            }
            else
            {
                //Todo
                cout<<"Todo AnaLVal"<<endl;
            }
            
        }
    }
    //数组的相关引用
    else
    {
        //Todo
    }
}

//-----------------------PrimaryExp-----------------------

void BackAnalyzer::AnaLValSave(MyTree * Node, string objReg)
{
    //意味着只是一个int变量
    if(Node->getchild_num()==1)
    {
        MyTree * identNode=Node->getLeftMostChild();
        string ident=identNode->token.str;
        StableHead head;
        head.lev=blockLev;
        head.name=ident;
        StableItem item=symbolTable.findStableItem(head);
        asmStr+="\tstr\t"+objReg+", [r7, #"+to_string(item.adrVal)+"]\n";
    }
    else
    {
        //Todo
    }
}

string BackAnalyzer::AnaPrimaryExp(MyTree * Node, string preReg)
{
    MyTree * childNode=Node->getLeftMostChild();
    if(childNode->token.str=="Number")
    {
        int numValue=AnaNumber(childNode);
        if(numValue<=0xffff&&numValue>-0xffff)
        {
            string reg=getReg(preReg);
            asmStr+="\tmov "+reg+", #"+to_string(numValue)+"\n";
            return reg;
        }
        else
        {
            //Todo
            cout<<"Todo AnaPrimaryExp"<<endl;
        }
    }
    else if(childNode->token.str=="LVal")
    {
        return AnaLVal(childNode,preReg);
    }
    else
    {
        return AnaExpHelp(childNode,preReg);
    }
}
//-----------------------PrimaryExp-----------------------

//-----------------------Exp-----------------------
string BackAnalyzer::AnaExp(MyTree * Node, string preReg)
{
    MyTree * childNode=Node->getLeftMostChild();
    return AnaExpHelp(childNode, preReg);
}
//-----------------------Exp-----------------------

//-----------------------add-----------------------
string BackAnalyzer::Anaadd(MyTree * Node, string preReg)
{
    //如果结点是单节点，加法意味着取正数，无意义
    if(Node->getchild_num()==1)
    {
        return AnaExpHelp(Node,preReg);
    }
    MyTree * leftNode =Node->getLeftMostChild();
    MyTree * RightNode=leftNode->getRightSibling();
    //对左节点运算
    string regStrLeft;
    regStrLeft = AnaExpHelp(leftNode,preReg);
    
    //保护该寄存器
    asmStr+="\tpush {"+regStrLeft+"}\n";
    //对右节点进行运算
    string regStrRight;
    regStrRight = AnaExpHelp(RightNode,regStrLeft);
    
    //运算完对两个结果进行相加
    asmStr+="\tpop  {"+regStrLeft+"}\n";
    asmStr+="\tadd "+regStrLeft+", "+regStrLeft+", "+regStrRight+"\n";
    return regStrLeft;

}
//-----------------------add-----------------------

//-----------------------sub-----------------------
string BackAnalyzer::Anasub(MyTree * Node, string preReg)
{
    //意味着需要做取相反数操作
    if(Node->getchild_num()==1)
    {
        string regStrsub = AnaExpHelp(Node,preReg);
        asmStr+="\trsb\t"+regStrsub+", "+regStrsub+", #0\n";
        return regStrsub;
    }
    MyTree * leftNode =Node->getLeftMostChild();
    MyTree * RightNode=leftNode->getRightSibling();
    //对左节点运算
    string regStrLeft;
    regStrLeft = AnaExpHelp(leftNode,preReg);
    
    //保护该寄存器
    asmStr+="\tpush\t{"+regStrLeft+"}\n";
    //对右节点进行运算
    string regStrRight;
    regStrRight = AnaExpHelp(RightNode,regStrLeft);
    
    //运算完对两个结果进行相加
    asmStr+="\tpop\t{"+regStrLeft+"}\n";
    asmStr+="\tsub\t"+regStrLeft+", "+regStrLeft+", "+regStrRight+"\n";
    return regStrLeft;
}
//-----------------------sub-----------------------

//-----------------------mul-----------------------
string BackAnalyzer::Anamul(MyTree * Node, string preReg)
{
    MyTree * leftNode =Node->getLeftMostChild();
    MyTree * RightNode=leftNode->getRightSibling();
    //对左节点运算
    string regStrLeft;
    regStrLeft = AnaExpHelp(leftNode,preReg);
    
    //保护该寄存器
    asmStr+="\tpush\t{"+regStrLeft+"}\n";
    //对右节点进行运算
    string regStrRight;
    regStrRight = AnaExpHelp(RightNode,regStrLeft);
    
    //运算完对两个结果进行相加
    asmStr+="\tpop\t{"+regStrLeft+"}\n";
    asmStr+="\tmul\t"+regStrLeft+", "+regStrLeft+", "+regStrRight+"\n";
    return regStrLeft;
}
//-----------------------mul-----------------------

//-----------------------div-----------------------
string BackAnalyzer::Anadiv(MyTree * Node, string preReg)
{
    MyTree * leftNode =Node->getLeftMostChild();
    MyTree * RightNode=leftNode->getRightSibling();
    //对左节点运算
    string regStrLeft;
    regStrLeft = AnaExpHelp(leftNode,preReg);
    
    //保护该寄存器
    asmStr+="\tpush\t{"+regStrLeft+"}\n";
    //对右节点进行运算
    string regStrRight;
    regStrRight = AnaExpHelp(RightNode,regStrLeft);
    
    //运算完对两个结果进行相加
    asmStr+="\tpop\t{"+regStrLeft+"}\n";
    asmStr+="\tsdiv\t"+regStrLeft+", "+regStrLeft+", "+regStrRight+"\n";
    return regStrLeft;
}
//-----------------------div-----------------------

//-----------------------mod-----------------------
string BackAnalyzer::Anamod(MyTree * Node, string preReg)
{

}
//-----------------------mod-----------------------

//-----------------------non-----------------------

string BackAnalyzer::Ananon(MyTree * Node, string preReg)
{

}
//-----------------------non-----------------------

//-----------------------UnaryExpFun-----------------------
string BackAnalyzer::AnaUnaryExpFun(MyTree * Node, string preReg)
{

}
string BackAnalyzer::AnaUnaryExpFunWithPara(MyTree * Node, string preReg)
{

}
//-----------------------UnaryExpFun-----------------------

//-----------------------Number-----------------------
int BackAnalyzer::AnaNumber(MyTree * Node)
{
    MyTree * childNode=Node->getLeftMostChild();
    string typeStr=childNode->token.str;
    if(typeStr=="Tdec")
        return AnaNumberDec(childNode);
    if(typeStr=="Thex")
        return AnaNumberHex(childNode);
    if(typeStr=="Toct")
        return AnaNumberOct(childNode);
    cout<<"None of dec, hex, oct\n";
    return 0;
}
int BackAnalyzer::AnaNumberDec(MyTree * Node)
{
    string numberStr=Node->getLeftMostChild()->token.str;
    // cout<<"numberStr is "<<numberStr<<endl;
    int Dec= strtol(numberStr.c_str(),nullptr,10);
    // cout<<"Number is "<<Dec<<endl;
    return Dec;
}
int BackAnalyzer::AnaNumberHex(MyTree * Node)
{
    string numberStr=Node->getLeftMostChild()->token.str;
    int Hex= strtol(numberStr.c_str(),nullptr,16);
    return Hex;
}
int BackAnalyzer::AnaNumberOct(MyTree * Node)
{
    string numberStr=Node->getLeftMostChild()->token.str;
    int Oct= strtol(numberStr.c_str(),nullptr,8);
    return Oct;
}
//-----------------------Number-----------------------

//-----------------------寄存器分配算法-----------------------
string BackAnalyzer::getReg()
{
    for(int i=0;i<7;i++)
    {
        if(RValue[i].name=="")
        {
            return "r"+to_string(i);
        }
    }
    //如果均没有，则选取一个放入寄存器中
    //Todo
}
string BackAnalyzer::getReg(string preReg)
{
    for(int i=0;i<7;i++)
    {
        if(RValue[i].name==""&&("r"+to_string(i))!=preReg)
        {
            return "r"+to_string(i);
        }
    }
    //如果均没有，则选取一个放入寄存器中
    //Todo
}
//-----------------------寄存器分配算法-----------------------