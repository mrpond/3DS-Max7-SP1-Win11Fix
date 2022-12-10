#pragma once
#include "stdafx.h"
#include <d3d9.h>

typedef int(__stdcall* pfnNPEnumResource)(HANDLE hEnum, LPDWORD lpcCount, LPVOID lpBuffer, LPDWORD lpBufferSize);
int WINAPI NPEnumResourceHook(DWORD RetAddr, pfnNPEnumResource pfnNPEnumResource, HANDLE hEnum, LPDWORD lpcCount, LPVOID lpBuffer, LPDWORD lpBufferSize);

typedef void(__stdcall* pfnNewSplashRemoveSplash)(UINT uElapse);

void WINAPI NewSplashRemoveSplashHook(DWORD RetAddr, pfnNewSplashRemoveSplash pfnNewSplashRemoveSplash, UINT uElapse);

typedef void(__stdcall* pfnNewSplashDisplayMessage)();

void WINAPI NewSplashDisplayMessageHook(DWORD RetAddr, pfnNewSplashDisplayMessage pfnNewSplashDisplayMessage);

typedef int(__stdcall* pfnDirect3DCreate9)(UINT SDKVersion);

int WINAPI Direct3DCreate9Hook(DWORD RetAddr, pfnDirect3DCreate9 pfnDirect3DCreate9, UINT SDKVersion);

typedef LPDIRECT3D9(CALLBACK* NILPD3DCREATE) (unsigned int);
