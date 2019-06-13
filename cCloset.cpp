#include "stdafx.h"
#include "cCloset.h"
#include"cButton.h" 

cCloset::cCloset(const string& key)
{
	m_Closet = IMAGE->FindImage(key);
	if (key == "Closet_Top")			m_DressKind = eTOP;
	else if (key == "Closet_Bottom")	m_DressKind = eBOTTOM;
	else if (key == "Closet_Accessory") m_DressKind = eACCESSORY;
	else if (key == "Closet_Shoes")		m_DressKind = eSHOES;
	m_closet_pos.x = 0;
	m_closet_pos.y = 0;
}

cCloset::~cCloset()
{
}

void cCloset::Init()
{
	switch (m_DressKind) {
	case eTOP:		Init_top();			break;
	case eBOTTOM:	Init_bottom();		break;
	case eACCESSORY:Init_accessory();	break;
	case eSHOES:	Init_shoes();		break;
	}
}

void cCloset::Render()
{
	static bool first=true;
	IMAGE->Render(m_Closet, m_closet_pos, false, RGB(255, 0, 255));
	switch (m_DressKind) {
	case eTOP: {
		m_top_1_btn->Render();
		break;
	}
	case eBOTTOM: {

		break;
	}
	case eACCESSORY: {

		break;
	}
	case eSHOES: {

		break;
	}
	}
}

void cCloset::Update()
{
	switch (m_DressKind) {
	case eTOP: {

		break;
	}
	case eBOTTOM: {

		break;
	}
	case eACCESSORY: {

		break;
	}
	case eSHOES: {

		break;
	}
	}
}

void cCloset::Release()
{
}

void cCloset::Init_top()
{
	m_top_1_btn = new cButton(100, 780, "Top_1");
	m_top_1_btn->Init();
}

void cCloset::Init_bottom()
{
	m_bottom_1_btn = new cButton(100, 780, "Top_1");
	m_bottom_1_btn->Init();
}

void cCloset::Init_accessory()
{
	m_accessory_1_btn = new cButton(100, 780, "Top_1");
	m_accessory_1_btn->Init();
}

void cCloset::Init_shoes()
{
	m_shoes_1_btn = new cButton(100, 780, "Top_1");
	m_shoes_1_btn->Init();
}
