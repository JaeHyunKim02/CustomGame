#include "stdafx.h"
#include "cCloset.h"
#include"cButton.h" 

cCloset::cCloset(const string& key)
{
	m_Closet = IMAGE->FindImage(key);
	if (key == "Closet_1")		m_DressKind = eTOP;
	else if (key == "Closet_2")	m_DressKind = eBOTTOM;
	else if (key == "Closet_3")	m_DressKind = eACCESSORY;
	else if (key == "Closet_4")	m_DressKind = eSHOES;
	m_closet_pos.x = 0;
	m_closet_pos.y = 0;
	for (int i = eTOP; i < eSHOES+1; i++) {
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
	IMAGE->Render(m_Closet, m_closet_pos, false, RGB(255, 0, 255));
	switch (m_DressKind) {
	case eTOP: {
		m_top_1_btn->Render();
		break;
	}
	case eBOTTOM: {
		m_bottom_1_btn->Render();
		break;
	}
	case eACCESSORY: {
		m_accessory_1_btn->Render();
		break;
	}
	case eSHOES: {
		m_shoes_1_btn->Render();
		break;
	}
	}
}
void cCloset::Update()
{
	switch (m_DressKind) {
	case eTOP:		 if (m_top_1_btn->Update())		  _EDress[eTOP] = eTOP_1;			  break;
	case eBOTTOM:    if(m_bottom_1_btn->Update())	  _EDress[eBOTTOM] = eBOTTOM_1;		  break;
	case eACCESSORY: if (m_accessory_1_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_1; break;
	case eSHOES: 	 if (m_shoes_1_btn->Update())     _EDress[eSHOES] = eSHOES_1;		  break;
	}
}

void cCloset::Release()
{
	SAFE_DELETE(m_top_1_btn);
	SAFE_DELETE(m_bottom_1_btn);
	SAFE_DELETE(m_accessory_1_btn);
	SAFE_DELETE(m_shoes_1_btn);
}

void cCloset::Init_top()
{
	m_top_1_btn = new cButton(100, 810, "Top_1");
	m_top_1_btn->Init();
}

void cCloset::Init_bottom()
{
	m_bottom_1_btn = new cButton(100, 810, "Top_1");
	m_bottom_1_btn->Init();
}

void cCloset::Init_accessory()
{
	m_accessory_1_btn = new cButton(100, 810, "Top_1");
	m_accessory_1_btn->Init();
}

void cCloset::Init_shoes()
{
	m_shoes_1_btn = new cButton(100, 810, "Top_1");
	m_shoes_1_btn->Init();
} 
