// gamehax.h by Fallout
// Library for hacking games in C++.

#include <iostream>
#include <Windows.h>
#include <string>

// This is the ease set of functions that don't really have anything to do with game hacks, but do help alot.
class functions
{
	// Print function (outputs text to the console, simpler version of std::cout)

	void print(std::string text)
	{
		std::cout << text << std::endl;
	}

	// wait function (better Sleep function [from Windows.h], counts in seconds instead of milliseconds)

	void wait(int seconds)
	{
		Sleep(seconds * 1000);
	}

	// This is the hacking set of functions. Most functions here can only be used after using the hookToProcess function.

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
			if (procID == NULL)
			{
				std::cout << "Hook failed. (could not obtain process ID)" << std::endl;
			}
			HANDLE handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
		}
	}

	// writeMem function (makes it much easier to write to memory)

	void writeMem(DWORD address, int value, std::string handleName)
	{
		WriteProcessMemory(&handleName, (LPVOID)address, &value, sizeof(value), 0);
	}

	// readMem function (makes it much easier to read memory)

	void readMem(DWORD address, std::string handleName)
	{
		ReadProcessMemory(&handleName, (PBYTE*)address, 0, sizeof(0), 0);
	};
};
