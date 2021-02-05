#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {

    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create UML Objects
    taswira::UML::Class Object1(50, 200), Object2(100, 150);

    //Create letter factory
    taswira::AlphaFactory LetterFactory(taswira::Colors::Green);

    //Add the word to the text box and draw it
    Object1.ObjectText().AddPhrase(taswira::CreatePhrase("TASWIRA", LetterFactory));
    Object2.ObjectText().AddPhrase(taswira::CreatePhrase("CREATOR", LetterFactory));

    Object1.AddAssociation(std::make_shared<taswira::UML::Inheritance>());

    Object1.DrawOnImage(image, 250, 200);
    Object2.DrawOnImage(image, 100, 100);

    //Connect objects
    taswira::Geometry::DrawLineOnImage(image, Object1.ConnectorBottom(), Object2.ConnectorTop(), taswira::Colors::Red);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
