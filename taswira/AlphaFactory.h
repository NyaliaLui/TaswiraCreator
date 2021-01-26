#ifndef ALPHAFACTORY_H
#define ALPHAFACTORY_H

#include "AlphaUppercase.h"

#include <vector>
#include <memory>
#include <string>

// The Alphafactory uses the factory method
namespace taswira {
	struct AlphaFactory {
		AlphaFactory(void)
		{  }

		~AlphaFactory(void)
		{  }

		std::shared_ptr<taswira::Uppercase::A> CreateA(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::A>(color);
		}

		std::shared_ptr<taswira::Uppercase::B> CreateB(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::B>(color);
		}

		std::shared_ptr<taswira::Uppercase::C> CreateC(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::C>(color);
		}

		std::shared_ptr<taswira::Uppercase::D> CreateD(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::D>(color);
		}

		std::shared_ptr<taswira::Uppercase::E> CreateE(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::E>(color);
		}

		std::shared_ptr<taswira::Uppercase::F> CreateF(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::F>(color);
		}

		std::shared_ptr<taswira::Uppercase::G> CreateG(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::G>(color);
		}

		std::shared_ptr<taswira::Uppercase::H> CreateH(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::H>(color);
		}

		std::shared_ptr<taswira::Uppercase::I> CreateI(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::I>(color);
		}

		std::shared_ptr<taswira::Uppercase::J> CreateJ(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::J>(color);
		}

		std::shared_ptr<taswira::Uppercase::K> CreateK(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::K>(color);
		}

		std::shared_ptr<taswira::Uppercase::L> CreateL(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::L>(color);
		}

		std::shared_ptr<taswira::Uppercase::M> CreateM(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::M>(color);
		}

		std::shared_ptr<taswira::Uppercase::N> CreateN(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::N>(color);
		}

		std::shared_ptr<taswira::Uppercase::O> CreateO(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::O>(color);
		}

		std::shared_ptr<taswira::Uppercase::P> CreateP(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::P>(color);
		}

		std::shared_ptr<taswira::Uppercase::Q> CreateQ(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::Q>(color);
		}

		std::shared_ptr<taswira::Uppercase::R> CreateR(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::R>(color);
		}

		std::shared_ptr<taswira::Uppercase::S> CreateS(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::S>(color);
		}

		std::shared_ptr<taswira::Uppercase::T> CreateT(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::T>(color);
		}

		std::shared_ptr<taswira::Uppercase::U> CreateU(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::U>(color);
		}

		std::shared_ptr<taswira::Uppercase::V> CreateV(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::V>(color);
		}

		std::shared_ptr<taswira::Uppercase::W> CreateW(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::W>(color);
		}

		std::shared_ptr<taswira::Uppercase::X> CreateX(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::X>(color);
		}

		std::shared_ptr<taswira::Uppercase::Y> CreateY(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::Y>(color);
		}

		std::shared_ptr<taswira::Uppercase::Z> CreateZ(taswira::Pixel& color, bool isUpper = true) {
			return std::make_shared<taswira::Uppercase::Z>(color);
		}
	};

	static taswira::AlphaFactory LetterFactory;

	static std::shared_ptr<taswira::IBaseShape> CreateLetter(char letter, taswira::Pixel& color) {
		if (letter == 'A') {
			return LetterFactory.CreateA(color);
		} else if (letter == 'B') {
			return LetterFactory.CreateB(color);
		}  else if (letter == 'C') {
			return LetterFactory.CreateC(color);
		} else if (letter == 'D') {
			return LetterFactory.CreateD(color);
		} else if (letter == 'E') {
			return LetterFactory.CreateE(color);
		} else if (letter == 'F') {
			return LetterFactory.CreateF(color);
		} else if (letter == 'G') {
			return LetterFactory.CreateG(color);
		} else if (letter == 'H') {
			return LetterFactory.CreateH(color);
		} else if (letter == 'I') {
			return LetterFactory.CreateI(color);
		} else if (letter == 'J') {
			return LetterFactory.CreateJ(color);
		} else if (letter == 'K') {
			return LetterFactory.CreateK(color);
		} else if (letter == 'L') {
			return LetterFactory.CreateL(color);
		} else if (letter == 'M') {
			return LetterFactory.CreateM(color);
		} else if (letter == 'N') {
			return LetterFactory.CreateN(color);
		} else if (letter == 'O') {
			return LetterFactory.CreateO(color);
		} else if (letter == 'P') {
			return LetterFactory.CreateP(color);
		} else if (letter == 'Q') {
			return LetterFactory.CreateQ(color);
		} else if (letter == 'R') {
			return LetterFactory.CreateR(color);
		} else if (letter == 'S') {
			return LetterFactory.CreateS(color);
		} else if (letter == 'T') {
			return LetterFactory.CreateT(color);
		} else if (letter == 'U') {
			return LetterFactory.CreateU(color);
		} else if (letter == 'V') {
			return LetterFactory.CreateV(color);
		} else if (letter == 'W') {
			return LetterFactory.CreateW(color);
		} else if (letter == 'X') {
			return LetterFactory.CreateX(color);
		} else if (letter == 'Y') {
			return LetterFactory.CreateY(color);
		} else if (letter == 'Z') {
			return LetterFactory.CreateZ(color);
		}
	}

	static std::vector<std::shared_ptr<taswira::IBaseShape>> CreatePhrase(std::string phrase, taswira::Pixel& color) {
		std::vector<std::shared_ptr<taswira::IBaseShape>> Phrase;

		for (char letter : phrase) {
			Phrase.push_back(taswira::CreateLetter(letter, color));
		}

		return Phrase;
	}
}

#endif // !ALPHAFACTORY_H