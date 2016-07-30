#include "Polygon.h"
#include <math.h>
#include "global.h"

Polygon::Polygon(const vector<Vector3>& nvertex)
{
	//setVertexes(nvertex);
}

Polygon::Polygon()
{

}

Polygon::Polygon(const Polygon& polygon)
{
	//????
}

/*
Vector3 Polygon::getNormal(Vector3 _Point)
{
	//whether the value is computed
	return normal;
}
*/

bool Polygon::isPointInPolygon(const Vector3& _Point)
{
	return false;
}

//void setVertexes(const vector<Vector3>& nvertex);	//设置多边形的顶点
//void setVertexes(const Vector3 vpt[], int index[], int n);	//设置多边形的顶点
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