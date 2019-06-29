#pragma once
#include"cButton.h"
#include"cScene.h"

class cShopScene: public cScene
{
private:
	cTexture * ShopBackGround;
	Point m_ShopBgPos;

	cButton * m_BuyButton_1;
	cButton * m_BuyButton_2;
	cButton * m_BuyButton_3;
	cButton * m_BuyButton_4;

	cButton * m_Exit;
	Point pos;

	cMouseCursor * m_Mouse;
	Point MousePoint;

	bool isBuy1=false;
	bool isBuy2=false;
	bool isBuy3=false;
	bool isBuy4=false;

public:
	cShopScene();
	~cShopScene();

	void Init();
	void Update();
	void Render();
	void Release();
};