#include "pch.h"
#include "MessageBox.h"



CMessageBox::CMessageBox() : m_value(0), m_hStaticText(NULL)
{
    CreateWindow();
}

CMessageBox::CMessageBox(WCHAR* lpText, WCHAR* lpCaption)
{
    if (wcslen(lpText) > static_cast<size_t>(0))
        m_text = lpText;

    if (wcslen(lpCaption) > static_cast<size_t>(0))
        m_caption = lpCaption;

    CreateWindow();


    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
}

CMessageBox::~CMessageBox()
{
}

int CMessageBox::GetData()
{
    return m_value;
}


HWND CMessageBox::CreateWindow()
{
    const wchar_t CLASS_NAME[] = L"MyWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = GetModuleHandle(NULL);
    wc.lpszClassName = CLASS_NAME;

    RegisterClass(&wc);

    HWND hwnd = CreateWindowEx(
        0,                              // Optional window styles
        CLASS_NAME,                     // Window class name
        m_caption.c_str(),                   // Window title
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU,            // Window style

        // Position and size
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 400,

        NULL,       // Parent window
        NULL,       // Menu
        GetModuleHandle(NULL),  // Instance handle
        NULL        // Additional application data
    );

    if (hwnd == NULL)
    {
        return NULL;
    }

    // Static 컨트롤 생성
    m_hStaticText = CreateWindowW(L"STATIC", m_text.c_str(), WS_VISIBLE | WS_CHILD | SS_CENTER | SS_CENTERIMAGE,
        CW_USEDEFAULT, CW_USEDEFAULT, 500, 400, hwnd, NULL, NULL, NULL);

    ShowWindow(hwnd, SW_SHOW);
}

LRESULT CMessageBox::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {
    case WM_CREATE:
    {
        break;
    }

    case WM_COMMAND:
    {
        // 버튼 클릭 처리
        if (HIWORD(wParam) == BN_CLICKED)
        {
            MessageBox(hwnd, L"Button Clicked!", L"Message", MB_OK);
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
