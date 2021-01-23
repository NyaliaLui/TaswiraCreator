#ifndef BASESHAPE_H
#define BASESHAPE_H

#include "Pixel.h"

namespace taswira {
    class IBaseShape {
    public:
        IBaseShape(void)
        {  }

        IBaseShape(const taswira::Pixel& color)
            :Color(color)
        {  }

        taswira::Pixel& ShapeColor(void) {
            return this->Color;
        }

        virtual void DrawSquareOnImage(taswira::BitmapImage& image, int startRow, int startCol) = 0;
        virtual void DrawCircleOnImage(taswira::BitmapImage& image, int CenterX, int CenterY) = 0;
        virtual void DrawAlphaCharOnImage(taswira::BitmapImage& image, int startRow, int startCol) = 0;

    private:
        taswira::Pixel Color;
    };
}

#endif // !BASESHAPE_H