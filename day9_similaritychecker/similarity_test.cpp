#include "gmock/gmock.h"
#include "similarity.cpp"


// 테스트 시작
TEST(ScoreTest, SameLength) {
    SimilarityChecker checker;

    EXPECT_EQ(checker.calculateScore("hello", "apple"), 60);
    EXPECT_EQ(checker.calculateScore("ASD", "DSA"), 60);
}

TEST(ScoreTest, DoubleLengthDifference) {
    SimilarityChecker checker;
    EXPECT_EQ(checker.calculateScore("abcdefghij", "ab"), 0); 
    EXPECT_EQ(checker.calculateScore("A", "BB"), 0); 
}

TEST(ScoreTest, PartialScore) {
    SimilarityChecker checker;
    EXPECT_EQ(checker.calculateScore("abcd", "abc"), 40);  
    EXPECT_EQ(checker.calculateScore("AAABB", "BAA"), 20);
    EXPECT_EQ(checker.calculateScore("AA", "AAE"), 30);
}

TEST(ScoreTest, CaseInsensitive) {
    SimilarityChecker checker;
    EXPECT_EQ(checker.calculateScore("Test", "test"), 60);  
}

TEST(ScoreTest, EmptyStringHandling) {
    SimilarityChecker checker;
    EXPECT_EQ(checker.calculateScore("", ""), 60);          
    EXPECT_EQ(checker.calculateScore("nonempty", ""), 0);   
}



int main() {
    ::testing::InitGoogleMock();
    return RUN_ALL_TESTS();
}