#include "Taswira.h"
#include <iostream>
#include <array>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create array of shapes to draw
    taswira::Uppercase::W Letter(taswira::Colors::White);

    Letter.DrawAlphaCharOnImage(image, image.ImageBottomMargin(), image.ImageLeftMargin());

    image.WriteToDisk("nyalia.bmp");

    return 0;
}
