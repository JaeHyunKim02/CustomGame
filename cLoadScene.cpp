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

	Load("GameExit_No_Nomal", "./Image/DImage/1.Title/Game_Exit_No_Nomal.bmp");
	Load("GameExit_No_OnCursor", "./Image/DImage/1.Title/Game_Exit_No_OnCursor.bmp");
	Load("GameExit_No_Click", "./Image/DImage/1.Title/Game_Exit_No_Click.bmp");
	
	Load("GameExit_Yes_nomal", "./Image/DImage/1.Title/Game_Exit_Yes_Nomal.bmp");
	Load("GameExit_Yes_OnCursor", "./Image/DImage/1.Title/Game_Exit_Yes_OnCursor.bmp");
	Load("GameExit_Yes_Click", "./Image/DImage/1.Title/Game_Exit_Yes_Click.bmp");

	
	//MainGame  
	Load("MainGameBg", "./Image/DImage/BackGround/MainGameBg.bmp");

	Load("Mannequin", "./Image/DImage/4.MainGame2/Character_base.bmp");

	//dress-top
	Load("Top_1",		"./Image/DImage/4.MainGame2/Character_hair_01.bmp");
	//dress-bottom
	Load("Bottom_1",	"./Image/DImage/4.MainGame2/Character_cloth_01.bmp");
	//dress-accessory
	Load("Accessory_1", "./Image/DImage/4.MainGame2/Character_mouth_01.bmp");
	//dress-shoes
	Load("Shoes_1",		"./Image/DImage/4.MainGame2/Character_shoes_01.bmp");

	//closet
	Load("Closet_1", "./Image/DImage/4.MainGame/closet/Closet_1.bmp");
	Load("Closet_2", "./Image/DImage/4.MainGame/closet/Closet_2.bmp");
	Load("Closet_3", "./Image/DImage/4.MainGame/closet/Closet_3.bmp");
	Load("Closet_4", "./Image/DImage/4.MainGame/closet/Closet_4.bmp");
	//closet dress button
	Load("Closet_Top_Nomal",    "./Image/DImage/4.MainGame/Closet_Top_btn(0).bmp");
	Load("Closet_Top_OnCursor", "./Image/DImage/4.MainGame/Closet_Top_btn(1).bmp");
	Load("Closet_Top_Click",    "./Image/DImage/4.MainGame/Closet_Top_btn(2).bmp");

	Load("Closet_Bottom_Nomal",		"./Image/DImage/4.MainGame/Closet_Bottom_btn(0).bmp");
	Load("Closet_Bottom_OnCursor",	"./Image/DImage/4.MainGame/Closet_Bottom_btn(1).bmp");
	Load("Closet_Bottom_Click",		"./Image/DImage/4.MainGame/Closet_Bottom_btn(2).bmp");

	Load("Closet_Accessory_Nomal",	"./Image/DImage/4.MainGame/Closet_Accessory_btn(0).bmp");
	Load("Closet_Accessory_OnCursor", "./Image/DImage/4.MainGame/Closet_Accessory_btn(1).bmp");
	Load("Closet_Accessory_Click",	"./Image/DImage/4.MainGame/Closet_Accessory_btn(2).bmp");

	Load("Closet_Shoes_Nomal",	"./Image/DImage/4.MainGame/Closet_Shoes_btn(0).bmp");
	Load("Closet_Shoes_OnCursor", "./Image/DImage/4.MainGame/Closet_Shoes_btn(1).bmp");
	Load("Closet_Shoes_Click",	"./Image/DImage/4.MainGame/Closet_Shoes_btn(2).bmp");

	//closet kind button
	Load("Top_1_Nomal",    "./Image/DImage/4.MainGame/top_1_btn(0).bmp");
	Load("Top_1_OnCursor", "./Image/DImage/4.MainGame/top_1_btn(1).bmp");
	Load("Top_1_Click",    "./Image/DImage/4.MainGame/top_1_btn(2).bmp");
	 
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

	//IMAGE->Render(IMAGE->FindImage("Loading"), Pos, false);
}

void cLoadScene::Release()
{

}
