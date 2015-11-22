#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "math/Matrix4x4.h"
using Math::Vector3D;
using Math::Vector4D;
using Math::Matrix4x4;

TEST(Matrix4x4, Constrauctor)
{
	Matrix4x4 matrix(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	EXPECT_FLOAT_EQ(matrix.matrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][0], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][0], 0.0f);

	EXPECT_FLOAT_EQ(matrix.matrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][1], 1.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][1], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][1], 0.0f);

	EXPECT_FLOAT_EQ(matrix.matrix[0][2], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][2], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][2], 1.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][2], 0.0f);

	EXPECT_FLOAT_EQ(matrix.matrix[0][3], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][3], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][3], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][3], 1.0f);
}

TEST(Matrix4x4, CopyConstrauctor)
{
	Matrix4x4 matrix(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	Matrix4x4 copyMatrix(matrix);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[2][0], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[3][0], 0.0f);

	EXPECT_FLOAT_EQ(copyMatrix.matrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[1][1], 1.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[2][1], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[3][1], 0.0f);

	EXPECT_FLOAT_EQ(copyMatrix.matrix[0][2], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[1][2], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[2][2], 1.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[3][2], 0.0f);

	EXPECT_FLOAT_EQ(copyMatrix.matrix[0][3], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[1][3], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[2][3], 0.0f);
	EXPECT_FLOAT_EQ(copyMatrix.matrix[3][3], 1.0f);

}
TEST(Matrix4x4, Matrix4x4Identity)
{

	Matrix4x4 matrix(1.0f);
	matrix = matrix.getMatrixIndentity();
	EXPECT_FLOAT_EQ(matrix.matrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][0], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][0], 0.0f);

	EXPECT_FLOAT_EQ(matrix.matrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][1], 1.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][1], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][1], 0.0f);

	EXPECT_FLOAT_EQ(matrix.matrix[0][2], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][2], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][2], 1.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][2], 0.0f);

	EXPECT_FLOAT_EQ(matrix.matrix[0][3], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[1][3], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[2][3], 0.0f);
	EXPECT_FLOAT_EQ(matrix.matrix[3][3], 1.0f);
}

TEST(Matrix4x4, Matrix4x4Multiply)
{
	Matrix4x4 leftMatrix(
		2.0f, 0.0f, 0.0f, 10.0f,
		0.0f, 2.0f, 0.0f, 10.0f,
		0.0f, 0.0f, 2.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 2.0f
		);
	Matrix4x4 rightMatrix(1.0f);
	Matrix4x4 reslutmatrix = leftMatrix*rightMatrix;

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][0], 2);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][0], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][0], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][1], 2);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][1], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][1], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][2], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][2], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][2], 2);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][2], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][3], 10.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][3], 10.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][3], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][3], 2);
}

TEST(Matrix4x4, Vector4DMatrixMultiply)
{
	Matrix4x4 leftMatrix(
		1.0f, 0.0f, 0.0f, 10.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	Vector4D right(1,
		           2,
		           3,
		           1
				   );
	Vector4D reslut = leftMatrix.multiply(right);
	EXPECT_FLOAT_EQ(reslut.x, 11.0f);
	EXPECT_FLOAT_EQ(reslut.y, 2.0f);
	EXPECT_FLOAT_EQ(reslut.z, 3.0f);
	EXPECT_FLOAT_EQ(reslut.w, 1.0f);
}

TEST(Matrix4x4, Vector3DMatrixMultiply)
{
	Matrix4x4 leftMatrix(
		1.0f, 0.0f, 0.0f, 10.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	Vector3D right(1,
		           2,
		           3);
	Vector3D reslut = leftMatrix.multiply(right);
	EXPECT_FLOAT_EQ(reslut.x, 11.0f);
	EXPECT_FLOAT_EQ(reslut.y, 2.0f);
	EXPECT_FLOAT_EQ(reslut.z, 3.0f);
}

TEST(Matrix4x4, ScaleMatrix)
{
	Matrix4x4 reslutmatrix(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	Vector3D scalar(0.1f,2.0f,3.5f);
	reslutmatrix = reslutmatrix.scaleMatrix(scalar.x, scalar.y, scalar.z);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][0], 0.1f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][0], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][0], 0.0f);


	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][1], 2,0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][1], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][1], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][2], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][2], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][2], 3.5f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][2], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][3], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][3], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][3], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][3], 1.0f);
}

TEST(Matrix4x4, RotationMatrix)
{
	Matrix4x4 reslutmatrix(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	Vector3D rotate(1.0f, 2.0f, 3.0f);

	reslutmatrix = reslutmatrix.rotationMatrix(rotate.x, rotate.y, rotate.z);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][0], 0.998021185f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][0], 0.0523040779f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][0], 0.0348994955f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][0], 0.0f);


	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][1], -0.0529362373f); 
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][1], 0.998445570f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][1], 0.0174417738f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][1], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][2], -0.0339329690f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][2], -0.0192547087f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][2], 0.999238670f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][2], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][3], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][3], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][3], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][3], 1.0f);
}

TEST(Matrix4x4, TranslationMatrix)
{
	Matrix4x4 reslutmatrix(
		1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 1.0f
		);
	Vector3D transform(0.1f, 2.0f, 3.5f);

	reslutmatrix = reslutmatrix.translationMatrix(transform.x, transform.y, transform.z);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][0], 1.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][0], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][0], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][0], 0.0f);


	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][1], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][1], 1.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][1], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][1], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][2], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][2], 0.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][2], 1.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][2], 0.0f);

	EXPECT_FLOAT_EQ(reslutmatrix.matrix[0][3], 0.1f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[1][3], 2.0f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[2][3], 3.5f);
	EXPECT_FLOAT_EQ(reslutmatrix.matrix[3][3], 1.0f);
}