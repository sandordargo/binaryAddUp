#include "gtest/gtest.h"
#include "BinaryAddUp.h"

#include <bitset>
#include <limits>
#include <exception>

TEST(BinaryAddUp, sumOfZeros_Is_Zero) {
    ASSERT_EQ(0, BinaryAddUp::add(0,0));
}

TEST(BinaryAddUp, addNumbersWithoutCarryOver) {
    ASSERT_EQ(5, BinaryAddUp::add(1,4));
}

TEST(BinaryAddUp, addNumbersWithCarryOvers) {
    ASSERT_EQ(14, BinaryAddUp::add(11,3));
}

TEST(BinaryAddUp, addNegativeNumberWithZeroSum) {
    ASSERT_EQ(0, BinaryAddUp::add(-2,2));
}

TEST(BinaryAddUp, addNegativeNumbersWithPositiveSum) {
    ASSERT_EQ(18, BinaryAddUp::add(-2,20));
}

TEST(BinaryAddUp, addNegativeNumbersWithNegativeSum) {
    ASSERT_EQ(-18, BinaryAddUp::add(-20,2));
}

TEST(BinaryAddUp, biggestNonOverflowingNumberDoesNotThrowException) {
    ASSERT_EQ(std::numeric_limits<int>::max(),
              BinaryAddUp::add(std::numeric_limits<int>::max()-1,1));
}

TEST(BinaryAddUp, smallestOverflowingPositiveNumberThrowsException) {
    ASSERT_THROW(BinaryAddUp::add(std::numeric_limits<int>::max(),1), std::overflow_error);
}

TEST(BinaryAddUp, smallestNonOverflowingNumberDoesNotThrowException) {
    ASSERT_EQ(std::numeric_limits<int>::min(),
              BinaryAddUp::add(std::numeric_limits<int>::min()+1,-1));
}

TEST(BinaryAddUp, biggestOverflowingNumberThrowsException) {
    ASSERT_THROW(BinaryAddUp::add(std::numeric_limits<int>::min(),-1), std::overflow_error);
}


TEST(BinaryAddUp, convertZeroToBitsetOfZeros) {
    ASSERT_EQ(std::bitset<32>("00000000000000000000000000000000"), BinaryAddUp::intToBitset(0));
}

TEST(BinaryAddUp, convertSevenToCorrespondingBitset) {
    ASSERT_EQ(std::bitset<32>("00000000000000000000000000000111"), BinaryAddUp::intToBitset(7));
}
