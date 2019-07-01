#pragma once
class cButton
{
private :
	cTexture * m_Nomal;
	cTexture * m_OnCursor;
	cTexture * m_Click;

	cTexture * m_Nomal2;
	cTexture * m_OnCursor2;
	cTexture * m_Click2;

	Point m_Pos;

	RECT m_rt;
	
	bool b_OnCursor;
	bool b_Click;

	bool bChkLock;
public:
	cButton(int x, int y , const string& key);
	cButton(int x, int y, const string & key, string & key2);
	~cButton();

	void Init();
	void Init(bool bChkLock);
	bool Update();
	void Render();
	void ClickRender();
	void StateRender(_EPRODUCSTATE state);
	void Release();
	void ChangeLock(bool lock) {
		if (this == nullptr)
			DEBUG_LOG("Hello");
		bChkLock = lock;
	}

	bool isOver();
};

