#ifndef SHAPES_H
#define SHAPES_H

#include "BaseShape.h"
#include "BitmapImage.h"

namespace taswira {
    class Circle : public taswira::IBaseShape {
    public:
        Circle(void)
            :Radius(0)
        {  }

        Circle(int radius, const taswira::Pixel& color)
            :IBaseShape(color),
            Radius(radius)
        {  }

        // Uses the Midpoint Circle Algorithm modified from https://www.geeksforgeeks.org/mid-point-circle-drawing-algorithm/
        virtual void DrawOnImage(taswira::BitmapImage& image, int CenterX, int CenterY) {
            int X = Radius, Y = 0;

            if (Radius > 0) {
                image.PixelAt(X + CenterX, -Y + CenterY) = this->ShapeColor();
                image.PixelAt(Y + CenterX, X + CenterY) = this->ShapeColor();
                image.PixelAt(-Y + CenterX, X + CenterY) = this->ShapeColor();
            }

            // Initialising the value of Point 
            int Point = 1 - Radius;
            while (X > Y) {
                ++Y;

                // Mid-point is inside or on the perimeter 
                if (Point <= 0)
                    Point += 2 * Y + 1;
                // Mid-point is outside the perimeter 
                else {
                    --X;
                    Point += 2 * Y - 2 * X + 1;
                }

                // All the perimeter points have already been printed 
                if (X < Y)
                    break;

                // Printing the generated point and its reflection 
                // in the other octants after translation 
                image.PixelAt(X + CenterX, Y + CenterY) = this->ShapeColor();
                image.PixelAt(-X + CenterX, Y + CenterY) = this->ShapeColor();
                image.PixelAt(X + CenterX, -Y + CenterY) = this->ShapeColor();
                image.PixelAt(-X + CenterX, -Y + CenterY) = this->ShapeColor();

                // If the generated point is on the line x = y then  
                // the perimeter points have already been printed 
                if (X != Y) {
                    image.PixelAt(Y + CenterX, X + CenterY) = this->ShapeColor();
                    image.PixelAt(-Y + CenterX, X + CenterY) = this->ShapeColor();
                    image.PixelAt(Y + CenterX, -X + CenterY) = this->ShapeColor();
                    image.PixelAt(-Y + CenterX, -X + CenterY) = this->ShapeColor();
                }
            }
        }

        int& ShapeRadius(void) {
            return this->Radius;
        }

    private:
        int Radius;
    };

    class Square : public taswira::IBaseShape {
    public:
        Square(void)
            :RowDims(0),
            ColDims(0)
        {  }

        Square(int rowDims, int colDims, const taswira::Pixel &color)
            :IBaseShape(color),
            RowDims(rowDims),
            ColDims(colDims)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            // do nothing;
        }

        int& ShapeWidth(void) {
            return this->RowDims;
        }

        int& ShapeHeight(void) {
            return this->ColDims;
        }

    private:
        int RowDims;
        int ColDims;
    };

    class FilledInSquare : public Square {
    public:
        FilledInSquare(void)
            :Square()
        {  }

        FilledInSquare(int rowDims, int colDims, const taswira::Pixel& color)
            :Square(rowDims, colDims, color)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage &image, int startRow, int startCol) {
            int RowLen = startRow + this->ShapeWidth();
            int ColLen = startCol + this->ShapeHeight();

            for (int row = startRow; row < RowLen; ++row) {
                for (int j = startCol; j < ColLen; ++j) {
                    image.PixelAt(row, j) = this->ShapeColor();
                }
            }
        }
    };

    class EmptySquare : public Square {
    public:
        EmptySquare(void)
            :Square()
        {  }

        EmptySquare(int rowDims, int colDims, const taswira::Pixel& color)
            :Square(rowDims, colDims, color)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int RowLen = startRow + this->ShapeWidth();
            int ColLen = startCol + this->ShapeHeight();

            // draw top line
            for (int col = startCol; col < ColLen; ++col) {
                image.PixelAt(startRow, col) = this->ShapeColor();
            }

            // draw bottom line
            for (int col = startCol; col < ColLen; ++col) {
                image.PixelAt(RowLen - 1, col) = this->ShapeColor();
            }

            // draw left line
            for (int row = startRow; row < RowLen; ++row) {
                image.PixelAt(row, startCol) = this->ShapeColor();
            }

            // draw right line
            for (int row = startRow; row < RowLen; ++row) {
                image.PixelAt(row, ColLen - 1) = this->ShapeColor();
            }
        }
    };
}

#endif // !SHAPES_H
