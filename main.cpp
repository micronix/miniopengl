#include "tgaimage.h"
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);
const TGAColor green = TGAColor(0, 255, 0, 255);
const TGAColor blue = TGAColor(0, 0, 255, 255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color){
  // determine if we should increase x or increase y
  int dx = x1 - x0;
  int dy = y1 - y0;

  dx = dx > 0 ? dx : -dx;
  dy = dy > 0 ? dy : -dy;

  if (dx > dy){
    if (x0 > x1){
      int temp = x0;
      x0 = x1;
      x1 = temp;

      temp = y0;
      y0 = y1;
      y1 = temp;
    }

    // calculate slope once
    float m = (y1 - y0) / (float)(x1 - x0);
    for(int x = x0; x <= x1; x++){
      int y = m * (x - x0) + y0;
      image.set(x, y, color);
    }
  } else {
    if (y0 > y1){
      int temp = x0;
      x0 = x1;
      x1 = temp;

      temp = y0;
      y0 = y1;
      y1 = temp;
    }

    // calculate slope once
    float m = (x1 - x0) / (float)(y1 - y0);
    for(int y = y0; y <= y1; y++){
      int x = m * (y - y0) + x0;
      image.set(x, y, color);
    }
  }
}

void point(int x, int y, TGAImage &image, TGAColor color){
  image.set(x, y, color);
}

int main(int argc, char** argv) {
  TGAImage image(100,100, TGAImage::RGB);

  // draw a line
  line(13,20, 80, 40, image, white);
  line(20,13, 40, 80, image, red);
  line(80,40, 13, 20, image, blue);

  point(0, 0, image, red);
  point(0, 99, image, red);
  point(99, 0, image, red);
  point(99, 99, image, red);


  image.flip_vertically();
  image.write_tga_file("output.tga");
  return 0;
}
