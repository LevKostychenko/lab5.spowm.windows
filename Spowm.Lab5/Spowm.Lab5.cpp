#include <iostream>
#include <Windows.h>

typedef void(__cdecl *FNPTR)(void);

int main()
{
	HINSTANCE hModule = NULL;
	hModule = LoadLibrary((LPCWSTR)L"C:\\Users\\Asus\\source\\repos\\Spowm.Lab5.Library\\Debug\\Spowm.Lab5.Library.dll");
	if (hModule != NULL)
	{
		FNPTR fn = (FNPTR)GetProcAddress(hModule, "IOManager");
		if (fn != NULL)
		{
			fn();
		}
		else
		{
			std::cout << "Error Load function" << std::endl;
		}

		FreeLibrary(hModule);
	}
	else
	{
		std::cout << "error load Dll" << std::endl;
	}

	return 0;
}
