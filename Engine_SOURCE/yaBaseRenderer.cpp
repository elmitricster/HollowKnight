#include "yaBaseRenderer.h"
#include "yaTexture.h"
#include "yaGameObject.h"
#include "yaTransform.h"
#include "yaResources.h"
 
namespace ya
{
	BaseRenderer::BaseRenderer(eComponentType type)
		: Component(type)
		, mChanged(false)
	{
		// 디폴트 매시 지정
		std::shared_ptr<Mesh> mesh = Resources::Find<Mesh>(L"Rectmesh");

		SetMesh(mesh);
	}

	BaseRenderer::~BaseRenderer()
	{
	}

	void BaseRenderer::Initialize()
	{
	}

	void BaseRenderer::Update()
	{

	}

	void BaseRenderer::FixedUpdate()
	{
		if (mChanged)
		{
			Transform* transform = GetOwner()->GetComponent<Transform>();

			Vector3 scale = transform->GetScale();
			Vector3 scaleTemp = transform->GetScale();

			scale.x = mWidthRatio;
			scale.y = mHeightRatio;

			scale *= scaleTemp;

			transform->SetScale(scale);

			mChanged = false;
		}
	}

	void BaseRenderer::Render()
	{
	}

	void BaseRenderer::SetMaterial(std::shared_ptr<Material> material)
	{
		mMaterial = material;

		adjustTexture();
	}

	void BaseRenderer::adjustTexture()
	{
		std::shared_ptr<Texture> texture = GetMaterial()->GetTexture();

		if (nullptr == texture)
			return;

		int width = texture->GetScratchImage().GetMetadata().width;
		int height = texture->GetScratchImage().GetMetadata().height;
		int widthcount = 0;
		int heightcount = 0;

		int GCD = std::gcd(width, height);

		float fwidth = width /= GCD;
		float fheight = height /= GCD;


		while (width > 0.f)
		{
			fwidth /= 10.f;
			width /= 10.f;
			++widthcount;
		}
		while (height > 0.f)
		{
			fheight /= 10.f;
			height /= 10.f;
			++heightcount;
		}


		if (widthcount == heightcount)
		{
			fwidth *= 10.f;
			fheight *= 10.f;
		}
		else if (widthcount < heightcount)
		{
			fwidth *= 10.f;
			fheight *= 100.f;
		}
		else
		{
			fwidth *= 100.f;
			fheight *= 10.f;
		}

		mWidthRatio = fwidth;
		mHeightRatio = fheight;

	}
}