#include <math.h>

typedef void (*MapXY)(double& x, double& y);



void Pie2XY(double alpha, double r, double&x, double& y);
void XY2Pie(double x, double y, double& alpha, double& r);
