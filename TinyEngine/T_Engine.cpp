//*******************************************************************
// TinyEngine����  
// ����: ������(WanLizhong)
// ����: www.wanlizhong.com 
// ����: 2013-08-02
// ����: 2019-11-28
// ��Ȩ���� 2007-2019 ������
// (C) 2007-2019 WanLizhong All Rights Reserved
//*******************************************************************

#include "T_Engine.h"

// ��ʼ����ľ�̬����
HWND T_Engine::m_hWnd = NULL;				// ���ھ��
HINSTANCE T_Engine::m_hInstance = NULL;		// ʵ�����
T_Engine* T_Engine::pEngine = NULL;			// ������ָ��

// ���캯��(����: 2019-09-28)
T_Engine::T_Engine(HINSTANCE hInstance, LPCTSTR szWindowClass, LPCTSTR szTitle,
	WORD Icon, WORD SmIcon, int iWidth, int iHeight, COLORREF bkColor)
{
	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	Gdiplus::GdiplusStartup(&ptrGdiplusToken, &gdiplusStartupInput, NULL);

	pEngine = this;
	m_hInstance = hInstance;
	wndClass = szWindowClass;
	wndTitle = szTitle;
	wndWidth = iWidth;
	wndHeight = iHeight;
	m_bFullScreen = FALSE;
	wIcon = Icon;
	wSmIcon = SmIcon;

	p_disp = new T_Display();

	for (int i = 0; i < 256; i++)
	{
		keys[i] = false;
	}

	//�����ڴ滺���豸���ڴ滺��λͼ
	bufferDC = CreateCompatibleDC(GetDC(m_hWnd));
	bufferBitmap = CreateCompatibleBitmap(GetDC(m_hWnd), wndWidth, wndHeight);
	SelectObject(bufferDC, bufferBitmap);

	// ��䴰�ڱ���ɫ(����: 2019-09-28)
	RECT    rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = wndWidth;
	rect.bottom = wndHeight;
	HBRUSH hBrush;
	hBrush = CreateSolidBrush(bkColor);
	FillRect(bufferDC, &rect, hBrush);
	DeleteObject(hBrush);

}

// ��������
T_Engine::~T_Engine()
{
	delete p_disp;
	//�ر�GDI+
	Gdiplus::GdiplusShutdown(ptrGdiplusToken);
}

// ����: 2019-10-11(�ı仺��λͼ����ɫ)
void T_Engine::SetBackColor(COLORREF bkcolor)
{
	RECT    rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = wndWidth;
	rect.bottom = wndHeight;
	HBRUSH hBrush;
	hBrush = CreateSolidBrush(bkcolor);
	FillRect(bufferDC, &rect, hBrush);
	DeleteObject(hBrush);
}

// �ص�����
LRESULT CALLBACK T_Engine::WndProc(HWND hWnd, UINT msg,
	WPARAM wParam, LPARAM lParam)
{
	// ֻ�������е���Ϣ������
	return pEngine->GameEvent(hWnd, msg, wParam, lParam);
}

// ��Ϸ���ڳ�ʼ������
BOOL T_Engine::GameWinInit()
{
	WNDCLASSEX gamewin;
	gamewin.cbSize = sizeof(WNDCLASSEX);
	gamewin.style = CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;
	gamewin.lpfnWndProc = WndProc;
	gamewin.cbClsExtra = 0;
	gamewin.cbWndExtra = 0;
	gamewin.hInstance = m_hInstance;
	gamewin.hIcon = LoadIcon(m_hInstance, MAKEINTRESOURCE(wIcon));
	gamewin.hCursor = LoadCursor(NULL, IDC_ARROW);
	gamewin.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	gamewin.lpszMenuName = NULL;
	gamewin.lpszClassName = wndClass;
	gamewin.hIconSm = LoadIcon(m_hInstance, MAKEINTRESOURCE(wSmIcon));

	if (!RegisterClassEx(&gamewin)) return FALSE;

	// ʹ���ھ���,��ȡ�ͻ���ȫ��Ļ���(ȥ���������߶�)
	// ���Ҫ��ȡ��ȫȫ��Ļ���,�����������߶�,ʹ��SM_CXSCREEN��SM_CYSCREEN
	scrnWidth = GetSystemMetrics(SM_CXFULLSCREEN);	// ��Ļ���    
	scrnHeight = GetSystemMetrics(SM_CYFULLSCREEN);	// ��Ļ�߶�(ȥ���������߶�)
	int x = (scrnWidth - wndWidth) / 2;
	int y = (scrnHeight - wndHeight) / 2;

	// �����ڰ���ָ���ͻ����ĳߴ���е���(����: 2019-09-28)
	RECT ClientRegion = { 0, 0, wndWidth, wndHeight };
	AdjustWindowRect(&ClientRegion, WS_OVERLAPPEDWINDOW, FALSE);

	m_hWnd = CreateWindow(wndClass, wndTitle,
		WS_OVERLAPPEDWINDOW & ~WS_SIZEBOX,	// ��ֹ������С
		x, y, ClientRegion.right - ClientRegion.left, ClientRegion.bottom - ClientRegion.top,	// ����: 2019-09-28
		NULL, NULL, m_hInstance, NULL);

	if (!m_hWnd) return FALSE;

	// �����ȫ��Ļ��ʾ
	if (m_bFullScreen == TRUE)
	{
		GetWindowRect(m_hWnd, &m_rcOld);//��ס��ǰ���ڵĳߴ�
		style = GetWindowLong(m_hWnd, GWL_STYLE);
		ex_style = GetWindowLong(m_hWnd, GWL_EXSTYLE);
		p_disp->SaveMode();
		//ȫ��Ļ��ʾ
		HWND hDesktop;
		RECT rc;
		hDesktop = GetDesktopWindow();	//��ȡ���洰�ڵ�ָ��  
		GetWindowRect(hDesktop, &rc);	//�õ����洰�ڵľ���
		p_disp->ChangeMode(wndWidth, wndHeight);
		// ����ΪWS_DLGFRAME��WS_BORDER��
		// WS_EX_CLIENTEDGE������ȥ��������
		// ������չ���ΪWS_EX_WINDOWEDGE��ȥ�����ڱ߿�
		SetWindowLong(m_hWnd, GWL_EXSTYLE, WS_EX_WINDOWEDGE);
		SetWindowLong(m_hWnd, GWL_STYLE, WS_BORDER);
		SetWindowPos(m_hWnd, HWND_TOP, -1, -1,
			rc.right, rc.bottom, SWP_SHOWWINDOW);
	}

	ShowWindow(m_hWnd, SW_NORMAL);
	UpdateWindow(m_hWnd);
	return TRUE;
}

// ���Ӱ�����Ϊ����(�˴�����ESC��)
void T_Engine::SubKeyAction(WPARAM wParam)
{
	int x, y;
	if (wParam == VK_ESCAPE)//����ESC��
	{
		m_bFullScreen = !m_bFullScreen; // ����ȫ����ʾ��־
		//�ָ�����ģʽ
		if (!m_bFullScreen)
		{
			p_disp->ResetMode();
			SetWindowLong(m_hWnd, GWL_STYLE, style);
			SetWindowLong(m_hWnd, GWL_EXSTYLE, ex_style);
			int oldWidth = m_rcOld.right - m_rcOld.left;
			int oldHeight = m_rcOld.bottom - m_rcOld.top;
			x = m_rcOld.left;
			y = m_rcOld.top;
			SetWindowPos(m_hWnd, HWND_NOTOPMOST, x, y,
				oldWidth, oldHeight, SWP_SHOWWINDOW);
		}
		else //��ʾ�˳�����Ի���
		{
			//��ʾ���
			ShowCursor(true);
			if (IDOK == MessageBox(NULL, L"��ȷ��Ҫ�˳���", wndTitle,
				MB_OKCANCEL | MB_ICONQUESTION))
			{
				DestroyWindow(m_hWnd);
			}
		}
	}
}

//��Ϣ�������������ص���������(������������Ϣ����)
LRESULT T_Engine::GameEvent(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	switch (msg)
	{
	case WM_SETFOCUS:
		SetSleep(FALSE);
		return 0;
	case WM_KILLFOCUS:
		SetSleep(TRUE);
		return 0;
	case WM_CREATE:
		m_hWnd = hWnd;
		GameInit();
		return 0;
	case WM_LBUTTONDOWN: //���������µĴ���
		GameMouseAction(LOWORD(lParam), HIWORD(lParam), MOUSE_LCLICK);
		return 0;
	case WM_MOUSEMOVE: //����ƶ�����
		GameMouseAction(LOWORD(lParam), HIWORD(lParam), MOUSE_MOVE);
		return 0;
	case WM_KEYDOWN: //�������µĴ���

		// ��¼��Ӧ�İ���״̬
		keys[wParam] = true;
		// ִ����Ϸ������Ϊ
		GameKeyAction(KEY_DOWN);
		// ���Ӱ�����Ϊ����
		SubKeyAction(wParam);

		return 0;
	case WM_KEYUP:  //�ͷŰ�������
		keys[wParam] = false;
		GameKeyAction(KEY_UP);
		return 0;
	case WM_NCLBUTTONDBLCLK:  //��ֹ˫�����ڱ�������󻯴��� 
		if (HTCAPTION == wParam)
		{
			return 0;
		}
	case WM_SYSCOMMAND:
		if (wParam == SC_MAXIMIZE)
		{
			m_bFullScreen = !m_bFullScreen; // ����ȫ����ʾ��־
			if (m_bFullScreen)
			{
				GetWindowRect(hWnd, &m_rcOld);//��ס��ǰ���ڵĳߴ�
				style = GetWindowLong(hWnd, GWL_STYLE);
				ex_style = GetWindowLong(hWnd, GWL_EXSTYLE);
				p_disp->SaveMode();
				//ȫ��Ļ��ʾ
				HWND hDesktop;
				RECT rc;
				hDesktop = GetDesktopWindow();	//��ȡ���洰�ڵ�ָ��  
				GetWindowRect(hDesktop, &rc);	//�õ����洰�ڵľ���
				p_disp->ChangeMode(wndWidth, wndHeight);
				// ����ΪWS_DLGFRAME��WS_BORDER��
				//  WS_EX_CLIENTEDGE������ȥ��������
				// ������չ���ΪWS_EX_WINDOWEDGE��ȥ�����ڱ߿�
				SetWindowLong(hWnd, GWL_EXSTYLE, WS_EX_WINDOWEDGE);
				SetWindowLong(hWnd, GWL_STYLE, WS_BORDER);
				SetWindowPos(hWnd, HWND_TOP, -1, -1,
					rc.right, rc.bottom, SWP_SHOWWINDOW);
			}
		}
		else if (wParam == SC_CLOSE)
		{
			if (IDOK == MessageBox(NULL, L"��ȷ��Ҫ�˳���",
				wndTitle, MB_OKCANCEL | MB_ICONQUESTION))
			{
				DestroyWindow(hWnd);
			}
		}
		else
		{
			//����WM_SYSCOMMAND��Ϣ�����ɳ�����Ƶģ�
			//���Ա��뽫����Ϣ����DefWindowProc,��������������Ϣ�޷�����
			return DefWindowProc(hWnd, WM_SYSCOMMAND, wParam, lParam);
		}
		return 0;
	case WM_CLOSE:
		DestroyWindow(hWnd);
		return 0;
	case WM_PAINT: //���ڻ���
		PAINTSTRUCT ps;
		hdc = BeginPaint(hWnd, &ps);
		hdc = bufferDC;
		GamePaint(hdc);
		EndPaint(hWnd, &ps);
		return 0;
	case WM_DESTROY: //��������
		pEngine->GameEnd();  // ��Ϸ��������(����: 2019-09-28)
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

void T_Engine::StartEngine()
{
	MSG msg;
	static int TickElapsed = 0;
	int nowTick;

	GameWinInit();						// ��ʼ����Ϸ����
	srand((unsigned)time(NULL));	// ��ʼ�������

	// ��Ϸ��ѭ��
	while (TRUE)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			// �����⵽WM_QUIT���˳���Ϸѭ��
			if (msg.message == WM_QUIT)
			{
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// ȷ����Ϸû�н���˯��״̬
			if (!GetSleep())
			{
				// �ж���Ϸѭ����ʱ��
				nowTick = GetTickCount();
				if (nowTick > TickElapsed)
				{
					TickElapsed = nowTick + GetInterval();
					//������Ϸ�߼�
					GameLogic();

					/*
					// ԭ����-----------------------------
					//���ڴ��л�������
					GamePaint(bufferDC);
					//��ȡ��Ϸ���ھ������ͼ�豸
					HDC hDC = GetDC(m_hWnd);
					//���ڴ��豸�л��Ƶ����ݻ浽��Ļ��
					BitBlt(hDC, 0, 0, WIN_WIDTH, WIN_HEIGHT,
					bufferDC, 0, 0, SRCCOPY);
					//�ͷ��豸
					ReleaseDC(m_hWnd, hDC);
					// -----------------------------ԭ����
					*/
				}
				// ------------���º�Ĵ�����루���£�2019-10-20��
				//���ڴ��л�������
				GamePaint(bufferDC);
				//��ȡ��Ϸ���ھ������ͼ�豸
				HDC hDC = GetDC(m_hWnd);
				//���ڴ��豸�л��Ƶ����ݻ浽��Ļ��
				BitBlt(hDC, 0, 0, WIN_WIDTH, WIN_HEIGHT, bufferDC, 0, 0, SRCCOPY);
				//�ͷ��豸
				ReleaseDC(m_hWnd, hDC);
				//------------���º�Ĵ�����루���£�2019-10-20��
			}
		}
	}
	//pEngine->GameEnd();  // ��Ϸ��������
}