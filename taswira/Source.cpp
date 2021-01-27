#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {

    taswira::UML::Inheritance Inheritance(taswira::Colors::White);
    taswira::UML::Aggregation Aggregation(taswira::Colors::White);

    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    Inheritance.DrawOnImage(image, 400, 250);
    Aggregation.DrawOnImage(image, 100, 250);

    taswira::Geometry::DrawLineOnImage(image, Inheritance, Aggregation, taswira::Colors::Green);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
