#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "math/Vector2D.h"
using Math::Vector2D;

TEST(Vector2D,Constrauctor)
{
	Vector2D vector;
	EXPECT_FLOAT_EQ(vector.x, 0.0f);
	EXPECT_FLOAT_EQ(vector.y, 0.0f);
	EXPECT_TRUE(0.0f == vector.x);
	EXPECT_TRUE(0.0f == vector.y);
}


TEST(Vector2D, CopyConstrauctor)
{
	Vector2D vector(1.0f, 1.0f);
	Vector2D copyVector(vector);
	EXPECT_FLOAT_EQ(copyVector.x, 1.0f);
	EXPECT_FLOAT_EQ(copyVector.y, 1.0f);
	EXPECT_TRUE(1.0f == copyVector.x);
	EXPECT_TRUE(1.0f == copyVector.y);
}

TEST(Vector2D, ArguementConstrauctor)
{
	Vector2D vector(1.0f,1.0f);
	EXPECT_FLOAT_EQ(vector.x, 1.0f);
	EXPECT_FLOAT_EQ(vector.y, 1.0f);
	EXPECT_TRUE(1.0f == vector.x);
	EXPECT_TRUE(1.0f == vector.y);
}

TEST(Vector2D, Vector2DAdding)
{
	Vector2D left(1.0f, 1.0f);
	Vector2D right(1.0f, 1.0f);
	Vector2D result = left + right;
	EXPECT_FLOAT_EQ(result.x, 2.0f);
	EXPECT_FLOAT_EQ(result.y, 2.0f);
	EXPECT_TRUE(2.0f == result.x);
	EXPECT_TRUE(2.0f == result.y);
}

TEST(Vector2D, Vector2DSubtract)
{
	Vector2D left(1.0f, 1.0f);
	Vector2D right(1.0f, 1.0f);
	Vector2D result = left - right;
	EXPECT_FLOAT_EQ(result.x, 0.0f);
	EXPECT_FLOAT_EQ(result.y, 0.0f);
	EXPECT_TRUE(0.0f == result.x);
	EXPECT_TRUE(0.0f == result.y);
}

TEST(Vector2D, Vector2DMultiply)
{
	Vector2D left(1.0f, 1.0f);
	Vector2D right(1.0f, 1.0f);
	Vector2D result = left * right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 1.0f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(1.0f == result.y);
}

TEST(Vector2D, Vector2DDivide)
{
	Vector2D left(1.0f, 1.0f);
	Vector2D right(1.0f, 1.0f);
	Vector2D result = left / right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 1.0f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(1.0f == result.y);
}

TEST(Vector2D, Vector2DPlusplusAdding)
{
	Vector2D right(1.0f, 2.0f);
	Vector2D result(1.0f, 1.0f);
	result+= right;
	EXPECT_FLOAT_EQ(result.x, 2.0f);
	EXPECT_FLOAT_EQ(result.y, 3.0f);
	EXPECT_TRUE(2.0f == result.x);
	EXPECT_TRUE(3.0f == result.y);
}

TEST(Vector2D, Vector2DSubtractSubtract)
{
	Vector2D right(1.0f, 3.0f);
	Vector2D result = Vector2D(1.0f, 1.0f);
	result -= right;
	EXPECT_FLOAT_EQ(result.x, 0.0f);
	EXPECT_FLOAT_EQ(result.y, -2.0f);
	EXPECT_TRUE(0.0f == result.x);
	EXPECT_TRUE(-2.0f == result.y);
}

TEST(Vector2D, Vector2DSubtractMultiplyMultiply)
{
	Vector2D right(1.0f, 3.0f);
	Vector2D result = Vector2D(1.0f, 1.0f);
	result *= right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 3.0f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(3.0f == result.y);
}

TEST(Vector2D, Vector2DSubtractDivideDivide)
{
	Vector2D right(1.0f, 4.0f);
	Vector2D result = Vector2D(1.0f, 1.0f);
	result /= right;
	EXPECT_FLOAT_EQ(result.x, 1.0f);
	EXPECT_FLOAT_EQ(result.y, 0.25f);
	EXPECT_TRUE(1.0f == result.x);
	EXPECT_TRUE(0.25f == result.y);
}

TEST(Vector2D, Vector2DEquals)
{
	Vector2D right(1.0f, 4.0f);
	Vector2D result = Vector2D(1.0f, 4.0f);
	result == right;
	EXPECT_TRUE(right== result);
	EXPECT_TRUE(right.x == result.x);
	EXPECT_TRUE(right.y == result.y);
}
TEST(Vector2D, Vector2DNoEquals)
{
	Vector2D right(1.0f, 2.0f);
	Vector2D result = Vector2D(1.0f, 4.0f);
	EXPECT_TRUE(right != result);
	EXPECT_TRUE(right.x == result.x);
	EXPECT_TRUE(right.y != result.y);
	right = Vector2D(2.0f, 4.0f);
	result = Vector2D(1.0f, 4.0f);
	EXPECT_TRUE(right != result);
	EXPECT_TRUE(right.x != result.x);
	EXPECT_TRUE(right.y == result.y);
}

TEST(Vector2D, ScalarMultiplication)
{
	Vector2D vector(-7, -3);
	Vector2D reslut1 = vector * 8;
	Vector2D reslut2 = 8 * vector;
	EXPECT_FLOAT_EQ(reslut1.x, -56);
	EXPECT_FLOAT_EQ(reslut1.y, -24);
	EXPECT_FLOAT_EQ(reslut2.x, -56);
	EXPECT_FLOAT_EQ(reslut2.y, -24);
	EXPECT_TRUE(reslut1.x == reslut2.x);
	EXPECT_TRUE(reslut1.y == reslut2.y);
}
TEST(Vector2D, Vector2DNrmalized)
{
	Vector2D normalize(3.0f, 4.0f);
	EXPECT_FLOAT_EQ(normalize.getNormalized().x, 0.600000024f);
	EXPECT_FLOAT_EQ(normalize.getNormalized().y, 0.800000012f);
	EXPECT_TRUE(normalize.getNormalized().x == 0.600000024f);
	EXPECT_TRUE(normalize.getNormalized().y == 0.800000012f);
}
TEST(Vector2D, Vector2DLength)
{
	Vector2D length(3.0f, 4.0f);
	EXPECT_FLOAT_EQ(length.length(), 5.0f);
	EXPECT_FLOAT_EQ(length.lengthSquared(), 25.0f);
	EXPECT_TRUE(length.length()==5.0f);
	EXPECT_TRUE(length.lengthSquared() == 25.0f);
}
TEST(Vector2D, Vector2DDistance)
{
	Vector2D point(3.0f, 4.0f);
	Vector2D otherPoint(6.0f, 8.0f);
	EXPECT_FLOAT_EQ(otherPoint.distance(point),5.0f);
	EXPECT_FLOAT_EQ(otherPoint.distanceSquared(point), 25.0f);
	EXPECT_TRUE(otherPoint.distance(point) == 5.0f);
	EXPECT_TRUE(otherPoint.distanceSquared(point) == 25.0f);
}