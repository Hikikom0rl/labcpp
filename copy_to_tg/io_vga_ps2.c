#include <io_vga_ps2.h>
#include <riscv_string.h>

static struct vga_pos global_vga_pos = {0, 0};

void clear_screen()
{
  full_clear_vga(&global_vga_pos);
}

void printf_string(const char *str)
{
  const VGA_INDEX_TYPE cur_empty_idx = get_current_index_vga(global_vga_pos) + 1;
  VGA_INDEX_TYPE str_len = __strlen(str);

  for (VGA_INDEX_TYPE i = 0; i < str_len; i++)
    vga.char_map[cur_empty_idx + i] = str[i];

  advance_vga_by_index(&global_vga_pos, str_len);
}

VGA_INDEX_TYPE print_to_curr_idx(uint8_t data)
{
  VGA_INDEX_TYPE cur_idx = get_current_index_vga(global_vga_pos);
  vga.char_map[cur_idx] = data;
  return cur_idx;
}

void set_pos(VGA_DIMENSION_TYPE row, VGA_DIMENSION_TYPE col)
{
  global_vga_pos.row = row;
  global_vga_pos.col = col;
}

void set_pos_at_idx(VGA_INDEX_TYPE idx)
{
  global_vga_pos.row = divu32_t(idx, VGA_MAX_ROW_LEN);
  global_vga_pos.col = modu32_t(idx, VGA_MAX_ROW_LEN);
}

uint8_t wait_for_number(unsigned char *char_)
{
  uint8_t print_once = 0;
  while ( !is_hex_num_pressed(*char_) )
  {
    if (*char_ == '\0')
      continue;

    if (!print_once)
    {
      print_once = 1;
      VGA_INDEX_TYPE cur_idx = print_to_curr_idx(*char_);
      set_pos(20, 0);
      printf_string("Number is in range [0-F]");
      set_pos_at_idx(cur_idx);
    }
  }
  clear_row(50);
  return get_num(*char_);
}

uint8_t wait_for_esc(unsigned char *char_)
{
  while (*char_ != '\0') {}
  return 0;
}
