#include "CGObject.h"

CGObject::CGObject(){};

CGObject::CGObject(Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, double _Shininess, double _Reflectivity)
{
	m_Ka = _Ka;
	m_Kd = _Kd;
	m_Ks = _Ks;
	m_Shininess = _Shininess;
	m_Reflectivity = _Reflectivity;
}

CGObject::~CGObject(){}

