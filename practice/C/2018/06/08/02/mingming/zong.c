#include <stdio.h>
#include <math.h>
#include "typedef.h"

// ��������ľ���
double two_point_distance(spot coordinate1, spot cordinate2)
{
	double x, y;
	x = coordinate1.x - cordinate2.x;
	y = coordinate1.y - cordinate2.y;
	return sqrt(pow(x,2) + pow(y,2));
}
