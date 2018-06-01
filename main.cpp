#include "tgaimage.h"
const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red = TGAColor(255, 0, 0, 255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color){
  for(float t = 0; t < 1; t += 0.01){
    int x = x1 * t + x0 * (1 - t);
    int y = y1 * t + y0 * (1 - t);
    image.set(x, y, color);
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
  line(80,40, 13, 20, image, red);

  point(0, 0, image, red);
  point(0, 99, image, red);
  point(99, 0, image, red);
  point(99, 99, image, red);


  image.flip_vertically();
  image.write_tga_file("output.tga");
  return 0;
}
