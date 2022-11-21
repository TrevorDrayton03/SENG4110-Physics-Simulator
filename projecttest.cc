/**
* @brief 
* @author Trevor Drayton
* @date 
* @version 1.0
*/
#include "simulation.h"
#include "cannon.h"
#include "cannonball.h"
#include "gtest/gtest.h"

using namespace projectlib;


TEST(Slice, Slice1) {
	EXPECT_EQ(Slice1(), 45.00);
}
//TEST(Slice, Slice2) {
//	EXPECT_EQ(Slice2(), 30.00);
//}
//TEST(Slice, Slice3) {
//	EXPECT_EQ(Slice3(), 25.00);
//}
//TEST(Slice, Slice4) {
//	EXPECT_EQ(Slice4(), 0);
//}
//TEST(Slice, Slice5) {
//	EXPECT_EQ(Slice5(), 0);
//}
//TEST(Slice, Slice6) {
//	EXPECT_EQ(Slice6(), 0);
//}
//TEST(Slice, Slice7) {
//	std::istringstream sin("10");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice7(), 10);
//}
//TEST(Slice, Slice8) {
//	std::istringstream sin("-1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice8(NULL, NULL), -1);
//}
//TEST(Slice, Slice9) {
//	std::istringstream sin("10 2 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice9(), 2);
//}
//TEST(Slice, Slice10) {
//	std::istringstream sin("10 3 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice10(), 3);
//}
//TEST(Slice, Slice11) {
//	std::istringstream sin("10 12 13 14 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice11(), 14);
//}
//TEST(Slice, Slice12) {
//	std::istringstream sin("10 12 13 14 -1 10 12 13 14 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice12(), 49.00);
//}
//TEST(Slice, Slice13) {
//	std::istringstream sin("10 2 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice13(), 2);
//}
//TEST(Slice, Slice14) {
//	std::istringstream sin("10 2 10 2 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice14(), 4);
//}
//TEST(Slice, Slice15) {
//	std::istringstream sin("10 2 10 2 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice15(), 2);
//}
//TEST(Slice, Slice16) {
//	std::istringstream sin("10 2 10 2 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice16(), 4);
//}
//TEST(Slice, Slice17) {
//	std::istringstream sin("10 12 13 14 -1 10 12 13 14 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	ASSERT_STREQ(Slice17().c_str(), "Locks sold: 49");
//}
//TEST(Slice, Slice18) {
//	std::istringstream sin("10 2 10 2 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	ASSERT_STREQ(Slice18().c_str(), "Stocks sold: 4");
//}
//TEST(Slice, Slice19) {
//	std::istringstream sin("10 2 10 2 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	ASSERT_STREQ(Slice19().c_str(), "Barrels sold: 4");
//}
//
//TEST(Slice, Slice20) {
//	EXPECT_EQ(Slice20(), 45.00);
//}
//TEST(Slice, Slice21) {
//	std::istringstream sin("10 12 13 14 -1 10 12 13 14 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice21(), 49.00);
//}
//TEST(Slice, Slice22) {
//	std::istringstream sin("10 12 13 14 -1 10 12 13 14 -1");
//	std::cin.rdbuf(sin.rdbuf());
//	EXPECT_EQ(Slice22(), 2205.00);
}


int main(int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
