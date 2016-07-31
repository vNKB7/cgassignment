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
	vector<CGObject *> m_Object; //模型
	vector<CLightSource *> m_LightSource;	//光源
	Vector3 m_Eye; //观察点位置
	Vector3 window[4];	//观察窗口位置
	double win_Width, win_Height;//观察窗口大小
	int pix_Width, pix_Height;	//设备窗口大小
	vector<Vector3> buffer;	//RGB三色的buffer
	bool isSceneChanged;
public:
	void initScence();
	Vector3 RayTracing(const CRay& ray, int depth);
	void writeFrameBuffer();
	CGObject *findNearestObject(const CRay& ray);
}

#endif