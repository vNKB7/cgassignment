#ifndef VECTOR3_H
#define VECTOR3_H

#include <math.h>
#include "global.h"

class Vector3
{
public:
	double x, y, z;
public:
	Vector3(){}

	Vector3(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3(double d)
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

	void set(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void set(double d)
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

	void operator*=(double r)
	{
		x *= r;
		y *= r;
		z *= r;
	}

	void operator/=(double r)
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

	Vector3 operator*(double r)const
	{
		Vector3 tmp = *this;
		tmp *= r;
		return tmp;
	}

	Vector3 operator/(double r)const
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

	void operator=(double f)
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

	double operator [](int i){
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

	double dot(const Vector3& b) const
	{
		return x*b.x + y*b.y + z*b.z;
	}

	double abs() const
	{
		return sqrt(x*x + y*y + z*z);
	}

	void normalize()
	{
		*this /= this->abs();
	}

	Vector3 norm()
	{
		return *this / this->abs();
	}

	bool isSame(const Vector3& b) const
	{
		return fabs(this->x - b.x) <= EPS && fabs(this->y - b.y) <= EPS && fabs(this->z - b.z) <= EPS;
	}

	double length(const Vector3& b)
	{
		return (*this - b).abs();
	}

};

#endif