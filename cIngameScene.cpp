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
	//������ , �ִϸ��̼��� ���� ���̴�.
	//m_PlayerFrame = new cFrame;

	//SetFrame�� ������� ���� ������, �� ������, �����̰��� �޴´�.
	//m_PlayerFrame->SetFrame(0, 2, 50);
	
	m_Exit_Button = new cButton(100, 500, "Exit");
	m_Exit_Button->Init();
	m_option_button = new cButton(100, 300, "Option");
	m_option_button->Init();
	m_info_button = new cButton(550, 100, "info");
	m_info_button->Init();
	m_notice_button = new cButton(100, 100, "notice");
	m_notice_button->Init();

	//â �ʱ�ȭ
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
	if (m_notice_button->Update())	m_notice_Wnd->bChkBtn = true;	//�˸� ��ư Ŭ���� ���
	if (m_notice_Wnd->Update())		m_notice_Wnd->bChkBtn = false;	//�˸� �ݱ� ��ư�� Ŭ���� ���

	if (m_info_button->Update())	m_info_Wnd->bChkBtn = true;		//�������� ��ư�� Ŭ���� ���
	if (m_info_Wnd->Update())		m_info_Wnd->bChkBtn = false;	//��������â �ݱ� ��ư�� Ŭ���� ���

	if (m_option_button->Update())	m_option_Wnd->bChkBtn = true;	//�ɼ� ��ư�� Ŭ���� ���
	if (m_option_Wnd->Update())		m_option_Wnd->bChkBtn = false;	//�ɼ�â �ݱ� ��ư�� Ŭ���� ���
}

void cIngameScene::Render()
{
	Point m_BackGroundPos;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;

	Point m_MoneyIconPos;
	m_MoneyIconPos.x = 450;
	m_MoneyIconPos.y = 200;
	 
	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("InGameBg"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);
	m_Exit_Button->Render();
	m_option_button->Render();
	
	m_notice_button->Render();	//�˸���ư �׸�
	m_notice_Wnd->Render();		//�ɼ�â

	m_info_button->Render();	//����������ư �׸�
	m_info_Wnd->Render();		//�ɼ�â

	m_option_button->Render();	//�ɼǹ�ư �׸�
	m_option_Wnd->Render();		//�ɼ�â
}

void cIngameScene::Release()
{
	//�������� �� Release���� �����ؾ� �Ѵ�.
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
