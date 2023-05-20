#pragma once

#ifdef FLEXIMSGBOX_EXPORTS
#define FLEXIMSGBOX_EXPORT __declspec(dllexport)
#else
#define FLEXIMSGBOX_EXPORT __declspec(dllimport)
#endif

#if __cplusplus
extern "C" {
#endif
	namespace FlexiUIComponent
	{
		FLEXIMSGBOX_EXPORT int FlexiMessageBox(WCHAR * lpText, WCHAR * lpCaption);
	};

#if __cplusplus
}
#endif