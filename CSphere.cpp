#include "CSphere.h"


CSphere::CSphere(){}

CSphere::CSphere(const Vector3& _Center, const float& _Radius, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual) :CGObject(_Ka, _Kd, _Ks, _Shininess, _Reflectivity, _isTransparent, _individual)
{
	m_Center = _Center;
	m_Radius = _Radius;
}

//CSphere(const CSphere& _copy);

CSphere::~CSphere(){}


Vector3 CSphere::getNormal(Vector3 _Point)
{

	return _Point - m_Center;
}


INTERSECTION_TYPE CSphere::isIntersected(CRay _Ray, float& out_Distance)
{
	Vector3 v = _Ray.m_Origin - m_Center;
	float b = -v.dot(_Ray.m_Direction);
	float det = (b * b) - v.dot(v) + m_Radius;
	INTERSECTION_TYPE retval = MISS;
	if (det > 0){
		det = sqrt(det);
		float t1 = b - det;
		float t2 = b + det;
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


Material CSphere::getMaterial(Vector3 _Point)
{
	if (!individual){
		return material;
	}
	else{
		//???
		return material;
	}
}