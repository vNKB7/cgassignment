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
	float d;	//多边形距原点的距离
public:
	Polygon();
	Polygon(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);
	Polygon(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);
	//Polygon(const Polygon& polygon);	
	void setVertexes(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);	//设置多边形的顶点
	void setVertexes(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);	//设置多边形的顶点
	bool isPlane(); //判断多边形中的点是否能组成一个平面
	Vector3 computeNormal();
	Vector3 getNormal(Vector3 _Point);
	INTERSECTION_TYPE isIntersected(CRay _Ray, float& out_Distance);
	Vector3 crossRayPlane(const CRay& ray);//求射线与多边形平面的交点
	bool isPointInPolygon(const Vector3& pt);// 判断点是不是在多边形内
	Material getMaterial(Vector3 _Point);
private:
	void computeNorm();
};

#endif