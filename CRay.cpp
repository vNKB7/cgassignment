#include "CRay.h"

CRay::CRay()
{
	m_Origin = 0;
	m_Direction = 0;
}
CRay::CRay(Vector3 _Origin, Vector3 _Direction)
{
	m_Origin = _Origin;
	m_Direction = _Direction;
	m_Direction.normalize();
}

CRay::~CRay(){}

Vector3 CRay::getPoint(float _t) const
{
	return m_Origin + m_Direction * _t;
}
