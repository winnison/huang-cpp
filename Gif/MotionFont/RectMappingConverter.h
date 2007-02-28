
#define _USE_MATH_DEFINES

#include "dib.h"
#include "xy.h"

class CRectMappingConverter
{
public:
	double m_Pos;
protected:
	virtual void Map(double& x, double& y){};
public:
	void RectConvert(LPBYTE lpDataSrc, LPBYTE lpDataDst, int cx, int cy, RECT& rc, DIB32COLOR trans);
};



class CHTurnOverRectMappingConverter
	:public CRectMappingConverter
{
protected:
	virtual void Map(double& x, double& y);
};

class CVTurnOverRectMappingConverter
	:public CRectMappingConverter
{
protected:
	virtual void Map(double& x, double& y);
};

class CRollingRectMappingConverter
	:public CRectMappingConverter
{
protected:
	virtual void Map(double& x, double& y);
};

class CWobblyRectMappingConverter
	:public CRectMappingConverter
{
protected:
	virtual void Map(double& x, double& y);
};

