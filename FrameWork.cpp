// FrameWork.cpp: 응용 프로그램의 진입점을 정의합니다.
//


#include "stdafx.h"
#include "FrameWork.h"
#include "cMainGame.h"

cMainGame mg;

#define MAX_LOADSTRING 100
DWORD dwTime = GetTickCount();
HWND g_hWnd;
bool isOrder;
bool isChangTime = false;

bool BGM;
bool EFFECT;

bool isOne = true;

float NowTime;
float m_fStartTime;

const float OrderTime = 3.0;
bool chkOrder = false;

bool first = true;

const float chageTime = 3.0f;
bool CKchangTime;
float C_NowTime;
float C_m_fStartTime;


// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.

// 이 코드 모듈에 들어 있는 함수의 정방향 선언입니다.
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//bool FullScreen();

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//콘솔창 추가
	//DEBUG_LOG("할말"); 을 사용해서 콘솔창에 로그를 띄울 수 있다
	AllocConsole();
	freopen("CONOUT$", "a", stdout);
	freopen("CONOUT$", "a", stderr);
	freopen("CONIN$", "r", stdin);

	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: 여기에 코드를 입력합니다.

	// 전역 문자열을 초기화합니다.
	//_CrtSetBreakAlloc(1596);
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_FRAMEWORK, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// 응용 프로그램 초기화를 수행합니다.
	if (InitInstance(hInstance, nCmdShow))
	{
		//return FALSE;
		//return TRUE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_FRAMEWORK));

	MSG msg;

	// 기본 메시지 루프입니다.
	//while (GetMessage(&msg, nullptr, 0, 0))
	//{
	//    if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
	//    {
	//        TranslateMessage(&msg);
	//        DispatchMessage(&msg);
	//    }
	//}


	while (true)
	{
		//메시지가 있으면 해당 메시지를 수행
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{

			//종료 메시지가 들어오면 루프를 탈출, 프로그램 종료
			if (msg.message == WM_QUIT)
				break;
			if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			if (isOrder) {
				if (first)
					m_fStartTime = (float)timeGetTime() * 0.001f;   //초단위로 바꿔줌
				if (NowTime - m_fStartTime >= OrderTime)   // 여기서 0.1 은 0.1초마다 실행을 의미
				{
					DEBUG_LOG("10c초");
					isOrder = false;
					chkOrder = true;
					first = true;
					//nConcept = rand() % 4;
				}
				else {
					first = false;
					NowTime = (float)timeGetTime() * 0.001f;    //초단위로 바꿔줌
				}
			}

			if (isChangTime) {
				if (isOne) {
					C_m_fStartTime = (float)timeGetTime() * 0.001f;//시작부분
					//CKchangTime = false;
					isOne = false;

				}
				if (C_NowTime - C_m_fStartTime >= chageTime) {
					DEBUG_LOG("옷 갈아입을 시간");
					CKchangTime = true;
					isOne = true;

				}
				else {
					//CKchangTime = false;
					C_NowTime = (float)timeGetTime()*0.001f;

				}
			}

			if (dwTime < GetTickCount())
			{
				dwTime = GetTickCount();
				//항상 수행해야 할 어떠한 함수 EX)Progress
				mg.Update();
				mg.Render();
			}
		}

	}

	return (int)msg.wParam;
}



//
//  함수: MyRegisterClass()
//
//  목적: 창 클래스를 등록합니다.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	
	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_FRAMEWORK));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;//MAKEINTRESOURCEW(IDC_FRAMEWORK);
	wcex.lpszClassName = szWindowClass;//szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));


	return RegisterClassExW(&wcex);
}


/*bool FullScreen()
{
	if (MessageBox(NULL, L"전체화면으로 전환?", L"옷입히기", MB_OKCANCEL) == true) {
		DEVMODE devmode;
		ZeroMemory(&devmode, sizeof(DEVMODE));
		devmode.dmSize = sizeof(DEVMODE);
		devmode.dmBitsPerPel = 32;
		devmode.dmPelsWidth = 640;
		devmode.dmPelsHeight = 960;
		devmode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
		ChangeDisplaySettings(&devmode, CDS_FULLSCREEN);
		return true;
	}
}*/

//
//   함수: InitInstance(HINSTANCE, int)
//
//   목적: 인스턴스 핸들을 저장하고 주 창을 만듭니다.
//
//   설명:
//
//        이 함수를 통해 인스턴스 핸들을 전역 변수에 저장하고
//        주 프로그램 창을 만든 다음 표시합니다.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.3
	ShowCursor(FALSE);//커서 지우기 
	g_hWnd = CreateWindowW(szWindowClass, L"그녀는 예뻤다", WS_BORDER, 0, 0, WINSIZEX, WINSIZEY, nullptr, nullptr, hInstance, nullptr);
	/*if (FullScreen()) {
		g_hWnd = CreateWindowW(szWindowClass, L"그녀는 예뻤다", WS_BORDER, 0, 0, WINSIZEX, WINSIZEY, nullptr, nullptr, hInstance, nullptr);
	}
	else {
		g_hWnd = CreateWindowW(szWindowClass, L"그녀는 예뻤다", WS_BORDER | WS_DLGFRAME,
			0, 0, WINSIZEX+16, WINSIZEY+39, nullptr, nullptr, hInstance, nullptr);
	}*/
	
	//if (MessageBox(NULL, L"전체화면으로 전환?", L"옷입히기", MB_OKCANCEL) == true) {
	//	DEVMODE devmode;
	//	ZeroMemory(&devmode, sizeof(DEVMODE));
	//	devmode.dmSize = sizeof(DEVMODE);
	//	devmode.dmBitsPerPel = 32;
	//	devmode.dmPelsWidth = 800;
	//	devmode.dmPelsHeight = 600;
	//	devmode.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
	//	ChangeDisplaySettings(&devmode, CDS_FULLSCREEN);
	//	g_hWnd = CreateWindowW(szWindowClass, L"그녀는 예뻤다", WS_BORDER, 0, 0, WINSIZEX, WINSIZEY, nullptr, nullptr, hInstance, nullptr);
	//	DEBUG_LOG("전체화면 됨");
	//}
	//else {
	//	g_hWnd = CreateWindowW(szWindowClass, L"그녀는 예뻤다", WS_BORDER | WS_DLGFRAME,
	//		0, 0, WINSIZEX + 16, WINSIZEY + 39, nullptr, nullptr, hInstance, nullptr);
	//	DEBUG_LOG("전체화면 안됨");
	//}







	if (!g_hWnd)
	{
		return FALSE;
	}
	IMAGE->InputHWND(g_hWnd);
	mg.InputHINSTANCE(hInst);
	mg.Init(g_hWnd);

	ShowWindow(g_hWnd, nCmdShow);
	UpdateWindow(g_hWnd);

	return TRUE;
}

//
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적:  주 창의 메시지를 처리합니다.
//
//  WM_COMMAND  - 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT    - 주 창을 그립니다.
//  WM_DESTROY  - 종료 메시지를 게시하고 반환합니다.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// 메뉴 선택을 구문 분석합니다.
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	//case WM_PAINT:
   //      {
		  //PAINTSTRUCT ps;
		  //HDC hdc = BeginPaint(hWnd, &ps);

		  // TODO: 여기에 hdc를 사용하는 그리기 코드를 추가합니다.
		  //mg.Render();

		  //EndPaint(hWnd, &ps);
	//     }
	 //   break;
	case WM_TIMER:
		DEBUG_LOG(mg.GetCount());
		mg.InputCount(0);
		break;
	case WM_DESTROY:

		mg.Release();
		FreeConsole();
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}