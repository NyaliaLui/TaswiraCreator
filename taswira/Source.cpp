#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create a word or phrase
    std::vector<std::shared_ptr<taswira::IBaseShape>> Word = taswira::CreatePhrase("TASWIRA", taswira::Colors::Green);

    //Create a text box for the word or phrase
    taswira::TextBox text(50, 200);

    //Add the word to the text box and draw it
    text.AddPhrase(Word);
    text.DrawOnImage(image, 250, 200);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
