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
	srand((unsigned)time(NULL));
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0; 
	Pos.x = 0;
	Pos.y = 0; 
	WndState = EMPTY_WND;
	m_Exit_Button = new cButton(100, 500, "Exit");
	m_Exit_Button->Init();
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
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//클릭 효과음
	}
	if (m_Exit_Button->Update()) {
		DEBUG_LOG("Click");
		PostQuitMessage(0);
	} 
	if (m_Notice_button->Update()) {//알림 버튼 클릭한 경우 
		WndState = MAKING_WND; DEBUG_LOG("Click");
	} 

	if (m_Info_button->Update()) {//가게정보 버튼을 클릭한 경우 
		WndState =STOREINFO_WND; DEBUG_LOG("Click");
	} 

	if (m_Option_button->Update()) {//옵션 버튼을 클릭  
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
	
	m_Notice_button->Render();	//알림버튼 그림
	m_Info_button->Render();	//가게정보버튼 그림
	m_Option_button->Render();	//옵션버튼 그림
	if (WndState != EMPTY_WND) {
		m_Window->Render(WndState);
	}
}

void cIngameScene::Release()
{
	//SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Exit_Button);
	SAFE_DELETE(m_Option_button);
	SAFE_DELETE(m_Info_button);
	SAFE_DELETE(m_Notice_button);
	SAFE_DELETE(m_notice_exit_btn);
}
