#ifndef VGA_H
#define VGA_H

#include <stdint.h>
#include <platform.h>
#include <maths.h>


#define VGA_DIMENSION_TYPE uint8_t
#define VGA_INDEX_TYPE uint16_t

#define VGA_MAX_ROW_LEN 80
#define VGA_MAX_AMT_ROWS 30

struct vga_pos
{
  VGA_DIMENSION_TYPE row;
  VGA_DIMENSION_TYPE col;
};

inline static 
VGA_INDEX_TYPE get_current_index_vga(struct vga_pos curr_pos)
{
  return ( (VGA_INDEX_TYPE) curr_pos.row* VGA_MAX_ROW_LEN) + (VGA_INDEX_TYPE) curr_pos.col;
}

static
void advance_vga_by_index(struct vga_pos *pos, VGA_INDEX_TYPE index)
{
  VGA_INDEX_TYPE adv_idx = get_current_index_vga(*pos) + index;
  pos->row = divu32_t(adv_idx, VGA_MAX_ROW_LEN);
  pos->col = modu32_t(adv_idx,  VGA_MAX_ROW_LEN);
}

static
void full_clear_vga(struct vga_pos *pos)
{
  pos->row = 0;
  pos->col = 0;
  for (VGA_INDEX_TYPE i = 0; i < (VGA_MAX_ROW_LEN * VGA_MAX_AMT_ROWS); i++)
    vga.char_map[i] = ' ';
}

#endif
