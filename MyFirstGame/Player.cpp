#include "Player.h"
#include "Engine/Fbx.h"
#include "ChildOden.h"
#include "Engine/Model.h"
#include "Engine/SphereCollider.h"
#include "Engine/Input.h"
#include "Bullet.h"


Player::Player(GameObject* parent)
	:GameObject(parent, "Player"), hModel_(-1)
{
}

Player::~Player()
{
}

void Player::Initialize()
{
	//pFbx_ = new Fbx;
	//pFbxがnullptrじゃなかったら
	//pFbxのチェックを入れたほうがいい
	//pFbx_->Load("Oden.fbx");

	hModel_ = Model::Load("Oden.fbx");
	assert(hModel_ >= 0);
	/*transform_.scale_.x = 0.7f;
	transform_.scale_.y = 0.7f;
	transform_.scale_.z = 0.7f;*/	
	//子オブジェクトにChildOdenを追加する
	pRChildOden_ = (ChildOden *)Instantiate<ChildOden>(this);
	pLChildOden_ = (ChildOden *)Instantiate<ChildOden>(this);
	pRChildOden_->SetPosition(2.0f, 1.0f, 0.0f);
	pLChildOden_->SetPosition(-2.0f, 1.0f, 0.0f);

	SphereCollider* col = new SphereCollider(0.5);
	AddCollider(col);
}

void Player::Update()
{
	static float x = 0.0;
	float tx = sin(x) * 5.0f;

	x += 0.02f;
	transform_.rotate_.y += 1.0f;

	if (Input::IsKey(DIK_SPACE))
	{
		Instantiate<Bullet>(this);
	}

	
	/*if (transform_.rotate_.y > 720)
	{
		KillMe();
	}*/
}

void Player::Draw()
{
	/*if (pFbx_)
	{
		pFbx_->Draw(transform_);
	}*/
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
	/*if (pFbx_)
	{
		pFbx_->Release();
		delete pFbx_;
		pFbx_ = nullptr;
	}*/
}
