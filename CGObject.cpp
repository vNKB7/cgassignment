#include "CGObject.h"

CGObject::CGObject(){}

CGObject::CGObject(Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual)
{
	material.m_Ka = _Ka;
	material.m_Kd = _Kd;
	material.m_Ks = _Ks;
	material.m_Kr = _Kr;
	material.m_Shininess = _Shininess;
	material.m_Reflectivity = _Reflectivity;
	material.isTransparent = _isTransparent;
	individual = _individual;
}

CGObject::~CGObject(){}

