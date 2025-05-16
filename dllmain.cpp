#include "pch.h"

static void Init()
{
	/*

	Write your initialization logic here..

	*/
}

int __stdcall DllMain(HMODULE hModule, DWORD ulReasonForCall, LPVOID lpReserved)
{
	DisableThreadLibraryCalls(hModule);

	if (ulReasonForCall != DLL_PROCESS_ATTACH) return 1;

	if (Proxy::Attach(hModule)) {
		HANDLE Thread = CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Init, 0, 0, 0);
		if (Thread != nullptr) CloseHandle(Thread);
	}

	return 1;
}