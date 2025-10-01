#include "pch.h"
#include "OglScreen.h"

void OglScreen::AdjustPixelFormat(void)
{
	// 구조체 초기화
	PIXELFORMATDESCRIPTOR PFD = {
sizeof(PIXELFORMATDESCRIPTOR), // size of PFD 
1,                              // version number 
PFD_DRAW_TO_WINDOW |      // support window 
PFD_SUPPORT_OPENGL |         // support OpenGL 
PFD_DOUBLEBUFFER,              // double buffered 
PFD_TYPE_RGBA,           // RGBA type 
32,                             // 32-bit color depth 
0, 0, 0, 0, 0, 0,               // color bits ignored 
0,                               // no alpha buffer 
0,                               // shift bit ignored 
0,                               // no accumulation buffer 
0, 0, 0, 0,                     // accum bits ignored 
32,                             // 32-bit z-buffer     
0,                               // no stencil buffer 
0,                               // no auxiliary buffer 
PFD_MAIN_PLANE,         // Main layer 
0,                               // reserved 
0, 0, 0                         // layer masks ignored 
	};
}

BOOL OglScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
	return bResult;
}

BEGIN_MESSAGE_MAP(OglScreen, CStatic)
	ON_WM_CREATE()
	ON_WM_PAINT()
	ON_WM_DESTROY()
END_MESSAGE_MAP()

int OglScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	//m_hDC = ::GetDC(m_hWnd); // m_hWnd: 현재 window의 핸들
	m_hDC = ::GetDC(GetSafeHwnd()); // 안전한 window 핸들 얻기

	return 0;
}

void OglScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
}

void OglScreen::OnDestroy()
{
	CStatic::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	::ReleaseDC(GetSafeHwnd(), m_hDC);
}
