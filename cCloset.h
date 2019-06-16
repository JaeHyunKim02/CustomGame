#pragma once


class cButton;
class cCloset
{
public:
	cCloset(const string& key);
	~cCloset();
public:
	void Init();
	void Update();
	void Render();
	void Release();
public:
	void Init_top();
	void Init_bottom();
	void Init_accessory();
	void Init_shoes();
private:
	_ClosetKind _EDress[4];
	Point m_closet_pos;
private:
	cTexture * m_Closet;
	_ClosetKind m_DressKind;

	cButton * m_top_1_btn;
	cButton * m_top_2_btn;
	cButton * m_top_3_btn;
	cButton * m_top_4_btn;

	cButton * m_bottom_1_btn;
	cButton * m_bottom_2_btn;
	cButton * m_bottom_3_btn;
	cButton * m_bottom_4_btn;

	cButton * m_accessory_1_btn;
	cButton * m_accessory_2_btn;
	cButton * m_accessory_3_btn;

	cButton * m_shoes_1_btn;
	cButton * m_shoes_2_btn;
	cButton * m_shoes_3_btn;
	cButton * m_shoes_4_btn;
public:
	_ClosetKind getTop() { return _EDress[eTOP]; }
	_ClosetKind getBottom() { return _EDress[eBOTTOM]; }
	_ClosetKind getAccessory() { return _EDress[eACCESSORY]; }
	_ClosetKind getShoes() { return _EDress[eSHOES]; }
};

