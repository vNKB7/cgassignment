#ifndef BMPFILE_H
#define BMPFILE_H

#include <iomanip> 
#include<math.h>
#include <windows.h>
#include "Vector3.h"

class BmpFile
{
public :
	unsigned char *pBmpBuf;//读入图像数据的指针

	int bmpWidth;//图像的宽
	int bmpHeight;//图像的高
	int lineByte;//每行的实际字节数
	RGBQUAD *pColorTable;//颜色表指针

	int biBitCount;//图像类型，每像素位数
public:
	BmpFile();
	BmpFile(char *bmpName);
	~BmpFile();
	bool readBmp(char *bmpName);
	bool saveBmp(char *bmpName);
	Vector3 getPixiv(int _x, int _y);
};



#endif