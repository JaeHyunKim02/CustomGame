#include "stdafx.h"
#include "cCloset.h"
#include"cButton.h" 
#define DRESS_BTN_Y 730
#define DRESS_BTN_X 125
cCloset::cCloset(_ClosetKind ClosetKind)
	:m_ClosetKind(ClosetKind)
{
	chkBtn = eNULL;
	beforeBtn = eNULL;
	nCntTopPos = 0;
}

cCloset::~cCloset()
{

	SAFE_DELETE(m_next_btn);
	SAFE_DELETE(m_before_btn);
	Release();
}
void cCloset::Init()
{
	bNextBtn = false;
	switch (m_ClosetKind) {
	case eTOP:		Init_top();
	case eBOTTOM:	Init_bottom();
	case eACCESSORY:Init_accessory();
	case eSHOES:	Init_shoes();
	}
	m_next_btn = new cButton(601, 736, "Next");
	m_next_btn->Init();
	m_before_btn = new cButton(38, 735, "Before");
	m_before_btn->Init();
}
void cCloset::Render()
{
	switch (m_ClosetKind) {
	case eTOP: {
		if (!bNextBtn) {
			m_top_1_btn->Render();
			m_top_2_btn->Render();
			m_top_3_btn->Render();
			m_top_4_btn->Render();
		}
		else NextCloseRender();
		break;
	}
	case eBOTTOM: {
		if (!bNextBtn) {
			m_bottom_1_btn->Render();
			m_bottom_2_btn->Render();
			m_bottom_3_btn->Render();
			m_bottom_4_btn->Render();
		}
		else NextCloseRender();
		break;
	}
	case eACCESSORY: {
		if (!bNextBtn) {
			m_accessory_1_btn->Render();
			m_accessory_2_btn->Render();
			m_accessory_3_btn->Render();
			m_accessory_4_btn->Render();
		}
		else NextCloseRender();
		break;
	}
	case eSHOES: {
		if (!bNextBtn) {
			m_shoes_1_btn->Render();
			m_shoes_2_btn->Render();
			m_shoes_3_btn->Render();
			m_shoes_4_btn->Render();
		}
		else NextCloseRender();
		break;
	}
	}

	m_next_btn->Render();
	m_before_btn->Render();
}

void cCloset::Update()
{
	switch (m_ClosetKind) {
	case eTOP: {
		if (bNextBtn) NextClosetUpdate();
		else if (!bNextBtn) {	//before closet
			if (m_top_1_btn->Update())		_EDress[eTOP] = eTOP_1;
			else if (m_top_2_btn->Update()) _EDress[eTOP] = eTOP_2;
			else if (m_top_3_btn->Update()) _EDress[eTOP] = eTOP_3;
			else if (m_top_4_btn->Update()) _EDress[eTOP] = eTOP_4;
		}
		break;
	}
	case eBOTTOM: {
		if (bNextBtn) NextClosetUpdate();
		else if (!bNextBtn) {
			if (m_bottom_1_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_1;
			if (m_bottom_2_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_2;
			if (m_bottom_3_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_3;
			if (m_bottom_4_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_4;
		}
		break;
	}
	case eACCESSORY: {
		if (bNextBtn) NextClosetUpdate();
		else if (!bNextBtn) {
			if (m_accessory_1_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_1;
			if (m_accessory_2_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_2;
			if (m_accessory_3_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_3;
			if (m_accessory_4_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_4;
		}
		break;
	}
	case eSHOES: {
		if (bNextBtn) NextClosetUpdate();
		else if (!bNextBtn) {
			if (m_shoes_1_btn->Update()) _EDress[eSHOES] = eSHOES_1;
			if (m_shoes_2_btn->Update()) _EDress[eSHOES] = eSHOES_2;
			if (m_shoes_3_btn->Update()) _EDress[eSHOES] = eSHOES_3;
			if (m_shoes_4_btn->Update()) _EDress[eSHOES] = eSHOES_4;
		}
		break;
	}
	}
	if (m_next_btn->Update()) {
		switch (m_ClosetKind) {
		case eTOP:		Next_Init_top();		break;
		case eBOTTOM:	Next_Init_bottom();		break;
		case eACCESSORY:Next_Init_accessory();	break;
		case eSHOES:	Next_Init_shoes();		break;
		}
	}
	else if (m_before_btn->Update()) {
		switch (m_ClosetKind) {
		case eTOP:
			bNextBtn = false;
			Release(); Init_top();		break;
		case eBOTTOM:
			bNextBtn = false;
			Release(); Init_bottom();	break;
		case eACCESSORY:
			bNextBtn = false;
			Release(); Init_accessory();break;
		case eSHOES:
			bNextBtn = false;
			Release(); Init_shoes();	break;
		}
	}
}
void cCloset::NextClosetUpdate()
{
	if (bNextBtn) {
		switch (m_ClosetKind) {
		case eTOP: {
			if(m_next_top_1_btn->Update())
				_EDress[eTOP] = eTOP_5;
			if(m_next_top_2_btn->Update()) 
				_EDress[eTOP] = eTOP_6;
			if(m_next_top_3_btn->Update())
				_EDress[eTOP] = eTOP_7;
			break;
		}
		case eBOTTOM: {
			if (m_next_bottom_1_btn->Update())  _EDress[eBOTTOM] = eBOTTOM_5;
			if (m_next_bottom_2_btn->Update())  _EDress[eBOTTOM] = eBOTTOM_6;
			break;
		}
		case eACCESSORY: { 
			break;
		}
		case eSHOES: {
			if (m_next_shoes_1_btn->Update())  _EDress[eSHOES] = eSHOES_5;
			break;
		}
		}
	}
}
void cCloset::NextCloseRender() { //다음 옷장 랜더
	if (bNextBtn) {
		switch (m_ClosetKind) {
		case eTOP: {
			m_next_top_1_btn->Render();
			m_next_top_2_btn->Render();
			m_next_top_3_btn->Render();
			break;
		}
		case eBOTTOM: {
			m_next_bottom_1_btn->Render();
			break;
		}
		case eACCESSORY: {
			break;
		}
		case eSHOES: {
			m_next_shoes_1_btn->Render();
			break;
		}
		}
	}
}

void cCloset::Init_top()
{  
	m_top_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_top_1_btn->Init();
	m_top_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_1");
	m_top_2_btn->Init();
	m_top_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1"); \
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
	m_bottom_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Top_1");
	m_bottom_4_btn->Init();
}
void cCloset::Init_accessory()
{
	m_accessory_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_accessory_1_btn->Init();
	m_accessory_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_1");
	m_accessory_2_btn->Init();
	m_accessory_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1");
	m_accessory_3_btn->Init();
	m_accessory_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Top_1");
	m_accessory_4_btn->Init();
}
void cCloset::Init_shoes()
{
	m_shoes_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_shoes_1_btn->Init();
	m_shoes_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_1");
	m_shoes_2_btn->Init();
	m_shoes_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_1");
	m_shoes_3_btn->Init();
	m_shoes_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Top_1");
	m_shoes_4_btn->Init();
}

void cCloset::Next_Init_top()
{
	bNextBtn = true;
	Release();
	m_next_top_1_btn = new cButton(DRESS_BTN_X +135 * nCntTopPos, DRESS_BTN_Y, "Top_1");
	m_next_top_1_btn->Init(false);
	m_next_top_2_btn = new cButton(DRESS_BTN_X + 135* nCntTopPos, DRESS_BTN_Y, "Top_1");
	m_next_top_2_btn->Init(false);
	m_next_top_3_btn = new cButton(DRESS_BTN_X + 135 * nCntTopPos, DRESS_BTN_Y, "Top_1");
	m_next_top_3_btn->Init(false);
}
void cCloset::Next_Init_bottom()
{
	bNextBtn = true;
	Release();
	m_next_bottom_1_btn = new cButton(DRESS_BTN_X+135*nCntBotPos, DRESS_BTN_Y, "Top_1");
	m_next_bottom_1_btn->Init(false);
	m_next_bottom_2_btn = new cButton(DRESS_BTN_X+ 135+nCntBotPos, DRESS_BTN_Y, "Top_1");
	m_next_bottom_2_btn->Init(false);
}
void cCloset::Next_Init_accessory()
{
	bNextBtn = true;
	Release(); 
}
void cCloset::Next_Init_shoes()
{
	bNextBtn = true;
	Release();
	m_next_shoes_1_btn = new cButton(DRESS_BTN_X+135*nCntShoesPos, DRESS_BTN_Y, "Top_1");
	m_next_shoes_1_btn->Init(false);
}
void cCloset::Release()
{
	SAFE_DELETE(m_top_1_btn);
	SAFE_DELETE(m_top_2_btn);
	SAFE_DELETE(m_top_3_btn);
	SAFE_DELETE(m_top_4_btn);
	SAFE_DELETE(m_TopNext_btn);

	SAFE_DELETE(m_bottom_1_btn);
	SAFE_DELETE(m_bottom_2_btn);
	SAFE_DELETE(m_bottom_3_btn);
	SAFE_DELETE(m_bottom_4_btn);

	SAFE_DELETE(m_accessory_1_btn);
	SAFE_DELETE(m_accessory_2_btn);
	SAFE_DELETE(m_accessory_3_btn);
	SAFE_DELETE(m_accessory_4_btn);

	SAFE_DELETE(m_shoes_1_btn);
	SAFE_DELETE(m_shoes_2_btn);
	SAFE_DELETE(m_shoes_3_btn);
	SAFE_DELETE(m_shoes_4_btn);

	SAFE_DELETE(m_next_top_1_btn);
	SAFE_DELETE(m_next_top_2_btn);
	SAFE_DELETE(m_next_top_3_btn);

	SAFE_DELETE(m_next_bottom_1_btn);
	SAFE_DELETE(m_next_bottom_2_btn);

	//SAFE_DELETE(m_next_accessory_1_btn);
	SAFE_DELETE(m_next_shoes_1_btn);
	// 
}