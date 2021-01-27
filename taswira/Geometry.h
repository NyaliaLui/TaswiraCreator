#ifndef GEOMETRY_H
#define GEOMETRY_H

#include "Connector.h"
#include "Pixel.h"
#include "BitmapImage.h"
#include <cmath>

namespace taswira {
    namespace Geometry {
        // Using Bresenham's Line drawing algorithm https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm#Derivation
        // Because I think about images by selecting the row first (i.e. the height) and then the column (i.e. the width),
        // the structure to a point is (Y, X) instead of (X, Y).
        static void DrawLineOnImage(taswira::BitmapImage& image, int row1, int col1, int row2, int col2, taswira::Pixel& color) {
            int DeltaCol = std::abs(col2 - col1);
            int SCol = (col1 < col2 ? 1 : -1);
            int DeltaRow = -std::abs(row2 - row1);
            int SRow = (row1 < row2 ? 1 : -1);
            int Err = DeltaCol + DeltaRow;

            while (true) {
                image.PixelAt(row1, col1) = color;

                if (col1 == col2 && row1 == row2) break;
                int Err2 = 2 * Err;

                if (Err2 >= DeltaRow) {
                    Err += DeltaRow;
                    col1 += SCol;
                }

                if (Err2 <= DeltaCol) {
                    Err += DeltaCol;
                    row1 += SRow;
                }
            }
        }

        static void DrawLineOnImage(taswira::BitmapImage& image, taswira::Connector& conn1, taswira::Connector& conn2, taswira::Pixel& color) {
            DrawLineOnImage(image, conn1.RowLocation(), conn1.ColLocation(), conn2.RowLocation(), conn2.ColLocation(), color);
        }

        static int CalculateDistance(int row1, int col1, int row2, int col2) {
            int DeltaCol = col2 - col1;
            int DeltaRow = row2 - row1;
            int Result = (DeltaCol * DeltaCol) + (DeltaRow * DeltaRow);
            Result = std::sqrt(Result);

            return Result;
        }

        static int CalculateDistance(taswira::Connector& conn1, taswira::Connector& conn2) {
            return CalculateDistance(conn1.RowLocation(), conn1.ColLocation(), conn2.RowLocation(), conn2.ColLocation());
        }
    }
}

#endif // !GEOMETRY_H