#include "CChar.h"


CChar::CChar(char* p)
{
	Init(p, *p<0);
}

CChar::CChar(char* p, bool dchar)
{
	Init(p, dchar);
}

void CChar::Init(char* p, bool dchar)
{
	if (dchar)
	{
		data = (*((unsigned int*)p) & 0xffff) | 0x01000000;
	}
	else
	{
		data = *((unsigned int*)p) & 0xff;
	}
}

const char* CChar::c_str()
{
	return (const char*)this;
}

void CChar::from(char* p, vector<CChar>& chars)
{
	chars.clear();
	while (*p)
	{
		if (*p<0)
		{
			chars.push_back(CChar(p,true));
			p+=2;
		}
		else
		{
			chars.push_back(CChar(p,false));
			p++;
		}
	}
}

int CChar::length()
{
	return (data & 0x01000000) ? 2 : 1;
}