#include "yaGridScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaApplication.h"
#include "yaConstantBuffer.h"
#include "yaRenderer.h"
#include "yaSceneManager.h"

extern ya::Application application;

namespace ya
{
	GridScript::GridScript()
		: Script()
		, mCamera(nullptr)
	{
	}

	GridScript::~GridScript()
	{
	}

	void GridScript::Initialize()
	{
		eSceneType type = SceneManager::GetActiveScene()->GetSceneType();
		mCamera = renderer::cameras[(UINT)type][0];
	}

	void GridScript::Update()
	{
		if (mCamera == nullptr)
			return;

		GameObject* gameObj = mCamera->GetOwner();
		Transform* tr = gameObj->GetComponent<Transform>();

		Vector3 cameraPos = tr->GetPosition();
		Vector4 position = Vector4(cameraPos.x, cameraPos.y, cameraPos.z, 1.0f);

		float scale = mCamera->GetScale();

		RECT winRect;
		GetClientRect(application.GetHwnd(), &winRect);
		float width = winRect.right - winRect.left;
		float height = winRect.bottom - winRect.top;
		Vector2 resolution(width, height);

		// Constant buffer
		ConstantBuffer* cb = renderer::constantBuffers[(UINT)eCBType::Grid];
		renderer::GridCB data;
		data.cameraPosition = position;
		data.cameraScale = Vector2(scale, scale);
		data.resolution = resolution;

		cb->Bind(&data);
		cb->SetPipeline(eShaderStage::VS);
		cb->SetPipeline(eShaderStage::PS);
	}

	void GridScript::FixedUpdate()
	{
	}

	void GridScript::Render()
	{
	}

}
