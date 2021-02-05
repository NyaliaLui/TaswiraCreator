#ifndef ALPHAFACTORY_H
#define ALPHAFACTORY_H

#include "AlphaUppercase.h"

#include <vector>
#include <array>
#include <memory>
#include <string>

// The Alphafactory uses the factory method
// and the flyweight pattern
namespace taswira {
	class AlphaFactory {
	public:
		AlphaFactory(void)
		{
			Uppercase[0] = std::make_shared<taswira::Uppercase::A>(taswira::Colors::Black);
			Uppercase[1] = std::make_shared<taswira::Uppercase::B>(taswira::Colors::Black);
			Uppercase[2] = std::make_shared<taswira::Uppercase::C>(taswira::Colors::Black);
			Uppercase[3] = std::make_shared<taswira::Uppercase::D>(taswira::Colors::Black);
			Uppercase[4] = std::make_shared<taswira::Uppercase::E>(taswira::Colors::Black);
			Uppercase[5] = std::make_shared<taswira::Uppercase::F>(taswira::Colors::Black);
			Uppercase[6] = std::make_shared<taswira::Uppercase::G>(taswira::Colors::Black);
			Uppercase[7] = std::make_shared<taswira::Uppercase::H>(taswira::Colors::Black);
			Uppercase[8] = std::make_shared<taswira::Uppercase::I>(taswira::Colors::Black);
			Uppercase[9] = std::make_shared<taswira::Uppercase::J>(taswira::Colors::Black);
			Uppercase[10] = std::make_shared<taswira::Uppercase::K>(taswira::Colors::Black);
			Uppercase[11] = std::make_shared<taswira::Uppercase::L>(taswira::Colors::Black);
			Uppercase[12] = std::make_shared<taswira::Uppercase::M>(taswira::Colors::Black);
			Uppercase[13] = std::make_shared<taswira::Uppercase::N>(taswira::Colors::Black);
			Uppercase[14] = std::make_shared<taswira::Uppercase::O>(taswira::Colors::Black);
			Uppercase[15] = std::make_shared<taswira::Uppercase::P>(taswira::Colors::Black);
			Uppercase[16] = std::make_shared<taswira::Uppercase::Q>(taswira::Colors::Black);
			Uppercase[17] = std::make_shared<taswira::Uppercase::R>(taswira::Colors::Black);
			Uppercase[18] = std::make_shared<taswira::Uppercase::S>(taswira::Colors::Black);
			Uppercase[19] = std::make_shared<taswira::Uppercase::T>(taswira::Colors::Black);
			Uppercase[20] = std::make_shared<taswira::Uppercase::U>(taswira::Colors::Black);
			Uppercase[21] = std::make_shared<taswira::Uppercase::V>(taswira::Colors::Black);
			Uppercase[22] = std::make_shared<taswira::Uppercase::W>(taswira::Colors::Black);
			Uppercase[23] = std::make_shared<taswira::Uppercase::X>(taswira::Colors::Black);
			Uppercase[24] = std::make_shared<taswira::Uppercase::Y>(taswira::Colors::Black);
			Uppercase[25] = std::make_shared<taswira::Uppercase::Z>(taswira::Colors::Black);
		}

		AlphaFactory(taswira::Pixel& color)
		{
			Uppercase[0] = std::make_shared<taswira::Uppercase::A>(color);
			Uppercase[1] = std::make_shared<taswira::Uppercase::B>(color);
			Uppercase[2] = std::make_shared<taswira::Uppercase::C>(color);
			Uppercase[3] = std::make_shared<taswira::Uppercase::D>(color);
			Uppercase[4] = std::make_shared<taswira::Uppercase::E>(color);
			Uppercase[5] = std::make_shared<taswira::Uppercase::F>(color);
			Uppercase[6] = std::make_shared<taswira::Uppercase::G>(color);
			Uppercase[7] = std::make_shared<taswira::Uppercase::H>(color);
			Uppercase[8] = std::make_shared<taswira::Uppercase::I>(color);
			Uppercase[9] = std::make_shared<taswira::Uppercase::J>(color);
			Uppercase[10] = std::make_shared<taswira::Uppercase::K>(color);
			Uppercase[11] = std::make_shared<taswira::Uppercase::L>(color);
			Uppercase[12] = std::make_shared<taswira::Uppercase::M>(color);
			Uppercase[13] = std::make_shared<taswira::Uppercase::N>(color);
			Uppercase[14] = std::make_shared<taswira::Uppercase::O>(color);
			Uppercase[15] = std::make_shared<taswira::Uppercase::P>(color);
			Uppercase[16] = std::make_shared<taswira::Uppercase::Q>(color);
			Uppercase[17] = std::make_shared<taswira::Uppercase::R>(color);
			Uppercase[18] = std::make_shared<taswira::Uppercase::S>(color);
			Uppercase[19] = std::make_shared<taswira::Uppercase::T>(color);
			Uppercase[20] = std::make_shared<taswira::Uppercase::U>(color);
			Uppercase[21] = std::make_shared<taswira::Uppercase::V>(color);
			Uppercase[22] = std::make_shared<taswira::Uppercase::W>(color);
			Uppercase[23] = std::make_shared<taswira::Uppercase::X>(color);
			Uppercase[24] = std::make_shared<taswira::Uppercase::Y>(color);
			Uppercase[25] = std::make_shared<taswira::Uppercase::Z>(color);
		}

		AlphaFactory(const AlphaFactory& factory)
			:Uppercase(factory.Uppercase)
		{  }

		~AlphaFactory(void)
		{  }

		AlphaFactory& operator = (const AlphaFactory& factory) {
			this->Uppercase = factory.Uppercase;

			return (*this);
		}

		std::shared_ptr<taswira::IBaseShape> CreateLetter(int letter, bool isUpper = true) {
			return this->Uppercase[letter - int('A')];
		}

		std::shared_ptr<taswira::IBaseShape> CreateA(bool isUpper = true) {
			return this->Uppercase[0];
		}

		std::shared_ptr<taswira::IBaseShape> CreateB(bool isUpper = true) {
			return this->Uppercase[1];
		}

		std::shared_ptr<taswira::IBaseShape> CreateC(bool isUpper = true) {
			return this->Uppercase[2];
		}

		std::shared_ptr<taswira::IBaseShape> CreateD(bool isUpper = true) {
			return this->Uppercase[3];
		}

		std::shared_ptr<taswira::IBaseShape> CreateE(bool isUpper = true) {
			return this->Uppercase[4];
		}

		std::shared_ptr<taswira::IBaseShape> CreateF(bool isUpper = true) {
			return this->Uppercase[5];
		}

		std::shared_ptr<taswira::IBaseShape> CreateG(bool isUpper = true) {
			return this->Uppercase[6];
		}

		std::shared_ptr<taswira::IBaseShape> CreateH(bool isUpper = true) {
			return this->Uppercase[7];
		}

		std::shared_ptr<taswira::IBaseShape> CreateI(bool isUpper = true) {
			return this->Uppercase[8];
		}

		std::shared_ptr<taswira::IBaseShape> CreateJ(bool isUpper = true) {
			return this->Uppercase[9];
		}

		std::shared_ptr<taswira::IBaseShape> CreateK(bool isUpper = true) {
			return this->Uppercase[10];
		}

		std::shared_ptr<taswira::IBaseShape> CreateL(bool isUpper = true) {
			return this->Uppercase[11];
		}

		std::shared_ptr<taswira::IBaseShape> CreateM(bool isUpper = true) {
			return this->Uppercase[12];
		}

		std::shared_ptr<taswira::IBaseShape> CreateN(bool isUpper = true) {
			return this->Uppercase[13];
		}

		std::shared_ptr<taswira::IBaseShape> CreateO(bool isUpper = true) {
			return this->Uppercase[14];
		}

		std::shared_ptr<taswira::IBaseShape> CreateP(bool isUpper = true) {
			return this->Uppercase[15];
		}

		std::shared_ptr<taswira::IBaseShape> CreateQ(bool isUpper = true) {
			return this->Uppercase[16];
		}

		std::shared_ptr<taswira::IBaseShape> CreateR(bool isUpper = true) {
			return this->Uppercase[17];
		}

		std::shared_ptr<taswira::IBaseShape> CreateS(bool isUpper = true) {
			return this->Uppercase[18];
		}

		std::shared_ptr<taswira::IBaseShape> CreateT(bool isUpper = true) {
			return this->Uppercase[19];
		}

		std::shared_ptr<taswira::IBaseShape> CreateU(bool isUpper = true) {
			return this->Uppercase[20];
		}

		std::shared_ptr<taswira::IBaseShape> CreateV(bool isUpper = true) {
			return this->Uppercase[21];
		}

		std::shared_ptr<taswira::IBaseShape> CreateW(bool isUpper = true) {
			return this->Uppercase[22];
		}

		std::shared_ptr<taswira::IBaseShape> CreateX(bool isUpper = true) {
			return this->Uppercase[23];
		}

		std::shared_ptr<taswira::IBaseShape> CreateY(bool isUpper = true) {
			return this->Uppercase[24];
		}

		std::shared_ptr<taswira::IBaseShape> CreateZ(bool isUpper = true) {
			return this->Uppercase[25];
		}

	private:
		std::array<std::shared_ptr<taswira::IBaseShape>, 26> Uppercase;
	};

	static std::vector<std::shared_ptr<taswira::IBaseShape>> CreatePhrase(std::string& phrase, taswira::AlphaFactory& letterFactory) {
		std::vector<std::shared_ptr<taswira::IBaseShape>> Phrase;

		for (char letter : phrase) {
			Phrase.push_back(letterFactory.CreateLetter(letter));
		}

		return Phrase;
	}

	static std::vector<std::shared_ptr<taswira::IBaseShape>> CreatePhrase(const char* phrase, taswira::AlphaFactory& letterFactory) {
		std::vector<std::shared_ptr<taswira::IBaseShape>> Phrase;
		std::string PhraseS(phrase);

		for (char letter : PhraseS) {
			Phrase.push_back(letterFactory.CreateLetter(letter));
		}

		return Phrase;
	}
}

#endif // !ALPHAFACTORY_H