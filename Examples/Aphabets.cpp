#include "Taswira.h"
#include <iostream>
#include <list>
#include <memory>

int main(void) {
    //Create BitmapImage
    taswira::BitmapImage image(14, 40, 512, 512, 3, 8);

    //Create array of shapes to draw
    std::list<std::unique_ptr<taswira::IBaseShape>> Alphabet;
    Alphabet.push_back(std::make_unique<taswira::Uppercase::A>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::B>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::C>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::D>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::E>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::F>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::G>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::H>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::I>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::J>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::K>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::L>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::M>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::N>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::O>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::P>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::Q>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::R>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::S>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::T>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::U>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::V>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::W>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::X>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::Y>(taswira::Colors::White));
    Alphabet.push_back(std::make_unique<taswira::Uppercase::Z>(taswira::Colors::White));

    image.WriteToDisk("nyalia.bmp");

    return 0;
}
