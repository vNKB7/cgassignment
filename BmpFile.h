#ifndef BMPFILE_H
#define BMPFILE_H

#include <iomanip> 
#include<math.h>
#include <windows.h>
#include "Vector3.h"

class BmpFile
{
public :
	unsigned char *pBmpBuf;//����ͼ�����ݵ�ָ��

	int bmpWidth;//ͼ��Ŀ�
	int bmpHeight;//ͼ��ĸ�
	int lineByte;//ÿ�е�ʵ���ֽ���
	RGBQUAD *pColorTable;//��ɫ��ָ��

	int biBitCount;//ͼ�����ͣ�ÿ����λ��
public:
	BmpFile();
	BmpFile(char *bmpName);
	~BmpFile();
	bool readBmp(char *bmpName);
	bool saveBmp(char *bmpName);
	Vector3 getPixiv(int _x, int _y);
};



#endif