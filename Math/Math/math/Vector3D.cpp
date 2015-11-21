#include "Vector3D.h"

namespace Math{

	void Vector3D::normalize()
	{
		float normalize = x * x + y * y + z*z;
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
	}
	Vector3D Vector3D::getNormalized()const
	{
		Vector3D vector(*this);
		vector.normalize();
		return vector;
	}

	float Vector3D::length()const
	{
		return std::sqrt(x*x + y*y+z*z);
	}

	float Vector3D::lengthSquared()const
	{
		return (x*x + y*y + z*z);
	}
	float Vector3D::distance(const Vector3D & vector) const
	{
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		return std::sqrt(dx * dx + dy * dy + dz * dz);
	}

	float Vector3D::distanceSquared(const Vector3D & vector) const
	{
		float dx = vector.x - x;
		float dy = vector.y - y;
		float dz = vector.z - z;
		return (dx * dx + dy * dy + dz * dz);
	}
	std::ostream& operator<<(std::ostream& stream, const Vector3D & vector)
	{
		stream << "Vector3D (" << vector.x << "," << vector.y << "," << vector.z << ")" << std::endl;
		return stream;
	}
}
