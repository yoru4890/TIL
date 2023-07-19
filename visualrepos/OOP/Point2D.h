#pragma once
class Point2D
{
private:
	int mX;
	int mY;

public:

	Point2D() : Point2D(0,0)
	{
		// �۾� 1
		// �۾� 2
	}

	Point2D(int x, int y) : mX{ x }, mY{ y }
	{
		// �۾� 1
		// �۾� 2
	}

	~Point2D()
	{

	}

	void Set(int x, int y);
	double Distance() const;
	void Print() const;
};

