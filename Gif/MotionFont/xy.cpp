#include "xy.h"

void Pie2XY(double alpha, double r, double&x, double& y)
{
	x = r * cos(alpha);
	y = r * sin(alpha);
}
void XY2Pie(double x, double y, double& alpha, double& r)
{
	r = sqrt(x*x+y*y);
	alpha = atan2(y,x);
}
