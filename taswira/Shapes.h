#ifndef SHAPES_H
#define SHAPES_H

#include "BaseShape.h"
#include "Geometry.h"
#include "BitmapImage.h"

namespace taswira {
    class Triangle : public taswira::IBaseShape {
    public:
        Triangle(void)
            :LineLength(0)
        {  }

        Triangle(int lineLength, const taswira::Pixel& color)
            :IBaseShape(color),
            LineLength(lineLength)
        {  }

        ~Triangle(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int VertexRow1 = startRow, VertexCol1 = startCol;
            int VertexRow2 = startRow + this->LineLength, VertexCol2 = startCol + (this->LineLength / 2);
            int VertexRow3 = startRow, VertexCol3 = startCol  + (this->LineLength);

            // diagonal lines
            taswira::Geometry::DrawLineOnImage(image, VertexRow1, VertexCol1, VertexRow2, VertexCol2, this->ShapeColor());
            taswira::Geometry::DrawLineOnImage(image, VertexRow2, VertexCol2, VertexRow3, VertexCol3, this->ShapeColor());

            // horizontal line
            for (int col = startCol; col < VertexCol3; ++col) {
                image.PixelAt(startRow, col) = this->ShapeColor();
            }
        }

        int& ShapeLineLength(void) {
            return this->LineLength;
        }

    private:
        int LineLength;
    };

    class Parallelogram : public taswira::IBaseShape {
    public:
        Parallelogram(void)
            :RowDims(0),
            ColDims(0)
        {  }

        Parallelogram(int rowDims, int colDims, const taswira::Pixel& color)
            :IBaseShape(color),
            RowDims(rowDims),
            ColDims(colDims)
        {  }

        virtual ~Parallelogram(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            // do nothing;
        }

        int& ShapeHeight(void) {
            return this->RowDims;
        }

        int& ShapeWidth(void) {
            return this->ColDims;
        }

    private:
        int RowDims;
        int ColDims;
    };

    class Rectangle : public Parallelogram {
    public:
        Rectangle(void)
            :Parallelogram()
        {  }

        Rectangle(int rowDims, int colDims, const taswira::Pixel& color)
            :Parallelogram(rowDims, colDims, color)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int RowLen = startRow + this->ShapeHeight();
            int ColLen = startCol + this->ShapeWidth();

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

    class Square : public Rectangle {
    public:
        Square(void)
            :Rectangle()
        {  }

        Square(int dims, const taswira::Pixel& color)
            :Rectangle(dims, dims, color)
        {  }
    };

    class Circle : public taswira::IBaseShape {
    public:
        Circle(void)
            :Radius(0)
        {  }

        Circle(int radius, const taswira::Pixel& color)
            :IBaseShape(color),
            Radius(radius)
        {  }

        ~Circle(void)
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
}

#endif // !SHAPES_H
