#ifndef SHAPES_H
#define SHAPES_H

#include "BaseShape.h"
#include "Geometry.h"
#include "BitmapImage.h"

namespace taswira {
    class Triangle : public taswira::IBaseShape {
    public:
        Triangle(void)
            :LineLen(0)
        {  }

        Triangle(int lineLength, const taswira::Pixel& color)
            :IBaseShape(color),
            LineLen(lineLength)
        {  }

        ~Triangle(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int VertexRow1 = startRow, VertexCol1 = startCol;
            int VertexRow2 = startRow + this->LineLen, VertexCol2 = startCol + (this->LineLen / 2);
            int VertexRow3 = startRow, VertexCol3 = startCol  + (this->LineLen);

            // diagonal lines
            taswira::Geometry::DrawLineOnImage(image, VertexRow1, VertexCol1, VertexRow2, VertexCol2, this->ShapeColor());
            taswira::Geometry::DrawLineOnImage(image, VertexRow2, VertexCol2, VertexRow3, VertexCol3, this->ShapeColor());

            // horizontal line
            for (int col = startCol; col < VertexCol3; ++col) {
                image.PixelAt(startRow, col) = this->ShapeColor();
            }
        }

        int& ShapeLineLength(void) {
            return this->LineLen;
        }

    private:
        int LineLen;
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

        Parallelogram(const Parallelogram& parallelogram)
            :IBaseShape(parallelogram),
            RowDims(parallelogram.RowDims),
            ColDims(parallelogram.ColDims)
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

        Rectangle(const Rectangle& rectangle)
            :Parallelogram(rectangle)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int RowLen = startRow + this->ShapeHeight();
            int ColLen = startCol + this->ShapeWidth();

            // draw horizontal lines
            for (int col = startCol; col < ColLen; ++col) {
                image.PixelAt(startRow, col) = this->ShapeColor();
                image.PixelAt(RowLen - 1, col) = this->ShapeColor();
            }

            // draw vertical lines
            for (int row = startRow; row < RowLen; ++row) {
                image.PixelAt(row, ColLen - 1) = this->ShapeColor();
                image.PixelAt(row, startCol) = this->ShapeColor();
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

    class Diamond : public Parallelogram {
    public:
        Diamond(void)
            :Parallelogram()
        {  }

        Diamond(int dims, const taswira::Pixel& color)
            :Parallelogram(dims, dims, color)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int LineLen = this->ShapeHeight();

            int VertexRow1 = startRow + (LineLen / 2), VertexCol1 = startCol;
            int VertexRow2 = startRow + LineLen - 1, VertexCol2 = startCol + (LineLen / 2);
            int VertexRow3 = startRow + (LineLen / 2), VertexCol3 = startCol + LineLen - 1;
            int VertexRow4 = startRow, VertexCol4 = startCol + (LineLen / 2);

            // diagonal lines
            taswira::Geometry::DrawLineOnImage(image, VertexRow1, VertexCol1, VertexRow2, VertexCol2, this->ShapeColor());
            taswira::Geometry::DrawLineOnImage(image, VertexRow2, VertexCol2, VertexRow3, VertexCol3, this->ShapeColor());
            taswira::Geometry::DrawLineOnImage(image, VertexRow3, VertexCol3, VertexRow4, VertexCol4, this->ShapeColor());
            taswira::Geometry::DrawLineOnImage(image, VertexRow4, VertexCol4, VertexRow1, VertexCol1, this->ShapeColor());
        }
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

    class Plus : public taswira::IBaseShape {
    public:
        Plus(void)
            :RowDims(0),
            ColDims(0)
        {  }

        Plus(int rowDims, int colDims, const taswira::Pixel& color)
            :IBaseShape(color),
            RowDims(rowDims),
            ColDims(colDims)
        {  }

        Plus(const Plus& plus)
            :IBaseShape(plus),
            RowDims(plus.RowDims),
            ColDims(plus.ColDims)
        {  }

        virtual ~Plus(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int MiddleRow = startRow + this->ShapeHeight() / 2;
            int MiddleCol = startCol + this->ShapeWidth() / 2;

            // horizontal bar
            for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                image.PixelAt(MiddleRow, col) = this->ShapeColor();
            }

            // vertical bar
            for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                image.PixelAt(row, MiddleCol) = this->ShapeColor();
            }
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

    class Minus : public taswira::IBaseShape {
    public:
        Minus(void)
            :RowDims(0),
            ColDims(0)
        {  }

        Minus(int rowDims, int colDims, const taswira::Pixel& color)
            :IBaseShape(color),
            RowDims(rowDims),
            ColDims(colDims)
        {  }

        Minus(const Minus& minus)
            :IBaseShape(minus),
            RowDims(minus.RowDims),
            ColDims(minus.ColDims)
        {  }

        virtual ~Minus(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int MiddleRow = startRow + this->ShapeHeight() / 2;

            // horizontal bar
            for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                image.PixelAt(MiddleRow, col) = this->ShapeColor();
            }
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

    class HashTag : public taswira::IBaseShape {
    public:
        HashTag(void)
            :RowDims(0),
            ColDims(0)
        {  }

        HashTag(int rowDims, int colDims, const taswira::Pixel& color)
            :IBaseShape(color),
            RowDims(rowDims),
            ColDims(colDims)
        {  }

        HashTag(const HashTag& sign)
            :IBaseShape(sign),
            RowDims(sign.RowDims),
            ColDims(sign.ColDims)
        {  }

        virtual ~HashTag(void)
        {  }

        virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
            int ThirdOfARow = this->ShapeHeight() / 3;
            int MiddleCol = startCol + this->ShapeWidth() / 2;

            // horizontal bars
            for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                image.PixelAt(startRow + ThirdOfARow, col) = this->ShapeColor();
                image.PixelAt(startRow + (2 * ThirdOfARow), col) = this->ShapeColor();
            }

            // diagonal bars
            taswira::Geometry::DrawLineOnImage(image, startRow, startCol, startRow + this->ShapeHeight() - 1, MiddleCol, this->ShapeColor());
            taswira::Geometry::DrawLineOnImage(image, startRow, MiddleCol, startRow + this->ShapeHeight() - 1, startCol + this->ShapeWidth() - 1, this->ShapeColor());
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
}

#endif // !SHAPES_H
