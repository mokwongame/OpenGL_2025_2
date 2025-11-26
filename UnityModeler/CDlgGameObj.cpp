// CDlgGameObj.cpp: 구현 파일
//

#include "pch.h"
#include "UnityModeler.h"
#include "afxdialogex.h"
#include "CDlgGameObj.h"


// CDlgGameObj 대화 상자

IMPLEMENT_DYNAMIC(CDlgGameObj, CDialogEx)

CDlgGameObj::CDlgGameObj(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GAMEOBJ, pParent)
{

}

CDlgGameObj::~CDlgGameObj()
{
}

void CDlgGameObj::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgGameObj, CDialogEx)
END_MESSAGE_MAP()


// CDlgGameObj 메시지 처리기
