#include "pch.h"
#include "Vector3.h"
#include <math.h>

Vector3::Vector3()
	: x(0.0f), y(0.0f), z(0.0f)
{
}

Vector3::Vector3(float _x, float _y, float _z)
	: x(_x), y(_y), z(_z)
{
}

float Vector3::Magnitude() const
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector3::SqrMagnitude() const
{
	return x * x + y * y + z * z;
}

float Vector3::Dot(Vector3& a, Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::operator+(Vector3& other)
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

Vector3 Vector3::operator-(Vector3& other)
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator*(float scalar)
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}