#include "Taswira.h"
#include <iostream>
#include <array>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create array of shapes to draw
    taswira::FilledInSquare sq1(50, 50, taswira::Colors::Blue);
    taswira::EmptySquare sq2(50, 50, taswira::Colors::Blue);
    taswira::Circle circle(10, taswira::Colors::White);

    sq1.DrawSquareOnImage(image, image.ImageBottomMargin(), image.ImageLeftMargin());
    sq2.DrawSquareOnImage(image, image.ImageTopMargin(), image.ImageLeftMargin());
    circle.DrawCircleOnImage(image, 300, 300);

    image.WriteToDisk("IMG000.bmp");

    return 0;
}
