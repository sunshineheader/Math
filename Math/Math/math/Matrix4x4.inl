#include "Matrix4x4.h"

using Math::Matrix4x4;

inline Matrix4x4::Matrix4x4()
{
}

inline Matrix4x4::Matrix4x4(float diagonal)
{
	matrix[0][0] = diagonal; matrix[0][1] = 0.0f;     matrix[0][2] = 0.0f;     matrix[0][3] = 0.0f;
	matrix[1][0] = 0.0f;     matrix[1][1] = diagonal; matrix[1][2] = 0.0f;     matrix[1][3] = 0.0f;
	matrix[2][0] = 0.0f;     matrix[2][1] = 0.0f;     matrix[2][2] = diagonal; matrix[2][3] = 0.0f;
	matrix[3][0] = 0.0f;     matrix[3][1] = 0.0f;     matrix[3][2] = 0.0f;     matrix[3][3] = diagonal;
}

inline Matrix4x4::Matrix4x4(
	float m00, float m01, float m02, float m03,
	float m10, float m11, float m12, float m13,
	float m20, float m21, float m22, float m23,
	float m30, float m31, float m32, float m33
	)
{
	matrix[0][0] = m00; matrix[0][1] = m01; matrix[0][2] = m02; matrix[0][3] = m03;
	matrix[1][0] = m10; matrix[1][1] = m11; matrix[1][2] = m12; matrix[1][3] = m13;
	matrix[2][0] = m20; matrix[2][1] = m21; matrix[2][2] = m22; matrix[2][3] = m23;
	matrix[3][0] = m30; matrix[3][1] = m31; matrix[3][2] = m32; matrix[3][3] = m33;
}

inline Matrix4x4::Matrix4x4(const Matrix4x4 & copy)
{
	matrix[0][0] = copy.matrix[0][0]; matrix[0][1] = copy.matrix[0][1]; matrix[0][2] = copy.matrix[0][2]; matrix[0][3] = copy.matrix[0][3];
	matrix[1][0] = copy.matrix[1][0]; matrix[1][1] = copy.matrix[1][1]; matrix[1][2] = copy.matrix[1][2]; matrix[1][3] = copy.matrix[1][3];
	matrix[2][0] = copy.matrix[2][0]; matrix[2][1] = copy.matrix[2][1]; matrix[2][2] = copy.matrix[2][2]; matrix[2][3] = copy.matrix[2][3];
	matrix[3][0] = copy.matrix[3][0]; matrix[3][1] = copy.matrix[3][1]; matrix[3][2] = copy.matrix[3][2]; matrix[3][3] = copy.matrix[3][3];
}

inline void Matrix4x4::identity()
{
	matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = 0.0f;
	matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = 0.0f;
	matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = 0.0f;
	matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
}

inline Matrix4x4:: ~Matrix4x4()
{

}

inline void Matrix4x4::add(const Matrix4x4 & right)
{
	float result[4][4];
	result[0][0] = matrix[0][0] + right.matrix[0][0];
	result[0][1] = matrix[0][1] + right.matrix[0][1];
	result[0][2] = matrix[0][2] + right.matrix[0][2];
	result[0][3] = matrix[0][3] + right.matrix[0][3];

	result[1][0] = matrix[1][0] + right.matrix[1][0];
	result[1][1] = matrix[1][1] + right.matrix[1][1];
	result[1][2] = matrix[1][2] + right.matrix[1][2];
	result[1][3] = matrix[1][3] + right.matrix[1][3];

	result[2][0] = matrix[2][0] + right.matrix[2][0];
	result[2][1] = matrix[2][1] + right.matrix[2][1];
	result[2][2] = matrix[2][2] + right.matrix[2][2];
	result[2][3] = matrix[2][3] + right.matrix[2][3];

	result[3][0] = matrix[3][0] + right.matrix[3][0];
	result[3][1] = matrix[3][1] + right.matrix[3][1];
	result[3][2] = matrix[3][2] + right.matrix[3][2];
	result[3][3] = matrix[3][3] + right.matrix[3][3];

	std::memcpy(matrix, result, 4 * 4 * sizeof(float));
}
inline void Matrix4x4::subtract(const Matrix4x4 & right)
{
	float result[4][4];
	result[0][0] = matrix[0][0] - right.matrix[0][0];
	result[0][1] = matrix[0][1] - right.matrix[0][1];
	result[0][2] = matrix[0][2] - right.matrix[0][2];
	result[0][3] = matrix[0][3] - right.matrix[0][3];
								
	result[1][0] = matrix[1][0] - right.matrix[1][0];
	result[1][1] = matrix[1][1] - right.matrix[1][1];
	result[1][2] = matrix[1][2] - right.matrix[1][2];
	result[1][3] = matrix[1][3] - right.matrix[1][3];
								
	result[2][0] = matrix[2][0] - right.matrix[2][0];
	result[2][1] = matrix[2][1] - right.matrix[2][1];
	result[2][2] = matrix[2][2] - right.matrix[2][2];
	result[2][3] = matrix[2][3] - right.matrix[2][3];
								
	result[3][0] = matrix[3][0] - right.matrix[3][0];
	result[3][1] = matrix[3][1] - right.matrix[3][1];
	result[3][2] = matrix[3][2] - right.matrix[3][2];
	result[3][3] = matrix[3][3] - right.matrix[3][3];

	std::memcpy(matrix, result, 4 * 4 * sizeof(float));

}
inline void Matrix4x4::multiply(const Matrix4x4 & right)
{
	float result[4][4];

	result[0][0] = matrix[0][0] * right.matrix[0][0] + matrix[0][1] * right.matrix[1][0] + matrix[0][2] * right.matrix[2][0] + matrix[0][3] * right.matrix[3][0];
	result[0][1] = matrix[0][0] * right.matrix[0][1] + matrix[0][1] * right.matrix[1][1] + matrix[0][2] * right.matrix[2][1] + matrix[0][3] * right.matrix[3][1];
	result[0][2] = matrix[0][0] * right.matrix[0][2] + matrix[0][1] * right.matrix[1][2] + matrix[0][2] * right.matrix[2][2] + matrix[0][3] * right.matrix[3][2];
	result[0][3] = matrix[0][0] * right.matrix[0][3] + matrix[0][1] * right.matrix[1][3] + matrix[0][2] * right.matrix[2][3] + matrix[0][3] * right.matrix[3][3];

	result[1][0] = matrix[1][0] * right.matrix[0][0] + matrix[1][1] * right.matrix[1][0] + matrix[1][2] * right.matrix[2][0] + matrix[1][3] * right.matrix[3][0];
	result[1][1] = matrix[1][0] * right.matrix[0][1] + matrix[1][1] * right.matrix[1][1] + matrix[1][2] * right.matrix[2][1] + matrix[1][3] * right.matrix[3][1];
	result[1][2] = matrix[1][0] * right.matrix[0][2] + matrix[1][1] * right.matrix[1][2] + matrix[1][2] * right.matrix[2][2] + matrix[1][3] * right.matrix[3][2];
	result[1][3] = matrix[1][0] * right.matrix[0][3] + matrix[1][1] * right.matrix[1][3] + matrix[1][2] * right.matrix[2][3] + matrix[1][3] * right.matrix[3][3];

	result[2][0] = matrix[2][0] * right.matrix[0][0] + matrix[2][1] * right.matrix[1][0] + matrix[2][2] * right.matrix[2][0] + matrix[2][3] * right.matrix[3][0];
	result[2][1] = matrix[2][0] * right.matrix[0][1] + matrix[2][1] * right.matrix[1][1] + matrix[2][2] * right.matrix[2][1] + matrix[2][3] * right.matrix[3][1];
	result[2][2] = matrix[2][0] * right.matrix[0][2] + matrix[2][1] * right.matrix[1][2] + matrix[2][2] * right.matrix[2][2] + matrix[2][3] * right.matrix[3][2];
	result[2][3] = matrix[2][0] * right.matrix[0][3] + matrix[2][1] * right.matrix[1][3] + matrix[2][2] * right.matrix[2][3] + matrix[2][3] * right.matrix[3][3];

	result[3][0] = matrix[3][0] * right.matrix[0][0] + matrix[3][1] * right.matrix[1][0] + matrix[3][2] * right.matrix[2][0] + matrix[3][3] * right.matrix[3][0];
	result[3][1] = matrix[3][0] * right.matrix[0][1] + matrix[3][1] * right.matrix[1][1] + matrix[3][2] * right.matrix[2][1] + matrix[3][3] * right.matrix[3][1];
	result[3][2] = matrix[3][0] * right.matrix[0][2] + matrix[3][1] * right.matrix[1][2] + matrix[3][2] * right.matrix[2][2] + matrix[3][3] * right.matrix[3][2];
	result[3][3] = matrix[3][0] * right.matrix[0][3] + matrix[3][1] * right.matrix[1][3] + matrix[3][2] * right.matrix[2][3] + matrix[3][3] * right.matrix[3][3];

	std::memcpy(matrix, result, 4 * 4 * sizeof(float));

}

inline const Matrix4x4 Matrix4x4:: operator+(const Matrix4x4 & right) const
{
	Matrix4x4 result(*this);
	result.add(right);
	return result;
}
inline const Matrix4x4 Matrix4x4:: operator-(const Matrix4x4 & right) const
{
	Matrix4x4 result(*this);
	result.subtract(right);
	return result;
}
inline const Matrix4x4 Matrix4x4:: operator* (const Matrix4x4 & right) const
{
	Matrix4x4 result(*this);
	result.multiply(right);
	return result;
}
