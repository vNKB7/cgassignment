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
	bool isPointInTriangle(const Vector3& _Point);	// �жϵ��ǲ����ڶ������
	void setVertexes(Vector3 _a, Vector3 _b, Vector3 _c);	//���ö���εĶ���
	void setVertexes(const Vector3 vpt[], int index[], int n);	//���ö���εĶ���
	bool isPlane(); //�ж϶�����еĵ��Ƿ������һ��ƽ��
	Vector3 computeNormal();
};

#endif
