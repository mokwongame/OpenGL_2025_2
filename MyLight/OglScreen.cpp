#include "pch.h"
#include "OglScreen.h"
#include <GL/GLU.h>

void OglScreen::colorrefToRgb(GLfloat& r, GLfloat& g, GLfloat& b, COLORREF color)
{
	// OpenGL 색깔 범위: 0~1, COLORREF 색깔 범위: 0~255
	r = GetRValue(color) / GLfloat(255);
	g = GetGValue(color) / GLfloat(255);
	b = GetBValue(color) / GLfloat(255);
}

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
	int nFormat = ::ChoosePixelFormat(m_hDC, &PFD);
	::SetPixelFormat(m_hDC, nFormat, &PFD);
}

void OglScreen::StartRC(void)
{
	::wglMakeCurrent(m_hDC, m_hRC);
}

void OglScreen::StopRC(void)
{
	::wglMakeCurrent(m_hDC, NULL);
}

void OglScreen::InitOpenGL(void)
{
	StartRC();

	// OpenGL 코드
	glEnable(GL_DEPTH_TEST);

	StopRC();
}

void OglScreen::RenderScene(void)
{
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
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

int OglScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	//m_hDC = ::GetDC(m_hWnd); // m_hWnd: 현재 window의 핸들
	m_hDC = ::GetDC(GetSafeHwnd()); // 안전한 window 핸들 얻기
	AdjustPixelFormat();
	m_hRC = ::wglCreateContext(m_hDC);
	InitOpenGL();

	return 0;
}

void OglScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	// 그리기 메시지에 대해서는 CStatic::OnPaint()을(를) 호출하지 마십시오.
	StartRC();

	// OpenGL 코드
	RenderScene();

	::SwapBuffers(m_hDC); // double buffer 때문에 필요
	StopRC();
}

void OglScreen::OnDestroy()
{
	CStatic::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	StopRC();
	::wglDeleteContext(m_hRC);
	::ReleaseDC(GetSafeHwnd(), m_hDC);
}

// OpenGL이 배경 처리하기 때문에 필요없는 메시지 핸들러
BOOL OglScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	return TRUE;
	//return CStatic::OnEraseBkgnd(pDC);
}
