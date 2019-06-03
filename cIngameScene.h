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
	bool bgmActive;

	cButton * m_Exit_Button;
	cButton * m_option_button;
	cButton * m_info_button;
	cButton * m_notice_button;

	//알림창 버튼
	cButton * m_notice_exit_btn;
	cWindow * m_notice_Wnd;
	cWindow * m_info_Wnd;
	cWindow * m_option_Wnd;
	bool bNotice_Click;

public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

