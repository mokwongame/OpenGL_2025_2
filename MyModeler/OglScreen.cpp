#include "pch.h"
#include "OglScreen.h"

BOOL OglScreen::Create(LPCTSTR lpszText, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	BOOL bResult = CStatic::Create(lpszText, dwStyle, rect, pParentWnd, nID);
	return bResult;
}

BEGIN_MESSAGE_MAP(OglScreen, CStatic)
	ON_WM_CREATE()
END_MESSAGE_MAP()

int OglScreen::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CStatic::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.

	return 0;
}
