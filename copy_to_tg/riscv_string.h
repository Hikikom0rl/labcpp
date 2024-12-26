#ifndef RISCV_STRING
#define RISCV_STRING

#include <stdint.h>

uint32_t __strlen(const char* str);
void reverse(char str[], int len);
uint32_t itoa(int num, char *str, int base);


inline uint8_t get_num(unsigned char char_)
{
  return (char_ >= '0'&& char_ <= '9') ? 
      char_ - '0'
      : (char_ >= 'A' && char_ <= 'F') ?
        char_ - 'A' + 10 : -1;
}

#endif
