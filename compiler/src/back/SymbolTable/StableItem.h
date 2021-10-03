#ifndef STABLEITEM_H
#define STABLEITEM_H

#define KIND_CONST 1
#define KIND_VAR 2

#define TYPE_INT 1
#define TYPE_ARRAY 2

#include <string>
#include "AtableHead.h"
using namespace std;

struct StableItem
{
    int adrVal;
    int kind;       //常量还是变量还是过程
    int type;       //是int 还是  int[]类型
    bool normal;    //是否为形参
    AtableHead ref;

    StableItem& operator = (const StableItem & b){
        kind =  b.kind;
        type =  b.type;
        normal =  b.normal;
        ref =  b.ref;
        adrVal =b.adrVal;
        return *this;
    }
};
#endif 