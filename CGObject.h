#ifndef CGOBJECT_H
#define CGOBJECT_H

#include "Vector3.h"
#include "CRay.h"
#include "global.h"

class CGObject
{
public:
	Vector3 m_Ka;
	Vector3 m_Kd;
	Vector3 m_Ks;
	double m_Shininess;
	double m_Reflectivity;
	bool isTransparent;
public:
	CGObject();
	CGObject(Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, double _Shininess, double _Reflectivity, bool _isTransparent);
	~CGObject();
	virtual Vector3 getNormal(Vector3 _Point) = 0;
	virtual INTERSECTION_TYPE isIntersected(CRay _Ray, double& out_Distance) = 0;
};

#endif