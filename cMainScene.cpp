#include "stdafx.h"
#include "cMainScene.h"

cMainScene::cMainScene()
{
}

cMainScene::~cMainScene()
{
}

void cMainScene::Init()
{
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
}

void cMainScene::Update()
{
}

void cMainScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("MainGameBg"), m_BackGroundPos, false);
}

void cMainScene::Release()
{
}
