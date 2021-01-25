#ifndef BASESHAPE_H
#define BASESHAPE_H

#include "Connector.h"
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

        taswira::Connector& ShapeBottomConnection(void) {
            return this->BottomConnector;
        }

        taswira::Connector& ShapeTopConnection(void) {
            return this->TopConnector;
        }

        taswira::Connector& ShapeLeftConnection(void) {
            return this->LeftConnector;
        }

        taswira::Connector& ShapeRightConnection(void) {
            return this->RightConnector;
        }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) = 0;

    private:
        taswira::Pixel Color;
        taswira::Connector BottomConnector;
        taswira::Connector TopConnector;
        taswira::Connector LeftConnector;
        taswira::Connector RightConnector;
    };
}

#endif // !BASESHAPE_H