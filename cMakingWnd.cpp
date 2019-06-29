#include "stdafx.h"
#include "cMakingWnd.h"
#include"cButton.h"

cMakingWnd::cMakingWnd(int x, int y, const string & key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
}


cMakingWnd::~cMakingWnd()
{
	Release();
}

void cMakingWnd::Init()
{
	m_Making_btn = new cButton(320, 480, "Making");
	m_Making_btn->Init();
	m_Exit_btn = new cButton(500, 200, "WndExit");
	m_Exit_btn->Init();
}

void cMakingWnd::Update()
{
	if (bClickChk) {
		Init();
		bClickChk = false;
	}
	if (m_Making_btn->Update()) {
		chkOrder = false;
		SCENE->ChangeScene("MainGame");
	}
	if (m_Exit_btn->Update()) {
		Release();
		bClickChk = true;
		SCENE->ChangeScene("InGame");
	}
}

void cMakingWnd::Render()
{
	if (!bClickChk) {
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_Making_btn->Render();
		m_Exit_btn->Render();
	}
}

void cMakingWnd::Release()
{
	SAFE_DELETE(m_Making_btn);
	SAFE_DELETE(m_Exit_btn);
}
