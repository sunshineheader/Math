#pragma once
#include <algorithm>
#include "Vector3D.h"
#include "Vector4D.h"
#include "MathUtils.h"
namespace Math{

	class Matrix4x4
	{
	public:
		float matrix[4][4];
	public:
		inline Matrix4x4();
		inline Matrix4x4(float diagonal);

		inline Matrix4x4(
			float m00, float m01, float m02, float m03,
			float m10, float m11, float m12, float m13,
			float m20, float m21, float m22, float m23,
			float m30, float m31, float m32, float m33 
			);
		inline Matrix4x4(const Matrix4x4 & copy);
		inline ~Matrix4x4();

		inline void add(const Matrix4x4 & other);
		inline void subtract(const Matrix4x4 & other);
		inline void multiply(const Matrix4x4 & other);

		inline const Matrix4x4 operator+(const Matrix4x4 & right) const;
		inline const Matrix4x4 operator-(const Matrix4x4 & right) const;
		inline const Matrix4x4 operator* (const Matrix4x4 & right) const;
	public:
		inline void identity();
		Matrix4x4 getMatrixIndentity()const;
		Vector3D  multiply(const Vector3D & right);// check thiis
		Vector4D  multiply(const Vector4D & right);


		Matrix4x4 scaleMatrix(float ScaleX, float ScaleY, float ScaleZ);
		Matrix4x4 rotationMatrix(float ScaleX, float ScaleY, float ScaleZ);
		Matrix4x4 translationMatrix(float x, float y, float z);
		friend std::ostream& operator<<(std::ostream& stream, const Matrix4x4 & matrix);
	};
#include "Matrix4x4.inl"
}
