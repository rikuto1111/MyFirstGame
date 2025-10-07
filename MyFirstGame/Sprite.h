#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>

using namespace DirectX;

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWorld; //world*view*projectionの行列
	//DirectX::XMMATRIX matNormal;法線変更用の行列
	//DirectX::XMMATRIX matWorld;ワールド行列
};

//頂点情報
struct VERTEX
{
	XMVECTOR pos;
	XMVECTOR uv;
	//XMVECTOR normal;
};


class Texture;

class Sprite
{
public:
	Sprite();
	virtual ~Sprite();
	virtual HRESULT Initialize();
	virtual void Draw(XMMATRIX& worldMatrix);
	void Release();
protected:
	ID3D11Buffer* pVertexBuffer_;	//頂点バッファ
	ID3D11Buffer* pIndexBuffer_;	//頂点バッファ
	ID3D11Buffer* pConstantBuffer_;	//コンスタントバッファ
	Texture* pTexture_;
};