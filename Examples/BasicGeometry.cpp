#include "Taswira.h"
#include <iostream>
#include <array>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    taswira::Connector BotLeftCorner(0, 0), TopRightCorner(image.ImageHeight() - 1, image.ImageWidth() - 1);
    taswira::Connector TopLeftCorner(image.ImageHeight() - 1, 0), BotRightCorner(0, image.ImageWidth() - 1);

    taswira::Geometry::DrawLineOnImage(image, BotLeftCorner, TopRightCorner, taswira::Colors::Green);
    taswira::Geometry::DrawLineOnImage(image, TopLeftCorner, BotRightCorner, taswira::Colors::Blue);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
