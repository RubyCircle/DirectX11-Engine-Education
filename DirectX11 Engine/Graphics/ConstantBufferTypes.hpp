#pragma once
#include <DirectXMath.h>

struct alignas(16) CB_VS_VertexShader
{
	DirectX::XMMATRIX wvpMatrix;
	DirectX::XMMATRIX worldMatrix;
};

/*struct alignas(16) CB_PS_PixelShader
{
	float alpha = 1.0f;
};*/
struct alignas(16) CB_PS_Light
{
	DirectX::XMFLOAT3 ambientLightColor;
	float ambientLightStrength = 0.0f;
};