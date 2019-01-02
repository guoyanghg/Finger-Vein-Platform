#pragma once


// GatherDlg 对话框
#include "DialogDlg.h"
#include "CvvImage.h"
#include "afxwin.h"
using namespace std;
class GatherDlg : public CDialogEx
{
	DECLARE_DYNAMIC(GatherDlg)

public:
	GatherDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~GatherDlg();
	BOOL m_bImage;
	BOOL m_bClosed;
	CvCapture *capture;
 
    
	HDC hDC;
	CRect rect;
	CDC *pDC;
	IplImage *m_Frame;
	CWnd *pwnd;


// 对话框数据
	enum { IDD = IDD_GATHERDLG };

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	//基础功能键
	afx_msg void OnBnClickedButton5();//返回
	afx_msg void OnBnClickedButton1();//打开摄像头
	afx_msg void OnBnClickedButton2();//关闭摄像头
	afx_msg void myClose();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	//
	afx_msg void OnBnClickedButton7();
	CString address;
	//afx_msg void OnBnClickedButton3();
	CComboBox ImgType;
	CString NUM1;
	CString NUM2;
	CString Type;
	CString SIM;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	void GetMsg();
	CString Message;
	CString modalPath;
	void getPath();
	int getLines();
	int count;
	BOOL EFIN[6];
	CString out;
	void Write();
};
