#pragma once

#include "D2DFramework.h"

class Actor
{
protected:
	/*ID2D1Factory* pFactory;
	IWICImagingFactory* pWICFactory;*/

	// vs

	D2DFramework* mpFramework;

	Microsoft::WRL::ComPtr<ID2D1Bitmap> mspBitmap;

	float mX;
	float mY;
	float mOpacity;

public:
	Actor() = delete;
	Actor(D2DFramework* pFramework, LPCWSTR filename);
	Actor(D2DFramework* pFramework, LPCWSTR filename, float x, float y, float opacity = 1.0f);

	virtual ~Actor();

private:
	HRESULT LoadWICImage(LPCWSTR filename);
	void Draw(float x, float y, float opacity = 1.0f);

public:
	virtual void Draw();
};

