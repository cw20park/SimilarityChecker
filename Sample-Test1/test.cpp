#include "pch.h"
#include "..\Project19\SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
};

TEST_F(SimilarityCheckerFixture, sameLength) {

	EXPECT_EQ(60, similarityChecker.checkLength("ASD", "DSA"));
}

TEST_F(SimilarityCheckerFixture, diffLength1) {

	EXPECT_EQ(0, similarityChecker.checkLength("A", "BB"));
}

TEST_F(SimilarityCheckerFixture, diffLength2) {

	EXPECT_EQ(0, similarityChecker.checkLength("A", "BBB"));
}

TEST_F(SimilarityCheckerFixture, diffLength3) {

	EXPECT_EQ(20, similarityChecker.checkLength("AAABB", "BAA"));
}
TEST_F(SimilarityCheckerFixture, diffLength4) {

	EXPECT_EQ(30, similarityChecker.checkLength("AA", "AAA"));
}
TEST_F(SimilarityCheckerFixture, noString) {

	EXPECT_EQ(0, similarityChecker.checkLength("", "AAA"));
}