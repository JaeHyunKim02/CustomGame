#pragma once
#include"cButton.h"
#include"cScene.h"

class cShopScene : public cScene
{
private:
	cTexture * ShopBackGround;
	Point m_ShopBgPos;

	cButton * m_BuyButton[4][4];
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
	void BuyDress();
	void CntBuyList(int i, int j);
};