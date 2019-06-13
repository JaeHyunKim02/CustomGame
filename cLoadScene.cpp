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

	//이미지 추가

	//이미지는 여기서 추가시킨다. 순서대로 이름, 경로, 이미지 갯수
	Load("TitleBg", "./Image/BackGround/title_background.bmp");
	Load("IngameBg", "./Image/DImage/BackGround/mini_background.bmp");
	Load("MainGameBg", "./Image/BackGround/maingame_background.bmp");
	//Load("Player", "./Image/Player/(%d).bmp", 2);
	Load("OH", "./Image/OH.bmp");
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

	//ingame
	Load("money_icon", "./Image/DImage/2.Home/have_money.bmp");

	Load("Notice_Nomal", "./Image/DImage/2.Home/Notice_icon(0).bmp");
	Load("Notice_OnCursor", "./Image/DImage/2.Home/Notice_icon(1).bmp");
	Load("Notice_Click", "./Image/DImage/2.Home/Notice_icon(2).bmp");

	Load("Info_Nomal", "./Image/DImage/2.Home/Store_Information_button(0).bmp");
	Load("Info_OnCursor", "./Image/DImage/2.Home/Store_Information_button(1).bmp");
	Load("Info_Click", "./Image/DImage/2.Home/Store_Information_button(2).bmp");

	//window
	Load("Making_Wnd", "./Image/DImage/Ui/Window.bmp");
	Load("StoreInfo_Wnd", "./Image/DImage/Ui/Window.bmp");
	Load("Option_Wnd", "./Image/DImage/Ui/Window.bmp");
	Load("WndExit_Nomal", "./Image/DImage/Ui/WndExit_Nomal.bmp");
	Load("WndExit_OnCursor", "./Image/DImage/Ui/WndExit_OnCursor.bmp");
	Load("WndExit_Click", "./Image/DImage/Ui/WndExit_Click.bmp"); 

	//making window button
	Load("Making_Nomal", "./Image/DImage/2.Home/Making_button(0).bmp");
	Load("Making_OnCursor", "./Image/DImage/2.Home/Making_button(1).bmp");
	Load("Making_Click", "./Image/DImage/2.Home/Making_button(2).bmp");
	
	Load("option_BGM_On_Nomal", "./Image/DImage/1.Title/option_sound_Down_Nomal.bmp");
	Load("option_BGM_On_OnCursor", "./Image/DImage/1.Title/option_sound_Down_OnCursor.bmp");
	Load("option_BGM_On_Click", "./Image/DImage/1.Title/option_sound_Down_Click.bmp");

	Load("option_BGM_Off_Nomal", "./Image/DImage/1.Title/option_sound_Up_Nomal.bmp");
	Load("option_BGM_Off_OnCursor", "./Image/DImage/1.Title/option_sound_Up_OnCursor.bmp");
	Load("option_BGM_Off_Click", "./Image/DImage/1.Title/option_sound_Up_Click.bmp");

	Load("Store_Expention_Nomal", "./Image/DImage/2.Home/Store_Expention(0).bmp");
	Load("Store_Expention_OnCursor", "./Image/DImage/2.Home/Store_Expention(1).bmp");
	Load("Store_Expention_Click", "./Image/DImage/2.Home/Store_Expention(2).bmp");
	//MainGame  
	Load("MainGameBg", "./Image/DImage/BackGround/title_background.bmp");
	Load("MessageWnd", "./Image/DImage/Ui/MessageWnd.bmp");
	Load("Wnd_Yes_Nomal",	 "./Image/DImage/Ui/Wnd_Yes_Nomal.bmp");
	Load("Wnd_Yes_OnCursor", "./Image/DImage/Ui/Wnd_Yes_OnCursor.bmp");
	Load("Wnd_Yes_Click",	 "./Image/DImage/Ui/Wnd_Yes_Click.bmp");

	Load("Wnd_No_Nomal",	"./Image/DImage/Ui/Wnd_No_Nomal.bmp");
	Load("Wnd_No_OnCursor", "./Image/DImage/Ui/Wnd_No_OnCursor.bmp");
	Load("Wnd_No_Click",	"./Image/DImage/Ui/Wnd_No_Click.bmp");

	Load("Top_btn_Nomal", "./Image/DImage/Ui/top_btn(0).bmp");
	Load("Top_btn_OnCursor", "./Image/DImage/Ui/top_btn(1).bmp");
	Load("Top_btn_Click", "./Image/DImage/Ui/top_btn(2).bmp");

	Load("Closet_Top", "./Image/DImage/4.MainGame/UI_Top.bmp");
	Load("Closet_Bottom", "./Image/DImage/4.MainGame/UI_Bottom.bmp");
	Load("Closet_Accessroy", "./Image/DImage/4.MainGame/UI_Accessory.bmp");
	Load("Closet_Shoes", "./Image/DImage/4.MainGame/UI_Shoes.bmp");
	//btn 
	Load("Top_1_Nomal", "./Image/DImage/4.MainGame/Button/top_1_btn(0).bmp");
	Load("Top_1_OnCursor", "./Image/DImage/4.MainGame/Button/top_1_btn(1).bmp");
	Load("Top_1_Click", "./Image/DImage/4.MainGame/Button/top_1_btn(2).bmp");

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
		//이미지 추가가 다 되었으면 Scene을 변경한다.
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
