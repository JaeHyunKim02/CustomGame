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

	//������ , �ִϸ��̼��� ���� ���̴�.
	m_PlayerFrame = new cFrame;

	//SetFrame�� ������� ���� ������, �� ������, �����̰��� �޴´�.
	m_PlayerFrame->SetFrame(0, 2, 50);
	
	m_Button = new cButton(250, 500, "Exit");
	m_Button->Init();

	m_option_button = new cButton(400, 100, "Option");
	m_option_button->Init();

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

	if (m_Button->Update()) {
		DEBUG_LOG("Click");
		PostQuitMessage(0);
	}
	if (m_option_button->Update()) {
		DEBUG_LOG("OPTION Click");

	}
}

void cIngameScene::Render()
{
	Point m_BackGroundPos;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;


	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("InGameBG"), m_BackGroundPos, false);
	//IMAGE->Render(IMAGE->FindImage("OH")->FindImage(0), Pos, true, RGB(255,0 ,255));
	//IMAGE->Render(IMAGE->FindImage("Exit_Nomal")->FindImage(0), Pos, true, RGB(255, 0, 255));
	//IMAGE->Render(IMAGE->FindImage("Option_Nomal")->FindImage(0), m_OptionPos, true, RGB(255, 0, 255));

	m_Button->Render();
	m_option_button->Render();
}

void cIngameScene::Release()
{
	//�������� �� Release���� �����ؾ� �Ѵ�.
	//SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Button);
	SAFE_DELETE(m_option_button);
}
