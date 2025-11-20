#include "Bullet.h"
#include "Engine/SphereCollider.h"
#include "Enemy.h"

Bullet::Bullet(GameObject* parent)
	:GameObject(parent, "Bullet"), pFbx(nullptr)
{
	
}

Bullet::~Bullet()
{
}

void Bullet::Initialize()
{
	pFbx = new Fbx;
	pFbx->Load("Oden.fbx");

	transform_.scale_.x = 0.5f;
	transform_.scale_.y = 0.5f;
	transform_.scale_.z = 0.5f;

	SphereCollider* col = new SphereCollider(0.5);
	AddCollider(col);
}

void Bullet::Update()
{
	transform_.position_.z += 0.2f;

	GameObject* root = GetRootJob();
	root->RoundRobin(this);
}

void Bullet::Draw()
{
	pFbx->Draw(transform_);
	
}

void Bullet::Release()
{
}
