#include "stdafx.h"
#include "cLoadScene.h"


cLoadScene::cLoadScene()
{
	//m_BackGround = IMAGE->AddImage("Loading", "./Image/Loading.bmp");

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
	//button
	Load("Start_Nomal", "./Image/DImage/Ui/Start_Nomal.bmp");
	Load("Start_OnCursor", "./Image/DImage/Ui/Start_OnCursor.bmp");
	Load("Start_Click", "./Image/DImage/Ui/Start_Click.bmp");

	Load("Exit_Nomal", "./Image/DImage/Ui/Exit_Nomal.bmp");
	Load("Exit_OnCursor", "./Image/DImage/Ui/Exit_OnCursor.bmp");
	Load("Exit_Click", "./Image/DImage/Ui/Exit_Click.bmp");

	Load("Option_Nomal", "./Image/DImage/Ui/option_button(0).bmp");
	Load("Option_OnCursor", "./Image/DImage/Ui/option_button(1).bmp");
	Load("Option_Click", "./Image/DImage/Ui/option_button(2).bmp");

	Load("money_icon", "./Image/DImage/2.Home/have_money.bmp");
	Load("notice_Nomal", "./Image/DImage/2.Home/notice_icon(0).bmp");
	Load("notice_OnCursor", "./Image/DImage/2.Home/notice_icon(1).bmp");
	Load("notice_Click", "./Image/DImage/2.Home/notice_icon(2).bmp");

	Load("info_Nomal", "./Image/DImage/2.Home/store_Information_button(0).bmp");
	Load("info_OnCursor", "./Image/DImage/2.Home/store_Information_button(1).bmp");
	Load("info_Click", "./Image/DImage/2.Home/store_Information_button(2).bmp");

	
	//window
	Load("notice_Wnd", "./Image/DImage/Ui/notice.bmp");
	Load("storeInfo_Wnd", "./Image/DImage/Ui/notice.bmp");
	Load("option_Wnd", "./Image/DImage/Ui/notice.bmp");
	//window button
	Load("wndExit_Nomal", "./Image/DImage/Ui/WndExit_Nomal.bmp");
	Load("wndExit_OnCursor", "./Image/DImage/Ui/WndExit_OnCursor.bmp");
	Load("wndExit_Click", "./Image/DImage/Ui/WndExit_Click.bmp"); 
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
}

void cLoadScene::Release()
{
}
