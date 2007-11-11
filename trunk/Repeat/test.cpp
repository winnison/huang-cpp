#include <iostream>
#include <stdio.h>
#include "repeat.h"
using namespace std;

#define SHOW_N(n1) NUMBERN(n1),
#define SHOW_NN(n1,n2) NUMBERNN(n1,n2),
#define SHOW_NNN(n1,n2,n3) NUMBERNNN(n1,n2,n3),
#define SHOW_NNNN(n1,n2,n3,n4) NUMBERNNNN(n1,n2,n3,n4),

#define TYPENAME_DECLARE(n)  typename T##n
#define ARGUMENT_DECLARE(n)  T##n __arg##n
#define ARGUMENT_USING(n)  __arg##n
#define TYPENAME_DECLAREA(n)  typename T##n ,
#define ARGUMENT_DECLAREA(n)  T##n __arg##n ,
#define ARGUMENT_USINGA(n)  __arg##n ,


#define TYPENAME_DECLARE3(n1,n2,n3)  typename T##n1##n2##n3
#define ARGUMENT_DECLARE3(n1,n2,n3)  T##n1##n2##n3  __arg##n1##n2##n3
#define ARGUMENT_USING3(n1,n2,n3)  __arg##n1##n2##n3
#define TYPENAME_DECLAREA3(n1,n2,n3)  typename T##n1##n2##n3 ,
#define ARGUMENT_DECLAREA3(n1,n2,n3)  T##n1##n2##n3 __arg##n1##n2##n3 ,
#define ARGUMENT_USINGA3(n1,n2,n3)  __arg##n1##n2##n3 ,
#define FIELD_DECLARE3(n1,n2,n3) \
T##n1##n2##n3 m_##n1##n2##n3;\


#define FIELD_ASSIGN3(n1,n2,n3) m_##n1##n2##n3 = __arg##n1##n2##n3;

#define VECTOR_DECLEAR(n1,n2,n3)\
template< REPEATC_NNN(n1,n2,n3,TYPENAME_DECLARE)>\
class Vector##n1##n2##n3\
{\
public:\
	REPEAT_NNN(n1,n2,n3,FIELD_DECLARE3)\
	Vector##n1##n2##n3( REPEATC_NNN(n1,n2,n3,ARGUMENT_DECLARE))\
	{\
		REPEAT_NNN(n1,n2,n3,FIELD_ASSIGN3)\
	};\
};


VECTOR_DECLEAR(0,6,3)

bool b;

void check0(int *p)
{
	if(*p != 0)
	{
		b = true;
	}
}
void check(int *p, int n)
{
	printf("check: %d",n);
	for (int i=1; i<=n; i++)
	{
		if(p[i-1] != i)
		{
			b = true;
			break;
		}
	}
	if(p[n] != -1)
	{
		b=true;
	}
	printf(" done.\n",n);
}

void check1(int *p, int n)
{
	printf("check1: %d",n);
	for (int i=1; i<=n; i++)
	{
		if(p[i] != i)
		{
			b = true;
			break;
		}
	}
	if(p[n+1] != -1)
	{
		b=true;
	}
	printf(" done.\n",n);
}


int main()
{
	b = false;
#define TEST_N(n)\
	int N##n [] = {REPEAT_N(n,SHOW_N) -1};\
	check( N##n , n);\
	int _N##n [] = {REPEAT_0_N(n,SHOW_N) -1};\
	check0(_N##n);\
	check1(_N##n,n);

	printf("N started...\n");
//_1_REP_N(9,TEST_N)

#define TEST_NN(n1,n2)\
	int NN##n1##n2 [] = {REPEAT_NN(n1,n2,SHOW_NN) -1};\
	check(NN##n1##n2,NUMBERNN(n1,n2));\
	int _NN##n1##n2 [] = {REPEAT_0_NN(n1,n2,SHOW_NN) -1};\
	check0(_NN##n1##n2);\
	check1(_NN##n1##n2,NUMBERNN(n1,n2));

printf("NN started...\n");
TEST_NN(0,0)
TEST_NN(0,1)
TEST_NN(0,9)
TEST_NN(1,0)
TEST_NN(1,1)
TEST_NN(1,8)
TEST_NN(5,6)
TEST_NN(8,9)
TEST_NN(9,0)
TEST_NN(9,1)
TEST_NN(9,9)

#define TEST_NNN(n1,n2,n3)\
	int NNN##n1##n2##n3 [] = {REPEAT_NNN(n1,n2,n3,SHOW_NNN) -1};\
	check(NNN##n1##n2##n3,NUMBERNNN(n1,n2,n3));\
	int _NNN##n1##n2##n3 [] = {REPEAT_0_NNN(n1,n2,n3,SHOW_NNN) -1};\
	check0(_NNN##n1##n2##n3);\
	check1(_NNN##n1##n2##n3,NUMBERNNN(n1,n2,n3));

printf("NNN started...\n");
TEST_NNN(0,0,0)
TEST_NNN(0,0,1)
TEST_NNN(0,0,9)
TEST_NNN(0,1,0)
TEST_NNN(0,1,1)
TEST_NNN(0,1,8)
TEST_NNN(0,5,6)
TEST_NNN(0,8,9)
TEST_NNN(0,9,0)
TEST_NNN(0,9,1)
TEST_NNN(0,9,9)
TEST_NNN(1,0,0)
TEST_NNN(1,0,1)
TEST_NNN(1,0,9)
TEST_NNN(1,1,0)
TEST_NNN(1,1,1)
TEST_NNN(1,1,9)
TEST_NNN(1,3,6)
TEST_NNN(1,9,9)
TEST_NNN(2,0,0)
TEST_NNN(5,6,7)
TEST_NNN(8,9,9)
TEST_NNN(9,0,0)
TEST_NNN(9,0,1)
TEST_NNN(9,0,9)
TEST_NNN(9,1,0)
TEST_NNN(9,1,1)
TEST_NNN(9,1,9)
TEST_NNN(9,2,7)
TEST_NNN(9,8,9)
TEST_NNN(9,9,0)
TEST_NNN(9,9,1)
TEST_NNN(9,9,9)

//#define TEST_NNNN(n1,n2,n3,n4)\
//	int NNNN##n1##n2##n3##n4 [] = {REPEAT_NNNN(n1,n2,n3,n4,SHOW_NNNN) -1};\
//	check(NNNN##n1##n2##n3##n4,NUMBERNNNN(n1,n2,n3,n4));
//	//int _NNNN##n1##n2##n3##n4 [] = {REPEAT_0_NNNN(n1,n2,n3,n4,SHOW_NNNN) -1};\
//	//check0(_NNNN##n1##n2##n3##n4);\
//	//check1(_NNNN##n1##n2##n3##n4,NUMBERNNNN(n1,n2,n3,n4));
//
//printf("NNNN started...\n");
//TEST_NNNN(9,9,9,9)
//#define TEST_NNNN_n(n)\
//TEST_NNNN(n,0,0,0)\
//TEST_NNNN(n,0,0,1)\
//TEST_NNNN(n,0,0,9)\
//TEST_NNNN(n,0,1,0)\
//TEST_NNNN(n,0,1,1)\
//TEST_NNNN(n,0,1,8)\
//TEST_NNNN(n,0,5,6)\
//TEST_NNNN(n,0,8,9)\
//TEST_NNNN(n,0,9,0)\
//TEST_NNNN(n,0,9,1)\
//TEST_NNNN(n,0,9,9)\
//TEST_NNNN(n,1,0,0)\
//TEST_NNNN(n,1,0,1)\
//TEST_NNNN(n,1,0,9)\
//TEST_NNNN(n,1,1,0)\
//TEST_NNNN(n,1,1,1)\
//TEST_NNNN(n,1,1,9)\
//TEST_NNNN(n,1,3,6)\
//TEST_NNNN(n,1,9,9)\
//TEST_NNNN(n,2,0,0)\
//TEST_NNNN(n,5,6,7)\
//TEST_NNNN(n,8,9,9)\
//TEST_NNNN(n,9,0,0)\
//TEST_NNNN(n,9,0,1)\
//TEST_NNNN(n,9,0,9)\
//TEST_NNNN(n,9,1,0)\
//TEST_NNNN(n,9,1,1)\
//TEST_NNNN(n,9,1,9)\
//TEST_NNNN(n,9,2,7)\
//TEST_NNNN(n,9,8,9)\
//TEST_NNNN(n,9,9,0)\
//TEST_NNNN(n,9,9,1)\
//TEST_NNNN(n,9,9,9)\



//TEST_NNNN_n(0)
//TEST_NNNN_n(1)
	return 0;
}