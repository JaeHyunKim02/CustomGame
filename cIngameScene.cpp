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
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0; 

	Pos.x = 0;
	Pos.y = 0; 
	WndState = EMPTY_WND; 
	m_Option_button = new cButton(100, 300, "Option");
	m_Option_button->Init();
	m_Info_button = new cButton(550, 100, "Info");
	m_Info_button->Init();
	m_Notice_button = new cButton(100, 100, "Notice");
	m_Notice_button->Init(); 

	m_Window = new cWindow(320, 480, "Making_Wnd");
	m_Window->Init();
}


void cIngameScene::Update()
{ 
	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//Ŭ�� ȿ����
	} 
	if (m_Notice_button->Update()) {//�˸� ��ư Ŭ���� ��� 
		WndState = MAKING_WND; DEBUG_LOG("Click");
	} 

	if (m_Info_button->Update()) {//�������� ��ư�� Ŭ���� ��� 
		WndState =STOREINFO_WND; DEBUG_LOG("Click");
	} 

	if (m_Option_button->Update()) {//�ɼ� ��ư�� Ŭ��  
		WndState = OPTION_WND; DEBUG_LOG("Click");
	} 
	if (WndState != EMPTY_WND) {
		m_Window->Update(WndState);
	}
}

void cIngameScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("InGameBg"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);
	
	m_Notice_button->Render();	//�˸���ư �׸�
	m_Info_button->Render();	//����������ư �׸�
	m_Option_button->Render();	//�ɼǹ�ư �׸�
	if (WndState != EMPTY_WND) {
		m_Window->Render(WndState);
	}
}

void cIngameScene::Release()
{
	//SAFE_DELETE(m_PlayerFrame); 
	SAFE_DELETE(m_Option_button);
	SAFE_DELETE(m_Info_button);
	SAFE_DELETE(m_Notice_button);
	SAFE_DELETE(m_notice_exit_btn);
}
