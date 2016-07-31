#ifndef Sence_H
#define Sence_H

#include <vector>
#include "CGObject.h"
#include "CLightSource.h"
#include "CRay.h"


using namespace std;

class Scence
{
public:
	Scence();
	~Scence();
	vector<CGObject *> m_Object; //ģ��
	vector<CLightSource *> m_LightSource;	//��Դ
	Vector3 m_Eye; //�۲��λ��
	Vector3 window[4];	//�۲촰��λ��
	double win_Width, win_Height;//�۲촰�ڴ�С
	int pix_Width, pix_Height;	//�豸���ڴ�С
	vector<Vector3> buffer;	//RGB��ɫ��buffer
	bool isSceneChanged;
public:
	void initScence();
	Vector3 RayTracing(const CRay& ray, int depth);
	void writeFrameBuffer();
	CGObject *findNearestObject(const CRay& ray);
}

#endif