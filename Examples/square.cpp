#include <iostream>
#include "BitmapImage.h"

int main(void) {
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    image.DrawFilledInSquare(image.ImageBottomMargin(), image.ImageLeftMargin(), 50, 50, taswira::Colors::Blue);
    image.DrawEmptySquare(image.ImageTopMargin(), image.ImageLeftMargin(), 50, 50, taswira::Colors::Blue);

    // draw line along right margin
    for (int row = image.ImageBottomMargin(); row < image.ImageBottomMargin() + 50; ++row) {
        image.PixelAt(row, image.ImageRightMargin()).Blue = taswira::Colors::White.Blue;
        image.PixelAt(row, image.ImageRightMargin()).Green = taswira::Colors::White.Green;
        image.PixelAt(row, image.ImageRightMargin()).Red = taswira::Colors::White.Red;
    }

    image.WriteToDisk("nyalia.bmp");

    return 0;
}
