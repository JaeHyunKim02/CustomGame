#include "stdafx.h"
#include "cMainScene.h"
#include "cCloset.h"
#include "cButton.h"  
#define DRESS_BTN_Y 888
cMainScene::cMainScene()
{
}

cMainScene::~cMainScene()
{
} 

void cMainScene::Init()
{
	isChangTime = false;
	m_Mouse = new cMouseCursor();
	m_Mouse->Init();

	for (int i = eTOP; i < eSHOES + 1; i++) m_EDress[i] = eNULL;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;

	m_ClosetPos.x = 320;
	m_ClosetPos.y = 450;

	m_Top_Closet       =new cCloset(eTOP);
	m_Bottom_Closet    =new cCloset(eBOTTOM);
	m_Accessory_Closet =new cCloset(eACCESSORY);
	m_Shoes_Closet     =new cCloset(eSHOES);
	m_Top_Closet->Init();
	m_Bottom_Closet->Init();
	m_Accessory_Closet->Init();
	m_Shoes_Closet->Init();

	m_Closet_Top_btn = new cButton(81, DRESS_BTN_Y, "Closet_Top");
	m_Closet_Top_btn->Init();
	m_Closet_Bottom_btn = new cButton(218, DRESS_BTN_Y, "Closet_Bottom");
	m_Closet_Bottom_btn->Init();
	m_Closet_Accessory_btn = new cButton(536, DRESS_BTN_Y, "Closet_Accessory");
	m_Closet_Accessory_btn->Init();
	m_Closet_Shoes_btn = new cButton(370, DRESS_BTN_Y, "Closet_Shoes");
	m_Closet_Shoes_btn->Init(); 

	m_Complete_btn = new cButton(540, 100, "Clear");
	m_Complete_btn->Init();

	m_EDress_State = eTOP;

	top_key		  = "Null";
	bottom_key	  = "Null";
	accessory_key = "Null";
	shoes_key	  = "Null";
}

void cMainScene::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;

	m_Mouse->Update(MousePoint);

	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//클릭 효과음
	}
	if (m_Closet_Top_btn->Update())		 m_EDress_State = eTOP;
	if (m_Closet_Bottom_btn->Update())	 m_EDress_State = eBOTTOM;
	if (m_Closet_Accessory_btn->Update())m_EDress_State = eACCESSORY;
	if (m_Closet_Shoes_btn->Update())	 m_EDress_State = eSHOES;
	if (m_Complete_btn->Update()) {
		isOrder = true;
		
		SCENE->ChangeScene("InGame");
	}
	switch (m_EDress_State) {
	case eBOTTOM: {
		m_Bottom_Closet->Update();
		m_EDress[eBOTTOM] = m_Bottom_Closet->getBottom(); //누른 옷의 정보를 가져옴
		switch (m_EDress[eBOTTOM]) {
		case eBOTTOM_1: bottom_key = "Bottom_1";break;
		case eBOTTOM_2: bottom_key = "Bottom_2"; break;
		case eBOTTOM_3: bottom_key = "Bottom_3"; break;
		case eBOTTOM_4: bottom_key = "Bottom_4"; break;
		case eBOTTOM_5: bottom_key = "Bottom_5"; break;
		case eBOTTOM_6: bottom_key = "Bottom_6"; break;
		default:		bottom_key = "Null";     break;
		}
		break;
	}
	case eTOP: {
		m_Top_Closet->Update();
		m_EDress[eTOP] = m_Top_Closet->getTop();
		switch (m_EDress[eTOP]) {
		case eTOP_1: top_key = "Top_1"; break;
		case eTOP_2: top_key = "Top_2"; break;
		case eTOP_3: top_key = "Top_3"; break;
		case eTOP_4: top_key = "Top_4"; break;
		case eTOP_5: top_key = "Top_5"; break;
		case eTOP_6: top_key = "Top_6"; break;
		case eTOP_7: top_key = "Top_7"; break;
		default:	 top_key = "Null";  break;
		}
		break;
	}
	case eACCESSORY: {
		m_Accessory_Closet->Update();
		m_EDress[eACCESSORY] = m_Accessory_Closet->getAccessory();
		switch (m_EDress[eACCESSORY]) {
		case eACCESSORY_1: accessory_key = "Accessory_1"; break;
		case eACCESSORY_2: accessory_key = "Accessory_2"; break;
		case eACCESSORY_3: accessory_key = "Accessory_3"; break;
		case eACCESSORY_4: accessory_key = "Accessory_4"; break;
		default:		   accessory_key = "Null";		  break;
		}
		break;
	}
	case eSHOES: {
		m_Shoes_Closet->Update();
		m_EDress[eSHOES] = m_Shoes_Closet->getShoes();
		switch (m_EDress[eSHOES]) {
		case eSHOES_1: shoes_key = "Shoes_1"; break;
		case eSHOES_2: shoes_key = "Shoes_2"; break;
		case eSHOES_3: shoes_key = "Shoes_3"; break;
		case eSHOES_4: shoes_key = "Shoes_4"; break;
		case eSHOES_5: shoes_key = "Shoes_5"; break;
		default:	   shoes_key = "Null";    break;
		}
		break;
	}
	}
}

void cMainScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("MainGameBg"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("Mannequin"), m_ClosetPos, true, RGB(255, 0, 255));
	m_Closet_Top_btn->Render();
	m_Closet_Bottom_btn->Render();
	m_Closet_Accessory_btn->Render();
	m_Closet_Shoes_btn->Render();

	m_Complete_btn->Render();
	switch (m_EDress_State) {
	case eTOP:		m_Top_Closet->Render();			break;
	case eBOTTOM:	m_Bottom_Closet->Render();		break;
	case eACCESSORY:m_Accessory_Closet->Render();	break;
	case eSHOES:	m_Shoes_Closet->Render();		break;
	} 
	if (bottom_key	  != "Null")IMAGE->Render(IMAGE->FindImage(bottom_key),		m_ClosetPos, true, RGB(255, 0, 255));
	if (top_key		  != "Null")IMAGE->Render(IMAGE->FindImage(top_key),		m_ClosetPos, true, RGB(255, 0, 255));
	if (accessory_key != "Null")IMAGE->Render(IMAGE->FindImage(accessory_key),	m_ClosetPos, true, RGB(255, 0, 255));
	if (shoes_key     != "Null")IMAGE->Render(IMAGE->FindImage(shoes_key),		m_ClosetPos, true, RGB(255, 0, 255));
	m_Mouse->Render(MousePoint);
}

void cMainScene::Release()
{
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_Top_Closet);
	SAFE_DELETE(m_Bottom_Closet);
	SAFE_DELETE(m_Accessory_Closet);
	SAFE_DELETE(m_Shoes_Closet	);
	SAFE_DELETE(m_Closet_Top_btn);
	SAFE_DELETE(m_Closet_Bottom_btn);
	SAFE_DELETE(m_Closet_Accessory_btn);
	SAFE_DELETE(m_Closet_Shoes_btn);
	 
	SAFE_DELETE(m_Complete_btn);
}
//int concept = 0;
//int cMainScene::getScore()
//{
//	int nScore = 5;
//	int nWrongCnt = 0;
//	for (int i = eTOP; i < eSHOES + 1; i++) if (m_EDress[i] != concept) nWrongCnt++;
//	switch (nWrongCnt) {
//	case 1: nScore -= 1; break;
//	case 2: nScore -= 2; break;
//	case 3: nScore -= 3; break;
//	case 4: nScore -= 4; break;
//	}
//	return nScore;
//}
