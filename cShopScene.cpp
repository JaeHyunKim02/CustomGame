#include "stdafx.h"
#include "cShopScene.h"
bool bBuyList[4][4];
int nCntBuyPos[4][4]; //���� �� ������ üũ�ϴ� ����
int nCnt[4] = { 0,0,0,0 };
cShopScene::cShopScene()
{

	m_ShopBgPos.x = 0;
	m_ShopBgPos.y = 0;

}


cShopScene::~cShopScene()
{
	Release();
}

void cShopScene::Init()
{
	m_Mouse = new cMouseCursor();
	m_Mouse->Init();
	m_next_btn = new cButton(600, 458, "Next");
	m_before_btn = new cButton(43, 458, "Before");
	m_next_btn->Init();
	m_before_btn->Init();
	m_Product[eTOP][0] = new cButton(193, 283, "Product_1",	"Product_1_UnLock");
	m_Product[eTOP][1] = new cButton(450, 283, "Product_2", "Product_2_UnLock");
	m_Product[eTOP][2] = new cButton(193, 708, "Product_3", "Product_3_UnLock");
	m_Product[eTOP][3] = new cButton(450, 708, "Product_4", "Product_4_UnLock"); 
		for (int i = 0; i < 4; i++) {
			m_product_state[eTOP][i] = SALE;
			m_Product[eTOP][i]->Init();
		}
	m_Exit = new cButton(40, 600, "WndExit");
	m_Exit->Init();
}

void cShopScene::Update()
{

	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;
	m_Mouse->Update(MousePoint);
		for (int i = 0; i < 4; i++) {
<<<<<<< HEAD
			if (bBuyList[j][i] == true) {//�� �ʵ��� ����Ʈ�� �޾ƿ�
				m_product_state[j][i] = SOLD; 
			}
		}
	}
 
	if (m_before_btn->Update() && m_state != eTOP) {//���� ��ư 
		m_state--;
		DEBUG_LOG(m_state);
	}
	if (m_next_btn->Update() && m_state != eSHOES) {//���� ��ư
=======
			if (bBuyList[eTOP][i] == true) {	//�� ���� ����Ʈ�� �޾ƿ� m_product_statae�� enum������ ����
				m_product_state[eTOP][i] = SOLD;
			}
		}

	if (m_before_btn->Update() && m_state != eTOP) { //���� ��ư
		m_state--;
		DEBUG_LOG(m_state);
	}
	if (m_next_btn->Update() && m_state != eSHOES) { //���� ��ư
>>>>>>> 7122d28a4584dbe7e1610660024869274bfdb92e
		m_state++;
		DEBUG_LOG(m_state);
	}
	BuyDress();
	if (m_Exit->Update()) {	//������ ��ư
		SCENE->ChangeScene("InGame");
	}
}
<<<<<<< HEAD

void cShopScene::BuyDress()//�� ����
{ 
	for (int i = 0; i < 4; i++) {
		if (m_Product[m_state][i]->Update()) { 
			m_bBuyBtn[m_state][i] = true;		 
=======
void cShopScene::BuyDress()//�� ����
{
	for (int i = 0; i < 4; i++) {
		if (m_Product[m_state][i]->Update()) {//��ư�� �������
			m_bBuyBtn[m_state][i] = true;
>>>>>>> 7122d28a4584dbe7e1610660024869274bfdb92e
		}
	}
	for (int i = 0; i < 4; i++) {
		if (m_bBuyBtn[m_state][i] == true && bBuyList[m_state][i] == false) { //���� ���� ���� �ʾҰ�, �ʹ�ư�� ������ ���
			if (Money >= 1000 * (i + 1)) { //���� �ִ� ���
				bBuyList[m_state][i] = true;
				DEBUG_LOG("�� ����");
				DEBUG_LOG(m_state);
				DEBUG_LOG(i);
				Money -= 1000 * (i + 1);
				CntBuyList(m_state, i); //������� �׷��ִ� �Լ�
			}
			else {
				m_bBuyBtn[m_state][i] = false;
				DEBUG_LOG("���� ����");
			}
		}
	}
}
void cShopScene::CntBuyList(int i, int j)//�� �� ������� ���忡 ����
{
	switch (i) {//�� ������ ���忡 ���� ���̴� �Լ�
	case eTOP: {
		nCntBuyPos[eTOP][j] = nCnt[eTOP];
		nCnt[eTOP]++;
		break;
	}
	case eBOTTOM: {
		nCntBuyPos[eBOTTOM][j] = nCnt[eBOTTOM];
		nCnt[eBOTTOM]++;
		break;
	}
	case eACCESSORY: {
		nCntBuyPos[eACCESSORY][j] = nCnt[eACCESSORY];
		nCnt[eACCESSORY]++;
		break;
	}
	case eSHOES: {
		nCntBuyPos[eSHOES][j] = nCnt[eSHOES];
		nCnt[eSHOES]++;
		break;
	}
	}
}


void cShopScene::Render()//������ �� ����
{
	IMAGE->Render(IMAGE->FindImage("ShopBg"), m_ShopBgPos, false);
	//for (int i = 0; i < 4; i++) {
	//	DEBUG_LOG("//////////");
	//	DEBUG_LOG(i);
	//	for (int j = 0; j < 4; j++) {
	//		DEBUG_LOG(m_product_state[i][j]);
	//	}
	//} 
	switch (m_state) {//���� �������� �ش��ϴ� �ʵ��� ������
	case eTOP:
		for (int i = 0; i < 4; i++) {
			m_Product[eTOP][i]->StateRender(m_product_state[eTOP][i]); //SALE
		}break;
	//case eBOTTOM:
	//	for (int i = 0; i < 4; i++) {
	//		m_Product[eBOTTOM][i]->StateRender(m_product_state[eBOTTOM][i]);
	//	}break;
	//case eACCESSORY: {
	//	for (int i = 0; i < 4; i++) {
	//		m_Product[eACCESSORY][i]->StateRender(m_product_state[eACCESSORY][i]);
	//	}break;
	//}
	//case eSHOES: {
	//	for (int i = 0; i < 4; i++) {
	//		m_Product[eSHOES][i]->StateRender(m_product_state[eSHOES][i]);
	//	}break;
	//}
	}
	m_next_btn->Render();
	m_before_btn->Render();
	m_Exit->Render();
	IMAGE->PrintTexture("Money =" + to_string(Money), { 300 , 200 });
	m_Mouse->Render(MousePoint);
}

void cShopScene::Release()
{
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 4; i++) {
			SAFE_DELETE(m_Product[j][i]);
		}
	}
	SAFE_DELETE(m_Exit);
	SAFE_DELETE(m_Mouse);
}
