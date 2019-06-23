#pragma once
#include "cScene.h"

class cButton;
class cTitleScene : public cScene
{
private:
	cTexture * m_BackGround;
	cFrame * m_PlayerFrame;
	Point Pos;
	Point m_TitleBgPos;
	bool b_Move;

	int WndState;


	cButton * m_StartButton;
	cButton * m_GameExitButton;
	cButton * m_option_button;
public:
	//¸¶¿ì½º
	cMouseCursor * m_Mouse;
	Point MousePoint;
public:
	cTitleScene();
	virtual ~cTitleScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};
