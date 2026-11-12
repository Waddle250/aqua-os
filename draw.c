#include <stdint.h>

//In progress (Working on color palette)
#define WIDTH 320
#define HEIGHT 200

uint8_t *framebuffer = (uint8_t *)0xA0000;

//Color Palette (10 colors for a test)
uint8_t palette[10]={
  0,  //BLACK
  4,  //RED
  2,  //GREEN
  1,  //BLUE
  15, //WHITE
  42, //ORANGE
  5,  //MAGENTA
  3,  //CYAN
  14, //YELLOW
  13  //PINK
};

void drawPixel(uint32_t x, uint32_t y, uint8_t colorcode){
  uint32_t pointer = y*WIDTH + x;

  //Safety net...
  if (x >= WIDTH || y >= HEIGHT || colorcode >= 10){
    return;
  }

  framebuffer[pointer] = palette[colorcode];
}

void drawRect(uint32_t startX, uint32_t startY, uint32_t rectWidth, uint32_t rectHeight, uint8_t colorcode) {
  for (uint32_t y = startY; y < startY + rectHeight; y++) {
    for (uint32_t x = startX; x < startX + rectWidth; x++) {
      drawPixel(x, y, colorcode);
    }
  }
}

void drawRectHollow(uint32_t startX, uint32_t startY, uint32_t rectWidth, uint32_t rectHeight, uint8_t colorcode) {
  if (rectWidth == 0 || rectHeight == 0) return;

  for (uint32_t x = startX; x < startX + rectWidth; x++) {
    drawPixel(x, startY, colorcode);
    drawPixel(x, startY + rectHeight - 1, colorcode);
  }

  for (uint32_t y = startY; y < startY + rectHeight; y++) {
    drawPixel(startX, y, colorcode);
    drawPixel(startX + rectWidth - 1, y, colorcode);
  }
}

