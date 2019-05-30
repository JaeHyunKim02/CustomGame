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
	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);


}

void cTitleScene::Release()
{
}
