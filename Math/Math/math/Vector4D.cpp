#include "Vector4D.h"

namespace Math{

	void Vector4D::normalize()
	{
		float normalize = x * x + y * y + z*z + w*w;
		// Already normalized.
		if (normalize == 1.0f)
			return;
		normalize = sqrt(normalize);
		// Too close to zero.
		if (normalize < 0.000001f)
			return;
		normalize = 1.0f / normalize;
		x *= normalize;
		y *= normalize;
		z *= normalize;
		w *= normalize;
	}
	Vector4D Vector4D::getNormalized()const
	{
		Vector4D vector(*this);
		vector.normalize();
		return vector;
	}

	float Vector4D::length()const
	{
		return std::sqrt(x*x + y*y + w*w + z*z);
	}

	float Vector4D::lengthSquared()const
	{
		return (x*x + y*y + w*w + z*z);
	}
	float Vector4D::distance(const Vector4D & vector) const
	{
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		float dw = vector.w - w;
		return std::sqrt(dx * dx + dy * dy + dz*dz + dw*dw);
	}

	float Vector4D::distanceSquared(const Vector4D & vector) const
	{
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		float dw = vector.w - w;
		return (dx * dx + dy * dy + dz*dz + dw*dw);
	}

	std::ostream& operator<<(std::ostream& stream, const Vector4D & vector)
	{
		stream << "Vector4D (" << vector.x << "," << vector.y << "," << vector.z << "," << vector.w << ")" << std::endl;
		return stream;
	}
}
