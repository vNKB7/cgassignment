#ifndef Scene_H
#define Scene_H

#include <vector>
#include "CGObject.h"
#include "CLightSource.h"
#include "CRay.h"


using namespace std;

class Scene
{
public:
	Scene();
	~Scene();
	vector<CGObject *> m_Object; //模型
	vector<CLightSource *> m_LightSource;	//光源
	Vector3 m_Eye; //观察点位置
	Vector3 m_Direction;//观察点面对的方向
	float distance; //观察点与屏幕的方向
	Vector3 window[4];	//观察窗口位置
	float win_Width, win_Height;//观察窗口大小
	int pix_Width, pix_Height;	//设备窗口大小
	vector<Vector3> buffer;	//RGB三色的buffer
	bool isSceneChanged;
	int TotalTraceDepth;
public:
	void test();
	void writePic();
	void initScene();
	Vector3 RayTracing(const CRay& ray, int depth, int sourceObj);
	void writeFrameBuffer();
	int findNearestObject(const CRay& ray, Vector3 &Intersection, int sourceObj);
	void displayScene();
	void computeWindow();
};

#endif