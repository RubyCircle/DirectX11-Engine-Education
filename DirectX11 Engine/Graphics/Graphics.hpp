#pragma once
#include <SpriteBatch.h>
#include <SpriteFont.h>
#include <WICTextureLoader.h>
#include "../Base.hpp"
#include "../Paths.hpp"
#include "../Timer.hpp"
#include "AdapterReader.hpp"
#include "Camera.hpp"
#include "Shaders.hpp"
#include "Vertex.hpp"
#include "VertexBuffer.hpp"
#include "IndexBuffer.hpp"
#include "ConstantBufferTypes.hpp"
#include "ConstantBuffer.hpp"

#include "ImGui/imgui.h"
#include "ImGui/imgui_impl_win32.h"
#include "ImGui/imgui_impl_dx11.h"

class Graphics
{
public:
	bool Initialize(HWND hWnd, int width, int height);
	void RenderFrame();

	Camera camera;
private:
	bool InitializeDirectX(HWND hWnd);
	bool InitializeShader();
	bool InitializeScene();

	com_ptr<ID3D11Device> device;
	com_ptr<ID3D11DeviceContext> deviceContext;
	com_ptr<IDXGISwapChain> swapchain;
	com_ptr<ID3D11RenderTargetView> renderTargetView;

	VertexShader vertexShader;
	PixelShader pixelShader;

	VertexBuffer<Vertex> vertexBuffer;
	IndexBuffer indexBuffer;
	ConstantBuffer<CB_VS_VertexShader> constantBuffer;

	com_ptr<ID3D11DepthStencilView> depthStencilView;
	com_ptr<ID3D11Texture2D> depthStencilBuffer;
	com_ptr<ID3D11DepthStencilState> depthStencilState;

	com_ptr<ID3D11RasterizerState> rasterizerState;

	std::unique_ptr<DirectX::SpriteBatch> spriteBatch;
	std::unique_ptr<DirectX::SpriteFont> spriteFont;

	com_ptr<ID3D11SamplerState> samplerState;
	com_ptr<ID3D11ShaderResourceView> myTexture;

	int windowWidth = 0;
	int windowHeight = 0;

	Timer fpsTimer;
};