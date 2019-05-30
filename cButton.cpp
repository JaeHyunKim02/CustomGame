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

	//������ ���� ��
	//SetRect(&m_rt, m_Pos.x, m_Pos.y,
	//	m_Pos.x + m_Nomal->m_info->bmWidth,
	//	m_Pos.x + m_Nomal->m_info->bmHeight);


	//������ ���
  	SetRect(&m_rt, 
		m_Pos.x - m_Nomal->m_info->bmWidth / 2,
		m_Pos.y - m_Nomal->m_info->bmHeight / 2,
		m_Pos.x + m_Nomal->m_info->bmWidth / 2,
		m_Pos.y + m_Nomal->m_info->bmHeight / 2);
}

bool cButton::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);

	if (b_Click) {
		if (INPUT->MouseLUp())
			return true;
	}

	if (PtInRect(&m_rt, pt)) {
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
}

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
