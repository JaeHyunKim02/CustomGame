#include "stdafx.h"
#include "cTitleScene.h"
#include"cButton.h"
#include <windows.h> 
#include"cMouseCursor.h"
#include"cOptionWnd.h"
#include"cWindow.h"
cTitleScene::cTitleScene()
{
}


cTitleScene::~cTitleScene()
{
	Release();
}

void cTitleScene::Init()
{

	isChangTime = false;
	isOrder = false;

	m_Mouse = new cMouseCursor();
	m_Mouse->Init();
	m_OptionWnd = new cOptionWnd(320, 480, "option_window");
	m_OptionWnd->Init();
	WndState = EMPTY_WND;

	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"./Sound/BGM.wav";

	mciSendCommand(1, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);

	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0;
	m_StartButton = new cButton(320, 550, "Start");
	m_GameExitButton = new cButton(590, 40, "Exit");
	m_option_button = new cButton(520, 40, "Option");
	m_HowToPlay_button = new cButton(450, 40, "HowToPlay");
	m_StartButton->Init();
	m_GameExitButton->Init();
	m_option_button->Init();
	m_HowToPlay_button->Init();
}
 
void cTitleScene::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;

	m_Mouse->Update(MousePoint);

	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);
	}
	if (m_StartButton->Update()) {
		int m_nConcept;
		isOrder = true; 
		isChangTime = true;
		m_nConcept = rand() % 4;
		SCENE->ChangeScene("InGame");
	}
	if (m_option_button->Update()) {
		WndState = OPTION_WND;
	}
	else if (WndState != EMPTY_WND) {
		switch (WndState) {
		case OPTION_WND:m_OptionWnd->Update("Title"); break;
		}
	}
	if (m_GameExitButton->Update()) {
		PostQuitMessage(0);
		//SCENE->ChangeScene("Comment");
	}
	if (m_HowToPlay_button->Update()) {

	}
	
}

void cTitleScene::Render()
{
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);

	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);
	//IMAGE->Render(IMAGE->FindImage("Game_Logo"), m_TitleBgPos, false,RGB(255,0,255));

	//IMAGE->Render(IMAGE->FindImage("MouseTest"), MousePoint, true, RGB(255, 0, 255));

	m_StartButton->Render();
	m_GameExitButton->Render();
	m_option_button->Render();
	m_HowToPlay_button->Render();
	if (WndState != EMPTY_WND) {
		switch (WndState) {
		case OPTION_WND:m_OptionWnd->Render(); break;
		}
	}

	m_Mouse->Render(MousePoint);
}

void cTitleScene::Release()
{
	
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_StartButton);
	SAFE_DELETE(m_GameExitButton);
	SAFE_DELETE(m_option_button);
	SAFE_DELETE(m_HowToPlay_button);
	SAFE_DELETE(m_OptionWnd);
}
