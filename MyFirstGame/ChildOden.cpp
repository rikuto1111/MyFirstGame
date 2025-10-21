#include "ChildOden.h"
#include "Engine/Fbx.h"
#include "Engine/Model.h"

ChildOden::ChildOden(GameObject* parent)
	:GameObject(parent, "ChildOden"), hModel_(-1)
{
	
}

ChildOden::~ChildOden()
{
}

void ChildOden::Initialize()
{	
	//pFbx_ = new Fbx;
	//pFbx��nullptr����Ȃ�������
	//pFbx�̃`�F�b�N����ꂽ�ق�������
	//pFbx_->Load("Oden.fbx");
	transform_.scale_.x = 0.2f;
	transform_.scale_.y = 0.2f;
	transform_.scale_.z = 0.2f;
	transform_.position_.x = 2.0f;
	transform_.position_.y = 1.0f;
	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
}

void ChildOden::Update()
{
	transform_.rotate_.y += 2.0f;
}

void ChildOden::Draw()
{
	/*if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}*/
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void ChildOden::Release()
{
	if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}
}
