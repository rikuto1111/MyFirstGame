#include "GameObject.h"

GameObject::GameObject()
	:pParent_(nullptr)
{
}

GameObject::GameObject(GameObject* parent, const std::string& name)
	:pParent_(parent), objectName_(name)
{
	if (pParent_ != nullptr)
	{
		transform_.pParent_ = &(parent->transform_);
	}
}

GameObject::~GameObject()
{
}

void GameObject::DrawSub()
{
	//0.自分を描画
	Draw(); //this->は書いても書かなくてもいい

	//1.子オブジェクトを描画　childList_の各要素に対してDrawを呼ぶ
	for(auto child : childList_)
	{
		child->DrawSub();
	}

}

void GameObject::UpdateSub()
{
	Update();

	for (auto child : childList_)
	{
		child->UpdateSub();
	}
}

void GameObject::ReleaseSub()
{
	Release();
	for (auto child : childList_)
	{
		child->ReleaseSub();
	}
}

void GameObject::SetPosition(XMFLOAT3 position)
{
	transform_.position_ = position;
}

void GameObject::SetPosition(float x, float y, float z)
{
	SetPosition(XMFLOAT3(x, y, z));
}
