// RegisterDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "RegisterDlg.h"
#include "afxdialogex.h"


// RegisterDlg 对话框

IMPLEMENT_DYNAMIC(RegisterDlg, CDialogEx)

RegisterDlg::RegisterDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(RegisterDlg::IDD, pParent)
	,m_Frame(NULL)
	,m_bImage(false)
	,m_bClosed(false)
	,counter(-1)
	,finNum(0)
	, Message(_T("注册信息\r\n"))
	,imgcounter(0)
{
	finImg1[0]=NULL;
	finImg1[1]=NULL;
	finImg1[2]=NULL;

	finImg2[0]=NULL;
	finImg2[1]=NULL;
	finImg2[2]=NULL;
	finImg2[3]=NULL;
	finImg2[4]=NULL;
	finImg2[5]=NULL;

	EFin[0]=FALSE;
	EFin[1]=FALSE;
	EFin[2]=FALSE;
	EFin[3]=FALSE;
	EFin[4]=FALSE;
	EFin[5]=FALSE;

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


	setlocale(LC_ALL,"chinese");
	getPath();
}

RegisterDlg::~RegisterDlg()
{
	if(m_bClosed)
	{
		cvReleaseCapture(&capture);
		m_bImage=FALSE;
		m_bClosed=FALSE;
		CString str;
	 }
}

void RegisterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MSG, Message);
}


BEGIN_MESSAGE_MAP(RegisterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &RegisterDlg::OnBnClickedButton3)
	ON_MESSAGE_VOID(WM_CLOSE,myClose)
	ON_BN_CLICKED(IDC_BUTTON6, &RegisterDlg::OnBnClickedButton6)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BUTTON4, &RegisterDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &RegisterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &RegisterDlg::OnBnClickedButton1)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_BUTTON5, &RegisterDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// RegisterDlg 消息处理程序


void RegisterDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_bImage)
	{
	capture=cvCaptureFromCAM(1);
	MessageBox(_T("摄像头打开成功"));
	m_bClosed=TRUE;
	}
	if(m_bImage)
	{
		
		MessageBox(_T(""));
		return;
	}
	m_Frame=cvQueryFrame(capture);
	if(!m_Frame)
	{
		return;
	}
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame,1);
	m_CvvImage.DrawToHDC(hDC,&rect);
	SetTimer(1,1,NULL);
}

void RegisterDlg::myClose()
{
        //AfxMessageBox("exit");
        //ExitProcess(-1);
        

        //if(::MessageBox(NULL,_T( "Save the current interface before exit？"),_T("Program Exit"), MB_YESNO) == IDYES)
        //
                //可以做一些保存数据的动作
	if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
	CDialogDlg *pDlg;
	pDlg=(CDialogDlg*)GetParent();
	pDlg->DisplayWindow(TRUE);
    this->OnClose();
	}else{
		MessageBox(_T("请先完成取样！"));
		return;
	}
}

void RegisterDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogDlg *pDlg;
	pDlg=(CDialogDlg*)GetParent();
	pDlg->DisplayWindow(TRUE);
	CDialog::OnOK();
}


BOOL RegisterDlg::OnInitDialog()
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

	



	// ÉèÖÃ´Ë¶Ô»°¿òµÄÍ¼±ê¡£µ±Ó¦ÓÃ³ÌÐòÖ÷´°¿Ú²»ÊÇ¶Ô»°¿òÊ±£¬¿ò¼Ü½«×Ô¶¯
	//  Ö´ÐÐ´Ë²Ù×÷
	SetIcon(m_hIcon, TRUE);			// ÉèÖÃ´óÍ¼±ê
	SetIcon(m_hIcon, FALSE);		// ÉèÖÃÐ¡Í¼±ê

	// TODO: ÔÚ´ËÌí¼Ó¶îÍâµÄ³õÊ¼»¯´úÂë
 
	pwnd=GetDlgItem(IDC_PIC);
	pDC=pwnd->GetDC();
	hDC=pDC->GetSafeHdc();
	pwnd->GetClientRect(&rect);
	return TRUE;  // ³ý·Ç½«½¹µãÉèÖÃµ½¿Ø¼þ£¬·ñÔò·µ»Ø TRUE

}

void RegisterDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ÔÚ´ËÌí¼ÓÏûÏ¢´¦Àí³ÌÐò´úÂëºÍ/»òµ÷ÓÃÄ¬ÈÏÖµ
	m_Frame=cvQueryFrame(capture);
	CvvImage m_CvvImage;
	m_CvvImage.CopyOf(m_Frame,3);
	m_CvvImage.DrawToHDC(hDC,&rect);

	CDialogEx::OnTimer(nIDEvent);
}


void RegisterDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(m_bClosed)
	{
		cvReleaseCapture(&capture);
		m_bImage=FALSE;
		m_bClosed=FALSE;
		CString str;
	 }
	MessageBox(_T("摄像头已关闭"));
}


void RegisterDlg::OnBnClickedButton2()
{
	//取样按钮
	// TODO: 在此添加控件通知处理程序代码
	if(msg.NAME=="")
	{
		MessageBox(_T("请先填写注册信息！"));
		return;
	}
	if(!m_bClosed)
	{
		MessageBox(_T("请先开启摄像头！"));
		return;
	}
	if(counter==-1)
	{
		if(IDCANCEL==MessageBox(_T("一旦开始取样注册信息将不得更改\r\n您确定要进行取样吗？"), _T("确认取样"), MB_OKCANCEL | MB_ICONQUESTION))
			return;
		else{
			GetDlgItem(IDC_BUTTON1)->EnableWindow(FALSE);
			GetDlgItem(IDC_BUTTON6)->EnableWindow(FALSE);
			MessageBox(_T("请继续点击取样并根据提示取完足够样本！\r\n若样本不足或质量不高会影响匹配模板，请慎重取图！"));
			WriteMessage();
			counter++;
			Message.Replace(_T("未开始取样。"),_T("正在取样...\r\n"));
			UpdateData(FALSE);
			return;
		}
	}
	IplImage* dst;
	dst=cvCreateImage(cvGetSize(m_Frame),m_Frame->depth,1);
	cvCvtColor(m_Frame,dst,CV_BGR2GRAY);
	
	if(msg.quantity[0]==1)
	{//每指取三张
		if(EFin[0])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<2){
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  右手食指")+a+_T("/3"));
				counter++;
			}else
			{
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  右手食指")+a+_T("/3"));
				//CString name;

				name=modalPath+msg.NUMBER+_T("_1.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
				counter=0;
				EFin[0]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);

					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[1])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<2){
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  右手中指")+a+_T("/3"));
				counter++;
			}else
			{
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  右手中指")+a+_T("/3"));
				name=modalPath+msg.NUMBER+_T("_2.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[1]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[2])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<2){
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  右手无名指")+a+_T("/3"));
				counter++;
			}else
			{
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  右手无名指")+a+_T("/3"));
				name=modalPath+msg.NUMBER+_T("_3.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[2]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){

					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[3])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<2){
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  左手食指")+a+_T("/3"));
				counter++;
			}else
			{
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  左手食指")+a+_T("/3"));
				name=modalPath+msg.NUMBER+_T("_4.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[3]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[4])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<2){
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  左手中指")+a+_T("/3"));
				counter++;
			}else
			{
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  左手中指")+a+_T("/3"));
				name=modalPath+msg.NUMBER+_T("_5.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[4]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[5])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<2){
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  左手无名指")+a+_T("/3"));
				counter++;
			}else
			{
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  左手无名指")+a+_T("/3"));
				name=modalPath+msg.NUMBER+_T("_6.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[5]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
	}
	if(msg.quantity[1]==1){
		if(EFin[0])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<5){
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  右手食指")+a+_T("/6"));
				counter++;
			}else
			{
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  右手食指")+a+_T("/6"));
				//CString name;

				name=modalPath+msg.NUMBER+_T("_1.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);
				counter=0;
				EFin[0]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);

					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[1])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<5){
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  右手中指")+a+_T("/6"));
				counter++;
			}else
			{
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  右手中指")+a+_T("/6"));
				name=modalPath+msg.NUMBER+_T("_2.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[1]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[2])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<5){
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  右手无名指")+a+_T("/6"));
				counter++;
			}else
			{
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  右手无名指")+a+_T("/6"));
				name=modalPath+msg.NUMBER+_T("_3.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[2]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){

					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[3])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<5){
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  左手食指")+a+_T("/6"));
				counter++;
			}else
			{
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  左手食指")+a+_T("/6"));
				name=modalPath+msg.NUMBER+_T("_4.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[3]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[4])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<5){
				finImg1[counter]=dst;
				MessageBox(_T("已取样：  左手中指")+a+_T("/6"));
				counter++;
			}else
			{
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  左手中指")+a+_T("/6"));
				name=modalPath+msg.NUMBER+_T("_5.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[4]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
		if(EFin[5])
		{
			CString a;
			a.Format(_T("%d"),counter+1);
			if(counter<5){
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  左手无名指")+a+_T("/6"));
				counter++;
			}else
			{
				finImg2[counter]=dst;
				MessageBox(_T("已取样：  左手无名指")+a+_T("/6"));
				name=modalPath+msg.NUMBER+_T("_6.mat");

				Message+=_T("正在制作模板，请等待...");
				UpdateData(FALSE);
				GetDlgItem(IDC_BUTTON2)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(FALSE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(FALSE);
				AfxBeginThread((AFX_THREADPROC)TrainThreadProc,this);
				
				while(!Saved(name))
					Sleep(30);
				Message.Replace(_T("正在制作模板，请等待..."),_T(""));
				UpdateData(FALSE);
				MessageBox(_T("模板已保存！"));
				GetDlgItem(IDC_BUTTON2)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON3)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON4)->EnableWindow(TRUE);
				GetDlgItem(IDC_BUTTON5)->EnableWindow(TRUE);;
				counter=0;
				EFin[5]=FALSE;
				if(!EFin[0]&&!EFin[1]&&!EFin[2]&&!EFin[3]&&!EFin[4]&&!EFin[5]){
					MessageBox(_T("取样结束！"));
					Message.Replace(_T("正在取样...\r\n"),_T("取样结束。"));
					UpdateData(FALSE);
					GetDlgItem(IDC_BUTTON1)->EnableWindow(TRUE);
					GetDlgItem(IDC_BUTTON6)->EnableWindow(TRUE);
				}
			}
			return;
		}
	}

}

BOOL RegisterDlg::Saved(CString name){
	fstream out;
	out.open(name,ios::in);
	
	if(!out){

		return FALSE;
	}else{
		out.close();
		return TRUE;

	}
		
}


void RegisterDlg::WriteMessage()
{
	wofstream out;
	out.open(modalPath+_T("log.txt"),ios::app);

	out<<CStringA(msg.NUMBER)<<' '<<msg.quantity[0]<<msg.quantity[1]<<' '<<msg.fingers[0]<<msg.fingers[1]<<msg.fingers[2]<<msg.fingers[3]<<msg.fingers[4]<<msg.fingers[5]<<' '<<CStringA(msg.NAME)<<' '<<CStringA(msg.JOB)<<'\n';

	out.close();
}
void RegisterDlg::getPath()
{
		wchar_t fileName[_MAX_FNAME], Dir[_MAX_DIR], Drive[_MAX_DRIVE], Ext[_MAX_EXT], newPath[_MAX_PATH];
	wchar_t* pgmptr;
	_get_wpgmptr(&pgmptr);
	_wsplitpath_s(pgmptr, Drive, Dir, fileName, Ext);

	_wmakepath_s(newPath, Drive, Dir, NULL, NULL);
	modalPath=newPath;
	modalPath+="modal\\";
	codePath=newPath;
	codePath+="code\\";
	codePath=_T("cd \'")+codePath+_T("\'");
}
void RegisterDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	Message=_T("注册信息\r\n");
	msgdlg.DoModal();
	msg=msgdlg.msg;


	if(msg.NAME!="")
	{
		finNum=msg.fingers[0]+msg.fingers[1]+msg.fingers[2]+
		msg.fingers[3]+msg.fingers[4]+msg.fingers[5];

		Message+=_T("编号：")+msg.NUMBER+_T("\r\n")+
			_T("姓名：")+msg.NAME+_T("\r\n")+
			_T("职位：")+msg.JOB+_T("\r\n");
		if(msg.quantity[0]==1)
			Message+=_T("取样数量：三张\r\n");
		else
			Message+=_T("取样数量：六张\r\n");
		Message+=_T("取样指：\r\n");
		if(msg.fingers[0]+msg.fingers[1]+msg.fingers[2]>0)
			Message+=_T("右手：   ");
		if(msg.fingers[0]==1){
			EFin[0]=TRUE;
			Message+=_T("食指   ");
		}
		if(msg.fingers[1]==1){
			EFin[1]=TRUE;
			Message+=_T("中指   ");}
		if(msg.fingers[2]==1){
			EFin[2]=TRUE;
			Message+=_T("无名指");}
		Message+=_T("\r\n");
		if(msg.fingers[3]+msg.fingers[4]+msg.fingers[5]>0)
			Message+=_T("左手：   ");
		if(msg.fingers[3]==1){
			EFin[3]=TRUE;
			Message+=_T("食指   ");}
		if(msg.fingers[4]==1){
			EFin[4]=TRUE;
			Message+=_T("中指   ");}
		if(msg.fingers[5]==1){
			EFin[5]=TRUE;
			Message+=_T("无名指");}
		Message+=_T("\r\n");
		Message+=_T("未开始取样。");
		UpdateData(FALSE);
	}
		
	
}


HBRUSH RegisterDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	 if (pWnd->GetDlgCtrlID() == IDC_MSG)
     {
         pDC->SetTextColor(RGB(0, 0, 250));
     }
	return hbr;
}

void RegisterDlg::train(CString name){
//	char* temp;
//	char* codepath;
//	CString temppath=modalPath+name;
//	
//	int n = temppath.GetLength(); //按字符计算，str的长度
//	int len = WideCharToMultiByte(CP_ACP,0,temppath,n,NULL,0,NULL,NULL);//按Byte计算str长度
//	temp = new char[len+1];//按字节为单位
//	WideCharToMultiByte(CP_ACP,0,temppath,n,temp,len,NULL,NULL);//宽字节转换为多字节编码
//	temp[len] = '\0';
//	mxArray *path=NULL;
//	path=mxCreateString(temp);
//
//	n=codePath.GetLength();
//	len=WideCharToMultiByte(CP_ACP,0,codePath,n,NULL,0,NULL,NULL);
//	codepath=new char[len+1];
//	WideCharToMultiByte(CP_ACP,0,codePath,n,codepath,len,NULL,NULL);
//	codepath[len]='\0';
//	engEvalString(ep,codepath);
//
//	if(msg.quantity[0]==1){
//		mxArray *shuru1=IplImage2mxArray(finImg1[0]);
//		mxArray* shuru2=IplImage2mxArray(finImg1[1]);
//		mxArray *shuru3=IplImage2mxArray(finImg1[2]);
//
//		engPutVariable(ep,"shuru1",shuru1);
//		engPutVariable(ep,"shuru2",shuru2);
//		engPutVariable(ep,"shuru3",shuru3);
//		engPutVariable(ep,"path",path);
//
//		engEvalString(ep,"trainning1(shuru1,shuru2,shuru3,path)");
//
//		mxDestroyArray(shuru1);
//		mxDestroyArray(shuru2);
//		mxDestroyArray(shuru3);
//
//	}
//	delete []temp;
//	delete []codepath;
}
UINT TrainThreadProc(LPVOID lpParam)
{
	RegisterDlg *pRDLG=(RegisterDlg*)lpParam;
	if (pRDLG == NULL ||
        !pRDLG->IsKindOf(RUNTIME_CLASS(RegisterDlg)))
    return 1;
	ImageProcess imp;
	if(pRDLG->msg.quantity[0]==1)
		//imp.Train1(pRDLG->finImg1[0],pRDLG->finImg1[1],pRDLG->finImg1[2],pRDLG->name);
		imp.max_cur1(pRDLG->finImg1[0],pRDLG->finImg1[1],pRDLG->finImg1[2],pRDLG->name);
	else
		//imp.Train2(pRDLG->finImg2[0],pRDLG->finImg2[1],pRDLG->finImg2[2],pRDLG->finImg2[3],pRDLG->finImg2[4],pRDLG->finImg2[5],pRDLG->name);
		imp.max_cur2(pRDLG->finImg2[0],pRDLG->finImg2[1],pRDLG->finImg2[2],pRDLG->finImg2[3],pRDLG->finImg2[4],pRDLG->finImg2[5],pRDLG->name);
	return 0;
}



void RegisterDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(_T("1、修改注册信息\r\n2、打开摄像头\r\n3、点击取样开始取样\r\n4、取样结束后返回"));
}
