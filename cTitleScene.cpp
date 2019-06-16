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
	BGM = true;
	EFFECT = true;
	isOrder = false;
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"./Sound/BGM.wav";

	mciSendCommand(1, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);
	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0;
	m_StartButton = new cButton(320, 550, "Start");
	m_GameExitButton = new cButton(100, 700, "Exit");
	m_option_button = new cButton(480, 700, "Option");
	m_StartButton->Init();
	m_GameExitButton->Init();
	m_option_button->Init();
}

void cTitleScene::Update()
{
	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);
	}
	if (m_StartButton->Update()) {
		SCENE->ChangeScene("InGame");
	}
	if (m_GameExitButton->Update()) {
		
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
	m_GameExitButton->Render();
	m_option_button->Render();
}

void cTitleScene::Release()
{
	SAFE_DELETE(m_StartButton);
	SAFE_DELETE(m_GameExitButton);
	SAFE_DELETE(m_option_button);
}
