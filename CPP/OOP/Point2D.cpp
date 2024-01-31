#include <iostream>
#include "Point2D.h"

Point2D::Point2D() : mX{}, mY{}
{
}

Point2D::Point2D(int x, int y) : mX{ x }, mY{ y }
{
}

void Point2D::Print() const
{
	std::cout<<"( " << mX<<" , " << mY<<" )" << std::endl;
}


