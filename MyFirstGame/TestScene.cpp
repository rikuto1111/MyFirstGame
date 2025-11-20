#include "TestScene.h"
#include "Engine/Input.h"
#include "Engine/SceneManager.h"
#include "Engine/Model.h"

TestScene::TestScene(GameObject* parent)
	:GameObject(parent, "TestScene"), hModel_(-1)
{
}

TestScene::~TestScene()
{
}

void TestScene::Initialize()	
{
	hModel_ = Model::Load("box.fbx");
	assert(hModel_ >= 0);
}

void TestScene::Update()
{

	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager *)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
	transform_.rotate_.y += 1.0f;
}

void TestScene::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void TestScene::Release()
{
}
