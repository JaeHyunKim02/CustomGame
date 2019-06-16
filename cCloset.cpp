#include "stdafx.h"
#include "cCloset.h"
#include"cButton.h" 
#define DRESS_BTN_Y 730
#define DRESS_BTN_X 125
cCloset::cCloset(const string& key)
{
	if (key == "Closet_1")		m_DressKind = eTOP;
	else if (key == "Closet_2")	m_DressKind = eBOTTOM;
	else if (key == "Closet_3")	m_DressKind = eACCESSORY;
	else if (key == "Closet_4")	m_DressKind = eSHOES;
	m_closet_pos.x = 0;
	m_closet_pos.y = 0;
	for (int i = eTOP; i < eSHOES + 1; i++) {
		_EDress[i] = eNULL;
	}
}

cCloset::~cCloset()
{
	Release();
}
void cCloset::Init()
{
	switch (m_DressKind) {
	case eTOP:		Init_top();
	case eBOTTOM:	Init_bottom();
	case eACCESSORY:Init_accessory();
	case eSHOES:	Init_shoes();
	}
}
void cCloset::Render()
{
	switch (m_DressKind) {
	case eTOP: {
		m_top_1_btn->Render();
		m_top_2_btn->Render();
		m_top_3_btn->Render();
		m_top_4_btn->Render();
		break;
	}
	case eBOTTOM: {
		m_bottom_1_btn->Render();
		m_bottom_2_btn->Render();
		m_bottom_3_btn->Render();
		break;
	}
	case eACCESSORY: {
		m_accessory_1_btn->Render();
		m_accessory_2_btn->Render();
		m_accessory_3_btn->Render();
		break;
	}
	case eSHOES: {
		m_shoes_1_btn->Render();
		m_shoes_2_btn->Render();
		m_shoes_3_btn->Render();
		m_shoes_4_btn->Render();
		break;
	}
	}
}
void cCloset::Update()
{
	if (m_DressKind == eTOP) {
		if (m_top_1_btn->Update())		  _EDress[eTOP] = eTOP_1;
		if (m_top_2_btn->Update())		  _EDress[eTOP] = eTOP_2;
		if (m_top_3_btn->Update())		  _EDress[eTOP] = eTOP_3;
		if (m_top_4_btn->Update())		  _EDress[eTOP] = eTOP_4;
	}
	if (m_DressKind == eBOTTOM) {
		if (m_bottom_1_btn->Update() && m_DressKind == eBOTTOM)	  _EDress[eBOTTOM] = eBOTTOM_1;
		if (m_bottom_2_btn->Update() && m_DressKind == eBOTTOM)	  _EDress[eBOTTOM] = eBOTTOM_2;
		if (m_bottom_3_btn->Update() && m_DressKind == eBOTTOM)	  _EDress[eBOTTOM] = eBOTTOM_3;
	}
	if (m_DressKind == eACCESSORY) {
		if (m_accessory_1_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_1;
		if (m_accessory_2_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_2;
		if (m_accessory_3_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_3;
	}
	if (m_DressKind == eSHOES) {
		if (m_shoes_1_btn->Update())     _EDress[eSHOES] = eSHOES_1;
		if (m_shoes_2_btn->Update())     _EDress[eSHOES] = eSHOES_2;
		if (m_shoes_3_btn->Update())     _EDress[eSHOES] = eSHOES_3;
		if (m_shoes_4_btn->Update())     _EDress[eSHOES] = eSHOES_4;
	}
}

void cCloset::Release()
{
	SAFE_DELETE(m_top_1_btn);
	SAFE_DELETE(m_top_2_btn);
	SAFE_DELETE(m_top_3_btn);
	SAFE_DELETE(m_top_4_btn);

	SAFE_DELETE(m_bottom_1_btn);
	SAFE_DELETE(m_bottom_2_btn);
	SAFE_DELETE(m_bottom_3_btn);

	SAFE_DELETE(m_accessory_1_btn);
	SAFE_DELETE(m_accessory_2_btn);
	SAFE_DELETE(m_accessory_3_btn);

	SAFE_DELETE(m_shoes_1_btn);
	SAFE_DELETE(m_shoes_2_btn);
	SAFE_DELETE(m_shoes_3_btn);
	SAFE_DELETE(m_shoes_4_btn);
}

void cCloset::Init_top()
{
	m_top_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_top_1_btn->Init();
	m_top_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_1");
	m_top_2_btn->Init();
	m_top_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1");
	m_top_3_btn->Init();
	m_top_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Top_1");
	m_top_4_btn->Init();
}

void cCloset::Init_bottom()
{
	m_bottom_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_bottom_1_btn->Init();
	m_bottom_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_1");
	m_bottom_2_btn->Init();
	m_bottom_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1");
	m_bottom_3_btn->Init();
}
void cCloset::Init_accessory()
{
	m_accessory_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_accessory_1_btn->Init();
	m_accessory_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_1");
	m_accessory_2_btn->Init();
	m_accessory_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1");
	m_accessory_3_btn->Init();
}

void cCloset::Init_shoes()
{
	m_shoes_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_shoes_1_btn->Init();
	m_shoes_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_1");
	m_shoes_2_btn->Init();
	m_shoes_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1");
	m_shoes_3_btn->Init();
	m_shoes_4_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1");
	m_shoes_4_btn->Init();
}
