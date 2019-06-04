#include "stdafx.h"
#include "cLoadScene.h"


cLoadScene::cLoadScene()
{
	m_BackGround = IMAGE->AddImage("Loading", "./Image/BackGround/Loading.bmp");

}


cLoadScene::~cLoadScene()
{
}

void cLoadScene::Init()
{
	m_NowLoad = 0;

	//�̹��� �߰�

	//�̹����� ���⼭ �߰���Ų��. ������� �̸�, ���, �̹��� ����
	Load("TitleBg", "./Image/DImage/BackGround/title_background.bmp");
	Load("InGameBg", "./Image/DImage/BackGround/mini_background.bmp");
	//Load("Player", "./Image/Player/(%d).bmp", 2);
	Load("OH", "./Image/OH.bmp");
	Load("Game_Logo", "./Image/DImage/Ui/game_logo.bmp");
	//button		title	
	Load("Start_Nomal", "./Image/DImage/Ui/Start_Nomal.bmp");
	Load("Start_OnCursor", "./Image/DImage/Ui/Start_OnCursor.bmp");
	Load("Start_Click", "./Image/DImage/Ui/Start_Click.bmp");

	Load("Exit_Nomal", "./Image/DImage/Ui/Exit_Nomal.bmp");
	Load("Exit_OnCursor", "./Image/DImage/Ui/Exit_OnCursor.bmp");
	Load("Exit_Click", "./Image/DImage/Ui/Exit_Click.bmp");

	Load("Option_Nomal", "./Image/DImage/Ui/Option_button(0).bmp");
	Load("Option_OnCursor", "./Image/DImage/Ui/Option_button(1).bmp");
	Load("Option_Click", "./Image/DImage/Ui/Option_button(2).bmp");
	//				ingame
	Load("money_icon", "./Image/DImage/2.Home/have_money.bmp");

	Load("Making_Nomal", "./Image/DImage/2.Home/Making_button(0).bmp");
	Load("Making_OnCursor", "./Image/DImage/2.Home/Making_button(1).bmp");
	Load("Making_Click", "./Image/DImage/2.Home/Making_button(2).bmp");

	Load("Info_Nomal", "./Image/DImage/2.Home/Store_Information_button(0).bmp");
	Load("Info_OnCursor", "./Image/DImage/2.Home/Store_Information_button(1).bmp");
	Load("Info_Click", "./Image/DImage/2.Home/Store_Information_button(2).bmp");

	//window
	Load("Order_Wnd", "./Image/DImage/Ui/Notice.bmp");
	Load("StoreInfo_Wnd", "./Image/DImage/Ui/Notice.bmp");
	Load("Option_Wnd", "./Image/DImage/Ui/Notice.bmp");
	//exit window button
	Load("WndExit_Nomal", "./Image/DImage/Ui/WndExit_Nomal.bmp");
	Load("WndExit_OnCursor", "./Image/DImage/Ui/WndExit_OnCursor.bmp");
	Load("WndExit_Click", "./Image/DImage/Ui/WndExit_Click.bmp"); 
	//making window button
	Load("Making_Nomal", "./Image/DImage/2.Home/Making_button(0).bmp");
	Load("Making_OnCursor", "./Image/DImage/2.Home/Making_button(1).bmp");
	Load("Making_Click", "./Image/DImage/2.Home/Making_button(2).bmp");


	//MainGame  
	m_MaxLoad = m_Load.size();
}

void cLoadScene::Update()
{
	if (m_NowLoad != m_MaxLoad) {
		IMAGE->AddImage(
			m_Load[m_NowLoad].key,
			m_Load[m_NowLoad].path,
			m_Load[m_NowLoad].count
		);

		m_NowLoad++;
	}
	else {
		//�̹��� �߰��� �� �Ǿ����� Scene�� �����Ѵ�.
		SCENE->ChangeScene("Title");
	}
}

void cLoadScene::Render()
{
	Point Pos;
	Pos.x = 0;
	Pos.y = 0;

	IMAGE->Render(IMAGE->FindImage("Loading"), Pos, false);
}

void cLoadScene::Release()
{
}
