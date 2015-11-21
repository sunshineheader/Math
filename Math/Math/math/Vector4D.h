#pragma once
#include <ostream>
#include <algorithm>

namespace Math{

	class Vector4D{

	public:
		float x;

		float y;

		float z;

		float w;

	public:
	    inline Vector4D();

	    inline Vector4D(const Vector4D & copy);

		inline Vector4D(float  xx, float  yy, float  zz, float  ww);

		inline ~Vector4D();

		inline void add(const Vector4D & vector);
		inline void subtract(const Vector4D & vector);
		inline void multiply(const Vector4D & vector);
		inline void divide(const Vector4D & vector);

		inline bool operator==(const Vector4D & vector);
		inline bool operator!=(const Vector4D & vector);

		inline const Vector4D operator+(const Vector4D & vector) const;
		inline Vector4D& operator+=(const Vector4D & vector);

		inline const Vector4D operator-(const Vector4D & vector) const;
		inline Vector4D& operator-=(const Vector4D & vector);

		inline const Vector4D operator*(const Vector4D & vector) const;
		inline Vector4D& operator*=(const Vector4D & vector);

		inline const Vector4D operator/(const Vector4D & vector) const;
		inline Vector4D& operator/=(const Vector4D & vector);

	public:
		inline void scale(float scalar);
		inline void scale(const Vector4D & vector);

		float length()const;
		float lengthSquared()const;
		float distance(const Vector4D & vector) const;
		float distanceSquared(const Vector4D & vector) const;

		void normalize();
		Vector4D getNormalized()const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector4D & vector);

	};
	inline const Vector4D operator*(float scalar, const Vector4D & right);
	inline const Vector4D operator*(const Vector4D & left, float scalar);
#include "Vector4D.inl"
}
