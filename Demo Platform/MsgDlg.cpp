// MsgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "MsgDlg.h"
#include "afxdialogex.h"


// MsgDlg 对话框

IMPLEMENT_DYNAMIC(MsgDlg, CDialogEx)

MsgDlg::MsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(MsgDlg::IDD, pParent)
	, NAME(_T(""))
	, JOB(_T(""))
{
	msg.fingers[0]=0;
	msg.fingers[1]=0;
	msg.fingers[2]=0;
	msg.fingers[3]=0;
	msg.fingers[4]=0;
	msg.fingers[5]=0;
	msg.quantity[0]=0;
	msg.quantity[1]=0;
	msg.NAME="";
	msg.JOB="";
	msg.NUMBER="";
	getPath();
	msg.NUMBER.Format(_T("%.3d"),getLines()+1);
}

MsgDlg::~MsgDlg()
{
}

void MsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_NAME, NAME);
	DDX_Text(pDX, IDC_JOB, JOB);
	DDX_Text(pDX, IDC_NUM, Pnum);
}


BEGIN_MESSAGE_MAP(MsgDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &MsgDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// MsgDlg 消息处理程序

BOOL MsgDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}
	ModifyStyleEx(0,WS_EX_APPWINDOW);
	SetIcon(m_hIcon, TRUE);			
	SetIcon(m_hIcon, FALSE);	
	SetActiveWindow();
	CButton* radio=(CButton*)GetDlgItem(IDC_NUM1);
	radio->SetCheck(1);
	Pnum=msg.NUMBER;
	UpdateData(FALSE);
	this->RedrawWindow();	
	return TRUE;
}
void MsgDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//GetDlgItem(IDC_NAME)->GetWindowTextW(msg.NAME);
	//GetDlgItem(IDC_JOB)->GetWindowTextW(msg.JOB);

	UpdateData(TRUE);
	if(NAME=="")
	{
		MessageBox(_T("请填写姓名！"));
		return;
	}	
	if(JOB=="")
	{
		MessageBox(_T("请填写职位！"));
		return;
	}
	msg.NAME=NAME;
	msg.JOB=JOB;
	if(GetCheckedRadioButton(IDC_NUM1,IDC_NUM2)==IDC_NUM1)
		msg.quantity[0]=1;
	else
		msg.quantity[0]=0;
	if(GetCheckedRadioButton(IDC_NUM1,IDC_NUM2)==IDC_NUM2)
		msg.quantity[1]=1;
	else
		msg.quantity[1]=0;
	if(IsDlgButtonChecked(IDC_Fin1)==BST_UNCHECKED
		&&IsDlgButtonChecked(IDC_Fin2)==BST_UNCHECKED
		&&IsDlgButtonChecked(IDC_Fin3)==BST_UNCHECKED
		&&IsDlgButtonChecked(IDC_Fin4)==BST_UNCHECKED
		&&IsDlgButtonChecked(IDC_Fin5)==BST_UNCHECKED
		&&IsDlgButtonChecked(IDC_Fin6)==BST_UNCHECKED)
	{
		MessageBox(_T("请至少选择一根手指作为取样指！"));
		return;
	}
	if(IsDlgButtonChecked(IDC_Fin1)==BST_CHECKED)
		msg.fingers[0]=1;
	else
		msg.fingers[0]=0;
	if(IsDlgButtonChecked(IDC_Fin2)==BST_CHECKED)
		msg.fingers[1]=1;
	else
		msg.fingers[1]=0;
	if(IsDlgButtonChecked(IDC_Fin3)==BST_CHECKED)
		msg.fingers[2]=1;
	else
		msg.fingers[2]=0;
	if(IsDlgButtonChecked(IDC_Fin4)==BST_CHECKED)
		msg.fingers[3]=1;
	else
		msg.fingers[3]=0;
	if(IsDlgButtonChecked(IDC_Fin5)==BST_CHECKED)
		msg.fingers[4]=1;
	else
		msg.fingers[4]=0;
	if(IsDlgButtonChecked(IDC_Fin6)==BST_CHECKED)
		msg.fingers[5]=1;
	else
		msg.fingers[5]=0;
	//RegisterDlg *reg;
	//reg=(RegisterDlg*)GetParent();
	//reg->msg=msg;
	CDialogEx::OnOK();
}

void MsgDlg::getPath()
{
		wchar_t fileName[_MAX_FNAME], Dir[_MAX_DIR], Drive[_MAX_DRIVE], Ext[_MAX_EXT], newPath[_MAX_PATH];
	wchar_t* pgmptr;
	_get_wpgmptr(&pgmptr);
	_wsplitpath_s(pgmptr, Drive, Dir, fileName, Ext);

	_wmakepath_s(newPath, Drive, Dir, NULL, NULL);
	modalPath=newPath;
	modalPath+="modal\\";
}
int MsgDlg::getLines()
{
	char buffer[50];
	int n=0;
	ifstream ReadLines;
	ReadLines.open(modalPath+_T("log.txt"),ios::in);
	if(ReadLines.fail())
		return 0;
	else
	{
		while(ReadLines.getline(buffer,50))
			n++;
	}
	ReadLines.close();
	return n;
	
}