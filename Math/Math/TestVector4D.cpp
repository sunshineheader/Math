#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "math\Vector4D.h"
using  Math::Vector4D;
TEST(Vector4D, Constrauctor)
{
	Vector4D vector;
	EXPECT_FLOAT_EQ(vector.x, 0.0f);
	EXPECT_FLOAT_EQ(vector.y, 0.0f);
	EXPECT_FLOAT_EQ(vector.w, 0.0f);
	EXPECT_FLOAT_EQ(vector.z, 0.0f);
	EXPECT_TRUE(0.0f == vector.x);
	EXPECT_TRUE(0.0f == vector.y);
	EXPECT_TRUE(0.0f == vector.w);
	EXPECT_TRUE(0.0f == vector.z);
}
TEST(Vector4D, CopyConstrauctor)
{
	Vector4D vector(1.0f,1.0f,1.0f,0.0f);
	Vector4D copyVector(vector);
	EXPECT_FLOAT_EQ(copyVector.x, 1.0f);
	EXPECT_FLOAT_EQ(copyVector.y, 1.0f);
	EXPECT_FLOAT_EQ(copyVector.z, 1.0f);
	EXPECT_FLOAT_EQ(copyVector.w, 0.0f);
	EXPECT_TRUE(1.0f == copyVector.x);
	EXPECT_TRUE(1.0f == copyVector.y);
	EXPECT_TRUE(1.0f == copyVector.z);
	EXPECT_TRUE(0.0f == copyVector.w);
}

TEST(Vector4D, Vector4DAdding)
{
	Vector4D left(1.0f, 1.0f,10.0f,2.0f);
	Vector4D right(1.0f, 1.0f, 0.0f, 2.0f);
	Vector4D result = left + right;
	EXPECT_FLOAT_EQ(result.x, 2.0f);
	EXPECT_FLOAT_EQ(result.y, 2.0f);
	EXPECT_FLOAT_EQ(result.z, 10.0f);
	EXPECT_FLOAT_EQ(result.w, 4.0f);
	EXPECT_TRUE(2.0f == result.x);
	EXPECT_TRUE(2.0f == result.y);
	EXPECT_TRUE(10.0f == result.z);
	EXPECT_TRUE(4.0f == result.w);
}
TEST(Vector4D, Vector4DSubtract)
{
	Vector4D left(1.0f, 1.0f, 10.0f, 2.0f);
	Vector4D right(1.0f, 1.0f, 0.0f, 2.0f);
	Vector4D result = left - right;
	EXPECT_FLOAT_EQ(result.x, 0.0f);
	EXPECT_FLOAT_EQ(result.y, 0.0f);
	EXPECT_FLOAT_EQ(result.z, 10.0f);
	EXPECT_FLOAT_EQ(result.w, 0.0f);
	EXPECT_TRUE(0.0f == result.x);
	EXPECT_TRUE(0.0f == result.y);
	EXPECT_TRUE(10.0f == result.z);
	EXPECT_TRUE(0.0f == result.w);
}

TEST(Vector4D, Vector4DMultiply)
{
	Vector4D left(1.0f, 1.0f, 10.0f, 2.0f);
	Vector4D right(1.0f, 1.0f, 0.0f, 2.0f);
	Vector4D result = left * right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 1.0f);
	EXPECT_FLOAT_EQ(result.z, 0.0f);
	EXPECT_FLOAT_EQ(result.w, 4.0f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(1.0f == result.y);
	EXPECT_TRUE(0.0f == result.z);
	EXPECT_TRUE(4.0f == result.w);
}

TEST(Vector4D, Vector4DDDivide)
{
	Vector4D left(1.0f, 1.0f, 10.0f, 2.0f);
	Vector4D right(1.0f, 1.0f, 1.0f, 2.0f);
	Vector4D result = left / right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 1.0f);
	EXPECT_FLOAT_EQ(result.z, 10.0f);
	EXPECT_FLOAT_EQ(result.w, 1.0f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(1.0f == result.y);
	EXPECT_TRUE(10.0f == result.z);
	EXPECT_TRUE(1.0f == result.w);
}
TEST(Vector4D, Vector4DPlusplusAdding)
{
	Vector4D right(1.0f, 1.0f, 1.0f, 2.0f);
	Vector4D result(1.0f, 1.0f, 10.0f, 2.0f);
	result += right;
	EXPECT_FLOAT_EQ(result.x, 2.0f);
	EXPECT_FLOAT_EQ(result.y, 2.0f);
	EXPECT_FLOAT_EQ(result.z, 11.0f);
	EXPECT_FLOAT_EQ(result.w, 4.0f);
	EXPECT_TRUE(2.0f == result.x);
	EXPECT_TRUE(2.0f == result.y);
	EXPECT_TRUE(11.0f == result.z);
	EXPECT_TRUE(4.0f == result.w);
}

TEST(Vector4D, Vector4DSubtractSubtract)
{
	Vector4D right(1.0f, 1.0f, 1.0f, 2.0f);
	Vector4D result(1.0f, 1.0f, 10.0f, 2.0f);
	result -= right;
	EXPECT_FLOAT_EQ(result.x, 0.0f);
	EXPECT_FLOAT_EQ(result.y, 0.0f);
	EXPECT_FLOAT_EQ(result.z, 9.0f);
	EXPECT_FLOAT_EQ(result.w, 0.0f);
	EXPECT_TRUE(0.0f == result.x);
	EXPECT_TRUE(0.0f == result.y);
	EXPECT_TRUE(9.0f == result.z);
	EXPECT_TRUE(0.0f == result.w);
}