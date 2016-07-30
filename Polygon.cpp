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

//void setVertexes(const vector<Vector3>& nvertex);	//���ö���εĶ���
//void setVertexes(const Vector3 vpt[], int index[], int n);	//���ö���εĶ���
bool Polygon::isPlane()
{
	//�������ȷ��һ��ƽ��,���ֻ�������㣬�ز�����ɣ������е㶼���ߣ�Ҳ���У�����������������ɵ�ƽ��֮�⣬Ҳ����
	//������裬��Ϊ����ĵ㲻���غ�
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