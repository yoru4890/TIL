#pragma once
class Point2D
{
private:
	int mX;
	int mY;

public:

	Point2D();
	Point2D(int x, int y);
	void Print() const;

	//////////////////////////////////////////////////////
	// 이항 연산자
	// 전역 친구 함수
	friend Point2D operator + (const Point2D& arg1, const Point2D& arg2)
	{
		Point2D result;

		result.mX = arg1.mX + arg2.mX;
		result.mY = arg1.mY + arg2.mY;

		return result;
	}
	// 멤버 함수
	Point2D operator - (const Point2D& op)
	{
		return Point2D(mX - op.mX, mY - op.mY);
	}
	/////////////////////////////////////////////////////
	// 단항 연산자
	// 전위 연산자 : 전역 친구 함수
	friend const Point2D& operator++(Point2D& arg1)
	{
		// 증가 후
		arg1.mX++;
		arg1.mY++;

		// 대입
		return arg1;
	}

	// 전위 연산자 : 멤버 함수
	const Point2D& operator -- ()
	{
		this->mX--;
		this->mY--;
		return *this;
	}

	// 후위 연산자 : 전역 친구 함수
	friend const Point2D& operator++ (Point2D& arg1, int v)
	{
		// 대입 후
		Point2D temp(arg1.mX, arg1.mY);

		// 증가
		arg1.mX++;
		arg1.mY++;

		return temp;
	}

	// 후위 연산자 : 멤버 함수 --
	
	const Point2D& operator -- (int v)
	{
		Point2D temp = *this;

		--(*this);
		/*
		mX--;
		mY--;
		*/

		return temp;
	}
	////////////////////////////////////////////////////

};



