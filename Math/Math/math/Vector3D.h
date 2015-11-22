#pragma once
#include <ostream>
#include <algorithm>
namespace Math{

	class Vector3D{

	public:
		float x;

		float y;

		float z;

	public:
	    inline Vector3D();

	    inline Vector3D(const Vector3D & copy);

		inline Vector3D(float  xx, float  yy, float  zz);

		inline ~Vector3D();

		inline void add(const Vector3D & vector);
		inline void subtract(const Vector3D & vector);
		inline void multiply(const Vector3D & vector);
		inline void divide(const Vector3D & vector);

		inline bool operator==(const Vector3D & vector);
		inline bool operator!=(const Vector3D & vector);

		inline const Vector3D operator+(const Vector3D & vector) const;
		inline Vector3D& operator+=(const Vector3D & vector);

		inline const Vector3D operator-(const Vector3D & vector) const;
		inline Vector3D& operator-=(const Vector3D & vector);

		inline const Vector3D operator*(const Vector3D & vector) const;
		inline Vector3D& operator*=(const Vector3D & vector);

		inline const Vector3D operator/(const Vector3D & vector) const;
		inline Vector3D& operator/=(const Vector3D & vector);

	public:
		inline void scale(float scalar);
		inline void scale(const Vector3D & vector);

		float length()const;
		float lengthSquared()const;
		float distance(const Vector3D & vector) const;
		float distanceSquared(const Vector3D & vector) const;
		Vector3D crossProduct(const Vector3D & vector) const;

		void normalize();
		Vector3D getNormalized()const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector3D & vector);

	};

	inline const Vector3D operator*(float scalar, const Vector3D & right);
	inline const Vector3D operator*(const Vector3D & left, float scalar);
#include "Vector3D.inl"
}
