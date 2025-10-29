#include "pch.h"
#include "OglScreen.h"
#include <GL/GLU.h>

void OglScreen::colorrefToRgb(GLfloat& r, GLfloat& g, GLfloat& b, COLORREF color)
{
	// OpenGL ���� ����: 0~1, COLORREF ���� ����: 0~255
	r = GetRValue(color) / GLfloat(255);
	g = GetGValue(color) / GLfloat(255);
	b = GetBValue(color) / GLfloat(255);
}

void OglScreen::SetViewport(void)
{
	// viewport ����
	CRect rect;
	GetClientRect(rect);
	int range = __min(rect.Width(), rect.Height());
	int diff = abs(rect.Width() - rect.Height());
	if (rect.Width() >= rect.Height()) glViewport(diff / 2, 0, range, range); // ���ΰ� �� ���
	else glViewport(0, diff / 2, range, range); // ���ΰ� �� ���

	// ���� ���
	GLdouble ranHalf = range / 2.;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// ranHalf - (-ranHalf) = range
	glOrtho(-ranHalf, ranHalf, -ranHalf, ranHalf, -ranHalf, ranHalf);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

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

	// OpenGL �ڵ�
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE); // Ư�� ��(face)�� ���½�Ű��(cull)�� �����ϰ�(enable)
	glFrontFace(GL_CCW); // ����(front face)�� ���� ���͸� �ݽð�(CCW) �������� ����
	glCullFace(GL_BACK); // �޸�(back face)�� ���½�Ű��(cull)

	StopRC();
}

void OglScreen::RenderScene(void)
{
}

BOOL OglScreen::Create(int nId, CWnd* pParent)
{
	CWnd* pWnd = pParent->GetDlgItem(nId);
	pWnd->ShowWindow(SW_HIDE);
	CRect rect;
	pWnd->GetWindowRect(rect); // ��ũ��(����) ��ǥ�踦 �������� ���� pWnd�� �簢�� ���� ���
	pParent->ScreenToClient(rect); // ��ũ�� ��ǥ�� -> dialog�� client ��ǥ��� ��ȯ
	return Create(NULL, WS_CHILD | WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN, rect, pParent); // ��ũ�� ����
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
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

int OglScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	//m_hDC = ::GetDC(m_hWnd); // m_hWnd: ���� window�� �ڵ�
	m_hDC = ::GetDC(GetSafeHwnd()); // ������ window �ڵ� ���
	AdjustPixelFormat();
	m_hRC = ::wglCreateContext(m_hDC);
	InitOpenGL();

	return 0;
}

void OglScreen::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	// �׸��� �޽����� ���ؼ��� CStatic::OnPaint()��(��) ȣ������ ���ʽÿ�.
	StartRC();

	// OpenGL �ڵ�
	RenderScene();

	::SwapBuffers(m_hDC); // double buffer ������ �ʿ�
	StopRC();
}

void OglScreen::OnDestroy()
{
	CStatic::OnDestroy();

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	StopRC();
	::wglDeleteContext(m_hRC);
	::ReleaseDC(GetSafeHwnd(), m_hDC);
}

// OpenGL�� ��� ó���ϱ� ������ �ʿ���� �޽��� �ڵ鷯
BOOL OglScreen::OnEraseBkgnd(CDC* pDC)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	return TRUE;
	//return CStatic::OnEraseBkgnd(pDC);
}
