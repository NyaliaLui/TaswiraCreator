#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {

    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create UML Objects
    taswira::UML::Class Object1(50, 100), Object2(50, 200), Object3(50, 100), Object4(50, 100);

    //Create letter factory
    taswira::AlphaFactory LetterFactory(taswira::Colors::Black);

    //Add the word to the text box and draw it
    Object1.ObjectText().AddPhrase(taswira::CreatePhrase("CHAIR", LetterFactory));
    Object2.ObjectText().AddPhrase(taswira::CreatePhrase("CLASSROOM", LetterFactory));
    Object3.ObjectText().AddPhrase(taswira::CreatePhrase("DESK", LetterFactory));
    Object4.ObjectText().AddPhrase(taswira::CreatePhrase("ROOM", LetterFactory));

    //Object1.AddAssociation(std::make_shared<taswira::UML::Aggregation>());

    Object1.DrawOnImage(image, 200, 50);
    Object2.DrawOnImage(image, 100, 150);
    Object3.DrawOnImage(image, 200, 350);
    Object4.DrawOnImage(image, image.ImageTopMargin() - 50, 200);

    taswira::UML::Inheritance association(Object1, Object2);

    //Connect objects
    //taswira::Geometry::DrawLineOnImage(image, Object1.ConnectorBottom(), Object2.ConnectorTop(), taswira::Colors::Red);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
