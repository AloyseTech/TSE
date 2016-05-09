#define ALPH 0x01
#define COL1 0x11
#define COL2 0x22
#define COL3 0x33
#define COL4 0x44

const uint8_t planetType1[2162] = { //47x46px, 3 colors
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x01, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x33, 0x33, 0x33, 0x11, 0x33, 0x33, 0x33, 0x22, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x11, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x22, 0x22, 0x11, 0x22, 0x33, 0x33, 0x33, 0x33, 0x22, 0x22, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x33, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x22, 0x11, 0x33, 0x11, 0x11, 0x33, 0x33, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x22, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x01, 0x33, 0x33, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x11, 0x33, 0x33, 0x33, 0x22, 0x01, 0x22, 0x22, 0x01, 0x01,
  0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x22, 0x22, 0x33, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x22, 0x22, 0x33, 0x01, 0x01,
  0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x11, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x01, 0x01,
  0x01, 0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x22, 0x11, 0x11, 0x33, 0x33, 0x11, 0x33, 0x33, 0x22, 0x33, 0x22, 0x33, 0x33, 0x01, 0x33, 0x22, 0x01,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x22, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x22, 0x22, 0x22, 0x11, 0x11, 0x33, 0x11, 0x11, 0x22, 0x22, 0x33, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x33, 0x01,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x33, 0x33, 0x22, 0x33, 0x22, 0x22, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x01,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x11, 0x33, 0x22, 0x11, 0x11, 0x11, 0x22, 0x33, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x11, 0x11, 0x33, 0x33, 0x33, 0x33, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x01, 0x01, 0x01,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x01, 0x01, 0x01,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x22, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x33,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x22, 0x22, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x33, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x33,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x01, 0x01, 0x01, 0x01, 0x33,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x01, 0x33, 0x01, 0x01, 0x01, 0x33,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x33,
  0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x11, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x22, 0x22, 0x33, 0x33, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x33, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x01, 0x01, 0x01,
  0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x33, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x33, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x22, 0x11, 0x11, 0x11, 0x11, 0x11, 0x22, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x22, 0x22, 0x22, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x22, 0x11, 0x11, 0x22, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x11, 0x33, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x22, 0x11, 0x22, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x22, 0x11, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x22, 0x11, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x22, 0x22, 0x22, 0x33, 0x22, 0x33, 0x33, 0x33, 0x01, 0x22, 0x01, 0x01, 0x01, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x22, 0x11, 0x11, 0x22, 0x11, 0x11, 0x22, 0x22, 0x22, 0x11, 0x22, 0x22, 0x11, 0x11, 0x11, 0x11, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x11, 0x33, 0x33, 0x22, 0x33, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x22, 0x22, 0x22, 0x22, 0x11, 0x11, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x33, 0x01, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x22, 0x22, 0x33, 0x22, 0x33, 0x33, 0x22, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x33, 0x01, 0x22, 0x01, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x22, 0x11, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x11, 0x11, 0x22, 0x22, 0x33, 0x22, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x33, 0x33, 0x01, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x22, 0x22, 0x11, 0x22, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x33, 0x22, 0x33, 0x22, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x22, 0x22, 0x11, 0x33, 0x22, 0x33, 0x01, 0x01, 0x33, 0x22, 0x33, 0x22, 0x22, 0x22, 0x22, 0x33, 0x22, 0x22, 0x01, 0x01, 0x33, 0x01, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x33, 0x22, 0x22, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x33, 0x33, 0x33, 0x22, 0x33, 0x33, 0x33, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x33, 0x33, 0x01, 0x01, 0x33, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
  0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x33, 0x33, 0x01, 0x33, 0x33, 0x22, 0x33, 0x33, 0x22, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
};

const uint8_t planetType2[3249] =
{
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x33 , 0x22 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x11 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x22 , 0x22 , 0x11 , 0x22 , 0x22 , 0x22 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x33 , 0x33 , 0x22 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x22 , 0x33 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x11 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x22 , 0x33 , 0x33 , 0x22 , 0x22 , 0x11 , 0x33 , 0x11 , 0x33 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x22 , 0x01 , 0x33 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x22 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x11 , 0x22 , 0x33 , 0x22 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x22 , 0x01 , 0x33 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x11 , 0x22 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x11 , 0x33 , 0x22 , 0x22 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x11 , 0x11 , 0x22 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x33 , 0x22 , 0x22 , 0x33 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x22 , 0x22 , 0x33 , 0x11 , 0x11 , 0x22 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x22 , 0x22 , 0x22 , 0x22 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x22 , 0x22 , 0x33 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x33 , 0x33 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x33 , 0x22 , 0x11 , 0x33 , 0x33 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 ,
  0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x33 , 0x33 , 0x01 ,
  0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x33 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x33 , 0x33 , 0x01 ,
  0x01 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x22 , 0x11 , 0x22 , 0x33 , 0x22 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 ,
  0x01 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 ,
  0x01 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 ,
  0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x22 , 0x11 , 0x11 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 ,
  0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x22 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 ,
  0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x01 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 ,
  0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 ,
  0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x22 , 0x11 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x11 , 0x22 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 ,
  0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x22 , 0x22 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 ,
  0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x22 , 0x11 , 0x22 , 0x22 , 0x33 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 ,
  0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x11 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x22 , 0x11 , 0x33 , 0x22 , 0x33 , 0x11 , 0x33 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x11 , 0x33 , 0x33 , 0x22 , 0x33 , 0x11 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x22 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x22 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x11 , 0x11 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x22 , 0x33 , 0x11 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x22 , 0x22 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x11 , 0x33 , 0x33 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x22 , 0x11 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x11 , 0x22 , 0x22 , 0x22 , 0x22 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x11 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x22 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x33 , 0x11 , 0x11 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x33 , 0x22 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x22 , 0x22 , 0x22 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x22 , 0x11 , 0x11 , 0x22 , 0x33 , 0x33 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x22 , 0x11 , 0x22 , 0x01 , 0x33 , 0x33 , 0x11 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x22 , 0x11 , 0x22 , 0x01 , 0x01 , 0x33 , 0x11 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x22 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x22 , 0x11 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x33 , 0x11 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x22 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x22 , 0x22 , 0x22 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x33 , 0x33 , 0x33 , 0x33 , 0x33 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
  0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01
};



