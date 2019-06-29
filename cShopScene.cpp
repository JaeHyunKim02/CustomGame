#include "stdafx.h"
#include "cShopScene.h"
bool bBuyList[4][4];
cShopScene::cShopScene()
{

	
}


cShopScene::~cShopScene()
{
	Release();
}

void cShopScene::Init()
{ 
	m_ShopBgPos.x = 0;
	m_ShopBgPos.y = 0;

	m_Mouse = new cMouseCursor();
	m_Mouse->Init();

	m_BuyButton_1 = new cButton(50, 500, "Buy");
	m_BuyButton_2 = new cButton(200, 500, "Buy");
	m_BuyButton_3 = new cButton(350, 500, "Buy");
	m_BuyButton_4 = new cButton(500, 500, "Buy");

	m_Exit = new cButton(500, 200, "WndExit");
	m_Exit->Init();
	m_BuyButton_1->Init();
	m_BuyButton_2->Init();
	m_BuyButton_3->Init();
	m_BuyButton_4->Init();

}

void cShopScene::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;
	m_Mouse->Update(MousePoint);
	UpdateTop();
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (bBuyBtn[j][i] == true && bBuyList[j][i] == false) {
				if (Money > 1000 * (i + 1)) {
					bBuyList[j][i] = true;
					Money -= 1000 * (i + 1);
				}
				else {
					bBuyBtn[j][i] = false;
					DEBUG_LOG("구입 실패");
				}
			}
		}
	}

	if (m_Exit->Update()) {
		SCENE->ChangeScene("InGame");
	}
} 
void cShopScene::UpdateTop()
{
	if (m_BuyButton_1->Update())	   bBuyBtn[eTOP][0] = true;
	else if (m_BuyButton_2->Update())  bBuyBtn[eTOP][1] = true;
	else if (m_BuyButton_3->Update())  bBuyBtn[eTOP][2] = true;
	else if (m_BuyButton_4->Update())  bBuyBtn[eTOP][3] = true; 
 
}
//void cShopScene::UpdateBOt()
//{
//	if (m_BuyButton_1->Update())  bBuyBtn[eTOP][0] = true;
//	if (m_BuyButton_2->Update())  bBuyBtn[eTOP][1] = true;
//	if (m_BuyButton_3->Update())  bBuyBtn[eTOP][2] = true;
//	if (m_BuyButton_4->Update())  bBuyBtn[eTOP][3] = true;
//}
//
//void cShopScene::UpdateAcc()
//{
//	if (m_BuyButton_1->Update())  bBuyBtn[eTOP][0] = true;
//	if (m_BuyButton_2->Update())  bBuyBtn[eTOP][1] = true;
//	if (m_BuyButton_3->Update())  bBuyBtn[eTOP][2] = true;
//	if (m_BuyButton_4->Update())  bBuyBtn[eTOP][3] = true;
//}
//
//void cShopScene::UpdateShoes()
//{
//	if (m_BuyButton_1->Update())  bBuyBtn[eTOP][0] = true;
//	if (m_BuyButton_2->Update())  bBuyBtn[eTOP][1] = true;
//	if (m_BuyButton_3->Update())  bBuyBtn[eTOP][2] = true;
//	if (m_BuyButton_4->Update())  bBuyBtn[eTOP][3] = true;
//}

void cShopScene::Render()
{

	IMAGE->Render(IMAGE->FindImage("ShopBg"), m_ShopBgPos, false);

	m_BuyButton_1->Render();
	m_BuyButton_2->Render();
	m_BuyButton_3->Render();
	m_BuyButton_4->Render();
	m_Exit->Render();
	IMAGE->PrintTexture("Money =" + to_string(Money), { 300 , 300 });
	m_Mouse->Render(MousePoint);
}

void cShopScene::Release()
{
	SAFE_DELETE(m_BuyButton_1);
	SAFE_DELETE(m_BuyButton_2);
	SAFE_DELETE(m_BuyButton_3);
	SAFE_DELETE(m_BuyButton_4);
	SAFE_DELETE(m_Exit);
	SAFE_DELETE(m_Mouse);
}
