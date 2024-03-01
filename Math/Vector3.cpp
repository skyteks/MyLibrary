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

float Vector3::Dot(const Vector3& u, const Vector3& v)
{
	return u.x * v.x + u.y * v.y + u.z * v.z;
}

Vector3 Vector3::Cross(const Vector3& u, const Vector3& v)
{
	return Vector3(
		u.y * v.z - u.z * v.y,
		u.z * v.x - u.x * v.z,
		u.x * v.y - u.y * v.x
	);
}

float Vector3::Distance(const Vector3& u, const Vector3& v)
{
	return (u - v).Magnitude();
}

float Vector3::SqrDistance(const Vector3& u, const Vector3& v)
{
	return (u - v).SqrMagnitude();
}

Vector3 Vector3::Project(const Vector3& u, const Vector3& v)
{
	Vector3 vn = Normalized(v);
	return Dot(u, vn) * vn;
}

Vector3 Vector3::ProjectOnPlane(const Vector3& u, const Vector3& v)
{
	Vector3 p = Project(u, v);
	return u - p;
}

inline void Vector3::operator=(const Vector3& v)
{
	x =v.x;
	y =v.y;
	z =v.z;
}

inline void Vector3::operator+=(const Vector3& v)
{
	x += v.x;
	y += v.y;
	z += v.z;
}

inline void Vector3::operator-=(const Vector3& v)
{
	x -= v.x;
	y -= v.y;
	z -= v.z;
}

inline void Vector3::operator*=(const float a)
{
	x *= a;
	y *= a;
	z *= a;
}

inline void Vector3::operator/=(const float a)
{
	x /= a;
	y /= a;
	z /= a;
}

inline static Vector3 operator+(const Vector3& u, const Vector3& v)
{
	return Vector3(u.x + v.x, u.y + v.y, u.z + v.z);
}

inline static Vector3 operator-(const Vector3& u, const Vector3& v)
{
	return Vector3(u.x - v.x, u.y - v.y, u.z - v.z);
}

inline static Vector3 operator*(const Vector3& u, const float a)
{
	return Vector3(u.x * a, u.y * a, u.z * a);
}

inline static Vector3 operator*(const float a, const Vector3& u)
{
	return Vector3(u.x * a, u.y * a, u.z * a);
}

inline static Vector3 operator/(const Vector3& u, const float a)
{
	return Vector3(u.x / a, u.y / a, u.z / a);
}

inline static bool operator==(const Vector3& u, const Vector3& v)
{
	return u.x == v.x && u.y == v.y && u.z == v.z;
}

inline static bool operator!=(const Vector3& u, const Vector3& v)
{
	return !(u == v);
}