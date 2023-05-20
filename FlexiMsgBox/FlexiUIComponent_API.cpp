#include "pch.h"
#include "MessageBox.h"
#include "FlexiUIComponent_API.h"

int FlexiUIComponent::FlexiMessageBox(WCHAR* lpText, WCHAR* lpCaption)
{
	CMessageBox msgbox(lpText, lpCaption);
	



	return msgbox.GetData();
}
