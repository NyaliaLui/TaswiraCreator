#ifndef BASESHAPE_H
#define BASESHAPE_H

#include "Connector.h"
#include "Pixel.h"
#include "BitmapImage.h"

namespace taswira {
    // Shapes in Taswira are designed with the Command Pattern
    class IBaseShape {
    public:
        IBaseShape(void)
        {  }

        IBaseShape(const taswira::Pixel& color)
            :Color(color)
        {  }

        IBaseShape(const IBaseShape& base)
            :Color(base.Color)
        {  }

        virtual ~IBaseShape(void)
        {  }

        IBaseShape& operator = (const IBaseShape& shape) {
            this->Color = shape.Color;

            return (*this);
        }

        taswira::Pixel& ShapeColor(void) {
            return this->Color;
        }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) = 0;

    private:
        taswira::Pixel Color;
    };
}

#endif // !BASESHAPE_H