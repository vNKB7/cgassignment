#include "CDirectionalLight.h"
#include <math.h>

#define MAX(a,b) (((a)>(b))?(a):(b))

CDirectionalLight::CDirectionalLight():CLightSource(){}

CDirectionalLight::CDirectionalLight(Vector3& _Postion, const Vector3& _Ka, const Vector3& _Kd, const Vector3& _Ks, const Vector3& _Direction) : CLightSource(_Postion, _Ka, _Kd, _Ks)
{
	m_Direction = _Direction;
}

//CDirectionalLight::CDirectionalLight(const CDirectionalLight& _copy){}

CDirectionalLight::~CDirectionalLight(){}

Vector3 CDirectionalLight::EvalAmbient(Vector3 _material_Ka)
{
	return Vector3(m_Ka[0] * _material_Ka[0],
		m_Ka[1] * _material_Ka[1],
		m_Ka[2] * _material_Ka[2]);
}

Vector3 CDirectionalLight::EvalDiffuse(Vector3 _material_Kd, Vector3 _N, Vector3 _L)
{
	Vector3 IdKd = Vector3(m_Kd[0] * _material_Kd[0],
		m_Kd[1] * _material_Kd[1],
		m_Kd[2] * _material_Kd[2]);

	double NdotL = MAX(_N.dot(_L), 0.0);
	return IdKd*NdotL;
}

Vector3 CDirectionalLight::EvalSpecular(Vector3 _material_Ks, double _material_Shininess, Vector3 _N, Vector3 _L, Vector3 _V)
{
	Vector3 IsKs = Vector3(m_Ks[0] * _material_Ks[0],
		m_Ks[1] * _material_Ks[1],
		m_Ks[2] * _material_Ks[2]);

	Vector3 H = (_L + _V).norm();

	double NdotL = MAX(_N.dot(_L), 0.0);
	double NdotH = pow(MAX(_N.dot(H), 0.0), _material_Shininess);

	if (NdotL <= 0.0)
		NdotH = 0.0;

	return IsKs*NdotH;
}
