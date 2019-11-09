#include "gtest/gtest.h"
#include "BinaryAddUp.h"

TEST(BinaryAddUp, sumOfZeros_Is_Zero) {
    ASSERT_EQ(0, BinaryAddUp::add(0,0));
}