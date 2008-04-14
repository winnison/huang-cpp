#include "repeat0.h"
#include "repeat1.h"
#include "repeat2.h"
#include "number0.h"
#include "number1.h"
#include "number2.h"

//////////////////////////////////////////////////////////////////////////
// Arrays
//////////////////////////////////////////////////////////////////////////
#define NUMBER(n1,n2,n3,n4)		, NUMBER_NNNN(,,n1,n2,n3,n4)
#define NUMBER_(n1,n2,n3,n4)	NUMBER_NNNN(,,n1,n2,n3,n4)

int a[] = { 0 REPEAT_NNNN(9,9,9,9,NUMBER) };
int b[] = { 0 REPEAT_0_NNNN(9,9,9,9,NUMBER) };
int c[] = { REPEATC_NNNN(9,9,9,9,NUMBER_,NUMBER) };


//////////////////////////////////////////////////////////////////////////
// Functions
//////////////////////////////////////////////////////////////////////////
#define ARG_DEF(n1,n2,n3)		, int NUMBER_NNN(p,,n1,n2,n3)
#define ARG_DEF_(n1,n2,n3)		int NUMBER_NNN(p,,n1,n2,n3)
#define ARG_SUM(n1,n2,n3)		+ NUMBER_NNN(p,,n1,n2,n3)

#define FUNC_DEF(n1,n2,n3)								\
	int func(int p0 REPEAT_NNN(n1,n2,n3,ARG_DEF))		\
	{ return p0 REPEAT_NNN(n1,n2,n3,ARG_SUM) ; }		\

_REPEAT_0_NNN(1,0,0,FUNC_DEF)

#define FUNC_DEF2(n1,n2,n3)								\
	int func2(REPEATC_NNN(n1,n2,n3,ARG_DEF_,ARG_DEF))	\
{ return 0 REPEAT_NNN(n1,n2,n3,ARG_SUM) ; }				\

_REPEAT_0_NNN(1,0,0,FUNC_DEF2)


//////////////////////////////////////////////////////////////////////////
// Classes
//////////////////////////////////////////////////////////////////////////
#define TARG_DEF(n1,n2,n3)		,class NUMBER_NNN(T,,n1,n2,n3)
#define TARG_DEF_(n1,n2,n3)		class NUMBER_NNN(T,,n1,n2,n3)
#define FLD_DEF(n1,n2,n3)		NUMBER_NNN(T,,n1,n2,n3) NUMBER_NNN(field,,n1,n2,n3);

#define CLAZ_DEF(n1,n2,n3)								\
template<REPEATC_NNN(n1,n2,n3,TARG_DEF_,TARG_DEF)>		\
struct NUMBER_NNN(Cls,,n1,n2,n3)						\
{ REPEAT_NNN(n1,n2,n3,FLD_DEF) };						\

_REPEAT_NNN(1,0,0,CLAZ_DEF)


int main()
{
	int x;
	x = a[10];
	x = b[100];
	x = c[1000];
	x = func(1);
	x = func(1,2,3);
	x = func2();
	x = func2(1);
	x = func2(1,2,3);

	Cls1<int> cls1;
	cls1.field1 = 123;
	Cls4<int,int,int,char> cls4;
	cls4,field2 = 12;
	cls4.field4 = 'a';
}