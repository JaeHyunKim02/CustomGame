#pragma once
#include "cScene.h"

class cButton;
class cCloset;
class cMainScene:public cScene
{
private:
	cTexture * m_BackGround;
	Point m_BackGroundPos;
public:
	cMainScene();
	~cMainScene();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	int getScore();
private:
	cCloset * m_Top_Closet;
	cCloset * m_Bottom_Closet;
	cCloset * m_Accessory_Closet;
	cCloset * m_Shoes_Closet;

	cButton * m_Closet_Top_btn;
	cButton * m_Closet_Bottom_btn;
	cButton * m_Closet_Accessory_btn;
	cButton * m_Closet_Shoes_btn;

	cButton * m_Complete_btn;

private:
	_ClosetKind m_EDress_State;
	_ClosetKind m_EDress[4];
}; 