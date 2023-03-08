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
		mainCamera = cameraComp;

		// UI Camera
		/*GameObject* cameraUIObj = object::Instantiate<GameObject>(eLayerType::Camera);
		Camera* cameraUIComp = cameraUIObj->AddComponent<Camera>();
		cameraUIComp->SetProjectionType(Camera::eProjectionType::Orthographic);
		cameraUIComp->DisableLayerMasks();

		cameraUIComp->TurnLayerMask(eLayerType::UI, true);*/

		// Light Object
		/*GameObject* spriteObj = object::Instantiate<GameObject>(eLayerType::Player);
		spriteObj->SetName(L"LIGHT");
		Transform* spriteTr = spriteObj->GetComponent<Transform>();
		spriteTr->SetPosition(Vector3(0.0f, 0.0f, 11.0f));
		spriteTr->SetScale(Vector3(5.0f, 5.0f, 1.0f));

		SpriteRenderer* sr = spriteObj->AddComponent<SpriteRenderer>();
		std::shared_ptr<Mesh> mesh = Resources::Find<Mesh>(L"RectMesh");
		std::shared_ptr<Material> spriteMaterial = Resources::Find<Material>(L"SpriteMaterial");
		sr->SetMaterial(spriteMaterial);
		sr->SetMesh(mesh);*/

		// 플레이어 코코미 RECT
		{
			Player* obj = object::Instantiate<Player>(eLayerType::Player);
			obj->SetName(L"KOKOMI");
			Transform* tr = obj->GetComponent<Transform>();
			tr->SetPosition(Vector3(0.0f, 0.0f, 5.0f));
			//tr->SetRotation(Vector3(0.0f, 0.0f, XM_PIDIV2));
			//tr->SetScale(Vector3(1.0f, 1.0f, 1.0f));
			Collider2D* collider = obj->AddComponent<Collider2D>();
			collider->SetType(eColliderType::Circle);

			SpriteRenderer* mr = obj->AddComponent<SpriteRenderer>();
			std::shared_ptr<Material> material = Resources::Find<Material>(L"RectMaterial");
			mr->SetMaterial(material);
			std::shared_ptr<Mesh> mesh = Resources::Find<Mesh>(L"RectMesh");
			mr->SetMesh(mesh);
			obj->AddComponent<PlayerScript>();
			object::DontDestroyOnLoad(obj);
		}

		// 몬스터 코코미 RECT
		{
			Monster* obj = object::Instantiate<Monster>(eLayerType::Monster);
			obj->SetName(L"KOKOMI");
			Transform* tr = obj->GetComponent<Transform>();
			tr->SetPosition(Vector3(2.0f, 0.0f, 5.0f));
			tr->SetRotation(Vector3(0.0f, 0.0f, XM_PIDIV2 / 3.0f));
			//tr->SetScale(Vector3(1.0f, 1.0f, 1.0f));
			Collider2D* collider = obj->AddComponent<Collider2D>();
			collider->SetType(eColliderType::Circle);

			SpriteRenderer* mr = obj->AddComponent<SpriteRenderer>();
			std::shared_ptr<Material> material = Resources::Find<Material>(L"RectMaterial");
			mr->SetMaterial(material);
			std::shared_ptr<Mesh> mesh = Resources::Find<Mesh>(L"RectMesh");
			mr->SetMesh(mesh);
			object::DontDestroyOnLoad(obj);
		}

		// 코코미 RECT Child
		/*GameObject* child = object::Instantiate<GameObject>(eLayerType::Player);
		child->SetName(L"KOKOMI");
		Transform* childTr = child->GetComponent<Transform>();
		childTr->SetPosition(Vector3(2.0f, 0.0f, 0.0f));
		childTr->SetScale(Vector3(1.0f, 1.0f, 1.0f));
		childTr->SetParent(tr);

		MeshRenderer* childMr = child->AddComponent<MeshRenderer>();
		std::shared_ptr<Material> childMaterial = Resources::Find<Material>(L"RectMaterial");
		childMr->SetMaterial(childMaterial);
		childMr->SetMesh(mesh);*/

		// HPBAR
		/*GameObject* hpBar = object::Instantiate<GameObject>(eLayerType::Player);
		hpBar->SetName(L"HPBAR");
		Transform* hpBarTR = hpBar->GetComponent<Transform>();
		hpBarTR->SetPosition(Vector3(-5.0f, 3.0f, 11.0f));
		hpBarTR->SetScale(Vector3(1.0f, 1.0f, 1.0f));

		SpriteRenderer* hpsr = hpBar->AddComponent<SpriteRenderer>();
		hpBar->AddComponent(hpsr);
		std::shared_ptr<Mesh> hpmesh = Resources::Find<Mesh>(L"RectMesh");
		std::shared_ptr<Material> hpspriteMaterial = Resources::Find<Material>(L"UIMaterial");
		hpsr->SetMesh(hpmesh);
		hpsr->SetMaterial(hpspriteMaterial);*/

		//// Grid Object
		//GameObject* gridObject = object::Instantiate<GameObject>(eLayerType::None);
		//MeshRenderer* gridMr = gridObject->AddComponent<MeshRenderer>();
		//gridMr->SetMesh(Resources::Find<Mesh>(L"RectMesh"));
		//gridMr->SetMaterial(Resources::Find<Material>(L"GridMaterial"));
		//GridScript* gridScript = gridObject->AddComponent<GridScript>();
		//gridScript->SetCamera(cameraComp);

		// FadeI/O
		GameObject* fadeObj = object::Instantiate<GameObject>(eLayerType::Player);
		Transform* fadeTr = fadeObj->GetComponent<Transform>();
		fadeTr->SetPosition(Vector3(0.0f, 0.0f, 1.0f));
		fadeTr->SetScale(Vector3(1.0f, 1.0f, 1.0f));

		MeshRenderer* fadeMr = fadeObj->AddComponent<MeshRenderer>();
		std::shared_ptr<Material> fadeMaterial = Resources::Find<Material>(L"FadeMaterial");
		fadeMr->SetMaterial(fadeMaterial);
		std::shared_ptr<Mesh> mesh = Resources::Find<Mesh>(L"RectMesh");
		fadeMr->SetMesh(mesh);
		fadeObj->AddComponent<FadeInAndOutScript>();

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Monster, true);

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