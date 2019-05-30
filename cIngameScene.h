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

	cButton * m_Button;
	cButton * m_option_button;

public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

