#pragma once
#include "CommonInclude.h"
#include "yaMath.h"

namespace ya
{
	enum class eKeyCode
	{
		//Alphabet
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M,

		//Special Key
		ENTER, ESC, LSHIFT, LALT, LCTRL,
		SPACE, LEFT, RIGHT, UP, DOWN,
		LBTN, RBTN,

		//Num Pad
		NUM_0, NUM_1, NUM_2,
		NUM_3, NUM_4, NUM_5,
		NUM_6, NUM_7, NUM_8,
		NUM_9,

		//Num Line
		N_0, N_1, N_2, N_3, N_4, N_5, N_6, N_7, N_8, N_9,

		End,
	};

	enum class eKeyState
	{
		DOWN,
		PRESSED,
		UP,
		NONE,
	};

	class Input
	{
	public:
		struct Key
		{
			eKeyCode keyCode;
			eKeyState state;
			bool bPressed;
		};

		static __forceinline eKeyState GetKeyState(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state;
		}

		static __forceinline math::Vector2 GetMousePos() 
		{ 
			return mMousePos;
		}

		//GetKey()			Ű�� ������ �ð���ŭ true�� ��ȯ
		//GetKeyDown()		Ű�� ������ ��, �� �ѹ� true�� ��ȯ
		//GetKeyUp()		Ű�� ������ ���� ��, �� �ѹ� true�� ��ȯ

		static __forceinline bool GetKey(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::PRESSED;
		}

		static __forceinline bool GetKeyDown(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::DOWN;
		}

		static __forceinline bool GetKeyUp(eKeyCode keyCode)
		{
			return mKeys[static_cast<UINT>(keyCode)].state == eKeyState::UP;
		}

	public:
		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static math::Vector2 GetMousePos(HWND hWnd);

	private:
		static std::vector<Key> mKeys;
		static math::Vector2 mMousePos;
	};
}