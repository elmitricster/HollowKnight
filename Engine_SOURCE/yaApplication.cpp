#include "yaApplication.h"
#include "yaRenderer.h"
#include "yaTime.h"
#include "yaInput.h"
#include "yaSceneManager.h"
#include "yaResources.h"
#include "yaCollisionManager.h"

namespace ya
{
	using namespace graphics;

	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Initialize()
	{
		Time::Initialize();
		Input::Initialize();
		CollisionManager::Initialize();
		renderer::Initialize();
		SceneManager::Initialize();
	}

	// 게임 로직, 캐릭터 이동 등등
	// CPU UPDATE
	void Application::Update()
	{
		Time::Update();
		Input::Update();
		CollisionManager::Update();
		SceneManager::Update();
	}

	// GPU UPDATE
	void Application::FixedUpdate()
	{
		CollisionManager::FixedUpdate();
		SceneManager::FixedUpdate();
	}

	void Application::Render()
	{
		Time::Render(mHdc);

		graphicDevice->Clear();
		graphicDevice->AdjustViewPorts();

		renderer::Render();
		CollisionManager::Render();
	}

	void Application::Destroy()
	{
	}

	void Application::Run()
	{
		Update();
		FixedUpdate();
		Render();
		Destroy();
	}

	void Application::Present()
	{
		graphicDevice->Present();
	}

	void Application::Release()
	{
		//Resources::Release();
	}

	void Application::SetWindow(HWND hwnd, UINT width, UINT height)
	{   
		if (graphicDevice == nullptr)
		{
			mHwnd = hwnd;
			mHdc = GetDC(mHwnd);
			mWidth = width;
			mHeight = height;

			ValidationMode validationMode = ValidationMode::Disabled;
			graphicDevice = std::make_unique<GraphicDevice_DX11>();
			graphics::GetDevice() = graphicDevice.get();
		}
		
		RECT rt = { 0, 0, (LONG)width, (LONG)height };
		AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, false);
		SetWindowPos(mHwnd, nullptr, 0, 0, rt.right - rt.left, rt.bottom - rt.top, 0);
		ShowWindow(mHwnd, true);
		UpdateWindow(mHwnd);
	}
}