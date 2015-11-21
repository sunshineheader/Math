#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "math/Vector3D.h"
using Math::Vector3D;

TEST(Vector3D, Constrauctor)
{
	Vector3D vector;
	EXPECT_FLOAT_EQ(vector.x, 0.0f);
	EXPECT_FLOAT_EQ(vector.y, 0.0f);
	EXPECT_FLOAT_EQ(vector.z, 0.0f);
	EXPECT_TRUE(0.0f == vector.x);
	EXPECT_TRUE(0.0f == vector.y);
	EXPECT_TRUE(0.0f == vector.z);
}
TEST(Vector3D, CopyConstrauctor)
{
	Vector3D vector(1.0f, 1.0f,1.0f);
	Vector3D copyVector(vector);
	EXPECT_FLOAT_EQ(copyVector.x, 1.0f);
	EXPECT_FLOAT_EQ(copyVector.y, 1.0f);
	EXPECT_FLOAT_EQ(copyVector.z, 1.0f);

	EXPECT_TRUE(1.0f == copyVector.x);
	EXPECT_TRUE(1.0f == copyVector.y);
	EXPECT_TRUE(1.0f == copyVector.z);

}

TEST(Vector3D, ArguementConstrauctor)
{
	Vector3D vector(1.0f, 1.0f,1.0f);
	EXPECT_FLOAT_EQ(vector.x, 1.0f);
	EXPECT_FLOAT_EQ(vector.y, 1.0f);
	EXPECT_FLOAT_EQ(vector.z, 1.0f);
	EXPECT_TRUE(1.0f == vector.x);
	EXPECT_TRUE(1.0f == vector.y);
	EXPECT_TRUE(1.0f == vector.z);
}

TEST(Vector3D, Vector3DAdding)
{
	Vector3D left(1.0f, 1.0f,2.0f);
	Vector3D right(1.0f, 1.0f, 42.0f);
	Vector3D result = left + right;
	EXPECT_FLOAT_EQ(result.x, 2.0f);
	EXPECT_FLOAT_EQ(result.y, 2.0f);
	EXPECT_FLOAT_EQ(result.z, 44.0f);
	EXPECT_TRUE(2.0f == result.x);
	EXPECT_TRUE(2.0f == result.y);
	EXPECT_TRUE(44.0f == result.z);
}

TEST(Vector3D, Vector3DSubtract)
{
	Vector3D left(1.0f, 1.0f, 4.0f);
	Vector3D right(1.0f, 1.0f, 4.0f);
	Vector3D result = left - right;
	EXPECT_FLOAT_EQ(result.x, 0.0f);
	EXPECT_FLOAT_EQ(result.y, 0.0f);
	EXPECT_FLOAT_EQ(result.z, 0.0f);
	EXPECT_TRUE(0.0f == result.x);
	EXPECT_TRUE(0.0f == result.y);
	EXPECT_TRUE(0.0f == result.z);
}

TEST(Vector3D, Vector3DMultiply)
{
	Vector3D left(1.0f, 1.0f, 4.0f);
	Vector3D right(1.0f, 1.0f, 4.0f);
	Vector3D result = left * right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 1.0f);
	EXPECT_FLOAT_EQ(result.z, 16.0f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(1.0f == result.y);
	EXPECT_TRUE(16.0f == result.z);
}

TEST(Vector3D, Vector3DDivide)
{
	Vector3D left(1.0f, 1.0f, 4.0f);
	Vector3D right(1.0f, 1.0f, 4.0f);
	Vector3D result = left / right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 1.0f);
	EXPECT_FLOAT_EQ(result.z, 1.0f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(1.0f == result.y);
	EXPECT_TRUE(1.0f == result.z);
}

TEST(Vector3D, ScalarMultiplication)
{
	Vector3D vector(-7, -3, 1);
	Vector3D reslut1 = vector * 8;
	Vector3D reslut2 = 8 * vector;
	EXPECT_FLOAT_EQ(reslut1.x, -56);
	EXPECT_FLOAT_EQ(reslut1.y, -24);
	EXPECT_FLOAT_EQ(reslut1.z, 8);

	EXPECT_FLOAT_EQ(reslut2.x, -56);
	EXPECT_FLOAT_EQ(reslut2.y, -24);
	EXPECT_FLOAT_EQ(reslut2.z, 8);

	EXPECT_TRUE(reslut1.x == reslut2.x);
	EXPECT_TRUE(reslut1.y == reslut2.y);
	EXPECT_TRUE(reslut1.z == reslut2.z);

}

TEST(Vector3D, Vector3DNrmalized)
{
	Vector3D normalize(3.0f, 4.0f,0.0f);
	EXPECT_FLOAT_EQ(normalize.getNormalized().x, 0.600000024f);
	EXPECT_FLOAT_EQ(normalize.getNormalized().y, 0.800000012f);
	EXPECT_FLOAT_EQ(normalize.getNormalized().z, 0.0f);

	EXPECT_TRUE(normalize.getNormalized().x == 0.600000024f);
	EXPECT_TRUE(normalize.getNormalized().y == 0.800000012f);
	EXPECT_TRUE(normalize.getNormalized().z == 0.0f);

}

TEST(Vector3D, Vector3DLength)
{
	Vector3D length(10.0f, 10.0f,10.0f);
	EXPECT_FLOAT_EQ(length.length(), 17.3205090f);
	EXPECT_FLOAT_EQ(length.lengthSquared(), 300.0f);
	EXPECT_TRUE(length.length() == 17.3205090f);
	EXPECT_TRUE(length.lengthSquared() == 300.0f);
}

TEST(Vector3D, Vector3DDistance)
{
	Vector3D point(10.0f, 10.0f, 10.0f);
	Vector3D otherPoint(20.0f, 20.0f, 20.0f);
	EXPECT_FLOAT_EQ(otherPoint.distance(point), 17.3205090f);
	EXPECT_FLOAT_EQ(otherPoint.distanceSquared(point), 300.0f);
	EXPECT_TRUE(otherPoint.distance(point) == 17.3205090f);
	EXPECT_TRUE(otherPoint.distanceSquared(point) == 300.0f);
}