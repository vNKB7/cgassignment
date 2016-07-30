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
	bool isPointInPolygon(const Vector3& _Point);	// �жϵ��ǲ����ڶ������
	void setVertexes(const vector<Vector3>& nvertex);	//���ö���εĶ���
	void setVertexes(const Vector3 vpt[], int index[], int n);	//���ö���εĶ���
	bool isPlane(); //�ж϶�����еĵ��Ƿ������һ��ƽ��
	Vector3 computeNormal();
};

#endif