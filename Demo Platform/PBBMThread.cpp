// PBBMThread.cpp : 实现文件
//

#include "stdafx.h"
#include "Dialog.h"
#include "PBBMThread.h"


// PBBMThread

IMPLEMENT_DYNCREATE(PBBMThread, CWinThread)

PBBMThread::PBBMThread()
{
}

PBBMThread::~PBBMThread()
{
}

BOOL PBBMThread::InitInstance()
{
	// TODO: 在此执行任意逐线程初始化
	return TRUE;
}

int PBBMThread::ExitInstance()
{
	// TODO: 在此执行任意逐线程清理
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(PBBMThread, CWinThread)
END_MESSAGE_MAP()


// PBBMThread 消息处理程序
