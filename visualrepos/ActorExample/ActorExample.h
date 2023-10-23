#pragma once
//#include <vector>
#include <memory>
#include "D2DFramework.h"
#include "Actor.h"

class ActorExample : public D2DFramework
{
	std::unique_ptr<Actor> mspBackground;
	//std::vector<std::unique_ptr<Actor>> mspBugs;
	std::unique_ptr<Actor> mspBug;

public:
	virtual HRESULT Initialize(HINSTANCE hInstance, LPCWSTR title = L"ActorExample", UINT width = 1024, UINT height = 768) override;
	virtual void Release() override;
	virtual void Render() override;
};

