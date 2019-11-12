
#ifndef BINARY_ADD_UP_BINARYADDUP_H
#define BINARY_ADD_UP_BINARYADDUP_H

#include <bitset>


namespace BinaryAddUp {
    std::bitset<32> intToBitset(int number) {
        std::bitset<32> numberAsBits(number);
        return numberAsBits;
    }

    int add(int a, int b) {
        // Implements a full adder circuit
        // More information at https://en.wikipedia.org/wiki/Adder_(electronics)#Full_adder
        auto aBits{intToBitset(a)};
        auto bBits{intToBitset(b)};
        auto resultBits{intToBitset(0)};
        bool carryOver = false;
        for (size_t i=0; i<aBits.size(); ++i) {
            resultBits[i] = (aBits[i] ^ bBits[i]) ^ carryOver;
            carryOver = (aBits[i] and bBits[i]) or ((aBits[i] ^ bBits[i]) and carryOver);
        }
        return resultBits.to_ulong();
    }
}

#endif //BINARY_ADD_UP_BINARYADDUP_H
