#pragma once

#include <iostream>
#include <fstream>
//#include "RegisterDlg.h"
using namespace std;
// MsgDlg 对话框
struct Messages
{
	CString NAME;
	CString JOB;
	CString NUMBER;

	int fingers[6];
	int quantity[2];
	
};
class MsgDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MsgDlg)

public:
	MsgDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~MsgDlg();
	Messages msg;
// 对话框数据
	enum { IDD = IDD_MSGDLG };

protected:
	HICON m_hIcon;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual BOOL OnInitDialog();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	void getPath();
	int getLines();
	CString NAME;
	CString JOB;
		//数据信息
	CString modalPath;
	CString Pnum;
};
