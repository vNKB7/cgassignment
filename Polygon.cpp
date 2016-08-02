#include "Polygon.h"
#include <math.h>
#include "global.h"

Polygon::Polygon(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, float _Shininess, float _Reflectivity, bool _isTransparent) :CGObject(_Ka, _Kd, _Ks, _Shininess, _Reflectivity, _isTransparent)
{
	vertex = nvertex;
	computeNorm();
}

Polygon::Polygon(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, float _Shininess, float _Reflectivity, bool _isTransparent) :CGObject(_Ka, _Kd, _Ks, _Shininess, _Reflectivity, _isTransparent)
{
	vertex.resize(n);
	for (int i = 0; i<n; i++)
		vertex[i] = vpt[index[i]];
	printf("computeNorm?\n");
	computeNorm();
}

Polygon::Polygon()
{}


Vector3 Polygon::getNormal(Vector3 _Point)
{
	if (vertex.size() < 2){
		printf("not a polygon\n");
	}
	return normal;
}

void Polygon::setVertexes(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, float _Shininess, float _Reflectivity, bool _isTransparent)
{
	vertex = nvertex;
	computeNorm();
	material.m_Ka = _Ka;
	material.m_Kd = _Kd;
	material.m_Ks = _Ks;
	material.m_Shininess = _Shininess;
	material.m_Reflectivity = _Reflectivity;
	material.isTransparent = _isTransparent;
}

void Polygon::setVertexes(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, float _Shininess, float _Reflectivity, bool _isTransparent)
{
	int i;
	vertex.resize(n);
	for (i = 0; i<n; i++)
		vertex[i] = vpt[index[i]];
	printf("computeNorm?\n");
	computeNorm();
	material.m_Ka = _Ka;
	material.m_Kd = _Kd;
	material.m_Ks = _Ks;
	material.m_Shininess = _Shininess;
	material.m_Reflectivity = _Reflectivity;
	material.isTransparent = _isTransparent;
}

bool Polygon::isPlane()
{
	//三点可以确定一个平面,如果只有两个点，必不能组成；若所有点都共线，也不行；若其他点在三点组成的平面之外，也不行
	//这里假设，作为输入的点不会重合
	if (vertex.size() < 3)
		return false;
	else{
		Vector3 a = vertex[1] - vertex[0];
		Vector3 b = vertex[2] - vertex[0];
		Vector3 nv = a.cross(b);

		for (int i = 3; i < vertex.size(); i++)
		{
			if (abs((vertex[i] - vertex[0]).dot(nv)) < EPS)
				return false;
		}
		return true;
	}
}

void Polygon::computeNorm()
{
	if (vertex.size()>2)
	{
		Vector3 a = vertex[1] - vertex[0];
		Vector3 b = vertex[vertex.size() - 1] - vertex[0];
		normal = a.cross(b);
		normal.normalize();
		d = -normal.dot(vertex[0]);
	}
}

Vector3 Polygon::crossRayPlane(const CRay& ray)
{
	Vector3 Q = ray.m_Origin;
	Vector3 E = ray.m_Direction;
	Vector3 N = normal;
	return Q - E*((d + N.dot(Q)) / N.dot(E));
}

bool Polygon::isPointInPolygon(const Vector3& pt)
{
	int i;
	Vector3 a, b, c;
	for (i = 0; i<vertex.size() - 1; i++)
	{
		a = vertex[i + 1] - vertex[i];
		b = pt - vertex[i];
		c = a.cross(b);
		c.normalize();
		if (!normal.isSame(c))
			return false;
	}
	a = vertex[0] - vertex[i];
	b = pt - vertex[i];
	c = a.cross(b);
	c.normalize();
	if (!normal.isSame(c))
		return false;
	else
		return true;
}

INTERSECTION_TYPE Polygon::isIntersected(CRay _Ray, float& out_Distance)
{
	INTERSECTION_TYPE retval = MISS;
	Vector3 crossPoint = crossRayPlane(_Ray);
	if (isPointInPolygon(crossPoint)){
		float distance = _Ray.m_Origin.length(crossPoint);
		if (distance < out_Distance)
		{
			out_Distance = _Ray.m_Origin.length(crossPoint);
			if (_Ray.m_Direction.dot(normal) <= 0){
				retval = INTERSECTED;
			}
			else{
				retval = INTERSECTED_IN;
			}
		}
	}
	return retval;
}

Material Polygon::getMaterial(Vector3 _Point, bool individual)
{
	if (!individual){
		return material;
	}
	else{
		//???
		return material;
	}
}