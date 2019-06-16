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

const int WINSIZEX = 640;
const int WINSIZEY = 960;

extern HWND g_hWnd;
extern bool isOrder;
extern bool chkOrder;
extern int Money;
extern bool BGM;
extern bool EFFECT;
int nConcept;
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

	eTOP_1,
	eBOTTOM_1,
	eACCESSORY_1,
	eSHOES_1,

};
enum _ECONCEPT {
	CASUAL = 202,
	PURITY,//청순

};
void setConcept(int concept) {
	nConcept = concept;
}
int getConcept() { return nConcept; }
// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.

//Manager
#include "cSceneManager.h"
#include "cImageManager.h"
#include "cInputManager.h"
