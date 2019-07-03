#pragma once
#include "cScene.h"
class cButton;
class cOptionWnd;
class cMakingWnd;

class cIngameScene : public cScene
{
private:
	cTexture * m_BackGround;
	//cFrame * m_PlayerFrame;
	Point Pos;
	int WndState;
	Point m_ChangePos;
	cTexture * m_ChangMmannequin;
	cMakingWnd * m_NoticeWnd;
	cOptionWnd * m_OptionWnd;

	cButton * m_GameExitButton;
	cButton * m_Notice_button;
	cButton * m_Option_button;
	cButton  * m_HowToPlay_button;

	Point m_BackGroundPos;
	Point m_MoneyIconPos;

	cButton * m_goshop;

	//알림창 버튼
	cButton * m_notice_exit_btn;

	Point CommentPos;
	Point CommentPos2;

	cButton * m_Page_Button1;
	cButton * m_Page_Button2;
	cButton * m_Page_Button3;
	Point ShowPageButtonPos;

	string m_Comment1 = "NULL";
	string m_Comment2= "NULL";



public:
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	//int Money;
	string kindC;

	//마우스
	cMouseCursor * m_Mouse;
	Point MousePoint;

	int count = 1;
public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
};

