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
	if(MyComment == GREAT){//�̷� �������� ���� ������ �ɵ�

	}
	else if(MyComment == GOOD){//�̷� �������� ���� ������ �ɵ�
	}
	else if(MyComment == BAD){//�̷� �������� ���� ������ �ɵ�
	}
	
}

void Comment::Render()
{
	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);
	m_GoTitle->Render();
	m_Mouse->Render(MousePoint);
}

void Comment::Release()
{
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_GoTitle);
}
