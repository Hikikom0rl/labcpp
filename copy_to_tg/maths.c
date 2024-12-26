#include <maths.h>

//__attribute__((no_profile_instrument_function)) uint32_t multu32_t(uint32_t op_a, uint32_t op_b)
//{
//  if (op_a == 0) return 0;
//  uint32_t result = 0;
//  while (op_b > 0)
//  {
//    result += op_a;
//    op_b -= 1;
//  }
//  return result;
//}
 uint32_t divu32_t(uint32_t op_a, uint32_t op_b)
{
  if (op_b == 0) return -1;
  uint32_t counter = 0;
  while (op_a >= op_b)
  {
    op_a -= op_b;
    ++counter;
  }
  return counter;
}

 uint32_t modu32_t(uint32_t op_a, uint32_t op_b)
{
  if (op_b == 0) return -1;
  while (op_a >= op_b)
    op_a -= op_b;
  return op_a;
}
