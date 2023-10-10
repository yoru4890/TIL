#include <windows.h>
#include <d2d1.h>

#pragma comment(lib,"d2d1.lib")

const wchar_t gClassName[] = L"MyWindowClass";

// 1. Direct2D ���丮 ����
// 2. ���� Ÿ�� ����
// 3. �׸��� (����Ÿ��)
// 4. ���ҽ� ����

// Interface
// D2D1 : Direct2D Version1

ID2D1Factory* gpD2DFactory{};
ID2D1HwndRenderTarget* gpRenderTarget{};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPSTR lpCmdLine,
    _In_ int nShowCmd)
{
    // D2D Factory
    HRESULT hr = D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &gpD2DFactory);
    if (FAILED(hr))
    {
        MessageBox(nullptr, L"Failed To CreateFactory", L"Error", MB_OK);
        return 0;
    }


    HWND hwnd;
    WNDCLASSEX wc;
    ZeroMemory(&wc, sizeof(WNDCLASSEX));
    wc.style = CS_HREDRAW | CS_VREDRAW;
    wc.lpszClassName = gClassName;
    wc.hInstance = hInstance;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)COLOR_WINDOW;
    wc.lpfnWndProc = WindowProc;
    wc.cbSize = sizeof(WNDCLASSEX);
    if (!RegisterClassEx(&wc))
    {
        MessageBox(nullptr, L"Failed to register window class!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    RECT wr = { 0, 0, 1024, 768 };
    AdjustWindowRect(&wr, WS_OVERLAPPEDWINDOW, FALSE);
    hwnd = CreateWindowEx(NULL,
        gClassName,
        L"Direct2D",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        wr.right - wr.left,
        wr.bottom - wr.top,
        NULL,
        NULL,
        hInstance,
        NULL);
    if (hwnd == nullptr)
    {
        MessageBox(nullptr, L"Failed to create window class!", L"Error", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    GetClientRect(hwnd, &wr);
    hr = gpD2DFactory->CreateHwndRenderTarget(
        D2D1::RenderTargetProperties(),
        D2D1::HwndRenderTargetProperties(hwnd, D2D1::SizeU(wr.right-wr.left,wr.bottom-wr.top)),
        &gpRenderTarget
    );
    if (FAILED(hr))
    {
        MessageBox(nullptr, L"Faile To Create HWNDRenderTarget!", L"Error", MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nShowCmd);
    UpdateWindow(hwnd);

    MSG msg;
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    // ����
    if (gpRenderTarget != nullptr)
    {
        gpRenderTarget->Release();
        gpRenderTarget = nullptr;
    }
    
    if (gpD2DFactory != nullptr)
    {
        gpD2DFactory->Release();
        gpD2DFactory = nullptr;
    }

    return static_cast<int>(msg.wParam);
}

void OnPaint(HWND hwnd)
{
    HDC hdc;
    PAINTSTRUCT ps;
    hdc = BeginPaint(hwnd, &ps);

    // RenderTarget�� �׸���
    gpRenderTarget->BeginDraw();
    gpRenderTarget->Clear(D2D1::ColorF(0.0f,0.2f,0.4f,1.0f));
    gpRenderTarget->EndDraw();

    EndPaint(hwnd, &ps);
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
        case WM_PAINT:
            OnPaint(hwnd);
            break;
        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
