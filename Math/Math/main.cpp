#include "../gtest-1.7.0/include/gtest/gtest.h"
#include "math\Vector2D.h"
using namespace Math;
int main(int argc, char**argv)
{
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
	system("PAUSE");
	return 0;
}