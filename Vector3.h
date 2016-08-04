#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
#include<stdio.h>
#include "global.h"

class Vector3
{
public:
	float x, y, z;
public:
	Vector3(){}

	Vector3(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3(float d)
	{
		this->x = d;
		this->y = d;
		this->z = d;
	}

	/*
	Vector3(const Vector3& v)
	{
	x = v.x;
	y = v.y;
	z = v.z;
	}
	*/

	void set(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void set(float d)
	{
		this->x = d;
		this->y = d;
		this->z = d;
	}
	

	Vector3 operator-() const
	{
		return Vector3(-x, -y, -z);
	}

	void operator+=(const Vector3& v)
	{
		x += v.x;
		y += v.y;
		z += v.z;
	}

	void operator-=(const Vector3& v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
	}

	void operator*=(float r)
	{
		x *= r;
		y *= r;
		z *= r;
	}

	void operator/=(float r)
	{
		x /= r;
		y /= r;
		z /= r;
	}

	void operator/=(const Vector3& v)
	{
		x /= v.x;
		y /= v.y;
		z /= v.z;
	}

	Vector3 operator+(const Vector3& v) const
	{
		Vector3 tmp = *this;
		tmp += v;
		return tmp;
	}
	
	Vector3 operator-(const Vector3& v)const
	{
		Vector3 tmp = *this;
		tmp -= v;
		return tmp;
	}

	Vector3 operator*(const Vector3& v)const
	{
		Vector3 tmp;
		tmp.x = x*v.x;
		tmp.y = y*v.y;
		tmp.z = z*v.z;
		return tmp;
	}

	Vector3 operator*(float r)const
	{
		Vector3 tmp = *this;
		tmp *= r;
		return tmp;
	}

	Vector3 operator/(float r)const
	{
		Vector3 tmp = *this;
		tmp /= r;
		return tmp;
	}

	Vector3 operator/(const Vector3& v) const
	{
		Vector3 tmp = *this;
		tmp /= v;
		return tmp;
	}

	void operator=(float f)
	{
		x = f;
		y = f;
		z = f;
	}

	void operator=(const Vector3& v)
	{
		x = v.x;
		y = v.y;
		z = v.z;
	}

	bool operator==(const Vector3& v)
	{
		return x == v.x && y == v.y && z == v.z;
	}

	float operator [](int i){
		if (i == 0)
			return x;
		else if (i == 1)
			return y;
		else if (i == 2)
			return z;
		else
			return 0;
	}

	Vector3 cross(const Vector3& b) const
	{
		Vector3 tmp;
		tmp.x = y*b.z - z*b.y;
		tmp.y = z*b.x - x*b.z;
		tmp.z = x*b.y - y*b.x;
		return tmp;
	}

	float dot(const Vector3& b) const
	{
		return x*b.x + y*b.y + z*b.z;
	}

	float abs() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	void normalize()
	{
		*this /= this->abs();
	}

	bool nearpoint(const Vector3& v)
	{
		return length(v) < 0.001;
	}

	Vector3 norm()
	{
		return *this / this->abs();
	}

	bool isSame(const Vector3& b) const
	{
		return fabs(this->x - b.x) <= EPS && fabs(this->y - b.y) <= EPS && fabs(this->z - b.z) <= EPS;
	}

	float length(const Vector3& b)
	{
		return (*this - b).abs();
	}

	void show()
	{
		printf("V3 x:%f y:%f z:%f\n", x, y, z);
	}

	void isAColor()
	{
		if (x > 1)
			x = 1;
		else if (x < 0)
			x = 0;
		if (y > 1)
			y = 1;
		else if (y < 0)
			y = 0;
		if (z > 1)
			z = 1;
		else if (z < 0)
			z = 0;
	}

};

#endif