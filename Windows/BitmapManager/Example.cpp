#include <vector>
#include "Example.h"

std::vector<std::unique_ptr<Actor>> grounds;

HRESULT Example::Initialize(HINSTANCE hInstance, LPCWSTR title, UINT width, UINT height)
{
    HRESULT hr;

    hr = D2DFramework::Initialize(hInstance, title, width, height);
    ThrowIfFailed(hr);

    /*mspBackground = std::make_unique<Actor>(this, L"Images/back1.png", 0.0f, 0.0f, 1.0f);

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            bugs.push_back(std::make_unique<Actor>(this, L"Images/bug1_1.png", 100.0f + i * 10.0f, 100.0f + j * 10.0f));
        }
    }

    mspBug = (std::make_unique<Actor>(this, L"Images/bug1_1.png", 100.0f, 100.0f));*/

    mspMainCharacter = std::make_unique<Actor>(this, L"Images/maincharacter.png", 100.0f, 50.0f);
    mspSnake = std::make_unique<Actor>(this, L"Images/snake.png", 200.0f, 50.0f);

    for (int i = 0; i < 10; i++)
    {
        grounds.push_back(std::make_unique<Actor>(this, L"Images/ground.png", 100.0f+i*30.0f, 100.0f));
    }

    //mspGround = std::make_unique<Actor>(this, L"Images/ground.png", 300.0f, 100.0f);
    mspTree = std::make_unique<Actor>(this, L"Images/tree.png", 400.0f, 100.0f);
    mspBind = std::make_unique<Actor>(this, L"Images/bine.png", 500.0f, 100.0f);

    return S_OK;
}

void Example::Release()
{

    /*mspBug.reset();

    bugs.clear();
    mspBackground.reset();*/

    mspBind.reset();
    mspTree.reset();

    grounds.clear();
    //mspGround.reset();
    mspSnake.reset();
    mspMainCharacter.reset();

    D2DFramework::Release();
}

void Example::Render()
{
    mspRenderTarget->BeginDraw();
    mspRenderTarget->Clear(D2D1::ColorF(0.0f, 0.2f, 0.4f, 1.0f));

    /*mspBackground->Draw();
    mspBug->Draw();

    for (const auto& e : bugs)
    {
        e->Draw();
    }*/

    mspMainCharacter->Draw();
    mspSnake->Draw();

    for (const auto& e : grounds)
    {
        e->Draw();
    }

    //mspGround->Draw();
    mspTree->Draw();
    mspBind->Draw();


    HRESULT hr = mspRenderTarget->EndDraw();

    if (hr == D2DERR_RECREATE_TARGET)
    {
        CreateDeviceResources();
    }
}
