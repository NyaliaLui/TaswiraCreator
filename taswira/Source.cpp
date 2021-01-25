#include "Taswira.h"
#include <iostream>
#include <array>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create array of shapes to draw
    taswira::Rectangle rectangle(100, 50, taswira::Colors::Green);
    taswira::Square square(50, taswira::Colors::Blue);
    taswira::Circle circle(10, taswira::Colors::White);
    taswira::Triangle triangle(20, taswira::Colors::Red);

    rectangle.DrawOnImage(image, 25, 25);
    square.DrawOnImage(image, 100, 100);
    circle.DrawOnImage(image, 200, 200);
    triangle.DrawOnImage(image, 300, 300);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
