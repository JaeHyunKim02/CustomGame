// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "msimg32.lib")
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include<mmsystem.h>
#include<conio.h>
#include <iostream>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <time.h>
#include <timeapi.h>
#include <mmsystem.h>
#include"Digitalv.h"



using namespace std;

#define PURE = 0

#ifndef SAFE_DELETE
#define SAFE_DELETE(p)       { if (p) { delete (p);     (p)=NULL; } }
#endif    
#ifndef SAFE_DELETE_ARRAY
#define SAFE_DELETE_ARRAY(p) { if (p) { delete[] (p);   (p)=NULL; } }
#endif    
#ifndef SAFE_RELEASE
#define SAFE_RELEASE(p)      { if (p) { (p)->Release(); (p)=NULL; } }
#endif

#ifdef _DEBUG
#define DEBUG_LOG(log) cout << log << endl;
#else
#define DEBUG_LOG(log)
#endif // _DEBUG

#define Game_Name "게임 이름임.. ㅎㅎ"
//

const int WINSIZEX = 656;
const int WINSIZEY = 999;

//const int WINSIZEX = 600;
//const int WINSIZEY = 800;
extern HWND g_hWnd;

extern bool isOrder;//시간
extern bool isChangTime;//옷 바뀔 시간 메인 씬에 한번만 들어가게 해줌
extern bool chkOrder;//시간
extern float C_NowTime; //몰라
extern enum SCORE{
	GOOD,
	BAD
};
extern bool CKchangTime;//옷 갈아입는 시간
extern bool bBuyList[4][4];
extern int nCntBuyPos[4][4];
extern int DressPrice[8][8];

extern int nConcept;
extern int nCnt[4];
extern int Money;
extern bool BGM;
extern bool EFFECT;

struct Point
{
	int x;
	int y;
};
enum InGameWnd {
	EMPTY_WND,
	MAKING_WND,
	STOREINFO_WND,
	OPTION_WND,
	GAMEEXTI_WND
}; 
enum _ClosetKind {
	eTOP,
	eBOTTOM,
	eACCESSORY,
	eSHOES,
	eNULL,

	eTOP_1, eTOP_2, eTOP_3, eTOP_4, eTOP_5, eTOP_6, eTOP_7, eTOP_8,
	eBOTTOM_1, eBOTTOM_2, eBOTTOM_3, eBOTTOM_4, eBOTTOM_5, eBOTTOM_6, eBOTTOM_7, eBOTTOM_8,
	eACCESSORY_1, eACCESSORY_2, eACCESSORY_3, eACCESSORY_4, eACCESSORY_5, eACCESSORY_6, eACCESSORY_7, eACCESSORY_8,
	eSHOES_1, eSHOES_2, eSHOES_3, eSHOES_4, eSHOES_5, eSHOES_6, eSHOES_7, eSHOES_8

};
enum _ECONCEPT {
	CASUAL = 202,
	PURITY,//청순

}; 

enum _EPRODUCSTATE {
	SOLD=100, // 판매됨
	SALE, //판매중
};
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

//Manager
#include "cSceneManager.h"
#include "cImageManager.h"
#include "cInputManager.h"


#include "cMouseCursor.h"
