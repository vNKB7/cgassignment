#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "CGObject.h"

class Triangle : public CGObject
{
public:
	Vector3 a, b, c;
	Vector3 normal;

public:
	Triangle(Vector3 _a, Vector3 _b, Vector3 _c);
	Triangle();
	//Triangle(const Triangle& triangle);
	//Vector3 getNormal(Vector3 _Point);
	bool isPointInTriangle(const Vector3& _Point);	// 判断点是不是在多边形内
	void setVertexes(Vector3 _a, Vector3 _b, Vector3 _c);	//设置多边形的顶点
	void setVertexes(const Vector3 vpt[], int index[], int n);	//设置多边形的顶点
	bool isPlane(); //判断多边形中的点是否能组成一个平面
	Vector3 computeNormal();
};

#endif
