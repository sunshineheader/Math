#include "Matrix4x4.h"

namespace Math{


	Matrix4x4 Matrix4x4::getMatrixIndentity()const
	{
		Matrix4x4 indentityMatrix(*this);
		indentityMatrix.identity();
		return indentityMatrix;
	}

	Vector3D  Matrix4x4::multiply(const Vector3D & right)
	{
		Vector3D result;
		result.x = matrix[0][0] * right.x + matrix[0][1] * right.y + matrix[0][2] * right.z + matrix[0][3] * 1;
		result.y = matrix[1][0] * right.x + matrix[1][1] * right.y + matrix[1][2] * right.z + matrix[1][3] * 1;
		result.z = matrix[2][0] * right.x + matrix[2][1] * right.y + matrix[2][2] * right.z + matrix[2][3] * 1;
		//result.w = matrix[3][0] * right.x + matrix[3][1] * right.y + matrix[3][2] * right.z + matrix[3][3] * 0;
		return result;
	}
	Vector4D Matrix4x4::multiply(const Vector4D & right)
	{
		Vector4D result;
		result.x = matrix[0][0] * right.x + matrix[0][1] * right.y + matrix[0][2] * right.z + matrix[0][3] * right.w;
		result.y = matrix[1][0] * right.x + matrix[1][1] * right.y + matrix[1][2] * right.z + matrix[1][3] * right.w;
		result.z = matrix[2][0] * right.x + matrix[2][1] * right.y + matrix[2][2] * right.z + matrix[2][3] * right.w;
		result.w = matrix[3][0] * right.x + matrix[3][1] * right.y + matrix[3][2] * right.z + matrix[3][3] * right.w;
		return result;
	}

	Matrix4x4 Matrix4x4::scaleMatrix(float ScaleX, float ScaleY, float ScaleZ)
	{
		matrix[0][0] = ScaleX; matrix[0][1] = 0.0f;   matrix[0][2] = 0.0f;   matrix[0][3] = 0.0f;
		matrix[1][0] = 0.0f;   matrix[1][1] = ScaleY; matrix[1][2] = 0.0f;   matrix[1][3] = 0.0f;
		matrix[2][0] = 0.0f;   matrix[2][1] = 0.0f;   matrix[2][2] = ScaleZ; matrix[2][3] = 0.0f;
		matrix[3][0] = 0.0f;   matrix[3][1] = 0.0f;   matrix[3][2] = 0.0f;   matrix[3][3] = 1.0f;
		return *this;
	}

	Matrix4x4 Matrix4x4::rotationMatrix(float RotateX, float RotateY, float RotateZ)
	{
		Matrix4x4 rx, ry, rz;

		const float x =ToRadian(RotateX);
		const float y =ToRadian(RotateY);
		const float z =ToRadian(RotateZ);

		rx.matrix[0][0] = 1.0f;    rx.matrix[0][1] = 0.0f;     rx.matrix[0][2] = 0.0f;     rx.matrix[0][3] = 0.0f;
		rx.matrix[1][0] = 0.0f;    rx.matrix[1][1] = cosf(x);  rx.matrix[1][2] = -sinf(x); rx.matrix[1][3] = 0.0f;
		rx.matrix[2][0] = 0.0f;    rx.matrix[2][1] = sinf(x);  rx.matrix[2][2] = cosf(x);  rx.matrix[2][3] = 0.0f;
		rx.matrix[3][0] = 0.0f;    rx.matrix[3][1] = 0.0f;     rx.matrix[3][2] = 0.0f;     rx.matrix[3][3] = 1.0f;

		ry.matrix[0][0] = cosf(y); ry.matrix[0][1] = 0.0f;     ry.matrix[0][2] = -sinf(y); ry.matrix[0][3] = 0.0f;
		ry.matrix[1][0] = 0.0f;    ry.matrix[1][1] = 1.0f;     ry.matrix[1][2] = 0.0f;     ry.matrix[1][3] = 0.0f;
		ry.matrix[2][0] = sinf(y); ry.matrix[2][1] = 0.0f;     ry.matrix[2][2] = cosf(y);  ry.matrix[2][3] = 0.0f;
		ry.matrix[3][0] = 0.0f;    ry.matrix[3][1] = 0.0f;     ry.matrix[3][2] = 0.0f;     ry.matrix[3][3] = 1.0f;

		rz.matrix[0][0] = cosf(z); rz.matrix[0][1] = -sinf(z); rz.matrix[0][2] = 0.0f;     rz.matrix[0][3] = 0.0f;
		rz.matrix[1][0] = sinf(z); rz.matrix[1][1] = cosf(z);  rz.matrix[1][2] = 0.0f;     rz.matrix[1][3] = 0.0f;
		rz.matrix[2][0] = 0.0f;    rz.matrix[2][1] = 0.0f;     rz.matrix[2][2] = 1.0f;     rz.matrix[2][3] = 0.0f;
		rz.matrix[3][0] = 0.0f;    rz.matrix[3][1] = 0.0f;     rz.matrix[3][2] = 0.0f;     rz.matrix[3][3] = 1.0f;
																					       
		return *this = rz * ry * rx;
		
	}


	Matrix4x4 Matrix4x4::translationMatrix(float x, float y, float z)
	{
		matrix[0][0] = 1.0f; matrix[0][1] = 0.0f; matrix[0][2] = 0.0f; matrix[0][3] = x;
		matrix[1][0] = 0.0f; matrix[1][1] = 1.0f; matrix[1][2] = 0.0f; matrix[1][3] = y;
		matrix[2][0] = 0.0f; matrix[2][1] = 0.0f; matrix[2][2] = 1.0f; matrix[2][3] = z;
		matrix[3][0] = 0.0f; matrix[3][1] = 0.0f; matrix[3][2] = 0.0f; matrix[3][3] = 1.0f;
		return *this;
	}

	std::ostream& operator<<(std::ostream& stream, const Matrix4x4 & Matrix)
	{
		const int wide = 4;
		for (int i = 0; i < wide; i++)
		{
			for (int j = 0; j < wide; j++)
			{
				stream << "Matrix4x4[" << i << "][" << j << "] is " << Matrix.matrix[i][j] << std::endl;
			}
		}
		return stream;
	}
}