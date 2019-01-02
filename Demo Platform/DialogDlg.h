
// DialogDlg.h : 头文件
//

#pragma once
#include "RegisterDlg.h"
#include "MatchDlg.h"
#include "GatherDlg.h"
#include "engine.h"

// CDialogDlg 对话框
class CDialogDlg : public CDialogEx
{
// 构造
public:
	CDialogDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CDialogDlg();

	void DisplayWindow( BOOL bShow );
// 对话框数据
	enum { IDD = IDD_DIALOG_DIALOG };



	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
	virtual void OnWindowPosChanging( WINDOWPOS* lpwndpos );


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	BOOL m_Visible;
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
};
