#include "stdafx.h"
#include "cShopScene.h"
#include"cButton.h"

cShopScene::cShopScene()
{

}


cShopScene::~cShopScene()
{
	Release();
}

void cShopScene::Init()
{
	Money += 10000;
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

	if (m_BuyButton_1->Update()) {//드레스 1. 1000원
		if (Money < 1000 || isBuy1) {
			DEBUG_LOG("돈 부족");
		}
		else {
			Money -= 1000;
			isBuy1 = true;

			DEBUG_LOG("드레스1");
		}
	}
	if (m_BuyButton_2->Update()) {//드레스 2. 2000원
		if (Money < 1000|| isBuy2) {
			DEBUG_LOG("돈 부족");
		}
		else {
			Money -= 2000;
			isBuy2 = true;
			DEBUG_LOG("드레스2");
		}
	}
	if (m_BuyButton_3->Update()) {//드래스 3. 3000원

		if (Money < 1000 || isBuy3) {
			DEBUG_LOG("돈 부족");
		}
		else {
			Money -= 3000;
			isBuy3 = true;
			DEBUG_LOG("드레스3");

		}
	}
	if (m_BuyButton_4->Update()) {//드레스 4 4000원
		if (Money < 4000 || isBuy4) {
			DEBUG_LOG("돈 부족");
		}
		else {
			Money -= 4000;
			isBuy4 = true;
			DEBUG_LOG("드레스4");
		}
	}
	if (m_Exit->Update()) {
		SCENE->ChangeScene("InGame"); 
	}
}

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

	SAFE_DELETE(m_Mouse);
}
