#pragma once
class cButton
{
private :
	cTexture * m_Nomal;
	cTexture * m_OnCursor;
	cTexture * m_Click;

	Point m_Pos;

	RECT m_rt;
	
	bool b_OnCursor;
	bool b_Click;
public:
	cButton(int x, int y , const string& key);
	~cButton();

	void Init();
	bool Update();
	void Render();
	void Release();


	bool isClickDown(int x, int y);
	bool isOver();
};

