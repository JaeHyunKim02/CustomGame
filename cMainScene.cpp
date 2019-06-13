#include "stdafx.h"
#include "cMainScene.h"
#include"cButton.h"
#include"cCloset.h"
#include<iostream>
cMainScene::cMainScene()
{
}

cMainScene::~cMainScene()
{
	Release();
}

void cMainScene::Init()
{
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	for (int i = 0; i < 4; i++) {
		eDress[i] = eNULL;
	}
	m_eDressKind = eTOP;
	m_Top_btn = new cButton(80,728,"Top_btn");
	m_Top_btn->Init();
	m_Bottom_btn = new cButton(208,728,"Top_btn");
	m_Bottom_btn->Init();
	m_Accessory_btn = new cButton(336,728,"Top_btn");
	m_Accessory_btn->Init();
	m_Shoes_btn = new cButton(464,728,"Top_btn");
	m_Shoes_btn->Init();

	m_Top_closet = new cCloset("Closet_Top");
	m_Bottom_closet = new cCloset("Closet_Bottom");
	m_Accessory_closet = new cCloset("Closet_Accessroy");
	m_Shoes_closet = new cCloset("Closet_Shoes");
}
 
void cMainScene::Update()
{	  
	if (m_Top_btn->Update()) {
		m_Top_closet->Update();
		m_eDressKind = eTOP;
	}
	else if (m_Bottom_btn->Update()) {
		m_Bottom_closet->Update();
		m_eDressKind = eBOTTOM;
	}
	else if (m_Accessory_btn->Update()) {
		m_Accessory_closet->Update();
		m_eDressKind = eACCESSORY;
	}
	else if (m_Shoes_btn->Update()) {
		m_Shoes_closet->Update();
		m_eDressKind = eSHOES;
	}
}

void cMainScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("MainGameBg"), m_BackGroundPos, false);
	
	m_Top_btn->Render();
	m_Bottom_btn->Render();
	m_Accessory_btn->Render();
	m_Shoes_btn->Render();
	switch (m_eDressKind)
	{
	case eTOP: {
		m_Top_closet->Render();		 
		break;			 
	}					 
	case eBOTTOM: {
		m_Bottom_closet->Render();		 
		break;			 
	}					 
	case eACCESSORY: {
		m_Accessory_closet->Render();	 
		break;			 
	}					 
	case eSHOES: {
		m_Shoes_closet->Render();		 
		break;
	}
	}
}

void cMainScene::Release()
{
	SAFE_DELETE(m_Top_btn);
	SAFE_DELETE(m_Bottom_btn);
	SAFE_DELETE(m_Accessory_btn);
	SAFE_DELETE(m_Shoes_btn);

	SAFE_DELETE(m_Top_closet);
	SAFE_DELETE(m_Bottom_closet);
	SAFE_DELETE(m_Accessory_closet);
	SAFE_DELETE(m_Shoes_closet);
}
