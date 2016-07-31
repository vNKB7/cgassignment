#include "CSphere.h"


CSphere::CSphere(){}

CSphere::CSphere(const Vector3& _Center, const double& _Radius)
{
	m_Center = _Center;
	m_Radius = _Radius;
}

//CSphere(const CSphere& _copy);

CSphere::~CSphere(){}

Vector3 CSphere::getNormal(Vector3 _Point)
{
	return Vector3();
}

INTERSECTION_TYPE CSphere::isIntersected(CRay _Ray, double& out_Distance)
{
	Vector3 v = _Ray.m_Origin - m_Center;
	double b = -v.dot(_Ray.m_Direction);
	double det = (b * b) - v.dot(v) + m_Radius;
	INTERSECTION_TYPE retval = MISS;
	if (det > 0){
		det = sqrt(det);
		double t1 = b - det;
		double t2 = b + det;
		if (t2 > 0){
			if (t1 < 0) {
				if (t2 < out_Distance) {
					out_Distance = t2;
					retval = INTERSECTED_IN;
				}
			}
			else{
				if (t1 < out_Distance){
					out_Distance = t1;
					retval = INTERSECTED;
				}
			}
		}
	}
	return retval;
}

//CSphere& CSphere::operator=(const CSphere& _copy);