// BlockTheSpot.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "UIControls.h"

void InitializeCustomUI () {}
void ShutdownCustomUI () {}



int WINAPI NPEnumResourceHook(DWORD RetAddr, pfnNPEnumResource pfnNPEnumResource, HANDLE hEnum, LPDWORD lpcCount, LPVOID lpBuffer, LPDWORD lpBufferSize)
{
	return WN_NO_NETWORK;
}

void WINAPI NewSplashRemoveSplashHook(DWORD RetAddr, pfnNewSplashRemoveSplash pfnNewSplashRemoveSplash, UINT uElapse)
{
	return;
}

void WINAPI NewSplashDisplayMessageHook(DWORD RetAddr, pfnNewSplashDisplayMessage pfnNewSplashDisplayMessage)
{
	return;
}

int WINAPI Direct3DCreate9Hook(DWORD RetAddr, pfnDirect3DCreate9 pfnDirect3DCreate9, UINT SDKVersion)
{
	
	auto ms_hDXLib = LoadLibrary("D3D9.DLL");
	auto ms_pfnD3DCreate9 = (NILPD3DCREATE)GetProcAddress(ms_hDXLib, "Direct3DCreate9");
	auto d3d9 = (*ms_pfnD3DCreate9)(D3D_SDK_VERSION);
	return (int)d3d9;
}
