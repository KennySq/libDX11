#pragma once

#ifndef NARCO_API
	#define NARCO_API __declspec(dllexport)
#endif

#include<Windows.h>
#include<iostream>
#include<string>
#include<sstream>
#include<exception>
#include<vector>
#include<map>
#include<typeinfo>
#include<fstream>

#include<d3d11.h>
#include<dxgi.h>
#include<DirectXMath.h>
#include<DirectXColors.h>
#include<wrl.h>

#include"CallStack.h"

using namespace Microsoft::WRL;
using namespace DirectX;