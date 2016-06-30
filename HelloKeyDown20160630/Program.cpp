#include <windows.h>
#include <tchar.h>

#include <sti.h>
#include <gdiplus.h>
using namespace Gdiplus;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
TCHAR szClassNme[] = _T("HelloKeyDown20160630");

GdiplusStartupInput gdiSI;
ULONG_PTR gdiToken;

HWND hWnd;

bool isDownSpaceKey = false;

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPreInst,
                   LPSTR lpszCmdLine, int nCmdShow)
{
	GdiplusStartup(&gdiToken, &gdiSI, NULL);

    //HWND hWnd;
    MSG msg;
    WNDCLASS myProg;
    if (!hPreInst) {
        myProg.style            = CS_HREDRAW | CS_VREDRAW;
        myProg.lpfnWndProc      = WndProc;
        myProg.cbClsExtra       = 0;
        myProg.cbWndExtra       = 0;
        myProg.hInstance        = hInstance;
        myProg.hIcon            = NULL;
        myProg.hCursor          = LoadCursor(NULL, IDC_ARROW);
		myProg.hbrBackground    = (HBRUSH)(COLOR_WINDOW+1);
        myProg.lpszMenuName     = NULL;
        myProg.lpszClassName    = szClassNme;
        if (!RegisterClass(&myProg))
            return FALSE;
    }
    hWnd = CreateWindow(szClassNme,	// class��
		_T("Hello KeyDown"),		// �^�C�g��
        WS_OVERLAPPEDWINDOW,		// Style
        CW_USEDEFAULT,				// X
        CW_USEDEFAULT,				// Y
        CW_USEDEFAULT,				// Width
        CW_USEDEFAULT,				// Height
        NULL,						// �e�E�B���h�E�܂��̓I�[�i�[�E�B���h�E�̃n���h��
        NULL,						// ���j���[�n���h���܂��͎q�E�B���h�E ID
        hInstance,					// �A�v���P�[�V�����C���X�^���X�̃n���h��
        NULL);						// �E�B���h�E�쐬�f�[�^
    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);
	
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

	GdiplusShutdown(gdiToken);

    return (msg.wParam);
}

void OnPaint(HDC hdc)
{
    Graphics g(hdc);
	
	Gdiplus::SolidBrush whiteBrush(Color(255, 255, 255, 255));
	g.FillRectangle(&whiteBrush, 0, 0, 9999, 9999);

    Gdiplus::Pen pen1(Color(255, 255, 0, 0), 5);
	g.DrawRectangle(&pen1, 0, 0, 200, 300);
	
	Gdiplus::Font font(L"�l�r �S�V�b�N", 18);
	Gdiplus::SolidBrush blackBrush(Color(255, 0, 0, 0));
	Gdiplus::StringFormat format;
	format.SetAlignment(StringAlignmentCenter);
	if (isDownSpaceKey) {
		g.DrawString(_T("�悭�ł��܂����I"), -1, &font, RectF(0.0f, 0.0f, 200.0f, 300.0f), &format, &blackBrush);
	}
	else {
		g.DrawString(_T("Space�L�[�������Ă��������B"), -1, &font, RectF(0.0f, 0.0f, 200.0f, 300.0f), &format, &blackBrush);
	}
	
    return;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    HDC hdc;
    PAINTSTRUCT ps;

    switch (msg) {
        case WM_PAINT:
            hdc = BeginPaint(hWnd, &ps);
            OnPaint(hdc);
            EndPaint(hWnd, &ps);
            break;
        case WM_KEYDOWN:
            switch (wParam) 
                case VK_SPACE:
					isDownSpaceKey = true;
					InvalidateRect(hWnd,0,false);
					break;
        case WM_KEYUP:
            switch (wParam)
                case VK_SPACE:
					isDownSpaceKey = false;
					InvalidateRect(hWnd,0,false);
					break;
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return(DefWindowProc(hWnd, msg, wParam, lParam));
    }
    return (0L);
}
