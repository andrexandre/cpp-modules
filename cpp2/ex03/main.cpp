#include "Fixed.hpp"
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(0.0f, 0.0f);
	Point b(5.5f, 0.0f);
	Point c(0.0f, 5.5f);
	Point p(2.0f, 2.5f);

	co << "p is inside the △: " << bsp(a, b, c, p) << nl;
	Point q(5.0f, 5.0f);
	co << "q is inside the △: " << bsp(a, b, c, q) << nl;
	return 0;
}
