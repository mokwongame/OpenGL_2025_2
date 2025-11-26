#pragma once
#include "afxdialogex.h"


// CDlgGameObj 대화 상자

class CDlgGameObj : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgGameObj)

public:
	CDlgGameObj(CWnd* pParent = nullptr);   // 표준 생성자입니다.
	virtual ~CDlgGameObj();

	// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GAMEOBJ };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
