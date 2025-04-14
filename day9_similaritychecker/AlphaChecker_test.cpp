#include "gmock/gmock.h"
#include "AlphaChecker.cpp"


TEST(AlphabetScoreTest, AllSameLetters) {
    Alpha alpha;
    EXPECT_EQ(alpha.calculateAlphabetScore("AAABB", "BA"), 40);
    EXPECT_EQ(alpha.calculateAlphabetScore("ASD", "DSA"), 40);
}

TEST(AlphabetScoreTest, AllDifferentLetters) {
    Alpha alpha;
    EXPECT_EQ(alpha.calculateAlphabetScore("A", "BB"), 0); 
}

TEST(AlphabetScoreTest, PartialMatch) {
    Alpha alpha;
    EXPECT_EQ(alpha.calculateAlphabetScore("AA", "AAE"), 20);
}


int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}