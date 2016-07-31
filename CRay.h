#ifndef CRAY_H
#define CRAY_H

#include "Vector3.h"

class CRay
{
public:
	Vector3 m_Origin;
	Vector3 m_Direction;

public:
	CRay();
	CRay(Vector3 _Origin, Vector3 _Direction);
	~CRay();
	Vector3 getPoint(double _t);
};

#endif