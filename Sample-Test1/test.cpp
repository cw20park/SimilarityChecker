#include "pch.h"
#include "..\Project19\SimilarityChecker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker similarityChecker;
};

TEST_F(SimilarityCheckerFixture, sameLength) {

	EXPECT_EQ(MAX_LENGTH_CHECK_POINT, similarityChecker.checkLength("ASD", "DSA"));
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
TEST_F(SimilarityCheckerFixture, sameAlphabetCount) {

	EXPECT_EQ(40, similarityChecker.checkSameAlphabetCount("ASD", "DSA"));
}
TEST_F(SimilarityCheckerFixture, diffAlphabetCount1) {

	EXPECT_EQ(0, similarityChecker.checkSameAlphabetCount("A", "BB"));
}
TEST_F(SimilarityCheckerFixture, diffAlphabetCount2) {

	EXPECT_EQ(40, similarityChecker.checkSameAlphabetCount("AAABB", "BA"));
}
TEST_F(SimilarityCheckerFixture, diffAlphabetCount3) {

	EXPECT_EQ(20, similarityChecker.checkSameAlphabetCount("AA", "AAE"));
}
TEST_F(SimilarityCheckerFixture, smallLetter) {

	EXPECT_EQ(0, similarityChecker.checkSameAlphabetCount("small", "letter"));
}