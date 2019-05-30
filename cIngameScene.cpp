#include "stdafx.h"
#include "cIngameScene.h"

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
	//프레임 , 애니메이션을 위한 것이다.
	m_PlayerFrame = new cFrame;

	//SetFrame은 순서대로 시작 프레임, 끝 프레임, 딜레이값을 받는다.
	m_PlayerFrame->SetFrame(0, 2, 50);
	
	m_Exit_Button = new cButton(100, 500, "Exit");
	m_Exit_Button->Init();

	m_option_button = new cButton(100, 300, "Option");
	m_option_button->Init();

	m_info_button = new cButton(550, 100, "info");
	m_info_button->Init();

	m_notice_button = new cButton(100, 100, "notice");
	m_notice_button->Init();

	m_notice_exit_btn = new cButton(500, 200, "newsExit");
	m_notice_exit_btn->Init();
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

	if (m_Exit_Button->Update()) {
		DEBUG_LOG("Click");
		PostQuitMessage(0);
	}
	if (m_option_button->Update()) {
		DEBUG_LOG("OPTION Click");
	} 
	if (m_notice_button->Update()) {
		bNotice_Click = true;
	}
	if (m_notice_exit_btn->Update()) {
		bNotice_Click = false;
	}
}

void cIngameScene::Render()
{
	Point m_BackGroundPos;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;

	Point m_MoneyIconPos;
	m_MoneyIconPos.x = 450;
	m_MoneyIconPos.y = 200;

	Point m_NewsWndPos;
	m_NewsWndPos.x = 320;
	m_NewsWndPos.y = 480;
	Point m_NewsExitPos;
	m_NewsExitPos.x = 500;
	m_NewsExitPos.y = 200;
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
	IMAGE->Render(IMAGE->FindImage("InGameBg"), m_BackGroundPos, false);
	//IMAGE->Render(IMAGE->FindImage("OH")->FindImage(0), Pos, true, RGB(255,0 ,255));
	//IMAGE->Render(IMAGE->FindImage("Exit_Nomal")->FindImage(0), Pos, true, RGB(255, 0, 255));
	//IMAGE->Render(IMAGE->FindImage("Option_Nomal")->FindImage(0), m_OptionPos, true, RGB(255, 0, 255));
	IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);
	m_Exit_Button->Render();
	m_option_button->Render();
	m_info_button->Render();
	m_notice_button->Render();
	if (bNotice_Click) {
		IMAGE->Render(IMAGE->FindImage("News"), m_NewsWndPos, true, false);
		m_notice_exit_btn->Render();
	}
}

void cIngameScene::Release()
{
	//프레임은 꼭 Release에서 제거해야 한다.
	//SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Exit_Button);
	SAFE_DELETE(m_option_button);
	SAFE_DELETE(m_info_button);
	SAFE_DELETE(m_notice_button);
	SAFE_DELETE(m_notice_exit_btn);
}
