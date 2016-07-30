#ifndef CGOBJECT_H
#define CGOBJECT_H

#include "Vector3.h"

enum INTERSECTION_TYPE { INTERSECTED_IN = -1, MISS = 0, INTERSECTED = 1 };

class CGObject
{
public:
	Vector3 m_Ka;
	Vector3 m_Kd;
	Vector3 m_Ks;
	double m_Shininess;
	double m_Reflectivity;
	CGObject();
	CGObject(Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, double _Shininess, double _Reflectivity);
	~CGObject();
	//virtual Vector3 getNormal(Vector3 _Point);
	//virtual INTERSECTION_TYPE isIntersected();
};

#endif