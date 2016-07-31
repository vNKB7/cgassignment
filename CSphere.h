#ifndef CSPHERE_H
#define CSPHERE_H

#include "CGObject.h"
#include "Vector3.h"
#include "CRay.h"

class CSphere : public CGObject
{
public:
	Vector3 m_Center;
	double m_Radius;

public:
	CSphere();
	CSphere(const Vector3& _Center, const double& _Radius);
	//CSphere(const CSphere& _copy);
	~CSphere();
	Vector3 getNormal(Vector3 _Point);
	INTERSECTION_TYPE isIntersected(CRay _Ray, double& out_Distance);
	CSphere& operator=(const CSphere& _copy);
};

#endif