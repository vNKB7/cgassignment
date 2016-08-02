#ifndef CSPHERE_H
#define CSPHERE_H

#include "Vector3.h"
#include "CRay.h"
#include "CGObject.h"

;//??????

class CSphere : public CGObject
{
public:
	Vector3 m_Center;
	float m_Radius;

public:
	CSphere();
	CSphere(const Vector3& _Center, const float& _Radius, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, float _Shininess, float _Reflectivity, bool _isTransparent);
	//CSphere(const CSphere& _copy);
	~CSphere();
	Vector3 getNormal(Vector3 _Point);
	INTERSECTION_TYPE isIntersected(CRay _Ray, float& out_Distance);
	Material getMaterial(Vector3 _Point, bool individual);
	//CSphere& operator=(const CSphere& _copy);
};

#endif