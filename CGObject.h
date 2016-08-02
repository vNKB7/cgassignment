#ifndef CGOBJECT_H
#define CGOBJECT_H

#include "Vector3.h"
#include "CRay.h"
#include "global.h"

struct Material
{
	Vector3 m_Ka;
	Vector3 m_Kd;
	Vector3 m_Ks;
	Vector3 m_Kr;
	float m_Shininess;
	float m_Reflectivity;
	bool isTransparent;
};

class CGObject
{
public:
	Material material;
	bool individual;//是否逐点定义材质
	//Vector3 m_Ka;
	//Vector3 m_Kd;
	//Vector3 m_Ks;
	//float m_Shininess;
	//float m_Reflectivity;
	//bool isTransparent;
public:
	CGObject();
	CGObject(Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);
	~CGObject();
	virtual Vector3 getNormal(Vector3 _Point) = 0;
	virtual INTERSECTION_TYPE isIntersected(CRay _Ray, float& out_Distance) = 0;
	virtual Material getMaterial(Vector3 _Point) = 0;
};

#endif