#include <iostream>
#include "CGObject.h"

using namespace std;

int main()
{
	Vector3 v1(23, 0, 0);
	Vector3 v2(0, 41, 0);
	Vector3 v3(0, 0, 1);

	Vector3 a = v1 - v2;
	Vector3 b = v1 - v3;
	Vector3 c = v2 - v3;


	double result = a.cross(b).dot(c);
	cout << result << endl;
}

