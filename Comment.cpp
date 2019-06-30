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
	m_GoTitle = new cButton(320, 500, "GameExit_Yes");
	m_GoTitle->Init();
	
	CommentPos1.x = 320;
	CommentPos1.y = 100;
	CommentPos2.x = 320;
	CommentPos2.y = 300;
	CommentPos3.x = 320;
	CommentPos3.y = 600;


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
	if (4 >= CommentCount) CommentCount = 1;

	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;

	m_Mouse->Update(MousePoint);
	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);
	}//kjhgfjkhjg
	if (m_GoTitle->Update()) {
		SCENE->ChangeScene("InGame");
	}

	
	if(MyComment == GREAT){//이런 느낌으로 조건 넣으면 될듯

	}
	else if(MyComment == GOOD){//이런 느낌으로 조건 넣으면 될듯

	}
	else if(MyComment == BAD){//이런 느낌으로 조건 넣으면 될듯
	
	}
	
	if (CommentCount == 1) {
		//m_Comment1
	}
	else if (CommentCount == 2) {
		//m_Comment2
	}
	else if (CommentCount == 3) {
		//m_Comment3
	}
}

void Comment::Render()
{
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);

	if (m_Comment1 != "NULL") {
		IMAGE->Render(IMAGE->FindImage(m_Comment1), CommentPos1, false);
	}
	if (m_Comment2 != "NULL") {
		IMAGE->Render(IMAGE->FindImage(m_Comment2), CommentPos2, false);
	}
	if (m_Comment3 != "NULL") {
		IMAGE->Render(IMAGE->FindImage(m_Comment3), CommentPos3, false);
	}

	m_GoTitle->Render();
	m_Mouse->Render(MousePoint);
}

void Comment::Release()
{
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_GoTitle);
}
