#pragma once
#include "opencv2/opencv.hpp"
#include "Engine.h"
#include <iostream>
#include <fstream>
 using namespace std;
class ImageProcess
{
public:
	ImageProcess(void);
	~ImageProcess(void);

	void Train1(IplImage *img1,IplImage *img2,IplImage *img3,CString path);
	void Train2(IplImage *img1,IplImage *img2,IplImage *img3,IplImage *img4,IplImage *img5,IplImage *img6,CString path);
	void max_cur1(IplImage *img1,IplImage *img2,IplImage *img3,CString path);
	void max_cur2(IplImage *img1,IplImage *img2,IplImage *img3,IplImage *img4,IplImage *img5,IplImage *img6,CString path);
	void getLBP();
	double match1(CString name);
	double match2(IplImage* img,CString name);
	void getlines();
	void getpath();
	void matchevery(IplImage *img);
	void Sort();
	void Swap(int p,int i,int j);
	void getMsg();
	void guiyihua(IplImage *img);
	CString modalPath;
	char * codePath;
	Engine *ep;
	void Select();
	mxArray *lbp;
	int PNUM;
	int position[1000][6];
	double score[1000][6];
	int person[2];
	CString Pmsg[1000];
};

