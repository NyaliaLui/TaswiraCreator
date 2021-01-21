#include <iostream>
#include "taswira/BitmapImage.h"

int main(void) {

    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    int stripe = 0;
    for (int i=0; i<image.ImageHeight(); ++i) {
        for (int j=0; j<image.ImageWidth(); ++j) {            
            if (stripe % 3 == 0) {
                image.PixelAt(i, j).Blue = 255;
                image.PixelAt(i, j).Green = 0;
                image.PixelAt(i, j).Red = 0;             
            } else if (stripe % 3 == 1) {
                image.PixelAt(i, j).Blue = 0;
                image.PixelAt(i, j).Green = 255;
                image.PixelAt(i, j).Red = 0;
            } else {
                image.PixelAt(i, j).Blue = 0;
                image.PixelAt(i, j).Green = 0;
                image.PixelAt(i, j).Red = 255;
            }

            if (i % 50 == 0) {
                ++stripe;
            }
        }
    }

    image.WriteToDisk("myimage.bmp");

    return 0;
}
