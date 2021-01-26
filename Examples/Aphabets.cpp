#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create array of shapes to draw
    std::vector<std::shared_ptr<taswira::IBaseShape>> Word;
    Word.push_back(std::make_shared<taswira::Uppercase::T>(taswira::Colors::White));
    Word.push_back(std::make_shared<taswira::Uppercase::A>(taswira::Colors::White));
    Word.push_back(std::make_shared<taswira::Uppercase::S>(taswira::Colors::White));
    Word.push_back(std::make_shared<taswira::Uppercase::W>(taswira::Colors::White));
    Word.push_back(std::make_shared<taswira::Uppercase::I>(taswira::Colors::White));
    Word.push_back(std::make_shared<taswira::Uppercase::R>(taswira::Colors::White));
    Word.push_back(std::make_shared<taswira::Uppercase::A>(taswira::Colors::White));

    taswira::TextBox text(50, 200);

    text.AddPhrase(Word);
    text.DrawOnImage(image, 250, 200);

    image.WriteToDisk("myimage.bmp");

    return 0;
}
