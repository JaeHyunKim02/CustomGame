#include "stdafx.h"
#include "cWindow.h"
#include"cButton.h"

cWindow::cWindow(int x, int y, const string & key, const string & btn_key, int WndState)
{
	
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
	m_exitBtn = new cButton(500, 230, btn_key);
}

cWindow::~cWindow()
{
	
}

void cWindow::Init()
{
	bChkBtn = false;
	m_exitBtn->Init();
	//order창 제작버튼
	m_Making_button = new cButton(320, 480, "Making");
	m_Making_button->Init();
}

bool cWindow::Update()
{
	if(m_Making_button->Update()&& bChkBtn==true&& WndState==ORDER_WND)
		SCENE->ChangeScene("MainGame");
	return m_exitBtn->Update();
}

bool cWindow::Render()
{ 
	if (bChkBtn) {
		switch (WndState) {
		case ORDER_WND:		return RenderNotice(); break;
		case STOREINFO_WND:	return RenderStoreInfo(); break;
		case OPTION_WND:	return RenderOption(); break;
		}
	}
}

void cWindow::Release()
{
	SAFE_DELETE(m_exitBtn);
}

int cWindow::RenderNotice()
{
	IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
	m_Making_button->Render();
	m_exitBtn->Render();
	return true;
}

int cWindow::RenderStoreInfo()
{
	IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
	DEBUG_LOG("STOREINFO");
	m_exitBtn->Render();
	return true;
}

int cWindow::RenderOption()
{
	IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
	DEBUG_LOG("OPTION_WND");
	m_exitBtn->Render();
	return true;
}

