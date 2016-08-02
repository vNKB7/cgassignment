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
	float d;	//����ξ�ԭ��ľ���
public:
	Polygon();
	Polygon(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);
	Polygon(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);
	//Polygon(const Polygon& polygon);	
	void setVertexes(const vector<Vector3>& nvertex, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);	//���ö���εĶ���
	void setVertexes(const Vector3 vpt[], int index[], int n, Vector3 _Ka, Vector3 _Kd, Vector3 _Ks, Vector3 _Kr, float _Shininess, float _Reflectivity, bool _isTransparent, bool _individual);	//���ö���εĶ���
	bool isPlane(); //�ж϶�����еĵ��Ƿ������һ��ƽ��
	Vector3 computeNormal();
	Vector3 getNormal(Vector3 _Point);
	INTERSECTION_TYPE isIntersected(CRay _Ray, float& out_Distance);
	Vector3 crossRayPlane(const CRay& ray);//������������ƽ��Ľ���
	bool isPointInPolygon(const Vector3& pt);// �жϵ��ǲ����ڶ������
	Material getMaterial(Vector3 _Point);
private:
	void computeNorm();
};

#endif