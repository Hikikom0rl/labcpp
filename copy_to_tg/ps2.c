#include <ps2.h>
#include <scan_code_decoder.h>

typedef enum {                                                                                     
  WAITING_FOR_PRESS, // actial press                                                             
  WAITING_FOR_BREAK, // break is F0 or other beginning of release sequence                       
  WAITING_FOR_TERMINATE // typically same as presses key                                         
} State;

static uint8_t allow_input = 0;
static uint8_t curr_char = 0;

uint8_t wait_for_key(uint8_t (*handler_)(unsigned char *))
{
  return (*handler_)(&curr_char);
}

static volatile State cur_state = WAITING_FOR_PRESS;

void int_handler()
{
  if (!ps2_ptr->unread_data) return;
  if (!allow_input) return;

  const uint8_t current_scan_code = ps2_ptr->scan_code;
  static uint8_t buff_scan_codes[2] = {0, 0};  
  static uint8_t ignore_amnt_of_scan_codes = 0; // if set to 1 then ignore only next scan code
  
  if (ignore_amnt_of_scan_codes != 0)
  {
    ignore_amnt_of_scan_codes--;

    if (current_scan_code == SCAN_CODE_SPECIAL_SHORT_SUFF 
        && buff_scan_codes[0] != SCAN_CODE_SPECIAL_SHORT_SUFF)
    {
      ignore_amnt_of_scan_codes = 8;
      buff_scan_codes[0] = SCAN_CODE_SPECIAL_SHORT_SUFF;
      return;
    }

    return;
  }


  switch (cur_state)
  {
    case WAITING_FOR_PRESS:
      if (current_scan_code != SCAN_CODE_RELEASE)
      {
        if (current_scan_code == SCAN_CODE_SPECIAL_SHORT)
        {
          ignore_amnt_of_scan_codes = 4;
          cur_state = WAITING_FOR_TERMINATE;
          buff_scan_codes[0] = 0;
          buff_scan_codes[1] = current_scan_code;
          curr_char = 0;
          return;
        }
        if (current_scan_code == SCAN_CODE_SPECIAL_LONG)
        {
          ignore_amnt_of_scan_codes = 7;
          cur_state = WAITING_FOR_TERMINATE;
          buff_scan_codes[0] = 0;
          buff_scan_codes[1] = 0;
          curr_char = 0;
          return;
        }

        cur_state = WAITING_FOR_BREAK;
        buff_scan_codes[0] = current_scan_code;
        buff_scan_codes[1] = 0;

        curr_char = decode_scan_code_to_ascii(buff_scan_codes[0]);
      }
      break;
    case WAITING_FOR_BREAK:
      if (current_scan_code == SCAN_CODE_RELEASE)
        cur_state = WAITING_FOR_TERMINATE;
      break;
    case WAITING_FOR_TERMINATE:
        cur_state  = WAITING_FOR_PRESS;
        curr_char = 0;
      break;
    default:
      break;
  }

}

void allow_input_from_ps2()
{
  // variable is volatile because it needs to be refreshed every time
  // if it is not volatile then compiler just sits in while infinitely long
  // but when interrupt occures and handled it goes back to infinite loop
  // instead of refreshing and checking new state of variable
  // P.S. probably just a niсhe problem
  while (cur_state!= WAITING_FOR_PRESS) {}
  allow_input = 1;
}

void dissallow_input_from_ps2()
{
  while (cur_state != WAITING_FOR_PRESS) {}
  allow_input = 0;
}

uint8_t is_input_allowed_from_ps2()
{
  return allow_input;
}
