#pragma once
class cButton;
class cCloset {
public:
	cCloset(const string& key);
	~cCloset();
public:
	void Init();
	void Render();
	void Update();
	void Release();
public:
	void Init_top();
	void Init_bottom();
	void Init_accessory();
	void Init_shoes();
private:
	cButton * m_top_1_btn;
	cButton * m_bottom_1_btn;
	cButton * m_accessory_1_btn;
	cButton * m_shoes_1_btn;

	cTexture * m_Closet;
	Point m_closet_pos;
	eDRESS_KIND m_DressKind;
};