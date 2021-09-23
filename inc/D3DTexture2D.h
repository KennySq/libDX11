#pragma once
#include"Common.h"
#include"D3DHardware.h"

namespace NARCO
{
	class D3DTexture2D
	{
	public:

		NARCO_API D3DTexture2D(ID3D11Device* device, DXGI_FORMAT format, D3D11_BIND_FLAG bindFlag, D3D11_USAGE usage, unsigned int width, unsigned int height, unsigned int mipLevels, unsigned int cpuAccessFlag = 0);
		NARCO_API ~D3DTexture2D();
	private:
		unsigned int mWidth;
		unsigned int mHeight;

		D3D11_CPU_ACCESS_FLAG mHostAccess;

		ComPtr<ID3D11Texture2D> mTexture = nullptr;

		ComPtr<ID3D11ShaderResourceView> mShaderResourceView = nullptr;
		ComPtr<ID3D11UnorderedAccessView> mUnorderedAccessView = nullptr;
		ComPtr<ID3D11RenderTargetView> mRenderTargetView = nullptr;
	};
}