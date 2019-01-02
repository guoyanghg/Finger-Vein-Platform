#include "stdafx.h"
#include "ImageProcess.h"


ImageProcess::ImageProcess(void)
{

	
	getpath();
	getlines();
	
	while(!(ep=engOpen(NULL)));
	engSetVisible(ep,TRUE);
}


ImageProcess::~ImageProcess(void)
{
	

	engClose(ep);
}
mxArray* IplImage2mxArray(IplImage* im)
{
	/*
	将单通道灰度图的IplImage转换为单通道的mxArray，其中申请了内存
	*/
	mwSize m = im->height;
	mwSize n = im->width;
	mxArray* pMat = mxCreateDoubleMatrix(m, n, mxREAL);

	double *pMatPr = (double*)mxGetData(pMat);
	for (int j = 0; j < im->height; j++)
		for (int i = 0; i < im->width; i++)
		{
		pMatPr[i * im->height + j] = CV_IMAGE_ELEM(im, uchar, j, i);
		}
	return pMat;
}
void ImageProcess::Train1(IplImage *img1,IplImage *img2,IplImage *img3,CString path){
	char* temp;


	int n = path.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP,0,path,n,NULL,0,NULL,NULL);//按Byte计算str长度
	temp = new char[len+1];//按字节为单位
	WideCharToMultiByte(CP_ACP,0,path,n,temp,len,NULL,NULL);//宽字节转换为多字节编码
	temp[len] = '\0';
	mxArray *str=NULL;
	str=mxCreateString(temp);
	engEvalString(ep,codePath);
	//if(msg.quantity[0]==1){
		mxArray *shuru1=IplImage2mxArray(img1);
		mxArray* shuru2=IplImage2mxArray(img2);
		mxArray *shuru3=IplImage2mxArray(img3);

		engPutVariable(ep,"shuru1",shuru1);
		engPutVariable(ep,"shuru2",shuru2);
		engPutVariable(ep,"shuru3",shuru3);
		engPutVariable(ep,"path",str);

		engEvalString(ep,"trainning1(shuru1,shuru2,shuru3,path)");

		mxDestroyArray(shuru1);
		mxDestroyArray(shuru2);
		mxDestroyArray(shuru3);

	//}
	delete []temp;

};
void ImageProcess::max_cur1(IplImage *img1,IplImage *img2,IplImage *img3,CString path){

	char* temp;
	int n = path.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP,0,path,n,NULL,0,NULL,NULL);//按Byte计算str长度
	temp = new char[len+1];//按字节为单位
	WideCharToMultiByte(CP_ACP,0,path,n,temp,len,NULL,NULL);//宽字节转换为多字节编码
	temp[len] = '\0';
	mxArray *str=NULL;
	str=mxCreateString(temp);
	engEvalString(ep,codePath);
	//if(msg.quantity[0]==1){
		mxArray *shuru1=IplImage2mxArray(img1);
		mxArray* shuru2=IplImage2mxArray(img2);
		mxArray *shuru3=IplImage2mxArray(img3);

		engPutVariable(ep,"shuru1",shuru1);
		engPutVariable(ep,"shuru2",shuru2);
		engPutVariable(ep,"shuru3",shuru3);
		engPutVariable(ep,"path",str);
		engEvalString(ep,"max_cur_get_temp1(shuru1,shuru2,shuru3,path)");
		delete []temp;
}
void ImageProcess::Train2(IplImage *img1,IplImage *img2,IplImage *img3,IplImage *img4,IplImage *img5,IplImage *img6,CString path){

	char* temp;


	int n = path.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP,0,path,n,NULL,0,NULL,NULL);//按Byte计算str长度
	temp = new char[len+1];//按字节为单位
	WideCharToMultiByte(CP_ACP,0,path,n,temp,len,NULL,NULL);//宽字节转换为多字节编码
	temp[len] = '\0';
	mxArray *str=NULL;
	str=mxCreateString(temp);
	engEvalString(ep,codePath);

	mxArray *shuru1=IplImage2mxArray(img1);
	mxArray* shuru2=IplImage2mxArray(img2);
	mxArray *shuru3=IplImage2mxArray(img3);
	mxArray *shuru4=IplImage2mxArray(img4);
	mxArray* shuru5=IplImage2mxArray(img5);
	mxArray *shuru6=IplImage2mxArray(img6);

	engPutVariable(ep,"shuru1",shuru1);
	engPutVariable(ep,"shuru2",shuru2);
	engPutVariable(ep,"shuru3",shuru3);
	engPutVariable(ep,"shuru4",shuru4);
	engPutVariable(ep,"shuru5",shuru5);
	engPutVariable(ep,"shuru6",shuru6);
	engPutVariable(ep,"path",str);

	engEvalString(ep,"trainning2(shuru1,shuru2,shuru3,shuru4,shuru5,shuru6,path)");

	mxDestroyArray(shuru1);
	mxDestroyArray(shuru2);
	mxDestroyArray(shuru3);
	mxDestroyArray(shuru4);
	mxDestroyArray(shuru5);
	mxDestroyArray(shuru6);

	//}
	delete []temp;
}
void ImageProcess::max_cur2(IplImage *img1,IplImage *img2,IplImage *img3,IplImage *img4,IplImage *img5,IplImage *img6,CString path){
	
	char* temp;


	int n = path.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP,0,path,n,NULL,0,NULL,NULL);//按Byte计算str长度
	temp = new char[len+1];//按字节为单位
	WideCharToMultiByte(CP_ACP,0,path,n,temp,len,NULL,NULL);//宽字节转换为多字节编码
	temp[len] = '\0';
	mxArray *str=NULL;
	str=mxCreateString(temp);
	engEvalString(ep,codePath);

	mxArray *shuru1=IplImage2mxArray(img1);
	mxArray* shuru2=IplImage2mxArray(img2);
	mxArray *shuru3=IplImage2mxArray(img3);
	mxArray *shuru4=IplImage2mxArray(img4);
	mxArray* shuru5=IplImage2mxArray(img5);
	mxArray *shuru6=IplImage2mxArray(img6);

	engPutVariable(ep,"shuru1",shuru1);
	engPutVariable(ep,"shuru2",shuru2);
	engPutVariable(ep,"shuru3",shuru3);
	engPutVariable(ep,"shuru4",shuru4);
	engPutVariable(ep,"shuru5",shuru5);
	engPutVariable(ep,"shuru6",shuru6);
	engPutVariable(ep,"path",str);
	engEvalString(ep,"max_cur_get_temp2(shuru1,shuru2,shuru3,shuru4,shuru5,shuru6,path)");
	delete []temp;


}
void ImageProcess::getMsg(){

	CStdioFile f;
	int count=1;
	CString logp=modalPath+"log.txt";
	char* old_locale = _strdup( setlocale(LC_CTYPE,NULL) );
	setlocale( LC_CTYPE, "chs" );//设定<ctpye.h>中字符处理方式

	if(f.Open(logp,CFile::modeRead)==TRUE)
	while(f.ReadString(Pmsg[count])){
		count++;
	}

	f.Close();
	setlocale( LC_CTYPE, old_locale );
	free( old_locale );//还原区域设定


}
void ImageProcess::matchevery(IplImage *img){
	//guiyihua(img);
	//getLBP();
	//getMsg();

	//for(int i=1;i<=PNUM;i++){
	//	
	//	if(Pmsg[i].Mid(7,1)=="1")
	//	{
	//		CString name;
	//		name=Pmsg[i].Mid(0,3);
	//		name+="_1.mat";
	//		name=modalPath+name;
	//		score[i][0]=match1(name);
	//	}
	//	if(Pmsg[i].Mid(8,1)=="1")
	//	{
	//		CString name;
	//		name=Pmsg[i].Mid(0,3);
	//		name+="_2.mat";
	//		name=modalPath+name;
	//		score[i][1]=match1(name);
	//	}
	//	if(Pmsg[i].Mid(9,1)=="1")
	//	{
	//		CString name;
	//		name=Pmsg[i].Mid(0,3);
	//		name+="_3.mat";
	//		name=modalPath+name;
	//		score[i][2]=match1(name);
	//	}
	//	if(Pmsg[i].Mid(10,1)=="1")
	//	{
	//		CString name;
	//		name=Pmsg[i].Mid(0,3);
	//		name+="_4.mat";
	//		name=modalPath+name;
	//		score[i][3]=match1(name);
	//	}
	//	if(Pmsg[i].Mid(11,1)=="1")
	//	{
	//		CString name;
	//		name=Pmsg[i].Mid(0,3);
	//		name+="_5.mat";
	//		name=modalPath+name;
	//		score[i][4]=match1(name);
	//	}	
	//	if(Pmsg[i].Mid(12,1)=="1")
	//	{
	//		CString name;
	//		name=Pmsg[i].Mid(0,3);
	//		name+="_6.mat";
	//		name=modalPath+name;
	//		score[i][5]=match1(name);
	//	}	
	//	position[i][0]=1;
	//	position[i][1]=2;
	//	position[i][2]=3;
	//	position[i][3]=4;
	//	position[i][4]=5;
	//	position[i][5]=6;
	//}

	getMsg();

	for(int i=1;i<=PNUM;i++){
		
		if(Pmsg[i].Mid(7,1)=="1")
		{
			CString name;
			name=Pmsg[i].Mid(0,3);
			name+="_1.mat";
			name=modalPath+name;
			score[i][0]=match2(img,name);
		}
		if(Pmsg[i].Mid(8,1)=="1")
		{
			CString name;
			name=Pmsg[i].Mid(0,3);
			name+="_2.mat";
			name=modalPath+name;
			score[i][1]=match2(img,name);
		}
		if(Pmsg[i].Mid(9,1)=="1")
		{
			CString name;
			name=Pmsg[i].Mid(0,3);
			name+="_3.mat";
			name=modalPath+name;
			score[i][2]=match2(img,name);
		}
		if(Pmsg[i].Mid(10,1)=="1")
		{
			CString name;
			name=Pmsg[i].Mid(0,3);
			name+="_4.mat";
			name=modalPath+name;
			score[i][3]=match2(img,name);
		}
		if(Pmsg[i].Mid(11,1)=="1")
		{
			CString name;
			name=Pmsg[i].Mid(0,3);
			name+="_5.mat";
			name=modalPath+name;
			score[i][4]=match2(img,name);
		}	
		if(Pmsg[i].Mid(12,1)=="1")
		{
			CString name;
			name=Pmsg[i].Mid(0,3);
			name+="_6.mat";
			name=modalPath+name;
			score[i][5]=match2(img,name);
		}	
		position[i][0]=1;
		position[i][1]=2;
		position[i][2]=3;
		position[i][3]=4;
		position[i][4]=5;
		position[i][5]=6;
	}
	Sort();
	Select();
}
void ImageProcess:: getLBP(){

	engEvalString(ep,codePath);
	engPutVariable(ep,"shuru",lbp);
	engEvalString(ep,"shuchu=getlbp(shuru)");
	mxDestroyArray(lbp);
	lbp=engGetVariable(ep,"shuchu");

}

double ImageProcess::match1(CString name){
	char *temp;
	int n = name.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP,0,name,n,NULL,0,NULL,NULL);//按Byte计算str长度
	temp = new char[len+1];//按字节为单位
	WideCharToMultiByte(CP_ACP,0,name,n,temp,len,NULL,NULL);//宽字节转换为多字节编码
	temp[len] = '\0';

	mxArray *Name=NULL;
	Name=mxCreateString(temp);
	engEvalString(ep,codePath);

	engPutVariable(ep,"lbp",lbp);
	engPutVariable(ep,"name",Name);

	engEvalString(ep,"score=match(lbp,name)");
	mxArray* shuchu=engGetVariable(ep,"score");
	double Score = ((double*)mxGetPr(shuchu))[0];
	mxDestroyArray(shuchu);
	mxDestroyArray(Name);
	delete []temp;
	return Score;
}
double ImageProcess::match2(IplImage* img,CString name){
	char *temp;
	int n = name.GetLength(); //按字符计算，str的长度
	int len = WideCharToMultiByte(CP_ACP,0,name,n,NULL,0,NULL,NULL);//按Byte计算str长度
	temp = new char[len+1];//按字节为单位
	WideCharToMultiByte(CP_ACP,0,name,n,temp,len,NULL,NULL);//宽字节转换为多字节编码
	temp[len] = '\0';

	mxArray *Name=NULL;
	Name=mxCreateString(temp);
	engEvalString(ep,codePath);
	mxArray *shuru= IplImage2mxArray(img);
	engPutVariable(ep,"name",Name);
	engPutVariable(ep,"shuru",shuru);
	engEvalString(ep,"[shuchu]=max_cur_match_work(shuru,name)");
	mxArray* shuchu=engGetVariable(ep,"shuchu");
	double Score = ((double*)mxGetPr(shuchu))[0];
	mxDestroyArray(shuchu);
	mxDestroyArray(Name);
	delete []temp;
	return Score;

}

void ImageProcess:: getlines(){

	char buffer[50];
	int n=0;
	ifstream ReadLines;
	ReadLines.open(modalPath+_T("log.txt"),ios::in);
	if(ReadLines.fail())
		return;
	else
	{
		while(ReadLines.getline(buffer,50))
			n++;
	}
	ReadLines.close();
	PNUM=n;

}

void ImageProcess::getpath(){
	wchar_t fileName[_MAX_FNAME], Dir[_MAX_DIR], Drive[_MAX_DRIVE], Ext[_MAX_EXT], newPath[_MAX_PATH];
	wchar_t* pgmptr;
	_get_wpgmptr(&pgmptr);
	_wsplitpath_s(pgmptr, Drive, Dir, fileName, Ext);

	_wmakepath_s(newPath, Drive, Dir, NULL, NULL);
	modalPath=newPath;
	modalPath+="modal\\";
	CString codepath=newPath;
	codepath+=_T("code\\\'");
	codepath=_T("cd \'")+codepath;
	
	int n=codepath.GetLength();
	int len=WideCharToMultiByte(CP_ACP,0,codepath,n,NULL,0,NULL,NULL);
	codePath=new char[len+1];
	WideCharToMultiByte(CP_ACP,0,codepath,n,codePath,len,NULL,NULL);
	codePath[len]='\0';

}

void ImageProcess::Sort(){
	for(int p=1;p<=PNUM;p++){
		for (int i = 0; i <= 5; i++)
		{
			for (int j = i+1; j <= 5; j++)
			{
				if (score[p][i]<score[p][j])
				{
					Swap(p,i,j);
				}
			}
		}
	}
}

void ImageProcess::Swap(int p,int i,int j){
	
	double temp=score[p][i];
	score[p][i]=score[p][j];
	score[p][j]=temp;
	int x=position[p][i];
	position[p][i]=position[p][j];
	position[p][j]=x;

}

void ImageProcess::guiyihua(IplImage *img){
	/*
	对图像进行归一化。输入图像返回IplImage指针
	*/
	mxArray *shuru=IplImage2mxArray(img);
	engEvalString(ep, codePath);

	engPutVariable(ep, "shuru", shuru);
	
	
	engEvalString(ep, "[shuchu]=guiyihua(shuru)");
	if(lbp!=NULL)
		mxDestroyArray(lbp);
	lbp = engGetVariable(ep, "shuchu");
	
	//output = mx_to_IplImage(shuchu);
	//output = mx2Ipl(shuchu);
	//engClose(ep);
	mxDestroyArray(shuru);
}
void ImageProcess::Select(){
	double sco=0;
	for (int i =1; i <=PNUM; i++)
	{
		if(score[i][0]>=sco){
			person[1]=position[i][0];
			sco=score[i][0];
			person[0]=i;
		}
	}
}