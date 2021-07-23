#include "IndexBuffer.hpp"

ID3D11Buffer* IndexBuffer::Get() const noexcept
{
	return buffer.Get();
}

ID3D11Buffer* const* IndexBuffer::GetAddressOf() const noexcept
{
	return buffer.GetAddressOf();
}

UINT IndexBuffer::BufferSize() const noexcept
{
	return bufferSize;
}

HRESULT IndexBuffer::Initialize(ID3D11Device* device, DWORD* data, UINT numVertices)
{
	if (buffer.Get() != nullptr)
		buffer.Reset();
	

	bufferSize = numVertices;

	D3D11_BUFFER_DESC indexBufferDesc;
	ZeroMemory(&indexBufferDesc, sizeof(indexBufferDesc));

	indexBufferDesc.ByteWidth = sizeof(DWORD) * numVertices;
	indexBufferDesc.StructureByteStride = sizeof(DWORD);
	indexBufferDesc.Usage = D3D11_USAGE_DEFAULT;
	indexBufferDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexBufferDesc.CPUAccessFlags = 0;
	indexBufferDesc.MiscFlags = 0;

	D3D11_SUBRESOURCE_DATA indexBufferData;
	//ZeroMemory(&indexBufferData, sizeof(indexBufferData));
	indexBufferData.pSysMem = data;

	return device->CreateBuffer(&indexBufferDesc, &indexBufferData, buffer.GetAddressOf());
}