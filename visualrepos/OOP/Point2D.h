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
	// ���� ������
	// ���� ģ�� �Լ�
	friend Point2D operator + (const Point2D& arg1, const Point2D& arg2)
	{
		Point2D result;

		result.mX = arg1.mX + arg2.mX;
		result.mY = arg1.mY + arg2.mY;

		return result;
	}
	// ��� �Լ�
	Point2D operator - (const Point2D& op)
	{
		return Point2D(mX - op.mX, mY - op.mY);
	}
	/////////////////////////////////////////////////////
	// ���� ������
	// ���� ������ : ���� ģ�� �Լ�
	friend const Point2D& operator++(Point2D& arg1)
	{
		// ���� ��
		arg1.mX++;
		arg1.mY++;

		// ����
		return arg1;
	}

	// ���� ������ : ��� �Լ�
	const Point2D& operator -- ()
	{
		this->mX--;
		this->mY--;
		return *this;
	}

	// ���� ������ : ���� ģ�� �Լ�
	friend const Point2D& operator++ (Point2D& arg1, int v)
	{
		// ���� ��
		Point2D temp(arg1.mX, arg1.mY);

		// ����
		arg1.mX++;
		arg1.mY++;

		return temp;
	}

	// ���� ������ : ��� �Լ� --
	
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



