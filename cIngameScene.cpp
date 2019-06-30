#include "stdafx.h"
#include "cIngameScene.h"
#include "cWindow.h"
#include "cButton.h"
#include <stdlib.h>

//bool first = true;

cIngameScene::cIngameScene()
{
}


cIngameScene::~cIngameScene()
{
	Release();
}

void cIngameScene::Init()
{ 
	kindC = "M_1";

	isChangTime = true;
	m_ChangPos.x = 300;
	m_ChangPos.y = 300;

	m_Mouse = new cMouseCursor();
	m_Mouse->Init();


	srand((unsigned)time(NULL));
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	Pos.x = 0;
	Pos.y = 0;

	WndState = EMPTY_WND;
	//m_Exit_Button = new cButton(100, 500, "Exit");
	//m_Exit_Button->Init();
	m_Option_button = new cButton(100, 300, "Option");
	m_Option_button->Init(); 
	m_Notice_button = new cButton(100, 100, "Notice");
	m_Notice_button->Init(); 
	m_goshop = new cButton(50, 300, "GoShop");
	m_goshop->Init();
	m_Window = new cWindow(320, 480, "Making_Wnd");
	m_Window->Init();
}

void cIngameScene::Update()
{  
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;
	m_Mouse->Update(MousePoint);
	//isOrder;
	//chkOrder;

	if (CKchangTime) {//��濡�� �̹��� �ٲ�� �ڵ� �־�� ��
		CKchangTime = false;
		DEBUG_LOG("����");
		count += 1;
		if (count > 4)
			count = 1;
		char a[128];
		sprintf_s(a, "M_%d", count);
		kindC = "M_" + count;
		kindC = a;
		//SCENE->ChangeScene("InGame");
	}

	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//Ŭ�� ȿ����
	} 
	if (m_Notice_button->Update() && chkOrder) {//�˸� ��ư Ŭ���� ��� 
		WndState = MAKING_WND;  
	}  
	else if (m_Option_button->Update()) {//�ɼ� ��ư�� Ŭ��  
		WndState = OPTION_WND;  
		//SCENE->ChangeScene("Comment");
	} 
	else if (WndState != EMPTY_WND) {
		m_Window->Update(WndState);
	}
	if (m_goshop->Update()) {
		SCENE->ChangeScene("Shop");
	}
}

void cIngameScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("InGameBG"), m_BackGroundPos, false);
	//IMAGE->Render(IMAGE->FindImage(a), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage(kindC), m_ChangPos, true);
	
	//IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);
	
	if (chkOrder)m_Notice_button->Render();	//�˸���ư �׸� 
	m_Option_button->Render();	//�ɼǹ�ư �׸�
	m_goshop->Render();//�������� ��ư
	if (WndState != EMPTY_WND) {
		m_Window->Render(WndState);
	}
	m_Mouse->Render(MousePoint);
}

void cIngameScene::Release()
{
	//SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Mouse);
	//SAFE_DELETE(m_Exit_Button);

	SAFE_DELETE(m_Window);
	SAFE_DELETE(m_goshop);
	SAFE_DELETE(m_Option_button); 
	SAFE_DELETE(m_Notice_button);
}
