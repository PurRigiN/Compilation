#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <map>
#include <string>
#include "StableHead.h"
#include "StableItem.h"
#include "AtableHead.h"
#include "AtableItem.h"
using namespace std;

class SymbolTable
{
private:
    map<StableHead,StableItem> globalStable;
    map<StableHead,StableItem> localStable;
    map<AtableHead,AtableItem> globalAtable;
    map<AtableHead,AtableItem> localAtable;

    StableHead findStableHead(StableHead stableHead);
public:
    SymbolTable();
    void changeStableItem(StableHead stableHead,StableItem stableItem);
    void changeAtableItem(AtableHead atableHead,AtableItem atableItem);
    StableItem findStableItem(StableHead stableHead);
    AtableItem findAtableItem(AtableHead atableHead);
    void addToStable(StableHead stableHead,StableItem stableItem);
    void addToAtable(AtableHead atableHead,AtableItem atableItem);
    void clearLocalStable();
    void clearLocalAtable();
};

#endif 