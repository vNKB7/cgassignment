#ifndef CLIGHTSOURCE_H
#define CLIGHTSOURCE_H

#include "Vector3.h"

class CLightSource
{
public :
	Vector3 m_Postion;
	Vector3 m_Ka;
	Vector3 m_Kd;
	Vector3 m_Ks;

public :
	CLightSource(){}

	CLightSource(Vector3& _Postion, const Vector3& _Ka, const Vector3& _Kd, const Vector3& _Ks)
	{
		m_Postion = _Postion;
		m_Ka = _Ka;
		m_Kd = _Kd;
		m_Ks = _Ks;
	}

	~CLightSource(){}

	virtual Vector3 EvalAmbient(Vector3 _material_Ka) = 0;
	virtual Vector3 EvalDiffuse(Vector3 _material_kd, Vector3 _N, Vector3 _L) = 0;
	virtual Vector3 EvalSpecular(Vector3 _material_Ks, float _material_Shininess, Vector3 _N, Vector3 _L, Vector3 _V) = 0;
};

#endif