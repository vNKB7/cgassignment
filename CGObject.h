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
	float m_Shininess;
	float m_Reflectivity;
	bool isTransparent;
};

class CGObject
{
public:
	Material material;
	//Vector3 m_Ka;
	//Vector3 m_Kd;
	//Vector3 m_Ks;
	//float m_Shininess;
	//float m_Reflectivity;
	//bool isTransparent;
public:
	CGObject();
	CGObject(Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, float _Shininess, float _Reflectivity, bool _isTransparent);
	~CGObject();
	virtual Vector3 getNormal(Vector3 _Point) = 0;
	virtual INTERSECTION_TYPE isIntersected(CRay _Ray, float& out_Distance) = 0;
	virtual Material getMaterial(Vector3 _Point, bool individual) = 0;
};

#endif