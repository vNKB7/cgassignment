#ifndef CDIRECTIONALLIGHT_H
#define CDIRECTIONALLIGHT_H

#include "Vector3.h"
#include "CLightSource.h"

class CDirectionalLight : public CLightSource
{
public :
	Vector3 m_Direction;

public :
	CDirectionalLight();
	CDirectionalLight(Vector3& _Postion, const Vector3& _Ka, const Vector3& _Kd, const Vector3& _Ks, const Vector3& _Direction);
	//CDirectionalLight(const CDirectionalLight& _copy);
	~CDirectionalLight();
	Vector3 EvalAmbient(Vector3 _material_Ka);
	Vector3 EvalDiffuse(Vector3 _material_Kd, Vector3 _N, Vector3 _L);
	Vector3 EvalSpecular(Vector3 _material_Ks, float _material_Shininess, Vector3 _N, Vector3 _L, Vector3 _V);

};


#endif