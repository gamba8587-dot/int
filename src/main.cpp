#include "windows.h"
#include <thread>
#include <chrono>

#include "roblox/task_scheduler/task_scheduler.h"

// ts auto signs the module after build so js run injector.exe to inject

extern "C" __declspec(dllexport) int NextHook(int code, WPARAM wParam, LPARAM lParam) { return CallNextHookEx(NULL, code, wParam, lParam); }

void load() {
	roblox::print(0, "module cuh");
	task_scheduler::initialize();

	while (true) {}
}

int __stdcall DllMain(HMODULE hmod, unsigned long reason, void*) {
	switch (reason) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hmod);
		std::thread(load).detach();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}