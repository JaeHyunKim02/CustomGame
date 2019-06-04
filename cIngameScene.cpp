#include "stdafx.h"
#include "cIngameScene.h"
#include "cWindow.h"
#include "cButton.h"

cIngameScene::cIngameScene()
{
}


cIngameScene::~cIngameScene()
{
}

void cIngameScene::Init()
{

	Pos.x = 0;
	Pos.y = 0;
	b_Move = false;
	bNotice_Click = false;
	
	m_Exit_Button = new cButton(100, 500, "Exit");
	m_Exit_Button->Init();
	m_Option_button = new cButton(100, 300, "Option");
	m_Option_button->Init();
	m_Info_button = new cButton(550, 100, "Info");
	m_Info_button->Init();
	m_Notice_button = new cButton(100, 100, "Making");
	m_Notice_button->Init();

	//â �ʱ�ȭ
	m_Notice_Wnd = new cWindow(320, 480, "Order_Wnd","WndExit", ORDER_WND); 
	m_Notice_Wnd->Init();
	m_Info_Wnd = new cWindow(320, 480, "StoreInfo_Wnd", "WndExit",STOREINFO_WND);
	m_Info_Wnd->Init();
	m_Option_Wnd = new cWindow(320, 480, "Option_Wnd", "WndExit",OPTION_WND);
	m_Option_Wnd->Init();
}


void cIngameScene::Update()
{

	/*m_PlayerFrame->Frame();
	if (INPUT->KeyPress(VK_UP)) {
		Pos.y -= 10;

	}
	if (INPUT->KeyPress(VK_DOWN)) {
		Pos.y += 10;
	}
	if (INPUT->KeyPress(VK_RIGHT)) {
		Pos.x += 10;
	}
	if (INPUT->KeyPress(VK_LEFT)) {
		Pos.x -= 10;
	}*/
	if (INPUT->MouseLDown())		PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//Ŭ�� ȿ����

	if (m_Exit_Button->Update()) {
		DEBUG_LOG("Click");
		PostQuitMessage(0);
	} 
	if (m_Notice_button->Update()) {
		m_Notice_Wnd->bChkBtn = true;	//�˸� ��ư Ŭ���� ���
		m_Notice_Wnd->WndState = ORDER_WND;
	}
	if (m_Notice_Wnd->Update())	m_Notice_Wnd->bChkBtn = false;	//�˸� �ݱ� ��ư�� Ŭ���� ���

	if (m_Info_button->Update()) {
		m_Info_Wnd->bChkBtn = true;		//�������� ��ư�� Ŭ���� ���
		m_Info_Wnd->WndState = STOREINFO_WND;
	}
	if (m_Info_Wnd->Update())	m_Info_Wnd->bChkBtn = false;	//��������â �ݱ� ��ư�� Ŭ���� ���

	if (m_Option_button->Update()) {
		m_Option_Wnd->bChkBtn = true;	//�ɼ� ��ư�� Ŭ���� ���
		m_Option_Wnd->WndState = OPTION_WND;
	}
	if (m_Option_Wnd->Update())	m_Option_Wnd->bChkBtn = false;	//�ɼ�â �ݱ� ��ư�� Ŭ���� ���
}

void cIngameScene::Render()
{
	Point m_BackGroundPos;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;

	Point m_MoneyIconPos;
	m_MoneyIconPos.x = 450;
	m_MoneyIconPos.y = 200;
	 
	IMAGE->Render(IMAGE->FindImage("InGameBg"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);
	
	m_Notice_button->Render();	//�˸���ư �׸�
	m_Info_button->Render();	//����������ư �׸�
	m_Option_button->Render();	//�ɼǹ�ư �׸�

	m_Notice_Wnd->Render();		//�ɼ�â
	m_Info_Wnd->Render();		 
	m_Option_Wnd->Render();		 
}

void cIngameScene::Release()
{
	//�������� �� Release���� �����ؾ� �Ѵ�.
	//SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Exit_Button);
	SAFE_DELETE(m_Option_button);
	SAFE_DELETE(m_Info_button);
	SAFE_DELETE(m_Notice_button);
	SAFE_DELETE(m_notice_exit_btn);

	m_Notice_Wnd->Release();
	m_Info_Wnd->Release();
	m_Option_Wnd->Release();
	SAFE_DELETE(m_Notice_Wnd);
	SAFE_DELETE(m_Info_Wnd);
	SAFE_DELETE(m_Option_Wnd);
}
