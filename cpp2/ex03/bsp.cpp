#include "Point.hpp"

// Area of △ = (1/2) |x1(y2 − y3) + x2(y3 − y1) + x3(y1 − y2)|
float area(Point A, Point B, Point C)
{
	return fabs((A.getPoint('x') * (B.getPoint('y') - C.getPoint('y')) + 
				 B.getPoint('x') * (C.getPoint('y') - A.getPoint('y')) + 
				 C.getPoint('x') * (A.getPoint('y') - B.getPoint('y'))) / 2.0);
}

// If sum of A_PBC, A_PCA and A_PAB is same as A_ABC, then the point lies inside the triangle.
bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float A_ABC = area(a, b, c);
	float A_PBC = area(point, b, c);
	float A_PCA = area(point, c, a);
	float A_PAB = area(point, a, b);

	return fabs(A_ABC == A_PBC + A_PCA + A_PAB);
}
