#pragma once
class cButton;
class cWindow
{
public:
	cWindow(int x, int y, const string& key,int btn_x, int btn_y, const string & btn_key);
	~cWindow();
public:

	void Init();
	bool Update();
	void Render();

	bool bChkBtn = false; //��ư ���� Ȯ��
private:
	cTexture * m_Window;
	Point m_Pos;
	cButton * m_exitBtn;
}; 