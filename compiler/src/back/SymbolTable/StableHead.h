#ifndef STABLEHEAD_H
#define STABLEHEAD_H
#include <string>
using namespace std;

struct StableHead
{
    string name;
    int lev;
    bool operator<(const StableHead b) const
	{
		if(this->name<b.name)
            return true;
        else if(this->name>b.name)
            return false;
        else
        {
            return this->lev < b.lev;
        }
        
	}

    StableHead& operator = (const StableHead & b){
        name =  b.name;
        lev =  b.lev;
        return *this;
    }
};
#endif 