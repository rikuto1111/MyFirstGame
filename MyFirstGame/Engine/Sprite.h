#pragma once
#include "Direct3D.h"
#include <DirectXMath.h>

using namespace DirectX;

struct CONSTANT_BUFFER
{
	DirectX::XMMATRIX matWorld; //world*view*projection�̍s��
	//DirectX::XMMATRIX matNormal;�@���ύX�p�̍s��
	//DirectX::XMMATRIX matWorld;���[���h�s��
};

//���_���
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
	ID3D11Buffer* pVertexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pIndexBuffer_;	//���_�o�b�t�@
	ID3D11Buffer* pConstantBuffer_;	//�R���X�^���g�o�b�t�@
	Texture* pTexture_;
};