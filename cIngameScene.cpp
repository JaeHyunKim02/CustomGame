#include "stdafx.h"
#include "cIngameScene.h"
#include "cButton.h"
#include"cOptionWnd.h"
#include"cMakingWnd.h"
#include <stdlib.h>

//bool first = true;

cIngameScene::cIngameScene()
{
}


cIngameScene::~cIngameScene()
{
	Release();
}

void cIngameScene::Init()
{
	kindC = "M_1";
	bClickOrder = false;
	isChangTime = true;
	m_ChangePos.x = 320;
	m_ChangePos.y = 450;

	//450+320
	m_Mouse = new cMouseCursor();
	m_Mouse->Init();


	srand((unsigned)time(NULL));
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	Pos.x = 473;
	Pos.y = 106;

	CommentPos.x = 23;
	CommentPos.y = 740;
	CommentPos2.x = 23;
	CommentPos2.y = 850;

	ShowPageButtonPos.x = 280;
	ShowPageButtonPos.y = 700;


	WndState = EMPTY_WND;
	//m_Exit_Button = new cButton(100, 500, "Exit");
	//m_Exit_Button->Init();
	m_Notice_button = new cButton(140, 130, "Notice");
	m_Notice_button->Init();

	m_goshop = new cButton(50, 130, "GoShop");
	m_goshop->Init();

<<<<<<< HEAD
=======
	m_NoticeWnd = new cMakingWnd(320, 480, "Order_List");
	m_NoticeWnd->Init();
	m_OptionWnd = new cOptionWnd(320, 480, "option_window");
	m_OptionWnd->Init();
>>>>>>> 7122d28a4584dbe7e1610660024869274bfdb92e
	m_Option_button = new cButton(520, 40, "Option");
	m_Option_button->Init();

	m_HowToPlay_button = new cButton(450, 40, "HowToPlay");
	m_HowToPlay_button->Init();

	m_GameExitButton = new cButton(590, 40, "Exit");
	m_GameExitButton->Init();

	m_Page_Button1 = new cButton(280, 700, "PageUp");
	m_Page_Button1->Init();

	m_Page_Button2 = new cButton(320, 700, "PageUp");//40씩 차이남
	m_Page_Button2->Init();

	m_Page_Button3 = new cButton(360, 700, "PageUp");
	m_Page_Button3->Init();

<<<<<<< HEAD
	m_OrderList = new cButton(0, 0, "OrderList");
	m_OrderList->Init();
	m_Wnd_Exit_btn = new cButton(400, 200, "Exit");
	m_Wnd_Exit_btn->Init();
=======
>>>>>>> 7122d28a4584dbe7e1610660024869274bfdb92e

}

void cIngameScene::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;
	m_Mouse->Update(MousePoint);
	//isOrder;
	//chkOrder;
	char a[128];
	if(m_Page_Button1->Update()){
		count = 1;
		ShowPageButtonPos.x = 280;
		sprintf_s(a, "M_%d", count);
		kindC = a;
	}
	if (m_Page_Button2->Update()) {
		count = 2;
		ShowPageButtonPos.x = 320;
		sprintf_s(a, "M_%d", count);
		kindC = a;
	}
	if (m_Page_Button3->Update()) {
		count = 3;
		ShowPageButtonPos.x = 360;
		sprintf_s(a, "M_%d", count);
		kindC = a;
	}

		if (CKchangTime) {//배경에서 이미지 바뀌는 코드 넣어야 함
			CKchangTime = false;
			DEBUG_LOG("들어옴");
			count += 1;
			if (count > 3)
				count = 1;
			//char a[128];
			sprintf_s(a, "M_%d", count);
			//kindC = "M_" + count;
			kindC = a;
			ShowPageButtonPos.x += 40;
			if (ShowPageButtonPos.x > 360) ShowPageButtonPos.x = 280;
			//SCENE->ChangeScene("InGame");
		}

	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//클릭 효과음
	} 
	if (bClickOrder&&m_Wnd_Exit_btn->Update()) {
		bClickOrder = false;
	}
<<<<<<< HEAD
	else if (bClickOrder&&m_OrderList->_Update()) {
	}
	else if (m_Notice_button->Update()) bClickOrder = true;
	else if (m_Option_button->Update()) {//옵션 버튼을 클릭  
=======
	if (m_Notice_button->Update()) {//알림 버튼 클릭한 경우 
		WndState = MAKING_WND;

	}

	else if (m_Option_button->Update()) {//옵션 버튼을 클릭  
		WndState = OPTION_WND;
		//SCENE->ChangeScene("Comment");
	}
	//else if (m_HowToPlay_button->Update()) {
	//	
	//}

	else if (WndState != EMPTY_WND) {//윈도우가 비어있지 않다면
		switch (WndState) {
		case MAKING_WND: m_NoticeWnd->Update("InGame"); break; //
		case OPTION_WND: m_OptionWnd->Update("InGame"); break;
		}
	}
	if (m_goshop->Update()) {
		SCENE->ChangeScene("Shop");
>>>>>>> 7122d28a4584dbe7e1610660024869274bfdb92e
	}
	else if (m_goshop->Update()) SCENE->ChangeScene("Shop");
	else if (m_GameExitButton->Update()) PostQuitMessage(0);
}
void cIngameScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("InGameBG"), m_BackGroundPos, false);
	//IMAGE->Render(IMAGE->FindImage(a), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage(kindC), m_ChangePos, true);
	IMAGE->Render(IMAGE->FindImage("MyMoney"), Pos, false, RGB(255, 0, 255));
	
	IMAGE->Render(IMAGE->FindImage("CommentWnd"), CommentPos, false, RGB(255, 0, 255));
	IMAGE->Render(IMAGE->FindImage("CommentWnd"), CommentPos2, false, RGB(255, 0, 255));
	m_Page_Button1->Render();
	m_Page_Button2->Render();
	m_Page_Button3->Render();
	IMAGE->Render(IMAGE->FindImage("PageDown"), ShowPageButtonPos, true, RGB(255, 0, 255));
	//IMAGE->Render(IMAGE->FindImage("money_icon"), m_MoneyIconPos, false);

	//240남았음
	//198
	if (!isOrder)m_Notice_button->Render();
	//m_Option_button->Render();	//옵션버튼 그림
<<<<<<< HEAD
	m_goshop->Render();//상점가는 버튼 
	m_GameExitButton->Render();
	m_HowToPlay_button->Render();
	m_Option_button->Render();
	m_Page_Button1->Render();
	m_Page_Button2->Render();
	m_Page_Button3->Render();
	if (bClickOrder) m_OrderList->_Render();
	if (bClickOrder) m_Wnd_Exit_btn->Render();
	IMAGE->PrintTexture("" + to_string(Money), { Pos.x - 50 , Pos.y + 15 });
	IMAGE->Render(IMAGE->FindImage("PageDown"), ShowPageButtonPos, true, RGB(255, 0, 255));
	m_Mouse->Render(MousePoint);
=======
	m_goshop->Render();//상점가는 버튼
	m_GameExitButton->Render();
	m_HowToPlay_button->Render();
	m_Option_button->Render();
	if (WndState != EMPTY_WND) {
		switch (WndState) {
		case MAKING_WND: m_NoticeWnd->Render(); break;
		case OPTION_WND: m_OptionWnd->Render(); break;
		}
	}
>>>>>>> 7122d28a4584dbe7e1610660024869274bfdb92e



	IMAGE->PrintTexture("" + to_string(Money), { Pos.x-50 , Pos.y+15 });
	
	m_Mouse->Render(MousePoint);
	
	//Pos.x = 473;
	//Pos.y = 106;
}

void cIngameScene::Release()
{
	//SAFE_DELETE(m_PlayerFrame);
	SAFE_DELETE(m_Mouse);
	//SAFE_DELETE(m_Exit_Button);

	SAFE_DELETE(m_goshop);
	SAFE_DELETE(m_Option_button);
	SAFE_DELETE(m_Notice_button);
	SAFE_DELETE(m_HowToPlay_button);
	SAFE_DELETE(m_GameExitButton);
	SAFE_DELETE(m_Page_Button1);
	SAFE_DELETE(m_Page_Button2);
	SAFE_DELETE(m_Page_Button3);
	SAFE_DELETE(m_OrderList);
	SAFE_DELETE(m_Wnd_Exit_btn);
	//SAFE_DELETE()
}
