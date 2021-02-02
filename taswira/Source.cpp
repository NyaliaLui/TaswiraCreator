#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {

    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create UML Objects
    taswira::UML::FullClass Object1(100, 100);

    //Create letter factory
    taswira::AlphaFactory LetterFactory(taswira::Colors::Black);

    //Add the word to the text box and draw it
    Object1.ObjectName().AddPhrase(taswira::CreatePhrase("CHAIR", LetterFactory));


    Object1.DrawOnImage(image, 200, 50);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
