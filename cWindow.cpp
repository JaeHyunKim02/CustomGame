#include "stdafx.h"
#include "cWindow.h"
#include"cButton.h"
cWindow::cWindow(int x, int y, const string & key, int btn_x, int btn_y, const string & btn_key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
	m_exitBtn = new cButton(btn_x, btn_y, btn_key);
}

cWindow::~cWindow()
{
	SAFE_DELETE(m_exitBtn);
}

void cWindow::Init()
{
	m_exitBtn->Init();
}

bool cWindow::Update()
{
	return m_exitBtn->Update();;
}

void cWindow::Render()
{
	if (bChkBtn) {
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_exitBtn->Render();
	}
}
