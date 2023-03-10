#include "yaTitleScene.h"
#include "yaTransform.h"
#include "yaMeshRenderer.h"
#include "yaRenderer.h"
#include "yaResources.h"
#include "yaTexture.h"
#include "yaPlayerScript.h"
#include "yaCamera.h"
#include "yaCameraScript.h"
#include "yaSpriteRenderer.h"
#include "yaGridScript.h"
#include "yaFadeInAndOutScript.h"
#include "yaObject.h"
#include "yaInput.h"
#include "yaCollider2D.h"
#include "yaPlayer.h"
#include "yaMonster.h"
#include "yaCollisionManager.h"
#include "yaBgImage.h"

namespace ya
{
	TitleScene::TitleScene()
		: Scene(eSceneType::Title)
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		// Main Camera Game Object
		GameObject* cameraObj = object::Instantiate<GameObject>(eLayerType::Camera);
		Camera* cameraComp = cameraObj->AddComponent<Camera>();
		//cameraComp->RegisterCameraInRenderer();
		cameraComp->TurnLayerMask(eLayerType::UI, false);
		cameraObj->AddComponent<CameraScript>();
		//mainCamera = cameraComp;

		// BG Image
		BgImage* bg = object::Instantiate<BgImage>(eLayerType::BgImage, this);
		Transform* tr = bg->GetComponent<Transform>();
		tr->SetPosition(Vector3(1.0f, 1.0f, 5.0f));
		//tr->SetScale(Vector3());

		SpriteRenderer* mr = bg->AddComponent<SpriteRenderer>();
		std::shared_ptr<Material> material = Resources::Find<Material>(L"TitleBGMaterial");
		mr->SetMaterial(material);
		std::shared_ptr<Mesh> mesh = Resources::Find<Mesh>(L"RectMesh");
		mr->SetMesh(mesh);
		bg->SetScale(Vector3(8.5f, 5.2f, 1.0f));

		// Logo
		Player* obj = object::Instantiate<Player>(eLayerType::Player, this);
		Transform* tr2 = obj->GetComponent<Transform>();
		tr2->SetPosition(Vector3(1.0f, 1.2f, 2.0f));

		SpriteRenderer* mr2 = obj->AddComponent<SpriteRenderer>();
		std::shared_ptr<Material> material2 = Resources::Find<Material>(L"RectMaterial");
		mr2->SetMaterial(material2);
		std::shared_ptr<Mesh> mesh2 = Resources::Find<Mesh>(L"RectMesh");
		mr2->SetMesh(mesh2);

		obj->SetScale(Vector3(0.3f, 0.3f, 1.0f));

		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(eSceneType::Play);
		}

		Scene::Update();
	}

	void TitleScene::FixedUpdate()
	{
		Scene::FixedUpdate();
	}

	void TitleScene::Render()
	{
		Scene::Render();
	}

	void TitleScene::OnEnter()
	{
	}

	void TitleScene::OnExit()
	{
	}
}