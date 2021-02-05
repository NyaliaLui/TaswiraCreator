#ifndef TEXTBOX_H
#define TEXTBOX_H

#include "BaseShape.h"
#include "Geometry.h"
#include "BitmapImage.h"
#include "Shapes.h"
#include "ObjectDims.h"

#include <vector>
#include <memory>

namespace taswira {
	class TextBox : public taswira::Rectangle {
    public:
        TextBox(void)
        {  }

        TextBox(int rowDims, int colDims, const taswira::Pixel& color = taswira::Colors::Black)
            :taswira::Rectangle(rowDims, colDims, color)
        {  }

        TextBox(int rowDims, int colDims, const std::vector<std::shared_ptr<taswira::IBaseShape>>& phrase, const taswira::Pixel& color = taswira::Colors::Black)
            :taswira::Rectangle(rowDims, colDims, color),
            Phrase(phrase)
        {  }

        TextBox(const TextBox& text)
            :taswira::Rectangle(text),
            Phrase(text.Phrase)
        {  }

        ~TextBox(void)
        {  }

        TextBox& operator = (const TextBox& text) {
            this->taswira::Rectangle::operator=(text);
            this->Phrase = text.Phrase;

            return (*this);
        }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            // draw the border by calling Parent's DrawOnImage
            taswira::Rectangle::DrawOnImage(image, startRow, startCol);

            // calculate the middle row and free column space while according for padding
            // this will center the phrase in the text box
            int TextBoxMidRow = this->ShapeHeight() / 2;
            int LetterMidRow = taswira::AlphaDims::RowDim / 2;

            int PhrasePixSize = (static_cast<int>(this->Phrase.size()) * taswira::AlphaDims::ColDim) + (static_cast<int>(this->Phrase.size()) * taswira::TextDims::LetterPadding);
            int FreeColSpace = this->ShapeWidth() - PhrasePixSize;

            // identify the starting line and column
            int Line = startRow + (TextBoxMidRow - LetterMidRow);
            int col = startCol + (FreeColSpace / 2);

            // draw the phrase
            for (const std::shared_ptr<taswira::IBaseShape>& letter : this->Phrase) {
                letter->DrawOnImage(image, Line, col);
                col += (taswira::AlphaDims::ColDim + taswira::TextDims::LetterPadding);
            }
        }

        void AddPhrase(const std::vector<std::shared_ptr<taswira::IBaseShape>>& phrase) {
            this->Phrase = phrase;
        }

    private:
        std::vector<std::shared_ptr<taswira::IBaseShape>> Phrase;
	};

    class TextBoxNoBorder : public taswira::Parallelogram {
    public:
        TextBoxNoBorder(void)
        {  }

        TextBoxNoBorder(int rowDims, int colDims, const taswira::Pixel& color = taswira::Colors::Black)
            :taswira::Parallelogram(rowDims, colDims, color)
        {  }

        TextBoxNoBorder(int rowDims, int colDims, const std::vector<std::shared_ptr<taswira::IBaseShape>>& phrase, const taswira::Pixel& color = taswira::Colors::Black)
            :taswira::Parallelogram(rowDims, colDims, color),
            Phrase(phrase)
        {  }

        TextBoxNoBorder(const TextBoxNoBorder& text)
            :taswira::Parallelogram(text),
            Phrase(text.Phrase)
        {  }

        TextBoxNoBorder& operator = (const TextBoxNoBorder& text) {
            this->taswira::Parallelogram::operator=(text);
            this->Phrase = text.Phrase;

            return (*this);
        }

        ~TextBoxNoBorder(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            // calculate the middle row and free column space while according for padding
            // this will center the phrase in the text box
            int TextBoxMidRow = this->ShapeHeight() / 2;
            int LetterMidRow = taswira::AlphaDims::RowDim / 2;

            int PhrasePixSize = (static_cast<int>(this->Phrase.size()) * taswira::AlphaDims::ColDim) + (static_cast<int>(this->Phrase.size()) * taswira::TextDims::LetterPadding);
            int FreeColSpace = this->ShapeWidth() - PhrasePixSize;

            // identify the starting line and column
            int Line = startRow + (TextBoxMidRow - LetterMidRow);
            int col = startCol + (FreeColSpace / 2);

            // draw the phrase
            for (const std::shared_ptr<taswira::IBaseShape>& letter : this->Phrase) {
                letter->DrawOnImage(image, Line, col);
                col += (taswira::AlphaDims::ColDim + taswira::TextDims::LetterPadding);
            }
        }

        void AddPhrase(const std::vector<std::shared_ptr<taswira::IBaseShape>>& phrase) {
            this->Phrase = phrase;
        }

    private:
        std::vector<std::shared_ptr<taswira::IBaseShape>> Phrase;
    };
}

#endif // !TEXTBOX_H