#include <iostream>
#include "BitmapImage.h"

int main(void) {
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    image.DrawCircle(300, 300, 10, taswira::Colors::White);

    image.WriteToDisk("nyalia.bmp");

    return 0;
}
