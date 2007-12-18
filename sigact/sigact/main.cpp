#define WIN32
#include "sigact.h"

#include "stdio.h"

using namespace sigact;

struct A 
{
	void act()
	{
		int a;
		a = 1;
	}
	void operator()()
	{
		int a;
		a = 1;
	}
	int a;
	int b;
};

struct AA
{
	AA operator+(const AA&)
	{
		return *this;
	}
	AA(){}
	AA(const A& a){}
	operator A()
	{
		return A();
	}
};

void act()
{
	int a;
	a = 1;
};

struct B 
{
	void act1(int i)
	{
		int a;
		a = 1;
	}
	void operator()(int i)
	{
		int a;
		a = 1;
	}
	int a;
	int b;
};

void act1(int i)
{
	int a;
	a = 1;
};

struct C 
{
	void act2(int i,int)
	{
		int a;
		a = 1;
	}
	void operator()(int i,int)
	{
		int a;
		a = 1;
	}
	int a;
	int b;
};

void act2(int i,int)
{
	int a;
	a = 1;
};

int main(int argc, const char *argv[])
{
	A a;
	AA aa, aa1;
aa1 = aa + a;
a = aa;

	signal s;
	action ac = s;
	s = ac;
	s += act;
	s += getaction(&a, &A::act);
	s += getaction(act);
	s += getaction(&a, &A::act);
	s += getaction(&a);
	s += &a;
	s();
	s -= getaction(&a, &A::act);
	s -= getaction(&a, &A::act);
	s();
	s -= getaction(act);
	s();

	B b;

	signal1<int> s1;
	action1<int> ac1 = s1;
	s1 = ac1;
	s1 += act1;
	s1 += getaction1(&b, &B::act1);
	s1 += getaction1(act1);
	s1 += getaction1(&b, &B::act1);
	s1 += &b;
	s1 += action1<int>::from(&b);
	s1(1);
	s1 -= getaction1(&b, &B::act1);
	s1 -= getaction1(&b, &B::act1);
	s1(1);
	s1 -= getaction1(act1);
	s1(1);

	C c;

	signal2<int, int> s2;
	action2<int, int> ac2 = s2;
	s2 = ac2;
	s2 += act2;
	s2 += getaction2(&c, &C::act2);
	s2 += getaction2(act2);
	s2 += getaction2(&c, &C::act2);
	s2 += &c;
	s2 += action2<int,int>::from(&c);
	s2(1,1);
	s2 -= getaction2(&c, &C::act2);
	s2 -= getaction2(&c, &C::act2);
	s2(1,1);
	s2 -= getaction2(act2);
	s2(1,1);

	return 0;
};