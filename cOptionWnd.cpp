#include "stdafx.h"
#include "cOptionWnd.h"
#include"cButton.h"
#include"cWindow.h"
cOptionWnd::cOptionWnd(int x, int y, const string & key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
}


cOptionWnd::~cOptionWnd()
{
	Release();
}

void cOptionWnd::Init()
{
	m_BGMOFF = new cButton(320, 320, "option_BGM_Off");
	m_BGMOFF->Init();
	m_BGMON = new cButton(430, 320, "option_BGM_On");
	m_BGMON->Init();
	m_SoundOFF = new cButton(430, 405, "option_Click_Off");
	m_SoundOFF->Init();
	m_SoundON = new cButton(320, 405, "option_Click_On");
	m_SoundON->Init();
	//m_SoundON = new cButton()

}

void cOptionWnd::Update(const string& key)
{
	if (bClickChk) {
		Init();
		bClickChk = false;
	}
	if (!bClickChk) {
		/*if (INPUT->MouseLUp()) {
			bClickChk = true;
			SCENE->ChangeScene(key);
		}*/
		if (m_BGMOFF->Update()) {
			mciSendCommand(1, MCI_STOP, MCI_DGV_PLAY_REPEAT, NULL);
			BGM = true;
			
		}
		if (m_BGMON->Update()) {
			mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);
			BGM = false;
			
		}
		if (m_SoundOFF->Update()) {

			EFFECT = false;

		}
		if (m_SoundON->Update()) {
		EFFECT = true;
		}
		
	}
}

void cOptionWnd::Render()
{
	if (!bClickChk) {
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_BGMOFF->Render();
		m_BGMON->Render();
		m_SoundOFF->Render();
		m_SoundON->Render();
	}
}

void cOptionWnd::Release()
{
	SAFE_DELETE(m_BGMOFF);
	SAFE_DELETE(m_BGMON);
	SAFE_DELETE(m_SoundOFF);
	SAFE_DELETE(m_SoundON);

}
