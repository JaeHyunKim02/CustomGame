#include "stdafx.h"
#include "cTitleScene.h"


cTitleScene::cTitleScene()
{
}


cTitleScene::~cTitleScene()
{
}

void cTitleScene::Init()
{
	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0;
}

void cTitleScene::Update()
{
	if (INPUT->KeyPress(VK_SPACE)) {
 		SCENE->ChangeScene("InGame");	DEBUG_LOG("dsf");
	}
}

void cTitleScene::Render()
{
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);


}

void cTitleScene::Release()
{
}
