#ifndef MATHS_H
#define MATHS_H

#include <stdint.h>

//extern int __mulsi3(int a, int b);

//__attribute__((no_profile_instrument_function)) uint32_t multu32_t(uint32_t op_a, uint32_t op_b);

uint32_t divu32_t(uint32_t op_a, uint32_t op_b);

uint32_t modu32_t(uint32_t op_a, uint32_t op_b);



#endif
