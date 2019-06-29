#include "stdafx.h"
#include"cButton.h"
#include"Comment.h"
Comment::Comment()
{

}


Comment::~Comment()
{

}

void Comment::Init()
{
	m_Mouse = new cMouseCursor();
	m_Mouse->Init();

	BGM = true;
	EFFECT = true;
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"./Sound/BGM.wav";

	mciSendCommand(1, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);


	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0;
	m_GoTitle = new cButton(320, 700, "GameExit_Yes");

	
	srand(nSeed);
	//m_Comment = rand()%3;
	if (MyScore >= 4) {
		MyComment = GREAT;
	}
	else if (MyScore >= 2) {
		MyComment = GOOD;
	}
	else if (MyScore >= 0) {
		MyComment = BAD;
	}
}

void Comment::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;

	m_Mouse->Update(MousePoint);
	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);
	}
	if (m_GoTitle->Update()) {
		SCENE->ChangeScene("InGame");
	}
	if(MyComment == GREAT){//이런 느낌으로 조건 넣으면 될듯

	}
	else if(MyComment == GOOD){//이런 느낌으로 조건 넣으면 될듯
	}
	else if(MyComment == BAD){//이런 느낌으로 조건 넣으면 될듯
	}
	
}

void Comment::Render()
{
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);
	m_GoTitle->Render();
	m_Mouse->Render(MousePoint);
}

void Comment::Release()
{
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_GoTitle);
}
