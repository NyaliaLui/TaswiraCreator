#include "Taswira.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>

template<typename VISTYPE>
void MakeAnImageFromClass(std::string className, VISTYPE& variables) {
    //Create letter factory and UML factory
    taswira::UML::UMLFactory UMLFactory(taswira::Colors::Black);

    //List of member variables
    std::vector<taswira::UML::Variable> MemberVariables;
    for (std::string& var : variables) {
        std::cout << var[0] << " " << var.substr(1) << std::endl;
        std::string name(var.substr(1));
        if (var[0] == '-') {
            MemberVariables.push_back(UMLFactory.CreateVariable<taswira::Minus>(name));
        } else if (var[1] == '#') {
            MemberVariables.push_back(UMLFactory.CreateVariable<taswira::HashTag>(name));
        } else {
            MemberVariables.push_back(UMLFactory.CreateVariable<taswira::Plus>(name));
        }
    }

    //Create UML Object
    taswira::UML::FullClass Object(UMLFactory.CreateFullClass(className, MemberVariables));

    //Create BitmapImage and draw the object on the image
    taswira::BitmapFactory ImageFactory;
    taswira::BitmapImage image(ImageFactory.CreateImageFromUMLObject(Object));
    Object.DrawOnImage(image, 0, 0);

    className += ".bmp";
    image.WriteToDisk(className);
}

int main(void) {
    std::array<std::string, 3> VisA = { "+VARAA", "+VARAB", "+VARAC" };
    std::array<std::string, 3> VisB = { "-VARBA", "-VARBB", "-VARBC" };
    std::array<std::string, 3> VisC = { "#VARCA", "#VARCB", "#VARCC" };

    MakeAnImageFromClass("CLASSA", VisA);
    MakeAnImageFromClass("CLASSB", VisB);
    MakeAnImageFromClass("CLASSC", VisC);
    return 0;
}
