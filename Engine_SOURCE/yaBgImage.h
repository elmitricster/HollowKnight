#pragma once
#include "yaGameObject.h"

namespace ya
{
	class BgImage : public GameObject
	{
	public:
		BgImage();
		virtual ~BgImage();

		virtual void Initialize();
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render();


	private:

	};
}


