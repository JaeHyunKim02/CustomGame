#pragma once
#include "cScene.h"

class cButton;
class cCloset;
class cMainScene:public cScene
{
private:
	cTexture * m_BackGround;
	Point m_BackGroundPos;
	Point m_ClosetPos;

	cMouseCursor * m_Mouse;
	Point MousePoint;
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

	cButton * m_Closet_Top_btn_1;
	cButton * m_Closet_Top_btn_2;
	cButton * m_Closet_Top_btn_3;
	cButton * m_Closet_Top_btn_4;

	cButton * m_Closet_Bottom_btn_1;
	cButton * m_Closet_Bottom_btn_2;
	cButton * m_Closet_Bottom_btn_3;
	cButton * m_Closet_Bottom_btn_4;
	
	cButton * m_Closet_Accessory_btn_1;
	cButton * m_Closet_Accessory_btn_2;
	cButton * m_Closet_Accessory_btn_3;
	cButton * m_Closet_Accessory_btn_4;

	cButton * m_Closet_Shoes_btn_1;
	cButton * m_Closet_Shoes_btn_2;
	cButton * m_Closet_Shoes_btn_3;
	cButton * m_Closet_Shoes_btn_4;

	cButton * m_Complete_btn;

private:
	_ClosetKind m_EDress_State;
	_ClosetKind m_EDress[4];
}; 