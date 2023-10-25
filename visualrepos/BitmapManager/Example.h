#pragma once
#include <memory>
#include "D2DFramework.h"
#include "Actor.h"
class Example : public D2DFramework
{
	/*std::unique_ptr<Actor> mspBackground;
	std::unique_ptr<Actor> mspBug;*/
	std::unique_ptr<Actor> mspMainCharacter;
	std::unique_ptr<Actor> mspSnake;
	std::unique_ptr<Actor> mspGround;
	std::unique_ptr<Actor> mspTree;
	std::unique_ptr<Actor> mspBind;

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"ActorExample", UINT width = 1024, UINT height = 768) override;
	virtual void Release() override;
	virtual void Render() override;
};

