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
            :taswira::Rectangle(),
            LetterPadding(0)
        {  }

        TextBox(int rowDims, int colDims, const taswira::Pixel& color = taswira::Colors::White)
            :taswira::Rectangle(rowDims, colDims, color),
            LetterPadding(2)
        {  }

        ~TextBox(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            // draw the border by calling Parent's DrawOnImage
            taswira::Rectangle::DrawOnImage(image, startRow, startCol);

            // calculate the middle row and free column space while according for padding
            // this will center the phrase in the text box
            int TextBoxMidRow = this->ShapeHeight() / 2;
            int LetterMidRow = taswira::AlphaDims::RowDim / 2;

            int PhrasePixSize = (this->Phrase.size() * taswira::AlphaDims::ColDim) + (this->Phrase.size() * this->LetterPadding);
            int FreeColSpace = this->ShapeWidth() - PhrasePixSize;

            // identify the starting line and column
            int Line = startRow + (TextBoxMidRow - LetterMidRow);
            int col = startCol + (FreeColSpace / 2);

            // draw the phrase
            for (const std::shared_ptr<taswira::IBaseShape>& letter : this->Phrase) {
                letter->DrawOnImage(image, Line, col);
                col += (taswira::AlphaDims::ColDim + this->LetterPadding);
            }
        }

        void AddPhrase(const std::vector<std::shared_ptr<taswira::IBaseShape>>& phrase) {
            this->Phrase = phrase;
        }

    private:
        int LetterPadding;

        std::vector<std::shared_ptr<taswira::IBaseShape>> Phrase;
	};
}

#endif // !TEXTBOX_H