#pragma once



// PBBMThread

class PBBMThread : public CWinThread
{
	DECLARE_DYNCREATE(PBBMThread)

protected:
	PBBMThread();           // 动态创建所使用的受保护的构造函数
	virtual ~PBBMThread();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


