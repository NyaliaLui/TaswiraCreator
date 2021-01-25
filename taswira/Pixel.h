#ifndef PIXEL_H
#define PIXEL_H

#include <cstdint>

namespace taswira {
    struct Pixel {
        uint8_t Blue;
        uint8_t Green;
        uint8_t Red;

        Pixel(void)
            :Blue(0),
            Green(0),
            Red(0)
        {  }

        Pixel(int blue, int green, int red)
            :Blue(blue),
            Green(green),
            Red(red)
        {  }

        Pixel(const Pixel& pixel)
            :Blue(pixel.Blue),
            Green(pixel.Green),
            Red(pixel.Red)
        {  }

        ~Pixel(void)
        {  }

        Pixel& operator = (const Pixel& pixel) {
            this->Blue = pixel.Blue;
            this->Green = pixel.Green;
            this->Red = pixel.Red;

            return (*this);
        }
    };

    namespace Colors {
        taswira::Pixel Blue(255, 0, 0);
        taswira::Pixel Green(0, 255, 0);
        taswira::Pixel Red(0, 0, 255);
        taswira::Pixel White(255, 255, 255);
        taswira::Pixel Black(0, 0, 0);
    } // namespace Colors

}

#endif // !PIXEL_H