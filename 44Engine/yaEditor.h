#pragma once
#include "yaDebugObject.h"
#include "yaWidget.h"
#include "yaEditorObject.h"
#include "yaGraphics.h"

namespace ya
{
	class Editor
	{
	public:
		void Initialize();
		void Run();

		void Update();
		void FixedUpdate();
		void Render();
		void Release();
		void DebugRender(graphics::DebugMesh& mesh);

	private:
		std::vector<Widget*> mWidgets;
		std::vector<EditorObject*> mEditorObjects;
		std::vector<DebugObject*> mDebugObjects;
	};
}


