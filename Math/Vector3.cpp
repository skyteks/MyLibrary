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

void Vector3::Normalize()
{
	float magnitude = Magnitude();
	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

Vector3 Vector3::Normalized(const Vector3& v)
{
	float magnitude = v.Magnitude();
	return Vector3(v.x / magnitude, v.y / magnitude, v.z / magnitude);
}

float Vector3::Magnitude() const
{
	return sqrtf(x * x + y * y + z * z);
}

float Vector3::SqrMagnitude() const
{
	return x * x + y * y + z * z;
}

float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

float Vector3::Distance(const Vector3& a, const Vector3& b)
{
	return (a - b).Magnitude();
}

float Vector3::SqrDistance(const Vector3& a, const Vector3& b)
{
	return (a - b).SqrMagnitude();
}

Vector3 Vector3::Project(const Vector3& v, const Vector3& onto)
{
	Vector3 pn = Normalized(onto);
	return Dot(v, pn) * pn;
}

Vector3 Vector3::ProjectOnPlane(const Vector3& v, const Vector3& n)
{
	Vector3 p = Project(v, n);
	return v - p;
}

inline void Vector3::operator=(const Vector3& other)
{
	x =other.x;
	y =other.y;
	z =other.z;
}

inline void Vector3::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
}

inline void Vector3::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
}

inline void Vector3::operator*=(const float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}

inline void Vector3::operator/=(const float scalar)
{
	x /= scalar;
	y /= scalar;
	z /= scalar;
}

inline static Vector3 operator+(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x + b.x, a.y + b.y, a.z + b.z);
}

inline static Vector3 operator-(const Vector3& a, const Vector3& b)
{
	return Vector3(a.x - b.x, a.y - b.y, a.z - b.z);
}

inline static Vector3 operator*(const Vector3& v, const float scalar)
{
	return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline static Vector3 operator*(const float scalar, const Vector3& v)
{
	return Vector3(v.x * scalar, v.y * scalar, v.z * scalar);
}

inline static Vector3 operator/(const Vector3& v, const float scalar)
{
	return Vector3(v.x / scalar, v.y / scalar, v.z / scalar);
}

inline static bool operator==(const Vector3& a, const Vector3& b)
{
	return a.x == b.x && a.y == b.y && a.z == b.z;
}

inline static bool operator!=(const Vector3& a, const Vector3& b)
{
	return !(a == b);
}