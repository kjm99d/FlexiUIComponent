#pragma once

#ifdef CreateWindow
#undef CreateWindow
#endif

#include <string>


class CMessageBox
{
public:
	CMessageBox();
	CMessageBox(WCHAR* lpText, WCHAR* lpCaption);
	~CMessageBox();

	int GetData();

private:
	HWND CreateWindow();
	static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

private:
	int m_value;
	HWND m_hStaticText;

private:
	std::wstring m_text;
	std::wstring m_caption;
	
};

