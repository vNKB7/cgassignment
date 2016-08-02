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
	vector<CGObject *> m_Object; //ģ��
	vector<CLightSource *> m_LightSource;	//��Դ
	Vector3 m_Eye; //�۲��λ��
	Vector3 m_Direction;//�۲����Եķ���
	float distance; //�۲������Ļ�ķ���
	Vector3 window[4];	//�۲촰��λ��
	float win_Width, win_Height;//�۲촰�ڴ�С
	int pix_Width, pix_Height;	//�豸���ڴ�С
	vector<Vector3> buffer;	//RGB��ɫ��buffer
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