#include "Taswira.h"
#include <iostream>
#include <array>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create array of shapes to draw
    taswira::Uppercase::K LetQ(taswira::Colors::White);
    taswira::Uppercase::X LetX(taswira::Colors::White);
    taswira::Uppercase::R LetO(taswira::Colors::White);
    taswira::Uppercase::A LetA(taswira::Colors::White);

    LetQ.DrawOnImage(image, image.ImageBottomMargin(), image.ImageRightMargin());
    LetX.DrawOnImage(image, image.ImageBottomMargin(), image.ImageRightMargin() - image.ImagePixelPadding());

    LetO.DrawOnImage(image, image.ImageTopMargin(), image.ImageLeftMargin());
    LetA.DrawOnImage(image, image.ImageTopMargin(), image.ImageLeftMargin() + image.ImagePixelPadding());

    taswira::Geometry::DrawLineOnImage(image, image.ImageBottomMargin(), image.ImageRightMargin() - image.ImagePixelPadding(),
        image.ImageTopMargin(), image.ImageLeftMargin() + image.ImagePixelPadding(),
        taswira::Colors::Blue);

    taswira::Connector BotLeftCorner(0, 0), TopRightCorner(image.ImageHeight() - 1, image.ImageWidth() - 1);
    taswira::Geometry::DrawLineOnImage(image, BotLeftCorner, TopRightCorner, taswira::Colors::Green);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
