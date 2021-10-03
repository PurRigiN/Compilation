#include "SymbolTable.h"
#include "StableHead.h"
#include "StableItem.h"
#include "AtableHead.h"
#include "AtableItem.h"
#include <map>
#include <iostream>
#include <string>

using namespace std;

SymbolTable::SymbolTable(){}

/**
 * @brief 依据模糊头部返回Item
 * 
 * @param stableHead 
 * @return StableItem 
 */
StableItem SymbolTable::findStableItem(StableHead stableHead)
{
    StableHead targetStableHead=findStableHead(stableHead);
    //迭代器
    map<StableHead, StableItem>::iterator  iter;
    if(targetStableHead.lev==0)
    {
        iter=globalStable.find(targetStableHead);
        StableItem item=iter->second;
        return item;
    }
    else
    {
        iter=localStable.find(targetStableHead);
        StableItem item=iter->second;
        // cout<<"adrValOut: "<<(iter->second).adrVal<<endl;
        return item;
    }
    
}

/**
 * @brief 用一个模糊头部，迭代找到对应作用域的头部
 * 
 * @param stableHead 模糊头部
 * @return StableHead 对应作用域的头部
 */
StableHead SymbolTable::findStableHead(StableHead stableHead)
{
    //迭代器
    map<StableHead, StableItem>::iterator  iter;
    int initLev=stableHead.lev;
    StableHead tempItem=stableHead;
    for(int i=initLev;i>0;i--)
    {
        iter=localStable.find(tempItem);
        if(iter!=localStable.end())
        {
            return iter->first;
        }
        else
        {
            tempItem.lev=tempItem.lev-1;
        }
    }
    //循环之后找不到，前往globalTable寻找
    iter=globalStable.find(tempItem);
    if(iter!=globalStable.end())
        return iter->first;
    else
    {   
        cout<<"Error: can Not find ident: "<<tempItem.name<<endl;
        return tempItem;
    }
}

AtableItem SymbolTable::findAtableItem(AtableHead atableHead)
{

}
void SymbolTable::changeStableItem(StableHead stableHead,StableItem stableItem)
{
    StableHead targetStableHead=findStableHead(stableHead);
    //迭代器
    map<StableHead, StableItem>::iterator  iter;
    if(targetStableHead.lev==0)
    {
        iter=globalStable.find(targetStableHead);
        iter->second=stableItem;
    }
    else
    {
        iter=localStable.find(targetStableHead);
        iter->second=stableItem;
    }
}
void SymbolTable::changeAtableItem(AtableHead atableHead,AtableItem atableItem)
{

}


void SymbolTable::addToStable(StableHead stableHead,StableItem stableItem)
{
    if(stableHead.lev==0)
    {
        globalStable.insert(map<StableHead, StableItem>::value_type (stableHead,stableItem));
    }
    else
    {
        localStable.insert(map<StableHead, StableItem>::value_type (stableHead,stableItem));
        cout<<"adrVal: "<<stableItem.adrVal<<endl;
    }
}
void SymbolTable::addToAtable(AtableHead atableHead,AtableItem atableItem)
{
    if(atableHead.lev==0)
    {
        globalAtable.insert(map<AtableHead, AtableItem>::value_type (atableHead,atableItem));
    }
    else
    {
        localAtable.insert(map<AtableHead, AtableItem>::value_type (atableHead,atableItem));
    }
}

void SymbolTable::clearLocalStable()
{
    localStable.clear();
}
void SymbolTable::clearLocalAtable()
{
    localAtable.clear();
}