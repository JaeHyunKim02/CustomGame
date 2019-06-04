#pragma once
#include "cScene.h"
class cButton;
class cWindow;
class cIngameScene : public cScene
{
private:
	cTexture * m_BackGround;
	//cFrame * m_PlayerFrame;
	Point Pos;
	bool b_Move;

	cButton * m_Exit_Button;
	cButton * m_Option_button;
	cButton * m_Info_button;
	cButton * m_Notice_button;

	
	//알림창 버튼
	cButton * m_notice_exit_btn;
	//알림창 
	cWindow * m_Notice_Wnd;
	cWindow * m_Info_Wnd;
	cWindow * m_Option_Wnd;
	bool bNotice_Click;
public:
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

