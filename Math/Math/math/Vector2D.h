#pragma once
#include <algorithm>
#include <ostream>
namespace Math{

	class Vector2D{

	public:

		float x;

		float y;

	public:
	    inline Vector2D();

	    inline Vector2D(const Vector2D & copy);

	    inline Vector2D(float  xx, float  yy);

		inline ~Vector2D();

		inline void add(const Vector2D & vector);

		inline void subtract(const Vector2D & vector);

		inline void multiply(const Vector2D & vector);

		inline void divide(const Vector2D & vector);

		inline bool operator==(const Vector2D & vector);
		inline bool operator!=(const Vector2D & vector);

		inline const Vector2D operator+(const Vector2D & vector) const;
		inline Vector2D& operator+=(const Vector2D & vector);

		inline const Vector2D operator-(const Vector2D & vector) const;
		inline Vector2D& operator-=(const Vector2D & vector);

		inline const Vector2D operator*(const Vector2D & vector) const;
		inline Vector2D& operator*=(const Vector2D & vector);

		inline const Vector2D operator/(const Vector2D & vector) const;
		inline Vector2D& operator/=(const Vector2D & vector);

	public:
		inline void scale(float scalar);
		inline void scale(const Vector2D & vector);

	    float length()const;
	    float lengthSquared()const;
	    float distance(const Vector2D & vector) const;
	    float distanceSquared(const Vector2D & vector) const;

		void normalize();
		Vector2D getNormalized();

		friend std::ostream& operator<<(std::ostream& stream, const Vector2D & vector);

	};
	inline const Vector2D operator*(float scalar,const Vector2D & right);
	inline const Vector2D operator*(const Vector2D & left, float scalar);
#include "Vector2D.inl"
}
