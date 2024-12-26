#include <scan_code_decoder.h>
#include <io_vga_ps2.h>
#include <maths.h>
#include <riscv_string.h>

static uint32_t sum_sub_4(uint32_t sw_i)
{
    uint32_t i = 0; // counter
    
    uint32_t mask = 0xf;        // mask first 4 bits of sw_i
    uint32_t sum = sw_i & mask; // writing first 4 bits to sum
    
    for (;2 >= i; ++i)  // condition is equivalent to i < 4
                        //but sum already contains 1 sub digit of sw_i (i < 3) and using >= gets us to 2 >= i
    {
        sw_i = (sw_i >> 4);     // bitshift to right to get new 4 bits (thus new sub digit)
        sum += (sw_i & mask);   // adding to sum result of applied mask to sw_i
    }
    
    return sum;
}

int main()
{
  reset_ps2();
  while (1)
  {
    uint8_t first_number = 0;
    set_pos(0, 12);
    printf_string("Welcome to sub_sum_4 101!");
    set_pos(1,0);
    printf_string("Enter first number [0-F]: "); 
    allow_input_from_ps2();
      first_number = wait_for_key(&wait_for_number);
    dissallow_input_from_ps2();

    uint8_t second_number = 0;
    set_pos(2, 0);
    printf_string("Enter second number [0-F]: "); 
    
    allow_input_from_ps2();
      second_number = wait_for_key(&wait_for_number);
    dissallow_input_from_ps2();
    
    uint8_t third_number = 0;
    set_pos(3,0);
    printf_string("Enter third number [0-F]: "); 
    
    allow_input_from_ps2();
      third_number = wait_for_key(&wait_for_number);
    dissallow_input_from_ps2();
      
    uint8_t fourth_number = 0;
    set_pos(4,0);
    printf_string("Enter fourth number [0-F]: "); 
    
    allow_input_from_ps2();
      fourth_number = wait_for_key(&wait_for_number);
    dissallow_input_from_ps2();

    uint32_t sw_i = fourth_number;
    sw_i = (sw_i << 4) + third_number;
    sw_i = (sw_i << 4) + second_number;
    sw_i = (sw_i << 4) + first_number;

    char buffered_hex_number[3] = {0}; 

    itoa(sum_sub_4(sw_i), buffered_hex_number, 16);
    set_pos(6, 0);
    printf_string("Answer: ");
    printf_string(buffered_hex_number);
    set_pos(7, 0);
    printf_string("Waiting for ESC...");
    allow_input_from_ps2();
      wait_for_key(&wait_for_esc);
    dissallow_input_from_ps2();
    clear_screen();
  }
  return 0;
}

