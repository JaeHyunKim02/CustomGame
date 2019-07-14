#pragma once
#include "cScene.h"
class cWindow;
class cOptionWnd;
class cButton;
class cTitleScene : public cScene
{
private:
	cTexture * m_BackGround;
	cOptionWnd * m_OptionWnd;
	Point Pos;
	Point m_TitleBgPos;
	bool b_Move;
	bool isOver;
	int WndState;

	cWindow *  m_Window;
	cButton * m_StartButton;
	cButton * m_GameExitButton;
	cButton * m_option_button;
	cButton * m_HowToPlay_button;
	//HowToPlay
public:
	//¸¶¿ì½º
	cMouseCursor * m_Mouse;
	Point MousePoint;
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
public:
	cTitleScene();
	virtual ~cTitleScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};
