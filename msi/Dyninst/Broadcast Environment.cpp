// Broadcast Environment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	DWORD dwReturnValue;

	SendMessageTimeout(HWND_BROADCAST, WM_SETTINGCHANGE, 0,
		(LPARAM) "Environment", SMTO_ABORTIFHUNG,
		5000, &dwReturnValue);

	return 0;
}
