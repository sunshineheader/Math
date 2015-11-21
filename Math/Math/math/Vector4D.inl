#include "Vector4D.h"
using  Math::Vector4D;

inline Vector4D::Vector4D()
	:x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{}

inline Vector4D::Vector4D(const Vector4D & copy)
	: x(copy.x), y(copy.y), z(copy.z), w(copy.w)
{}

inline Vector4D::Vector4D(float  xx, float  yy, float  zz, float  ww)
	: x(xx), y(yy), z(zz), w(ww)
{}

inline Vector4D::~Vector4D()
{}

inline void Vector4D::add(const Vector4D & vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	w += vector.w;
}
inline void Vector4D::subtract(const Vector4D & vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	w -= vector.w;

}
inline void Vector4D::multiply(const Vector4D & vector)
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	w *= vector.w;
}
inline void Vector4D::divide(const Vector4D & vector)
{
	x /= vector.x;
	y /= vector.y;
	z /= vector.z;
	w /= vector.w;
}

inline bool Vector4D::operator==(const Vector4D & vector)
{
	return x == vector.x&&y == vector.y&&z == vector.z&&w == vector.w;
}

inline bool Vector4D::operator!=(const Vector4D & vector)
{
	return x != vector.x || y != vector.y || z != vector.z || w != vector.w;
}

inline const Vector4D Vector4D::operator+(const Vector4D & vector) const
{
	Vector4D result(*this);
	result.add(vector);
	return result;
}
inline Vector4D& Vector4D::operator+=(const Vector4D & vector)
{
	add(vector);
	return *this;
}

inline const Vector4D Vector4D::operator-(const Vector4D & vector) const
{
	Vector4D result(*this);
	result.subtract(vector);
	return result;
}

inline  Vector4D& Vector4D::operator-=(const Vector4D & vector)
{
	subtract(vector);
	return *this;
}
inline const Vector4D Vector4D::operator*(const Vector4D & vector) const
{
	Vector4D result(*this);
	result.multiply(vector);
	return result;
}

inline Vector4D& Vector4D::operator*=(const Vector4D & vector)
{
	multiply(vector);
	return *this;
}

inline const Vector4D Vector4D::operator/(const Vector4D & vector) const
{
	Vector4D result(*this);
	result.divide(vector);
	return result;
}

inline Vector4D& Vector4D::operator/=(const Vector4D & vector)
{
	divide(vector);
	return *this;
}
inline void Vector4D::scale(float scalar)
{
	x *= scalar;
	y *= scalar;
	z *= scalar;
	w *= scalar;
}
inline void Vector4D::scale(const Vector4D & vector)
{
	x *= vector.x;
	y *= vector.y;
	z *= vector.z;
	w *= vector.w;
}
inline const Vector4D operator*(float scalar, const Vector4D & right)
{
	Vector4D result(right);
	result.scale(scalar);
	return result;
}
inline const Vector4D operator*(const Vector4D & left, float scalar)
{
	Vector4D result(left);
	result.scale(scalar);
	return result;
}
