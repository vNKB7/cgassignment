#ifndef CPOLYGON_H
#define CPOLYGON_H

#include <vector>
#include "CGObject.h"
#include "BmpFile.h"

using namespace std;

class CPolygon: public CGObject
{
public:
	vector<Vector3> vertex;
	Vector3 normal;
	float d;	//多边形距原点的距离
	BmpFile *texture;
	int fillType;// 0 没有  1 平铺  2 拉伸
	float zoom;//图片的缩放倍率
public:
	CPolygon();
	CPolygon(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);
	CPolygon(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);
	//CPolygon(const CPolygon& CPolygon);	
	~CPolygon();
	void setVertexes(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);	//设置多边形的顶点
	void setVertexes(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);	//设置多边形的顶点
	bool isPlane(); //判断多边形中的点是否能组成一个平面
	Vector3 computeNormal();
	Vector3 getNormal(Vector3 _Point);
	INTERSECTION_TYPE isIntersected(CRay _Ray, float& out_Distance);
	Vector3 crossRayPlane(const CRay& ray);//求射线与多边形平面的交点
	bool isPointInCPolygon(const Vector3& pt);// 判断点是不是在多边形内
	Material getMaterial(Vector3 _Point);
	void setTexture(BmpFile *_texture, int _type, float _zoom);
private:
	void computeNorm();
};

#endif