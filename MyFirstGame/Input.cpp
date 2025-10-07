#include "Input.h"


namespace Input
{
	//キーボードインプット
	LPDIRECTINPUT8   pDInput = nullptr;
	LPDIRECTINPUTDEVICE8 pKeyDevice = nullptr;
	BYTE keyState[256] = { 0 };
	BYTE prevKeyState[255] = { 0 };

	//マウスインプット
	LPDIRECTINPUTDEVICE8 pMouseDevice = nullptr;
	DIMOUSESTATE mouseState; //マウスの状態
	DIMOUSESTATE prevMouseState; //前回のマウスの状態
	XMVECTOR mouseposition;

	void Initialize(HWND hWnd)
	{
		DirectInput8Create(GetModuleHandle(nullptr), DIRECTINPUT_VERSION, IID_IDirectInput8, (VOID**)&pDInput, nullptr);
		pDInput->CreateDevice(GUID_SysKeyboard, &pKeyDevice, nullptr);
		pKeyDevice->SetDataFormat(&c_dfDIKeyboard);
		pKeyDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_BACKGROUND);

		//マウスデバイス初期化
		pDInput->CreateDevice(GUID_SysMouse, &pMouseDevice, nullptr);
		pMouseDevice->SetDataFormat(&c_dfDIMouse);
		pMouseDevice->SetCooperativeLevel(hWnd, DISCL_NONEXCLUSIVE | DISCL_FOREGROUND);
	}

	void Update()
	{
		for (auto i = 0;i < 256;i++)
		{
			prevKeyState[i] = keyState[i];
		}
		pKeyDevice->Acquire();
		pKeyDevice->GetDeviceState(sizeof(keyState), &keyState);
	}

	bool IsKey(int keyCode)
	{
		if (keyState[keyCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsKeyUp(int keyCode)
	{
		//今は離してて、前回は押している　解放=Release
		if (!IsKey(keyCode) && (prevKeyState[keyCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	bool IsKeyDown(int keyCode)
	{
		//今は押してて、前回は押してない　押下=Push
		if (IsKey(keyCode) && !(prevKeyState[keyCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	XMVECTOR GetMousePosition()
	{
		return mouseposition;
	}

	void SetMousePosition(int x, int y)
	{
		//mouseposition = XMVectorSet((float)x, (float)y, 0.0f, 1.0f);
		mouseposition = { (float)x,(float)y,0.0f,1.0f };
	}

	bool IsMouseBotton(int btnCode)
	{
		if (mouseState.rgbButtons[btnCode] & 0x80)
		{
			return true;
		}
		return false;
	}

	bool IsMouseBottonUp(int btnCode)
	{
		//今は離してて、前回は押している　解放=Release
		if (!IsMouseBotton(btnCode) && (prevMouseState.rgbButtons[btnCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	bool IsMouseBottonDown(int btnCode)
	{
		//今は押してて、前回は押してない　押下=Push
		if (IsMouseBotton(btnCode) && !(prevMouseState.rgbButtons[btnCode] & 0x80))
		{
			return true;
		}
		return false;
	}

	void Release()
	{
		SAFE_RELEASE(pDInput);
	}
}