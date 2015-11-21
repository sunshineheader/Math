#include "Vector3D.h"
using  Math::Vector3D;

inline Vector3D::Vector3D()
	:x(0.0f), y(0.0f), z(0.0f)
{}

inline Vector3D::Vector3D(const Vector3D & copy)
	: x(copy.x), y(copy.y), z(copy.z)
{}

inline Vector3D::Vector3D(float  xx, float  yy, float  zz)
	: x(xx), y(yy), z(zz)
{}

inline Vector3D::~Vector3D()
{}

inline void Vector3D::add(const Vector3D & vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
}
inline void Vector3D::subtract(const Vector3D & vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
}
inline void Vector3D::multiply(const Vector3D & vector)
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
}
inline void Vector3D::divide(const Vector3D & vector)
{
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
}
inline bool Vector3D::operator==(const Vector3D & vector)
{
	return x == vector.x&&y == vector.y&&z == vector.z;
}
inline bool Vector3D::operator!=(const Vector3D & vector)
{
	return x != vector.x || y != vector.y || z != vector.z;
}

inline const Vector3D Vector3D::operator+(const Vector3D & vector) const
{
	Vector3D result(*this);
	result.add(vector);
	return result;
}
inline Vector3D& Vector3D::operator+=(const Vector3D & vector)
{
	add(vector);
	return *this;
}
inline const Vector3D Vector3D::operator-(const Vector3D & vector) const
{
	Vector3D result(*this);
	result.subtract(vector);
	return result;
}

inline  Vector3D& Vector3D::operator-=(const Vector3D & vector)
{
	subtract(vector);
	return *this;
}

inline const Vector3D Vector3D::operator*(const Vector3D & vector) const
{
	Vector3D result(*this);
	result.multiply(vector);
	return result;
}

inline Vector3D& Vector3D::operator*=(const Vector3D & vector)
{
	multiply(vector);
	return *this;
}
inline const Vector3D Vector3D::operator/(const Vector3D & vector) const
{
	Vector3D result(*this);
	result.divide(vector);
	return result;
}

inline Vector3D& Vector3D::operator/=(const Vector3D & vector)
{
	divide(vector);
	return *this;
}
inline void Vector3D::scale(float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
}
inline void Vector3D::scale(const Vector3D & vector)
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
}
inline const Vector3D operator*(float scalar, const Vector3D & right)
{
	Vector3D result(right);
	result.scale(scalar);
	return result;
}
inline const Vector3D operator*(const Vector3D & left, float scalar)
{
	Vector3D result(left);
	result.scale(scalar);
	return result;
}
