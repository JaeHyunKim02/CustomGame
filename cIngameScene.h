#pragma once
#include "cScene.h"
class cButton;
class cIngameScene : public cScene
{
private:
	cTexture * m_BackGround;
	cFrame * m_PlayerFrame;
	Point Pos;
	bool b_Move;

	cButton * m_Exit_Button;
	cButton * m_option_button;
	cButton * m_info_button;
	cButton * m_notice_button;



public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

