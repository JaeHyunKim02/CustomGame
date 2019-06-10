#pragma once
class cButton;
class cMakingWnd;
class cOptionWnd;
class cStoreWnd;
class cWindow
{
public:
	cWindow(int x, int y, const string & key);
	~cWindow();
public:


	void Init();
	bool Update(int WndState);
	bool Render(int WndState);
	void Release();
public:
	int getbChkBtn() { return bChkBtn; }
	void SetState(int state) { WndState = state; }

private:
	bool bChkBtn;//버튼 누름 확인
	int WndState;
	string ExitBtnKey;
public:
	MCI_PLAY_PARMS mciPlay;

private:
	string m_Window;
	Point m_Pos;
	Point m_BtnPos;

	cButton * m_exitBtn;

	cMakingWnd * m_MakingWnd;
	cStoreWnd * m_StoreWnd;
	cOptionWnd * m_OptionWnd;
};