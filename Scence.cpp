#include "Scence.h"
#include "CSphere.h"
#include "CDirectionalLight.h"
#include "CRay.h"
#include "test.h"

Scence::Scence(){}

Scence::~Scence()
{
	if (!m_Object.empty())
	{
		CGObject *tmp = m_Object.back();
		m_Object.pop_back();
		delete tmp;
	}

	if (!m_LightSource.empty())
	{
		CLightSource *tmp = m_LightSource.back();
		m_LightSource.pop_back();
		delete tmp;
	}
}


void Scence::initScence()
{
	m_Object.push_back(new CSphere(Vector3(0, 0, 0), 1, Vector3(1, 1, 1), Vector3(1, 1, 1), Vector3(1, 1, 1), 0.5, 0.5, false));
	m_LightSource.push_back( new CDirectionalLight(Vector3(10, 0, 0), Vector3(1), Vector3(1), Vector3(1), Vector3(-1, 0, 0)));
	m_Eye.set(0, 0, -5);

	window[0].set(-2.5, 2.5, -2.5);
	window[1].set(2.5, 2.5, -2.5);
	window[2].set(2.5, -2.5, -2.5);
	window[3].set(-2.5, -2.5, -2.5);

	win_Width = 5;
	win_Height = 5;

	pix_Width = 400;
	pix_Height = 400;
}

CGObject *Scence::findNearestObject(const CRay& ray)
{
	int objects_numbers = m_Object.size();
	double distance = 1000000; // 初始化无限大距离
	Vector3 Intersection;     // 交点
	for (int i = 0; i<objects_numbers; i++)  // 遍历场景中每一个物体
	{

		CGObject *obj = m_Object[i];
		if (obj->isIntersected(ray, distance) != MISS) // 判断是否有交点
		{
			Intersection = ray.getPoint(distance); //如果相交，求出交点保存到Intersection
		}

	}
}


void Scence::writeFrameBuffer()
{
	Vector3 xRate = (window[1] - window[0]) / pix_Width;
	Vector3 yRate = (window[3] - window[0]) / pix_Height;



	for (int y = 0; y <= pix_Height; y++)
	{
		for (int x = 0; x <= pix_Width; x++)
		{
			Vector3 pos = (window[0] + xRate * x) + (window[0] + yRate * y);
			Vector3 direction = pos - m_Eye;
			CRay ray(m_Eye, direction);

			
		}
	}
}

Vector3 Scence::RayTracing(const CRay& ray, int depth)
{
	return Vector3();
}