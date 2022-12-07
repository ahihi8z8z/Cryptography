#include <string.h>
#include <stdlib.h>
#include <stdint.h>

#define ROTL(x,shift) (uint8_t) ((x << shift) | (x >> (8 - shift)))
#define modulo (uint16_t)0x011b
uint8_t parityCheck(uint8_t input) ;

const uint8_t affineMatrix[8] = { 0xf1, ROTL(0xf1,1), ROTL(0xf1,2), ROTL(0xf1,3), ROTL(0xf1,4), ROTL(0xf1,5), ROTL(0xf1,6), ROTL(0xf1,7)};

#define affineConst (uint8_t)0x63;

static uint8_t sboxMatrix[256];

void initSboxMatric() ;
