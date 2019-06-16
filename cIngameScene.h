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
	int WndState;
	int m_nConcept;

	cButton * m_Exit_Button;
	cButton * m_Option_button;
	cButton * m_Info_button;
	cButton * m_Notice_button;

	Point m_BackGroundPos;
	Point m_MoneyIconPos;
	//알림창 버튼
	cButton * m_notice_exit_btn;
	cWindow * m_Window;
public:
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
	int Money;
public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
};

