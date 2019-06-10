#pragma once
class cButton;
class cStoreWnd
{
public:
	cStoreWnd(int x, int y, const string & key);
	~cStoreWnd();
public:
	void Init();
	void Update();
	void Render();
	void Release();
private:
	bool bClickChk = true;
	cButton * m_Exit_btn;
	cTexture * m_Window;
	Point m_Pos;
};

