#include "stdafx.h"
#include "cMakingWnd.h"
#include"cButton.h"

int temp=0;
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
	srand(nSeed);
	CountOrder = rand()%4+1;//�ֹ��� �þ�� ���⼭ �߰���Ű�� ��
	if (temp == CountOrder) {
		while (1)
		{
		CountOrder = rand() % 4 + 1;
		if (CountOrder != temp)
			break;
		}
	}
	temp = CountOrder;
	
	//CountOrder = 1;
	char buffer[128];
	sprintf_s(buffer, "Order_%d", CountOrder);
	strOrder = buffer;

	m_OrderPos.x = 280;
	m_OrderPos.y = 300;

	m_OrderBackPos.x = 320;
	m_OrderBackPos.y = 300;
	m_Making_btn = new cButton(450, 300, "Making");
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
		IMAGE->Render(IMAGE->FindImage("order_Contents"), m_OrderBackPos, true, RGB(255, 0, 255));
		IMAGE->Render(IMAGE->FindImage(strOrder), m_OrderPos, true);
		m_Making_btn->Render();
		m_Exit_btn->Render();
	}
	//Order_1
	
	//	IMAGE->Render(IMAGE->FindImage(m_Comment3), CommentPos3, false);
	
}

void cMakingWnd::Release()
{
	SAFE_DELETE(m_Making_btn);
	SAFE_DELETE(m_Exit_btn);
}
