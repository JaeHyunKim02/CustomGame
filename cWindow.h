#pragma once
class cButton;
class cWindow
{
public:
	cWindow(int x, int y, const string& key, const string & btn_key, int WndState);
	~cWindow();
public:

	void Init();
	bool Update();
	bool Render();
	void Release();

	bool bChkBtn;//버튼 누름 확인
	int WndState;

	int RenderNotice();
	int RenderStoreInfo();
	int RenderOption();
	
private:
	
	cTexture * m_Window;
	Point m_Pos;
	cButton * m_exitBtn;

	cButton * m_Making_button;

};