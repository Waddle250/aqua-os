#include <stdint.h>

//In progress (Working on color palette)
#define WIDTH = 100;
#define HEIGHT = 100;
uint32_t framebuffer[WIDTH*HEIGHT];
//Color Palette (10 colors for a test)
uint32_t palette[10]={
  0x000000, //BLACK
  0xFF0000, //RED
  0x00FF00, //GREEN
  0x0000FF, //BLUE
  0xFFFFFF, //WHITE
  0xFFA500, //ORANGE
  0xFF00FF, //MAGENTA
  0x00FFFF, //CYAN
  0xFFFF00, //YELLOW
  0xFF88FF, //PINK
}


void DrawPixel(x, y, colorcode){
  int pointer = y*WIDTH + x;

  //Safety net...
  if (x >= WIDTH || y >= HEIGHT || colorcode > 10){
    return;
  }
  
  framebuffer[y * WIDTH + x] = palette[colorcode];
}
