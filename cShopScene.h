#pragma once
#include"cButton.h"
#include"cScene.h"

class cShopScene : public cScene
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

private:
	
	bool bBuyBtn[4][4];
public:
	cShopScene();
	~cShopScene();

	void Init();
	void Update();
	void Render();
	void Release();
public:
	void UpdateTop();
	void UpdateBOt();
	void UpdateAcc();
	void UpdateShoes();
};