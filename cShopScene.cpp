#include "stdafx.h"
#include "cShopScene.h"
bool bBuyList[4][4];
int nCntBuyPos[4][4]; //옷을 산 순서를 체크하는 변수
int nCnt[4] = { 0,0,0,0 };
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
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			m_BuyButton[j][i] = new cButton(50 + (150 * i), 500 + (j * 100), "Buy");
			m_BuyButton[j][i]->Init();
		}
	}
	m_Exit = new cButton(500, 200, "WndExit");
	m_Exit->Init();

}

void cShopScene::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;
	m_Mouse->Update(MousePoint);
	BuyDress();
	if (m_Exit->Update()) {
		SCENE->ChangeScene("InGame");
	}
}
void cShopScene::BuyDress()//옷 구
{
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (m_BuyButton[j][i]->Update())
				bBuyBtn[j][i] = true;
		}
	}
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			if (bBuyBtn[j][i] == true && bBuyList[j][i] == false) {
				if (Money >= 1000 * (i + 1)) {
					bBuyList[j][i] = true;
					Money -= 1000 * (i + 1);
					CntBuyList(j, i);
				}
				else {
					bBuyBtn[j][i] = false;
					DEBUG_LOG("구입 실패");
				}
			}
		}
	}

}
void cShopScene::CntBuyList(int i, int j)
{
	switch (i) {
	case eTOP: {
		nCntBuyPos[eTOP][j] = nCnt[eTOP];
		nCnt[eTOP]++;
		break;
	}
	case eBOTTOM: {
		nCntBuyPos[eBOTTOM][j] = nCnt[eBOTTOM];
		nCnt[eBOTTOM]++;
		break;
	}
	case eACCESSORY: {
		nCntBuyPos[eACCESSORY][j] = nCnt[eACCESSORY];
		nCnt[eACCESSORY]++;
		break;
	}
	case eSHOES: {
		nCntBuyPos[eSHOES][j] = nCnt[eSHOES];
		nCnt[eSHOES]++;
		break;
	}
	}
}


void cShopScene::Render()
{

	IMAGE->Render(IMAGE->FindImage("ShopBg"), m_ShopBgPos, false);
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			m_BuyButton[j][i]->Render();
		}
	}
	m_Exit->Render();
	IMAGE->PrintTexture("Money =" + to_string(Money), { 300 , 300 });
	m_Mouse->Render(MousePoint);
}

void cShopScene::Release()
{
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			SAFE_DELETE(m_BuyButton[j][i]);
		}
	}
	SAFE_DELETE(m_Exit);
	SAFE_DELETE(m_Mouse);
}
