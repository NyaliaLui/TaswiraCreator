#ifndef BASESHAPE_H
#define BASESHAPE_H

#include "Pixel.h"
#include "BitmapImage.h"

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

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) = 0;

    private:
        taswira::Pixel Color;
    };
}

#endif // !BASESHAPE_H