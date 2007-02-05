#include "xy.h"

inline void PieToXY(double&x, double& y, double alpha, double r)
{
	x = r * cos(alpha);
	y = r * sin(alpha);
}