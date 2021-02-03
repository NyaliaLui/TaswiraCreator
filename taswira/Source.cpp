#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {

    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create letter factory
    taswira::AlphaFactory LetterFactory(taswira::Colors::Black);

    //Create UML Objects
    taswira::UML::FullClass Object1(200, 200, taswira::CreatePhrase("CHAIR", LetterFactory));
    Object1.AddVariable<taswira::Minus>(taswira::CreatePhrase("VAR", LetterFactory));
    Object1.AddVariable<taswira::Plus>(taswira::CreatePhrase("TESTVAR", LetterFactory));

    Object1.DrawOnImage(image, 100, 50);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
