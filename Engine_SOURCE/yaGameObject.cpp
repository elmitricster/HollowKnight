#include "yaGameObject.h"

namespace ya
{
	GameObject::GameObject()
		: mState(eState::Active)
		, mType(eLayerType::None)
		, mbDontDestory(false)
	{
		mComponents.resize((UINT)eComponentType::End);
		AddComponent(new Transform());
	}

	GameObject::~GameObject()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			delete comp;
			comp = nullptr;
		}

		for (Component* scrComp : mScripts)
		{
			if (scrComp == nullptr)
				continue;

			delete scrComp;
			scrComp = nullptr;
		}
	}

	void GameObject::Initialize()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Initialize();
		}

		for (Component* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->Initialize();
		}
	}

	void GameObject::Update()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Update();
		}

		for (Component* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->Update();
		}
	}

	void GameObject::FixedUpdate()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->FixedUpdate();
		}

		for (Component* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->FixedUpdate();
		}
	}

	void GameObject::Render()
	{
		for (Component* comp : mComponents)
		{
			if (comp == nullptr)
				continue;

			comp->Render();
		}

		for (Component* script : mScripts)
		{
			if (script == nullptr)
				continue;

			script->Render();
		}
	}

	void GameObject::AddComponent(Component* comp)
	{
		eComponentType order = comp->GetOrder();

		if (order != eComponentType::Script)
		{
			mComponents[(UINT)order] = comp;
			mComponents[(UINT)order]->SetOwner(this);
		}
		else
		{
			mScripts.push_back(dynamic_cast<Script*>(comp));
			comp->SetOwner(this);
		}
	}

	void GameObject::SetPos(Vector3 value)
	{
		if (nullptr != GetComponent<Transform>())
		{
			GetComponent<Transform>()->SetPosition(value);
		}
	}

	void GameObject::SetScale(Vector3 value)
	{
		if (nullptr != GetComponent<Transform>())
		{
			GetComponent<Transform>()->SetScale(value);
		}
		if (nullptr != GetComponent<SpriteRenderer>())
		{
			GetComponent<SpriteRenderer>()->ChangeSize();
		}
		if (nullptr != GetComponent<MeshRenderer>())
		{
			GetComponent<MeshRenderer>()->ChangeSize();
		}
	}

	void GameObject::SetRotation(Vector3 value)
	{
		if (nullptr != GetComponent<Transform>())
		{
			GetComponent<Transform>()->SetRotation(value);
		}
	}

	Vector3 GameObject::GetPos()
	{
		return GetComponent<Transform>()->GetPosition();
	}

	Vector3 GameObject::GetScale()
	{
		return GetComponent<Transform>()->GetScale();
	}

	Vector3 GameObject::GetRotation()
	{
		return GetComponent<Transform>()->GetRotation();
	}

	void GameObject::SetMaterial(std::shared_ptr<Material> material)
	{
		if (nullptr != GetComponent<SpriteRenderer>())
		{
			GetComponent<SpriteRenderer>()->SetMaterial(material);
		}
	}

	void GameObject::SetMesh(std::shared_ptr<Mesh> mesh)
	{
		if (nullptr != GetComponent<SpriteRenderer>())
		{
			GetComponent<SpriteRenderer>()->SetMesh(mesh);
		}
	}
}