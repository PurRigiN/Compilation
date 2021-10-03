#ifndef ATABLEHEAD_H
#define ATABLEHEAD_H
#include <string>
using namespace std;

struct AtableHead
{
    string name;
    int lev;
    int dimen;
    bool operator<(const AtableHead b) const
	{
		return this->lev < b.lev;
	}

    AtableHead& operator = (const AtableHead & b){
        name =  b.name;
        lev =  b.lev;
        dimen =  b.dimen;
        return *this;
    }
};
#endif 