#include"inc/D3DUtil.h"
#include"inc/CallStack.h"

namespace NARCO
{
	NARCO_API void ExceptionError(HRESULT result, const char* description)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		if (result == S_OK)
		{
			std::cout << " :: SUCCESS :: " << description << '\n';
		}

		else if (result == E_FAIL)
		{
			SetConsoleTextAttribute(console, 12);

			std::cout << ":: ERROR E_FAIL :: " << description << '\n';

			CallStack cs;

			cs.Print();

			SetConsoleTextAttribute(console, 15);

		}

		else if (result == E_INVALIDARG)
		{
			SetConsoleTextAttribute(console, 12);

			std::cout << ":: ERROR E_INVALIDARG :: " << description << '\n';
			CallStack cs;

			cs.Print();
			SetConsoleTextAttribute(console, 15);

		}

		return;
	}

	NARCO_API void ExceptionWarning(HRESULT result, const char* description)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		if (result == S_OK)
		{
			std::cout << " :: SUCCESS :: " << description << '\n';

		}

		else if (result == E_FAIL)
		{
			SetConsoleTextAttribute(console, 14);

			std::cout << ":: WARNING E_FAIL:: " << description << '\n';

			CallStack cs;

			cs.Print();

			SetConsoleTextAttribute(console, 15);

		}

		else if (result == E_INVALIDARG)
		{
			SetConsoleTextAttribute(console, 14);

			std::cout << ":: WARNING E_INVALIDARG :: " << description << '\n';
			CallStack cs;

			cs.Print();
			SetConsoleTextAttribute(console, 15);

		}

		return;
	}

	NARCO_API void ExceptionLog(HRESULT result, const char* description)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		if (result == S_OK)
		{
			SetConsoleTextAttribute(console, 10);


			std::cout << " :: SUCCESS :: " << description << '\n';


		}
		else if (result == E_FAIL)
		{
			SetConsoleTextAttribute(console, 14);

			std::cout << ":: LOG E_FAIL :: " << description << '\n';

			CallStack cs;

			cs.Print();
		}

		else if (result == E_INVALIDARG)
		{
			SetConsoleTextAttribute(console, 14);

			std::cout << ":: LOG E_INVALIDARG :: " << description << '\n';
			CallStack cs;

			cs.Print();
		}

		SetConsoleTextAttribute(console, 15);

		return;
	}

	NARCO_API long long MakeHash(std::string s)
	{
		const int p = 53;
		const int m = 1e9 + 9;

		int val = 0;
		int pow = 1;

		for (unsigned int i = 0; i < s.length(); i++)
		{
			val = (val + (s[i] - 'a' + 1) * pow) % m;
			pow = (p * pow) % m;
		}

		return val;
	}

}