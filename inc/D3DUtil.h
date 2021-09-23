#pragma once
#include"Common.h"

#include<DirectXColors.h>
#include<DirectXMath.h>

namespace NARCO
{
	NARCO_API void ExceptionError(HRESULT result, const char* description = "");
	NARCO_API void ExceptionWarning(HRESULT result, const char* description = "");
	NARCO_API void ExceptionLog(HRESULT result, const char* description = "");
	
#ifdef _DEBUG

	template<typename _Ty>
	NARCO_API void NullCheck(_Ty* ptr)
	{
		HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

		if (ptr == nullptr)
		{
			SetConsoleTextAttribute(console, 12);

			std::cout <<":: WARNING :: " << ptr << " is nullptr.";

			SetConsoleTextAttribute(console, 15);
		}
	}
#endif

	NARCO_API long long MakeHash(std::string s);
	NARCO_API long long MakeHash(unsigned int i);
}