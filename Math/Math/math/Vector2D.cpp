#include "Vector2D.h"

namespace Math{


	void Vector2D::normalize()
	{
		float normalize = x * x + y * y;
		// Already normalizeormalized.
		if (normalize == 1.0f)
			return;

		normalize = sqrt(normalize);
		// Too close to zero.
		if (normalize < 0.000001f)
			return;

		normalize = 1.0f / normalize;
		x *= normalize;
		y *= normalize;
	}
	Vector2D Vector2D::getNormalized()
	{
		Vector2D vector(*this);
		vector.normalize();
		return vector;
	}

	float Vector2D::length()const
	{
		return std::sqrt(x*x + y*y);
	}

	float Vector2D::lengthSquared()const
	{
		return (x*x + y*y);
	}
	float Vector2D::distance(const Vector2D & vector) const
	{
		float dx = vector.x - x;
		float dy = vector.y - y;
		return std::sqrt(dx * dx + dy * dy);
	}

	float Vector2D::distanceSquared(const Vector2D & vector) const
	{
		float dx = vector.x - x;
		float dy = vector.y - y;
		return (dx * dx + dy * dy);
	}
	float Vector2D::crossProduct(const Vector2D & vector) const
	{
		return x*vector.y - y*vector.x;
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2D & vector)
	{
		stream << "Vector2D (" << vector.x << "," << vector.y << ")" << std::endl;
		return stream;
	}
}
