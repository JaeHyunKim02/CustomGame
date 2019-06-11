#include "stdafx.h"
#include "cStoreWnd.h"
#include"cButton.h"

cStoreWnd::cStoreWnd(int x, int y, const string & key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
}


cStoreWnd::~cStoreWnd()
{
}

void cStoreWnd::Init()
{
	m_Exit_btn = new cButton(500, 200, "WndExit");
	m_Exit_btn->Init();
	m_Store_Expansion_btn = new cButton(300, 600, "Store_Expention");
	m_Store_Expansion_btn->Init();

	m_Yes_btn = new cButton(200, 560, "Wnd_Yes");
	m_Yes_btn->Init();
	m_No_btn = new cButton(430, 560, "Wnd_No");
	m_No_btn->Init();
}
void cStoreWnd::Update()
{
	if (bClickChk) {
		Init();
		bClickChk = false;
	}
	if (!bClickChk) {
		if (m_Exit_btn->Update()) {
			Release();
			SCENE->ChangeScene("InGame");
			bClickChk = true;	
		}
		else if (m_Store_Expansion_btn->Update()) {

		}
	}
}

void cStoreWnd::Render()
{
	if (!bClickChk) {
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_Exit_btn->Render();
		m_Store_Expansion_btn->Render();
		//
		IMAGE->Render(IMAGE->FindImage("MessageWnd"), m_Pos, true);
		m_Yes_btn->Render();
		m_No_btn->Render();
	}
}

void cStoreWnd::Release()
{
	SAFE_DELETE(m_Exit_btn);
	SAFE_DELETE(m_Store_Expansion_btn);
	SAFE_DELETE(m_Yes_btn);
	SAFE_DELETE(m_No_btn);
}
