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
			bClickChk = true;
			SCENE->ChangeScene("InGame");
		}
	}
}

void cStoreWnd::Render()
{
	if (!bClickChk) {
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_Exit_btn->Render();
	}
}

void cStoreWnd::Release()
{
	SAFE_DELETE(m_Exit_btn);
}
