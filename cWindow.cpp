#include "stdafx.h"
#include "cWindow.h"
#include"cButton.h"
#include"cOptionWnd.h"
#include"cMakingWnd.h"
#include"cStoreWnd.h"
#include"cGameExitWnd.h"
cWindow::cWindow(int x, int y, const string & key)
{
	m_Window = key;
	m_Pos.x = x;
	m_Pos.y = y;
}

cWindow::~cWindow()
{
	Release();
}

void cWindow::Init()
{
	bChkBtn = false;
	//m_MakingWnd = new cMakingWnd(m_Pos.x, m_Pos.y, m_Window);
	//m_OptionWnd = new cOptionWnd(m_Pos.x, m_Pos.y, m_Window); 
}

bool cWindow::Update(int WndState)
{
	switch (WndState) {
	//case MAKING_WND: m_MakingWnd->Update(); break;
	//case OPTION_WND: m_OptionWnd->Update(); break;
	}
	return true;
}

bool cWindow::Render(int WndState)
{
	switch (WndState) {
	case MAKING_WND: m_MakingWnd->Render(); break;
	case OPTION_WND: m_OptionWnd->Render(); break;
	}
	return true;
}

void cWindow::Release()
{ 
	SAFE_DELETE(m_MakingWnd);
	SAFE_DELETE(m_OptionWnd);
} 