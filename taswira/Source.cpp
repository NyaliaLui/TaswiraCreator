#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

void MakeAnImageFromClass(taswira::ClassSignature& Signature) {
    //Create letter factory and UML factory
    taswira::UML::UMLFactory UMLFactory(taswira::Colors::Black);

    //List of member variables
    std::vector<taswira::UML::Variable> MemberVariables;
    for (std::string& var : Signature.MemberVariables) {
        std::cout << var[0] << " " << var.substr(1) << std::endl;
        std::string name(var.substr(1));
        if (var[0] == '-') {
            MemberVariables.push_back(UMLFactory.CreateVariable<taswira::Minus>(name));
        }
        else if (var[0] == '#') {
            MemberVariables.push_back(UMLFactory.CreateVariable<taswira::HashTag>(name));
        }
        else {
            MemberVariables.push_back(UMLFactory.CreateVariable<taswira::Plus>(name));
        }
    }

    //Create UML Object
    taswira::UML::FullClass Object(UMLFactory.CreateFullClass(Signature.Name, MemberVariables));

    //Create BitmapImage and draw the object on the image
    taswira::BitmapFactory ImageFactory;
    taswira::BitmapImage image(ImageFactory.CreateImageFromUMLObject(Object));
    Object.DrawOnImage(image, 0, 0);

    image.WriteToDisk(Signature.Name + ".bmp");
}

int main(void) {
    std::vector<taswira::ClassSignature> Classes(taswira::ParseHeaderFile("D:\\Documents\\taswira\\taswira\\SampleHeader.h"));

    for (taswira::ClassSignature& signature : Classes) {
        MakeAnImageFromClass(signature);
    }
    return 0;
}
