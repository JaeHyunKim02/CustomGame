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
	//프레임 , 애니메이션을 위한 것이다.
	//m_PlayerFrame = new cFrame;

	//SetFrame은 순서대로 시작 프레임, 끝 프레임, 딜레이값을 받는다.
	//m_PlayerFrame->SetFrame(0, 2, 50);
	
	m_Exit_Button = new cButton(100, 500, "Exit");
	m_Exit_Button->Init();
	m_option_button = new cButton(100, 300, "Option");
	m_option_button->Init();
	m_info_button = new cButton(550, 100, "info");
	m_info_button->Init();
	m_notice_button = new cButton(100, 100, "notice");
	m_notice_button->Init();

	//창 초기화
	m_notice_Wnd = new cWindow(320, 480, "notice_Wnd",500,230,"wndExit");
	m_notice_Wnd->Init();
	m_info_Wnd = new cWindow(320, 480, "storeInfo_Wnd", 500, 230, "wndExit");
	m_info_Wnd->Init();
	m_option_Wnd = new cWindow(320, 480, "option_Wnd", 500, 230, "wndExit");
	m_option_Wnd->Init();
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
	if (m_notice_button->Update())	m_notice_Wnd->bChkBtn = true;	//알림 버튼 클릭한 경우
	if (m_notice_Wnd->Update())		m_notice_Wnd->bChkBtn = false;	//알림 닫기 버튼을 클릭한 경우

	if (m_info_button->Update())	m_info_Wnd->bChkBtn = true;		//가게정보 버튼을 클릭한 경우
	if (m_info_Wnd->Update())		m_info_Wnd->bChkBtn = false;	//가게정보창 닫기 버튼을 클릭한 경우

	if (m_option_button->Update())	m_option_Wnd->bChkBtn = true;	//옵션 버튼을 클릭한 경우
	if (m_option_Wnd->Update())		m_option_Wnd->bChkBtn = false;	//옵션창 닫기 버튼을 클릭한 경우
}

void cIngameScene::Render()
{
	Point m_BackGroundPos;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;

	Point m_MoneyIconPos;
	m_MoneyIconPos.x = 450;
	m_MoneyIconPos.y = 200;
	 
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
	IMAGE->Render(IMAGE->FindImage("InGameBg"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);
	m_Exit_Button->Render();
	m_option_button->Render();
	
	m_notice_button->Render();	//알림버튼 그림
	m_notice_Wnd->Render();		//옵션창

	m_info_button->Render();	//가게정보버튼 그림
	m_info_Wnd->Render();		//옵션창

	m_option_button->Render();	//옵션버튼 그림
	m_option_Wnd->Render();		//옵션창
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

	SAFE_DELETE(m_notice_Wnd);
	SAFE_DELETE(m_info_Wnd);
	SAFE_DELETE(m_option_Wnd);
}
