#pragma once


// MatchDlg 对话框
#include "DialogDlg.h"
#include "CvvImage.h"
#include "ImageProcess.h"
using namespace std;
UINT MatchThreadProc(LPVOID lpParam);
class MatchDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MatchDlg)

public:
	MatchDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MatchDlg();
	BOOL m_bImage;
	BOOL m_bClosed;
	CvCapture *capture;
 
    
	HDC hDC;
	CRect rect;
	CDC *pDC;
	IplImage *m_Frame;
	CWnd *pwnd;

	//匹配数据
	IplImage* dst;
// 对话框数据
	enum { IDD = IDD_MATCHDLG };

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	//基础功能键
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void myClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	//
	afx_msg void OnBnClickedButton3();
};
