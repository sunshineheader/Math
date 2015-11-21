#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "math/Matrix4x4.h"
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