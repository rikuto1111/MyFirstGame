#pragma once
#include "Engine/GameObject.h"

class Fbx;
class ChildOden;

class TestScene :
    public GameObject
{
	int hModel_;
public:
	TestScene(GameObject* parent);
	~TestScene();
	void Initialize() override;
	void Update() override;
	void Draw() override;
	void Release() override;
	
};

