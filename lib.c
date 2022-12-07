#include "lib.h"
#include <stdio.h>

uint8_t parityCheck(uint8_t input) {
    uint8_t result = 0x00; 
    for (uint8_t i = 0; i < 8; i++) {
        result ^= ((input >> i) & 0x01);
    }
    return result;
}

static uint8_t affineTrans(uint8_t input) {
    uint8_t output = 0;
    for (uint8_t i = 0; i < 8; i ++) {
        output |=  ( parityCheck(input & affineMatrix[i]) << i );
    }
    output ^= 0x63;
    return output;
}

static uint8_t multipleInGF28(uint8_t a, uint8_t b) {
    uint16_t result = 0;
    uint16_t temp = (uint16_t) a ; 
    while (b > 0)
    {
        if (b & 0x01) result ^= temp;
        b = b >> 1;
        temp = temp << 1;

        if (temp & 0x0100) temp ^= modulo;
    }
    return result;
}

static uint8_t byteInverseGF(uint8_t input) { 
    uint8_t output = 0;
    while (1) {
        output++;
        if (multipleInGF28(input, output) == 0x01)
            return output;
    }
}

void initSboxMatric() {
    sboxMatrix[0] = 0x63;
    for (uint16_t i = 0x01; i <= 0xff; ++i) {
        sboxMatrix[i] = affineTrans(byteInverseGF(i));
        printf("%02x/",sboxMatrix[i]);
    }
}

int main() {
    // printf("%x",affineTrans(0x1c));
    initSboxMatric();
    return 0;
}
