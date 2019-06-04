#include "stdafx.h"
#include "MainGame.h"


MainGame::MainGame()
{
}


MainGame::~MainGame()
{
}

void MainGame::Init()
{
	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0;
}

void MainGame::Update()
{
}

void MainGame::Render()
{ 
	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);
}

void MainGame::Release()
{
}
