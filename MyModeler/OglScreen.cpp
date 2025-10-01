#include "pch.h"
#include "OglScreen.h"

void OglScreen::AdjustPixelFormat(void)
{
	// ����ü �ʱ�ȭ
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	//m_hDC = ::GetDC(m_hWnd); // m_hWnd: ���� window�� �ڵ�
	m_hDC = ::GetDC(GetSafeHwnd()); // ������ window �ڵ� ���

	return 0;
}

void OglScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
}

void OglScreen::OnDestroy()
{
	CStatic::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	::ReleaseDC(GetSafeHwnd(), m_hDC);
}
