// gamehax.h by Fallout
// Library for hacking games in C++.

#include <iostream>
#include <Windows.h>
#include <string>

// This is the ease set of functions that don't really have anything to do with game hacks, but do help alot.

// Print function (outputs text to the console, simpler version of std::cout)

void print(std::string text)
{
	std::cout << text << std::endl;
}

// This is the hacking set of functions. Most functions here can only be used after using the hookToProcess function.

// writeMem function (makes it much easier to write to memory)

void writeMem(DWORD address, int value)
{
	WriteProcessMemory(handle, (LPVOID)address, &value, sizeof(value), 0);
}

// readMem function (makes it much easier to read memory)

void readMem(DWORD address)
{
	ReadProcessMemory(handle, (PBYTE*)address, 0, sizeof(0), 0);
};

// hookToProcess function (hooks the program to a process, allowing you to hack. Creates handle with the name 'handle')

void hookToProcess(LPCSTR windowName)
{
	HWND hwnd = FindWindowA(NULL, windowName);
	if (hwnd == NULL)
	{
		std::cout << "Hook failed. (could not find specified window)" << std::endl;
	}
	else
	{
		DWORD procID;
		GetWindowThreadProcessId(hwnd, &procID);
		HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		if (procID == NULL)
		{
			std::cout << "Hook failed. (could not obtain process ID)" << endl;
		}
	}
}