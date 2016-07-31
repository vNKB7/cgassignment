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
	double m_Radius;

public:
	CSphere();
	CSphere(const Vector3& _Center, const double& _Radius, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, double _Shininess, double _Reflectivity, bool _isTransparent);
	//CSphere(const CSphere& _copy);
	~CSphere();
	Vector3 getNormal(Vector3 _Point);
	INTERSECTION_TYPE isIntersected(CRay _Ray, double& out_Distance);
	//CSphere& operator=(const CSphere& _copy);
};

#endif