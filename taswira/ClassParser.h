#ifndef CLASSPARSER_H
#define CLASSPARSER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <utility>

namespace taswira {
    //Using a struct because we don't need to restrict access to the member variables
    //since we're simply representing the user's own class. They already have access to their own source code!
    struct ClassSignature {
        std::string Name;
        //Using a vector because direct access is not necessary
        std::vector<std::string> MemberVariables;

        ClassSignature(void)
            :Name("N/A")
        {  }

        ClassSignature(std::string& name, std::vector<std::string>& variables)
            :Name(name),
            MemberVariables(variables)
        {  }

        ClassSignature(const ClassSignature& signature)
            :Name(signature.Name),
            MemberVariables(signature.MemberVariables)
        {  }

        ClassSignature& operator = (const ClassSignature& signature) {
            this->Name = signature.Name;
            this->MemberVariables = signature.MemberVariables;
            return (*this);
        }

        ~ClassSignature(void)
        {  }
    };

    std::ostream& operator << (std::ostream& out, const ClassSignature& signature) {
        out << signature.Name << ": [";
        size_t i = 0;
        for (; i < signature.MemberVariables.size()-1; ++i) {
            out << signature.MemberVariables[i] << ", ";
        }
        out << signature.MemberVariables[i] << "]";

        return out;
    }

    static bool isValidSymbol(char sym) {
        return ('A' <= sym && sym <= 'Z') || ('a' <= sym && sym <= 'z');
    }

    static std::string SanitizeLine(std::string& unsanitizedLine) {
        size_t Start = 0;
        for (; Start < unsanitizedLine.length(); ++Start) {
            if (taswira::isValidSymbol(unsanitizedLine[Start])) {
                break;
            }
        }

        size_t End = unsanitizedLine.length() - 1;
        for (; End > -1; --End) {
            if (taswira::isValidSymbol(unsanitizedLine[End])) {
                break;
            }
        }

        return unsanitizedLine.substr(Start, End - 1);
    }

    static std::pair<std::string, std::string> HeaderFileLexer(std::string& line) {
        line = taswira::SanitizeLine(line);
        size_t SpaceCount = std::count(line.begin(), line.end(), ' ');

        std::pair<std::string, std::string> Token = std::make_pair<std::string, std::string>("N/A", "N/A");

        if (SpaceCount == 0) {
            // At the moment, SanitizeLine() trims the last letter of the visibility substring
            if (line == "publi") {
                Token = std::make_pair<std::string, std::string>("visibility", "+");
            } else if (line == "protecte") {
                Token = std::make_pair<std::string, std::string>("visibility", "#");
            } else if (line == "privat") {
                Token = std::make_pair<std::string, std::string>("visibility", "-");
            }
        }
        // Only member variables and class names have 1 space character
        else if (SpaceCount == 1) {
            size_t SpaceIndex = line.find(' ');
            std::string Type(line.substr(0, SpaceIndex));
            std::string Name(line.substr(SpaceIndex + 1, line.length() - SpaceIndex));
            Token = std::make_pair(Type, Name);
        }

        return Token;
    }

    static std::vector<taswira::ClassSignature> ParseHeaderFile(std::string& absolutePath) {
        std::vector<taswira::ClassSignature> Classes;
        
        //Signature.Name = "CHAIR";
        //Signature.MemberVariables.push_back("+BACK");
        //Signature.MemberVariables.push_back("+SEAT");
        //Signature.MemberVariables.push_back("+LEGS");
        //Signature.MemberVariables.push_back("+ARMS");
        //Signature.MemberVariables.push_back("#NUMLEGS");
        //Signature.MemberVariables.push_back("-TEXTURE");
        //Signature.MemberVariables.push_back("-ROUGHNESS");

        //Classes.push_back(Signature);

        std::ifstream HeaderFile;

        HeaderFile.open(absolutePath.c_str());
        if (!HeaderFile.is_open()) {
            throw std::ios_base::failure(absolutePath + " failed to open.");
        }

        std::string Line, Visibility("N/A");
        std::vector<std::string> HeaderLines;
        std::pair<std::string, std::string> Token;
        taswira::ClassSignature Signature;

        while (std::getline(HeaderFile, Line)) {

            //Use the lexer to get the tokens
            Token = taswira::HeaderFileLexer(Line);

            //Now we actually parse
            if (Token.first == "N/A") {
                continue;
            }

            if (Token.first == "class") {
                if (Signature.Name != "N/A") {
                    Classes.push_back(Signature);
                }
                Signature.Name = Token.second;
                Signature.MemberVariables.clear();
            }
            else if (Token.first == "visibility") {
                Visibility = Token.second;
            } else {
                Signature.MemberVariables.push_back(Visibility + Token.second);
            }
        }

        if (Signature.Name != "N/A") {
            Classes.push_back(Signature);
        }

        return Classes;
    }

    static std::vector<taswira::ClassSignature> ParseHeaderFile(const char* absolutePath) {
        std::string AbsolutePath(absolutePath);
        return taswira::ParseHeaderFile(AbsolutePath);
    }
}

#endif // !CLASSPARSER_H