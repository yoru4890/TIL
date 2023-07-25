#include <iostream>
#include "Point2D.h"

int main()
{
	int x{ 1 }, y{};
	
	y = ++x;

	std::cout << x << " , " << y << std::endl;

	Point2D pt1{ 2,3 };
	Point2D pt2{ 3,4 };

	Point2D pt3 = pt1 + pt2;

	pt3.Print();

	Point2D pt4 = pt1 + pt2 + pt3;

	pt4.Print();

	Point2D pt5 = pt2 - pt1;
	pt5.Print();

	Point2D pt6{ 1,2 }, pt7{};

	pt7 = ++pt6;

	pt6.Print();
	pt7.Print();

	pt7 = pt6++;
	pt6.Print();
	pt7.Print();

	///////////////////////////

	Point2D pt8{ 1,2 }, pt9{ };

	pt9 = --pt8;

	// operatror --(pt8);

	pt8.Print();
	pt9.Print();



	pt9 = pt8--;

	//operator --(pt8,1);

	pt8.Print();
	pt9.Print();

}


