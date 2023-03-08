#pragma once
#include "yaScript.h"

namespace ya
{
	class FadeInAndOutScript : public Script
	{
	public:

		FadeInAndOutScript();
		~FadeInAndOutScript();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render() override;

		void SetType(int type) { mFadeType = type; }

		void SetFadeValue(float value) { mFadeValue = value; }
		void SetFadeTextureType(int value) { mFadeTextureType = value; }

	private:
		int mFadeType;
		int mFadeTextureType;
		float mFadeValue;
		float mTime;

		bool mStart;
	};
}


