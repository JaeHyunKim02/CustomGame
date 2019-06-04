#include "stdafx.h"
#include "cTitleScene.h"
#include"cButton.h"

#include <windows.h> 
cTitleScene::cTitleScene()
{
}


cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0;
	m_StartButton = new cButton(320, 550, "Start");
	m_ExitButton = new cButton(100, 700, "Exit");
	m_option_button = new cButton(480, 700, "Option");
	m_StartButton->Init();
	m_ExitButton->Init();
	m_option_button->Init();
}

void cTitleScene::Update()
{
	if (m_StartButton->Update()) {
		DEBUG_LOG("Click");
		SCENE->ChangeScene("InGame");
	}
	if (m_ExitButton->Update()) {
		DEBUG_LOG("Click");
		PostQuitMessage(0);
	}
	if (m_option_button->Update()) {
		DEBUG_LOG("Click");
	}
}

void cTitleScene::Render()
{
	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);
	IMAGE->Render(IMAGE->FindImage("Game_Logo"), m_TitleBgPos, false);

	m_StartButton->Render();
	m_ExitButton->Render();
	m_option_button->Render();
}

void cTitleScene::Release()
{
	SAFE_DELETE(m_StartButton);
	SAFE_DELETE(m_ExitButton);
	SAFE_DELETE(m_option_button);
}
