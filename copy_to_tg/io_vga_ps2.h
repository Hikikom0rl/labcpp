#ifndef IO_VGA_PS2
#define IO_VGA_PS2

#include <vga.h>
#include <ps2.h>

void printf_string(const char* str);

inline void clear_row(VGA_DIMENSION_TYPE row)
{
  for (int i = 0; i < VGA_MAX_ROW_LEN; i++)
    vga.char_map[row * VGA_MAX_ROW_LEN+ i] = ' ';
}

VGA_INDEX_TYPE print_to_curr_idx(uint8_t data);
void set_pos(VGA_DIMENSION_TYPE row,
    VGA_DIMENSION_TYPE col);

void set_pos_at_idx(VGA_INDEX_TYPE idx);

uint8_t wait_for_number(unsigned char *char_);
uint8_t wait_for_esc(unsigned char *char_);

void clear_screen();

#endif
