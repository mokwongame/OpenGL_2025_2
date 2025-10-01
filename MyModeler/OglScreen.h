#pragma once
#include <afxwin.h>
class OglScreen :
    public CStatic
{
protected:
    HDC m_hDC;      // OpenGL용 RC를 위한 DC의 핸들(handle)
    HGLRC m_hRC;    // OpenGL용 RC(rendering context)의 핸들(handle)

    void AdjustPixelFormat(void);

public:
    virtual BOOL Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID = 0xffff);

    DECLARE_MESSAGE_MAP()
    afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
    afx_msg void OnPaint();
    afx_msg void OnDestroy();
};

