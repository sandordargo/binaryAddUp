#include "gtest/gtest.h"
#include "BinaryAddUp.h"

#include <bitset>

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

TEST(BinaryAddUp, convertZeroToBitsetOfZeros) {
    ASSERT_EQ(std::bitset<32>("00000000000000000000000000000000"), BinaryAddUp::intToBitset(0));
}

TEST(BinaryAddUp, convertSevenToCorrespondingBitset) {
    ASSERT_EQ(std::bitset<32>("00000000000000000000000000000111"), BinaryAddUp::intToBitset(7));
}
