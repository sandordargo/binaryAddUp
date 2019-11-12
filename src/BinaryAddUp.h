
#ifndef BINARY_ADD_UP_BINARYADDUP_H
#define BINARY_ADD_UP_BINARYADDUP_H

#include <bitset>


namespace BinaryAddUp {
    std::bitset<32> intToBitset(int number) {
        std::bitset<32> numberAsBits(number);
        return numberAsBits;
    }

    int add(int a, int b) {
        auto resultBits{intToBitset(0)};
        return resultBits.to_ulong();
    }
}

#endif //BINARY_ADD_UP_BINARYADDUP_H
