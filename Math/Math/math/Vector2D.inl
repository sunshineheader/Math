#include "Vector2D.h"
using  Math::Vector2D;

inline Vector2D::Vector2D()
:x(0.0f), y(0.0f)
{}

inline Vector2D::Vector2D(const Vector2D & copy)
	: x(copy.x), y(copy.y)
{}

inline Vector2D::Vector2D(float  xx, float  yy)
	: x(xx), y(yy)
{}

inline Vector2D::~Vector2D()
{}

inline void Vector2D::add(const Vector2D & vector)
{
	x += vector.x;
	y += vector.y;
}
inline void Vector2D::subtract(const Vector2D & vector)
{
	x -= vector.x;
	y -= vector.y;
}
inline void Vector2D::multiply(const Vector2D & vector)
{
	x *= vector.x;
	y *= vector.y;
}
inline void Vector2D::divide(const Vector2D & vector)
{
	x /= vector.x;
	y /= vector.y;
}

inline bool Vector2D::operator==(const Vector2D & vector)
{
	return x == vector.x&&y == vector.y;
}

inline bool Vector2D::operator!=(const Vector2D & vector)
{
	return x != vector.x || y != vector.y;
}

inline const Vector2D Vector2D::operator+(const Vector2D & vector) const
{
	Vector2D result(*this);
	result.add(vector);
	return result;
}

inline Vector2D& Vector2D::operator+=(const Vector2D & vector)
{
	add(vector);
	return *this;
}
inline const Vector2D Vector2D::operator-(const Vector2D & vector) const
{
	Vector2D result(*this);
	result.subtract(vector);
	return result;
}

inline  Vector2D& Vector2D::operator-=(const Vector2D & vector)
{
	subtract(vector);
	return *this;
}

inline const Vector2D Vector2D::operator*(const Vector2D & vector) const
{
	Vector2D result(*this);
	result.multiply(vector);
	return result;
}

inline Vector2D& Vector2D::operator*=(const Vector2D & vector)
{
	multiply(vector);
	return *this;
}

inline const Vector2D Vector2D::operator/(const Vector2D & vector) const
{
	Vector2D result(*this);
	result.divide(vector);
	return result;
}

inline Vector2D& Vector2D::operator/=(const Vector2D & vector)
{
	divide(vector);
	return *this;
}

inline void Vector2D::scale(float scalar)
{
	x *= scalar;
	y *= scalar;
}
inline void Vector2D::scale(const Vector2D & vector)
{
	x *= vector.x;
	y *= vector.y;
}

inline const Vector2D operator*(float scalar, const Vector2D & right)
{
	Vector2D result(right);
	result.scale(scalar);
	return result;
}
inline const Vector2D operator*(const Vector2D & left, float scalar)
{
	Vector2D result(left);
	result.scale(scalar);
	return result;
}

