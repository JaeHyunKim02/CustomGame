#include "stdafx.h"
#include "cLoadScene.h"


cLoadScene::cLoadScene()
{
}


cLoadScene::~cLoadScene()
{
}

void cLoadScene::Init()
{
	m_NowLoad = 0;

	//이미지 추가

	//이미지는 여기서 추가시킨다. 순서대로 이름, 경로, 이미지 갯수
	Load("TitleBg", "./Image/1.Title/BackGround/TitleBG.bmp");
	Load("InGameBG", "./Image/2.InGame/BackGround/InGameBG.bmp");
	Load("MainGameBg", "./Image/3.MainGame/BackGround/MainGameBG.bmp");

	Load("Game_Logo", "./Image/1.Title/Ui/game_logo.bmp");

	//button      title   
	Load("Start_Nomal",		"./Image/1.Title/Ui/Start_Nomal.bmp");
	Load("Start_OnCursor",	"./Image/1.Title/Ui/Start_OnCursor.bmp");
	Load("Start_Click",		"./Image/1.Title/Ui/Start_Click.bmp");

	Load("Exit_Nomal",		"./Image/1.Title/Ui/Exit_Nomal.bmp");
	Load("Exit_OnCursor",	"./Image/1.Title/Ui/Exit_OnCursor.bmp");
	Load("Exit_Click",		"./Image/1.Title/Ui/Exit_Click.bmp");

	Load("Option_Nomal",	"./Image/1.Title/Ui/Option_button(0).bmp");
	Load("Option_OnCursor", "./Image/1.Title/Ui/Option_button(1).bmp");
	Load("Option_Click",	"./Image/1.Title/Ui/Option_button(2).bmp");

	//ingame
	Load("Notice_Nomal",	"./Image/2.InGame/UI/Notice_icon(0).bmp");
	Load("Notice_OnCursor", "./Image/2.InGame/UI/Notice_icon(1).bmp");
	Load("Notice_Click",	"./Image/2.InGame/UI/Notice_icon(2).bmp");

	Load("Info_Nomal",		"./Image/2.InGame/UI/Store_Information_button(0).bmp");
	Load("Info_OnCursor",	"./Image/2.InGame/UI/Store_Information_button(1).bmp");
	Load("Info_Click",		"./Image/2.InGame/UI/Store_Information_button(2).bmp");

	//window
	Load("Making_Wnd",		"./Image/UI/Window.bmp");
	Load("StoreInfo_Wnd",	"./Image/UI/Window.bmp");
	Load("Option_Wnd",		"./Image/UI/Window.bmp");
	Load("WndExit_Nomal",	"./Image/UI/WndExit_Nomal.bmp");
	Load("WndExit_OnCursor","./Image/UI/WndExit_OnCursor.bmp");
	Load("WndExit_Click",	"./Image/UI/WndExit_Click.bmp");

	//making window button
	Load("Making_Nomal",	"./Image/2.InGame/UI/Making_button(0).bmp");
	Load("Making_OnCursor", "./Image/2.InGame/UI/Making_button(1).bmp");
	Load("Making_Click",	"./Image/2.InGame/UI/Making_button(2).bmp");

	Load("option_BGM_On_Nomal",		"./Image/UI/option_sound_Down_Nomal.bmp");
	Load("option_BGM_On_OnCursor",	"./Image/UI/option_sound_Down_OnCursor.bmp");
	Load("option_BGM_On_Click",		"./Image/UI/option_sound_Down_Click.bmp");

	Load("option_BGM_Off_Nomal",	"./Image/UI/option_sound_Up_Nomal.bmp");
	Load("option_BGM_Off_OnCursor", "./Image/UI/option_sound_Up_OnCursor.bmp");
	Load("option_BGM_Off_Click",	"./Image/UI/option_sound_Up_Click.bmp"); 
  
	//closet
	//closet dress button
	Load("Closet_Top_Nomal",	"./Image/3.MainGame/UI/Closet/jacket_button(0).bmp");
	Load("Closet_Top_OnCursor", "./Image/3.MainGame/UI/Closet/jacket_button(1).bmp");
	Load("Closet_Top_Click",	"./Image/3.MainGame/UI/Closet/jacket_button(2).bmp");

	Load("Closet_Bottom_Nomal",		"./Image/3.MainGame/UI/Closet/skirt_button(0).bmp");
	Load("Closet_Bottom_OnCursor",	"./Image/3.MainGame/UI/Closet/skirt_button(1).bmp");
	Load("Closet_Bottom_Click",		"./Image/3.MainGame/UI/Closet/skirt_button(2).bmp");

	Load("Closet_Accessory_Nomal",		"./Image/3.MainGame/UI/Closet/accessory_button(0).bmp");
	Load("Closet_Accessory_OnCursor",	"./Image/3.MainGame/UI/Closet/accessory_button(1).bmp");
	Load("Closet_Accessory_Click",		"./Image/3.MainGame/UI/Closet/accessory_button(2).bmp");

	Load("Closet_Shoes_Nomal",		"./Image/3.MainGame/UI/Closet/shoes_button(0).bmp");
	Load("Closet_Shoes_OnCursor",	"./Image/3.MainGame/UI/Closet/shoes_button(1).bmp");
	Load("Closet_Shoes_Click",		"./Image/3.MainGame/UI/Closet/shoes_button(2).bmp");

	Load("Clear_Nomal",    "./Image/3.MainGame/UI/clear_button.bmp");
	Load("Clear_OnCursor", "./Image/3.MainGame/UI/clear_button.bmp");
	Load("Clear_Click",    "./Image/3.MainGame/UI/clear_button.bmp");
	//closet kind button
	Load("Top_1_Nomal",		"./Image/3.MainGame/UI/Closet/top_1_btn(0).bmp");
	Load("Top_1_OnCursor",	"./Image/3.MainGame/UI/Closet/top_1_btn(1).bmp");
	Load("Top_1_Click",		"./Image/3.MainGame/UI/Closet/top_1_btn(2).bmp");

	Load("GameExit_No_Nomal",	"./Image/UI/Game_Exit_No_Nomal.bmp");
	Load("GameExit_No_OnCursor","./Image/UI/Game_Exit_No_OnCursor.bmp");
	Load("GameExit_No_Click",	"./Image/UI/Game_Exit_No_Click.bmp");

	Load("GameExit_Yes_Nomal",		"./Image/UI/Game_Exit_Yes_Nomal.bmp");
	Load("GameExit_Yes_OnCursor",	"./Image/UI/Game_Exit_Yes_OnCursor.bmp");
	Load("GameExit_Yes_Click",		"./Image/UI/Game_Exit_Yes_Click.bmp");

	Load("Upgrade_Nomal",		"./Image/2.InGame/Upgrade_Nomal.bmp");
	Load("Upgrade_OnCursor",	"./Image/2.InGame/Upgrade_OnCursor.bmp");
	Load("Upgrade_Click",		"./Image/2.InGame/Upgrade_Click.bmp");
	 
	Load("Mannequin", "./Image/3.MainGame/UI/Mannequin.bmp");

	Load("Top_1", "./Image/3.MainGame/Dress/Top/jacket_01.bmp");
	Load("Top_2", "./Image/3.MainGame/Dress/Top/jacket_02.bmp");
	Load("Top_3", "./Image/3.MainGame/Dress/Top/jacket_03.bmp");
	Load("Top_4", "./Image/3.MainGame/Dress/Top/jacket_04.bmp");
	Load("Top_5", "./Image/3.MainGame/Dress/Top/jacket_05.bmp");
	Load("Top_6", "./Image/3.MainGame/Dress/Top/jacket_06.bmp");
	Load("Top_7", "./Image/3.MainGame/Dress/Top/jacket_07.bmp");

	Load("Bottom_1", "./Image/3.MainGame/Dress/Bottom/skirt.bmp");
	Load("Bottom_2", "./Image/3.MainGame/Dress/Bottom/skirt_02.bmp");
	Load("Bottom_3", "./Image/3.MainGame/Dress/Bottom/skirt_03.bmp");
	Load("Bottom_4", "./Image/3.MainGame/Dress/Bottom/skirt_04.bmp");
	Load("Bottom_5", "./Image/3.MainGame/Dress/Bottom/skirt_05.bmp");
	Load("Bottom_6", "./Image/3.MainGame/Dress/Bottom/skirt_06.bmp");
	//Load("Bottom_4""./Image/3.MainGame3/Dress/Top, "./Image/DImage/4.MainGame3/pants_04.bmp");

	Load("Shoes_1", "./Image/3.MainGame/Dress/Shoes/shose.bmp");
	Load("Shoes_2", "./Image/3.MainGame/Dress/Shoes/shose_01.bmp");
	Load("Shoes_3", "./Image/3.MainGame/Dress/Shoes/shose_02.bmp");
	Load("Shoes_4", "./Image/3.MainGame/Dress/Shoes/shose_03.bmp");
	Load("Shoes_5", "./Image/3.MainGame/Dress/Shoes/shose_04.bmp");

	Load("Accessory_1", "./Image/3.MainGame/Dress/Accessory/accessory_01.bmp");
	Load("Accessory_2", "./Image/3.MainGame/Dress/Accessory/accessory_02.bmp");
	Load("Accessory_3", "./Image/3.MainGame/Dress/Accessory/accessory_03.bmp");
	Load("Accessory_4", "./Image/3.MainGame/Dress/Accessory/accessory_04.bmp");
	//Load("Accessory_4", "./Image/DImage/4.MainGame3/accessory_03.bmp");

	Load("Next_Nomal",		"./Image/3.MainGame/UI/Closet/next.bmp");
	Load("Next_OnCursor",	"./Image/3.MainGame/UI/Closet/next.bmp");
	Load("Next_Click",		"./Image/3.MainGame/UI/Closet/next.bmp");

	Load("Before_Nomal",		"./Image/3.MainGame/UI/Closet/before.bmp");
	Load("Before_OnCursor",		"./Image/3.MainGame/UI/Closet/before.bmp");
	Load("Before_Click",		"./Image/3.MainGame/UI/Closet/before.bmp");

	//마우서 커서 
	Load("MouseCursor_nomal",	"Image/Ui/MouseCursor/MouseCur.bmp");
	Load("MouseCursor_onclick", "Image/Ui/MouseCursor/MouseCur(1).bmp");
	Load("MouseCursor_upclick", "Image/Ui/MouseCursor/MouseCur(2).bmp");

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