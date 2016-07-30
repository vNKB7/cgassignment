#ifndef POLYGON_H
#define POLYGON_H

#include <vector>
#include "CGObject.h"

using namespace std;

class Polygon: public CGObject
{
public:
	vector<Vector3> vertex;
	Vector3 normal;
public:
	Polygon(const vector<Vector3>& nvertex);
	Polygon();
	Polygon(const Polygon& polygon);
	//Vector3 getNormal(Vector3 _Point);
	bool isPointInPolygon(const Vector3& _Point);	// 判断点是不是在多边形内
	void setVertexes(const vector<Vector3>& nvertex);	//设置多边形的顶点
	void setVertexes(const Vector3 vpt[], int index[], int n);	//设置多边形的顶点
	bool isPlane(); //判断多边形中的点是否能组成一个平面
	Vector3 computeNormal();
};

#endif