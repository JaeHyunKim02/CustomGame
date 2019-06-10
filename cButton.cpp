#include "stdafx.h"
#include "cButton.h"


cButton::cButton(int x, int y, const string& key)
{

	m_Nomal = IMAGE->FindImage(key +    "_Nomal");
	m_OnCursor = IMAGE->FindImage(key + "_OnCursor");
	m_Click = IMAGE->FindImage(key +    "_Click");

	m_Pos.x = x;
	m_Pos.y = y;
}

cButton::~cButton()
{
}

void cButton::Init()
{
	//중점이 왼쪽 위
	//SetRect(&m_rt, m_Pos.x, m_Pos.y,
	//	m_Pos.x + m_Nomal->m_info->bmWidth,
	//	m_Pos.x + m_Nomal->m_info->bmHeight);

	//중점이 가운데
  	SetRect(&m_rt, 
		m_Pos.x - m_Nomal->m_info->bmWidth / 2,
		m_Pos.y - m_Nomal->m_info->bmHeight / 2,
		m_Pos.x + m_Nomal->m_info->bmWidth / 2,
		m_Pos.y + m_Nomal->m_info->bmHeight / 2);
}

bool cButton::isOver() {
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	if (PtInRect(&m_rt, pt)) 
		return true;
	else
		return false;
}
bool cButton::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (b_Click) {
		if (INPUT->MouseLUp() && isOver())
			return true;
		else
			b_Click = false;
	}

	if (isOver()) {
		b_OnCursor = true;
		if (INPUT->MouseLPress()) {
			b_Click = true;
		}
		else {
			b_Click = false;
		}
	}
	else
		b_OnCursor = false;

	return false;
}/*
bool cButton::isClickDown(int x, int y)
{
	if (isOver)
	{
		stateBtn = ON;
		return true;
	}
	stateBtn = OFF;
	return false;
}*/
void cButton::Render()
{
	if (b_Click) {
		IMAGE->Render(m_Click, m_Pos, true, RGB(255, 0, 255));
	}
	else if (b_OnCursor) {
		IMAGE->Render(m_OnCursor, m_Pos, true, RGB(255, 0, 255));
	}
	else
		IMAGE->Render(m_Nomal, m_Pos, true, RGB(255, 0, 255));
}

void cButton::Release()
{
}
