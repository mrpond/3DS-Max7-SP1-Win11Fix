// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include <string_view>
#include "UIControls.h"

BOOL APIENTRY DllMain (HMODULE hModule,
					   DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	
	DisableThreadLibraryCalls (hModule);
	std::string_view procname = GetCommandLine ();
	// only 3dsmax process - this help avoid false positive
	if (std::string_view::npos != procname.find ("3dsmax_fix.exe")) {
		switch (ul_reason_for_call)
		{
		case DLL_PROCESS_ATTACH:
			//InstallHookApi("npapi.dll", "NPEnumResource", NPEnumResourceHook);
			InstallHookApi("p9np.dll", "NPEnumResource", NPEnumResourceHook);
			//InstallHookApi("splash.dll", "NewSplashRemoveSplash", NewSplashRemoveSplashHook);
			InstallHookApi("splash.dll", "NewSplashDisplayMessage", NewSplashDisplayMessageHook);
			//InstallHookApi("d3d9.dll", "Direct3DCreate9", Direct3DCreate9Hook);
			break;
		}
	}
	return TRUE;
}

