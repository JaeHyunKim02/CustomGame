#pragma once
#include "cScene.h"

class cButton;
class cMainScene:public cScene
{
private:
	cTexture * m_BackGround;
	Point m_BackGroundPos;
public:
	cMainScene();
	~cMainScene();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
}; 