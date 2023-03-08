#include "yaFadeInAndOutScript.h"
#include "yaRenderer.h"
#include "yaTransform.h"
#include "yaMaterial.h"
#include "yaGameObject.h"
#include "yaConstantBuffer.h"
#include "yaTime.h"
#include "yaInput.h"

namespace ya
{
	FadeInAndOutScript::FadeInAndOutScript()
		: mFadeType(1)
		, mFadeTextureType(1)
		, mFadeValue(1.0f)
		, mTime(0.0f)
		, mStart(false)
	{
	}

	FadeInAndOutScript::~FadeInAndOutScript()
	{
	}

	void FadeInAndOutScript::Initialize()
	{
	}

	void FadeInAndOutScript::Update()
	{
		if (Input::GetKeyState(eKeyCode::I) == eKeyState::PRESSED)
		{
			mStart = true;
			mFadeType = 1;
			mTime = 0.0f;
		}
		if (Input::GetKeyState(eKeyCode::O) == eKeyState::PRESSED)
		{
			mStart = true;
			mFadeType = 0;
			mTime = 0.0f;
		}

		if (mStart)
		{
			mTime += Time::DeltaTime();
			ConstantBuffer* cb = renderer::constantBuffers[(UINT)eCBType::FadeInAndOut];
			renderer::FadeInAndOutCB fadeData = {};

			fadeData.fValue = mFadeValue * mTime;
			fadeData.bFadeType = mFadeType;
			fadeData.bTextureType = mFadeTextureType;

			cb->Bind(&fadeData);
			cb->SetPipeline(eShaderStage::VS);
			cb->SetPipeline(eShaderStage::PS);
		}	
	}

	void FadeInAndOutScript::Render()
	{
	}
}