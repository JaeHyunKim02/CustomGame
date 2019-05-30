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

	bgmActive = true;

	//������ , �ִϸ��̼��� ���� ���̴�.
	m_PlayerFrame = new cFrame;

	//SetFrame�� ������� ���� ������, �� ������, �����̰��� �޴´�.
	m_PlayerFrame->SetFrame(0, 2, 50);
	
	m_Exit_Button = new cButton(100, 500, "Exit");
	m_Exit_Button->Init();

	m_option_button = new cButton(100, 300, "Option");
	m_option_button->Init();

	m_info_button = new cButton(550, 100, "info");
	m_info_button->Init();

	m_notice_button = new cButton(100, 100, "notice");

}

void cIngameScene::Update()
{

	m_PlayerFrame->Frame();
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
	}

	if (m_Exit_Button->Update()) {
		DEBUG_LOG("Click");
		PostQuitMessage(0);
	}
	if (m_option_button->Update()) {
		DEBUG_LOG("OPTION Click");
		
			if (bgmActive == true)
			{
				PlaySound(NULL, NULL, SND_PURGE);
				bgmActive = false;
			}
			else if(bgmActive == false)
			{
				PlaySound(TEXT("./Sound/BGM.wav"), NULL, SND_ASYNC|SND_LOOP);
				bgmActive = true;
			}
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


	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("InGameBG"), m_BackGroundPos, false);
	//IMAGE->Render(IMAGE->FindImage("OH")->FindImage(0), Pos, true, RGB(255,0 ,255));
	//IMAGE->Render(IMAGE->FindImage("Exit_Nomal")->FindImage(0), Pos, true, RGB(255, 0, 255));
	//IMAGE->Render(IMAGE->FindImage("Option_Nomal")->FindImage(0), m_OptionPos, true, RGB(255, 0, 255));
	IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);
	m_Exit_Button->Render();
	m_option_button->Render();
	m_info_button->Render();
	m_notice_button->Render();


}

void cIngameScene::Release()
{
	//�������� �� Release���� �����ؾ� �Ѵ�.
	//SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Exit_Button);
	SAFE_DELETE(m_option_button);
	SAFE_DELETE(m_info_button);
	SAFE_DELETE(m_notice_button);
}
