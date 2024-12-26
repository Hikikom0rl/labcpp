#ifndef SCAN_CODE_DECODER_H
#define SCAN_CODE_DECODER_H

#define SCAN_CODE_A 0x1C
#define SCAN_CODE_B 0x32
#define SCAN_CODE_C 0x21
#define SCAN_CODE_D 0x23
#define SCAN_CODE_E 0x24
#define SCAN_CODE_F 0x2B
#define SCAN_CODE_G 0x34
#define SCAN_CODE_H 0x33
#define SCAN_CODE_I 0x43
#define SCAN_CODE_J 0x3B
#define SCAN_CODE_K 0x42
#define SCAN_CODE_L 0x4B
#define SCAN_CODE_M 0x3A
#define SCAN_CODE_N 0x31
#define SCAN_CODE_O 0x44
#define SCAN_CODE_P 0x4D
#define SCAN_CODE_Q 0x15
#define SCAN_CODE_R 0x2D
#define SCAN_CODE_S 0x1B
#define SCAN_CODE_T 0x2C
#define SCAN_CODE_U 0x3C
#define SCAN_CODE_V 0x2A
#define SCAN_CODE_W 0x1D
#define SCAN_CODE_X 0x22
#define SCAN_CODE_Y 0x35
#define SCAN_CODE_Z 0x1A

#define SCAN_CODE_1 0x16
#define SCAN_CODE_2 0x1E
#define SCAN_CODE_3 0x26
#define SCAN_CODE_4 0x25
#define SCAN_CODE_5 0x2E
#define SCAN_CODE_6 0x36
#define SCAN_CODE_7 0x3D
#define SCAN_CODE_8 0x3E
#define SCAN_CODE_9 0x46
#define SCAN_CODE_0 0x45

#define SCAN_CODE_RELEASE 0xF0
#define SCAN_CODE_SPECIAL_LONG 0xE1
#define SCAN_CODE_SPECIAL_SHORT 0xE0
#define SCAN_CODE_SPECIAL_SHORT_SUFF 0x12

#define SCAN_CODE_ENTER 0x5A
#define SCAN_CODE_ESC 0x76
#define SCAN_CODE_BACKSPACE 0x66

#define INVALID_KEY (uint8_t)(-1)
#define ESC_KEY (uint8_t)(-3)
#define BACKSPACE_KEY (uint8_t)(-2)
#define ENTER_KEY (uint8_t)(-4)
#define RELEASE_ (uint8_t)(-5)

#define IGNORE_CHAR (uint8_t)(-1)

#include <stdint.h>

static 
uint8_t decode_scan_code_to_ascii(uint8_t scan_code)
{
  uint8_t character = 0;
  switch(scan_code)
  {
    case SCAN_CODE_A:
      character = 'A';
      break;
    
    case SCAN_CODE_B:
      character = 'B';
      break;

    case SCAN_CODE_C:
      character = 'C';
      break;

    case SCAN_CODE_D:
      character = 'D';
      break;

    case SCAN_CODE_E:
      character = 'E';
      break;

    case SCAN_CODE_F:
      character = 'F';
      break;

    //case SCAN_CODE_G:
    //  character = 'G';
    //  break;
    //case SCAN_CODE_H:
    //  character = 'H';
    //  break;
    //case SCAN_CODE_I:
    //  character = 'I';
    //  break;
    //case SCAN_CODE_J:
    //  character = 'J';
    //  break;
    //case SCAN_CODE_K:
    //  character = 'K';
    //  break;
    //case SCAN_CODE_L:
    //  character = 'L';
    //  break;
    //case SCAN_CODE_M:
    //  character = 'M';
    //  break;
    //case SCAN_CODE_N:
    //  character = 'N';
    //  break;
    //case SCAN_CODE_O:
    //  character = 'O';
    //  break;
    //case SCAN_CODE_P:
    //  character = 'P';
    //  break;
    //case SCAN_CODE_Q:
    //  character = 'Q';
    //  break;
    //case SCAN_CODE_R:
    //  character = 'R';
    //  break;
    //case SCAN_CODE_S:
    //  character = 'S';
    //  break;
    //case SCAN_CODE_T:
    //  character = 'T';
    //  break;
    //case SCAN_CODE_U:
    //  character = 'U';
    //  break;
    //case SCAN_CODE_V:
    //  character = 'V';
    //  break;
    //case SCAN_CODE_W:
    //  character = 'W';
    //  break;
    //case SCAN_CODE_X:
    //  character = 'X';
    //  break;
    //case SCAN_CODE_Y:
    //  character = 'Y';
    //  break;
    //case SCAN_CODE_Z:
    //  character = 'Z';
    //  break;
    
    case SCAN_CODE_1:
      character = '1';
      break;
    case SCAN_CODE_2:
      character = '2';
      break;
    case SCAN_CODE_3:
      character =  '3';
      break;
    case SCAN_CODE_4:
      character = '4';
      break;
    case SCAN_CODE_5:
      character = '5';
      break;
    case SCAN_CODE_6:
      character = '6';
      break;
    case SCAN_CODE_7:
      character = '7';
      break;
    case SCAN_CODE_8:
      character = '8';
      break;
    case SCAN_CODE_9:
      character = '9';
      break;
    case SCAN_CODE_0:
      character = '0';
      break;
    
    case SCAN_CODE_RELEASE:
      character = RELEASE_;
      break;
    case SCAN_CODE_ESC:
      character = ESC_KEY;
      break;
    case SCAN_CODE_BACKSPACE:
      character = BACKSPACE_KEY;
      break;
    case SCAN_CODE_ENTER:
      character = ENTER_KEY;
      break;

    default:
      character = INVALID_KEY;
      break;
  }
  return character;
}

#endif
