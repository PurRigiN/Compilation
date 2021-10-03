#ifndef ATABLEITEM_H
#define ATABLEITEM_H
#include <string>
#include "AtableHead.h"
using namespace std;

struct AtableItem
{
    int eltyp;
    AtableHead ref;
    int high;
    int elsize;
    int totalSize;
};
#endif 