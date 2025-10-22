#pragma once
#include <afxwin.h>
#include <GL/glew.h>

class OglScreen :
	public CStatic
{
public:
	static void colorrefToRgb(GLfloat& r, GLfloat& g, GLfloat& b, COLORREF color);

protected:
	HDC m_hDC = NULL;      // OpenGL용 RC를 위한 DC의 핸들(handle)
	HGLRC m_hRC = NULL;    // OpenGL용 RC(rendering context)의 핸들(handle)

	void AdjustPixelFormat(void);
	void StartRC(void);
	void StopRC(void);
	virtual void InitOpenGL(void);
	virtual void RenderScene(void);

public:
	BOOL Create(int nId, CWnd* pParent);
	virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

	DECLARE_MESSAGE_MAP()
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnDestroy();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
};

