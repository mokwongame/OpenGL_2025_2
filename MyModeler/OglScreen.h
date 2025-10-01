#pragma once
#include <afxwin.h>
class OglScreen :
    public CStatic
{
protected:
    HDC m_hDC;      // OpenGL�� RC�� ���� DC�� �ڵ�(handle)
    HGLRC m_hRC;    // OpenGL�� RC(rendering context)�� �ڵ�(handle)

    void AdjustPixelFormat(void);

public:
    virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();
    afx_msg void OnDestroy();
};

