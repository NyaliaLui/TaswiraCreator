#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create letter factory
    taswira::AlphaFactory LetterFactory(taswira::Colors::Red);

    //Create a word or phrase
    std::vector<std::shared_ptr<taswira::IBaseShape>> Word1 = taswira::CreatePhrase("TASWIRA", LetterFactory);
    std::vector<std::shared_ptr<taswira::IBaseShape>> Word2 = taswira::CreatePhrase("CREATOR", LetterFactory);

    //Create a text box for the word or phrase
    taswira::TextBox text1(50, 200), text2(100, 150);

    //Add the word to the text box and draw it
    text1.AddPhrase(Word1);
    text2.AddPhrase(Word2);

    text1.DrawOnImage(image, 250, 200);
    text2.DrawOnImage(image, 100, 100);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
