#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Pixel.h"
#include "BitmapImage.h"
#include <cmath>

namespace taswira {
    namespace Geometry {
        // Using Bresenham's Line drawing algorithm https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#Derivation
        static void DrawLineOnImage(taswira::BitmapImage &image, int row1, int col1, int row2, int col2, taswira::Pixel &color) {
            int DeltaRow = std::abs(row2 - row1);
            int SRow = (row1 < row2 ? 1 : -1);
            int DeltaCol = -std::abs(col2 - col1);
            int SCol = (col1 < col2 ? 1 : -1);
            int Err = DeltaRow + DeltaCol;

            while (true) {
                image.PixelAt(row1, col1) = color;

                if (row1 == row2 && col1 == col2) break;
                int Err2 = 2 * Err;

                if (Err2 >= DeltaCol) {
                    Err += DeltaCol;
                    row1 += SRow;
                }

                if (Err2 <= DeltaRow) {
                    Err += DeltaRow;
                    col1 += SCol;
                }
            }
        }
    }
}

#endif // !GEOMETRY_H