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
    };
}

#endif // !PIXEL_H
