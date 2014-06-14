#define myvar 0
#define myconst 1
#define myor 2
#define myand 4
#define myxor 3
#define myno 5
#define open 6
#define close 7
#include "stack.h"
class Operand
{
public:
	int type;
	int x,y;
	Operand()
	{type=x=y=0;
	}
};