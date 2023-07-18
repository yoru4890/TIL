#include <iostream>
#include <cmath>
#include "Point2D.h"

void Point2D::Set(int x, int y)
{
    mX = x;
    mY = y;
}

double Point2D::Distance() const
{
    return sqrt(mX * mX + mY * mY);
}

void Point2D::Print() const
{
    std::cout << "(" << mX << "," << mY << ")" << std::endl;
}
