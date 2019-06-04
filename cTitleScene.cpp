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
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"./Sound/BGM.wav";

	mciSendCommand(1, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);
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
	if (INPUT->MouseLDown())		PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);
	if (m_StartButton->Update()) {
		DEBUG_LOG("Click");
		PlaySound(TEXT("./Sound/General touch_effect.wav"), NULL, SND_ASYNC);
		SCENE->ChangeScene("InGame");
	}
	if (m_ExitButton->Update()) {
		DEBUG_LOG("Click");
		PlaySound(TEXT("./Sound/General touch_effect.wav"), NULL, SND_ASYNC);
		PostQuitMessage(0);
	}
	if (m_option_button->Update()) {
		DEBUG_LOG("Click");
		PlaySound(TEXT("./Sound/General touch_effect.wav"), NULL, SND_ASYNC);
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
