#ifndef PS2_LIB_H
#define PS2_LIB_H

#include <platform.h>

void int_handler();

void    allow_input_from_ps2();
uint8_t is_input_allowed_from_ps2();
void    dissallow_input_from_ps2();

inline static void reset_ps2()
{
  ps2_ptr->rst = 1;
}

inline static uint8_t is_hex_num_pressed(unsigned char cur_char)
{
  return (cur_char >= '0' && cur_char <= '9') || (cur_char >= 'A' && cur_char <= 'F');
}

uint8_t wait_for_key( uint8_t (*handler_)(unsigned char*));

#endif
