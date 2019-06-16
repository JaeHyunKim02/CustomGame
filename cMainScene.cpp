#include "stdafx.h"
#include "cMainScene.h"
#include "cCloset.h"
#include "cButton.h"  
cMainScene::cMainScene()
{
}

cMainScene::~cMainScene()
{
}

void cMainScene::Init()
{
	for (int i = eTOP; i < eSHOES + 1; i++) m_EDress[i] = eNULL;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	m_Top_Closet = new cCloset("Closet_1");
	m_Bottom_Closet = new cCloset("Closet_2");
	m_Accessory_Closet = new cCloset("Closet_3");
	m_Shoes_Closet = new cCloset("Closet_4");
	m_Top_Closet->Init();
	m_Bottom_Closet->Init();
	m_Accessory_Closet->Init();
	m_Shoes_Closet->Init();

	m_Closet_Top_btn = new cButton(76,729,"Closet_Top");
	m_Closet_Top_btn->Init();
	m_Closet_Bottom_btn= new cButton(176, 729, "Closet_Bottom");
	m_Closet_Bottom_btn->Init();
	m_Closet_Accessory_btn = new cButton(276, 729, "Closet_Accessory");
	m_Closet_Accessory_btn->Init();
	m_Closet_Shoes_btn = new cButton(376, 729, "Closet_Shoes");
	m_Closet_Shoes_btn->Init();
	m_EDress_State = eTOP;

	m_Complete_btn = new cButton(540, 100, "WndExit");
	m_Complete_btn->Init();
}

void cMainScene::Update()
{
	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//클릭 효과음
	}
	if (m_Closet_Top_btn->Update()) {
		m_EDress_State = eTOP;
	}
	if (m_Closet_Bottom_btn->Update()) {
		m_EDress_State = eBOTTOM;
	}
	if (m_Closet_Accessory_btn->Update()) {
		m_EDress_State = eACCESSORY;
	}
	if (m_Closet_Shoes_btn->Update()) {
		m_EDress_State = eSHOES;
	}
	if (m_Complete_btn->Update()) {
		isOrder = true;
		nConcept = rand() % 4;
		SCENE->ChangeScene("InGame");
	}

	switch (m_EDress_State) {
	case eTOP: {
		m_Top_Closet->Update();
		m_EDress[eTOP] = m_Top_Closet->getTop();
		break;
	}
	case eBOTTOM: {
		m_Bottom_Closet->Update();
		m_EDress[eBOTTOM] = m_Bottom_Closet->getBottom();
		break;
	}
	case eACCESSORY: {
		m_Accessory_Closet->Update();
		m_EDress[eACCESSORY] = m_Accessory_Closet->getAccessory();
		break;
	}
	case eSHOES: {
		m_Shoes_Closet->Update();
		m_EDress[eSHOES] = m_Shoes_Closet->getShoes();
		break;
	}
	}
}

void cMainScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("MainGameBg"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("Mannequin"), m_BackGroundPos, false, RGB(255, 0, 255));
	m_Closet_Top_btn->Render();
	m_Closet_Bottom_btn->Render();
	m_Closet_Accessory_btn->Render();
	m_Closet_Shoes_btn->Render();

	m_Complete_btn->Render();
	switch (m_EDress_State) {
	case eTOP: {
		m_Top_Closet->Render();
		break;
	}
	case eBOTTOM: {
		m_Bottom_Closet->Render();
		break;
	}
	case eACCESSORY: {
		m_Accessory_Closet->Render();
		break;
	}
	case eSHOES: {
		m_Shoes_Closet->Render();
		break;
	}
	}
	switch (m_EDress[eTOP]) {
	case eTOP_1: IMAGE->Render(IMAGE->FindImage("Top_1"), m_BackGroundPos, false, RGB(255, 0, 255)); break;
	}
	switch (m_EDress[eBOTTOM]) {
	case eBOTTOM_1: IMAGE->Render(IMAGE->FindImage("Bottom_1"), m_BackGroundPos, false, RGB(255, 0, 255)); break;
	}
	switch (m_EDress[eACCESSORY]) {
	case eACCESSORY_1: IMAGE->Render(IMAGE->FindImage("Accessory_1"), m_BackGroundPos, false, RGB(255, 0, 255)); break;
	}
	switch (m_EDress[eSHOES]) {
	case eSHOES_1: IMAGE->Render(IMAGE->FindImage("Shoes_1"), m_BackGroundPos, false, RGB(255, 0, 255)); break;
	}
}

void cMainScene::Release()
{
	SAFE_DELETE(m_Top_Closet);
	SAFE_DELETE(m_Bottom_Closet);
	SAFE_DELETE(m_Accessory_Closet);
	SAFE_DELETE(m_Shoes_Closet);

	SAFE_DELETE(m_Closet_Top_btn);
	SAFE_DELETE(m_Closet_Bottom_btn);
	SAFE_DELETE(m_Closet_Accessory_btn);
	SAFE_DELETE(m_Closet_Shoes_btn);

	SAFE_DELETE(m_Complete_btn);
}
int concept = 0;
int cMainScene::getScore()
{
	int nScore=5;
	int nWrongCnt=0;
	for (int i = eTOP; i < eSHOES + 1; i++) if (m_EDress[i] != concept) nWrongCnt++;
	switch (nWrongCnt) {
	case 1: nScore -= 1; break;
	case 2: nScore -= 2; break;
	case 3: nScore -= 3; break;
	case 4: nScore -= 4; break;
	}
	return nScore;
}
