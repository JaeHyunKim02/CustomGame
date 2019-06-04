#pragma once
#include "cScene.h"
class cButton;
class MainGame :public cScene
{
private:
	cTexture * m_BackGround;
	Point m_TitleBgPos;
public:
	MainGame();
	~MainGame();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
}; 