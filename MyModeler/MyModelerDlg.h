﻿
// MyModelerDlg.h: 헤더 파일
//

#pragma once

#include "MyScreen.h"

// CMyModelerDlg 대화 상자
class CMyModelerDlg : public CDialogEx
{
	// 생성입니다.
public:
	CMyModelerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMODELER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


	// 구현입니다.
protected:
	HICON m_hIcon;
	MyScreen m_screen; // OpenGL modeler 역할을 할 스크린 멤버

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CMFCColorButton m_btBackColor;
	CMFCColorButton m_btTriColor;
};
