#pragma once
#include "cScene.h"
class cCloset;
class cButton;
 
class cMainScene:public cScene
{
private:
	eDRESS_KIND eDress[4]; 
	eDRESS_KIND m_eDressKind;
private:
	cTexture * m_BackGround;
	Point m_BackGroundPos;

	cButton * m_Top_btn;
	cButton * m_Bottom_btn;
	cButton * m_Accessory_btn;
	cButton * m_Shoes_btn;

	cCloset * m_Top_closet;
	cCloset * m_Bottom_closet;
	cCloset * m_Accessory_closet;
	cCloset * m_Shoes_closet;
public:
	cMainScene();
	~cMainScene();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

}; 
