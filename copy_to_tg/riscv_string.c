#include <riscv_string.h>
#include <maths.h>

uint32_t __strlen(const char *str)
{
  const char *s;
  for (s = str; *s; ++s);
  return (s - str);
}

void reverse(char str[], int len)
{
  int start = 0;
  int end = len - 1;
  while (start < end)
  {
    char temp = str[start];
    str[start] = str[end];
    str[end] = temp;
    end--;
    start++;
  }
}

uint32_t itoa(int num, char *str, int base)
{
  int i = 0;
  uint8_t is_neg = 0;
  if (num == 0)
  {
    str[i++] = '0';
    str[i] = '\0';
    return 0;
  }

  if (num < 0 && base == 10)
  {
    is_neg = 1;
    num = -num;
  }
  while (num != 0)
  {
    int rem = modu32_t(num, base);
    str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
    num = divu32_t(num, base);
  }

  if (is_neg)
    str[i++] = '-';
  str[i] = '\0';
  reverse(str, i);
  return 0;
}

