#ifndef ALPHAUPPERCASE_H
#define ALPHAUPPERCASE_H

#include "Shapes.h"
#include "BitmapImage.h"
#include "ObjectDims.h"
#include "Geometry.h"

namespace taswira {

    namespace Uppercase {
        class A : public taswira::Parallelogram {
        public:
            A(void)
                :Parallelogram()
            {  }

            A(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {

                // left diagonal
                taswira::Geometry::DrawLineOnImage(image, startRow, startCol, startRow + 15, startCol + 8, this->ShapeColor());

                // right diagonal
                taswira::Geometry::DrawLineOnImage(image, startRow + 15, startCol + 8, startRow, startCol + 15, this->ShapeColor());

                // horizontal bar
                for (int col = startCol + 3; col < startCol + 13; ++col) {
                    image.PixelAt(startRow + 7, col) = this->ShapeColor();
                }
            }
        };

        class B : public taswira::Parallelogram {
        public:
            B(void)
                :Parallelogram()
            {  }

            B(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + 13; ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow + 7, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }
                image.PixelAt(startRow, startCol + 13) = this->ShapeColor();

                // vertical bars
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }

                image.PixelAt(startRow + 14, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 13, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 12, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 11, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 10, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 9, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 8, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 6, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 5, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 4, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 3, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 2, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 1, startCol + 14) = this->ShapeColor();
            }
        };

        class C : public taswira::Parallelogram {
        public:
            C(void)
                :Parallelogram()
            {  }

            C(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol + 4; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // add the "curve" dots
                image.PixelAt(startRow + 15, startCol + 3) = this->ShapeColor();
                image.PixelAt(startRow + 14, startCol + 2) = this->ShapeColor();
                image.PixelAt(startRow + 13, startCol + 1) = this->ShapeColor();
                image.PixelAt(startRow + 3, startCol + 1) = this->ShapeColor();
                image.PixelAt(startRow + 2, startCol + 2) = this->ShapeColor();
                image.PixelAt(startRow + 1, startCol + 3) = this->ShapeColor();

                // vertical bar
                for (int row = startRow + 4; row < startRow + 13; ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }
            }
        };

        class D : public taswira::Parallelogram {
        public:
            D(void)
                :Parallelogram()
            {  }

            D(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + 11; ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // add the "curve" dots
                image.PixelAt(startRow + 14, startCol + 11) = this->ShapeColor();
                image.PixelAt(startRow + 13, startCol + 12) = this->ShapeColor();
                image.PixelAt(startRow + 12, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 11, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 4, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 3, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 2, startCol + 12) = this->ShapeColor();
                image.PixelAt(startRow + 1, startCol + 11) = this->ShapeColor();

                // left vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }

                // right vertical bar
                for (int row = startRow + 5; row < startRow + 11; ++row) {
                    image.PixelAt(row, startCol + 15) = this->ShapeColor();
                }
            }
        };

        class E : public taswira::Parallelogram {
        public:
            E(void)
                :Parallelogram()
            {  }

            E(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow + 7, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }
            }
        };

        class F : public taswira::Parallelogram {
        public:
            F(void)
                :Parallelogram()
            {  }

            F(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow + 7, col) = this->ShapeColor();
                }

                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }
            }
        };

        class G : public taswira::Parallelogram {
        public:
            G(void)
                :Parallelogram()
            {  }

            G(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();

                    if (col >= (startCol + 11) && col <= (startCol + this->ShapeWidth())) {
                        image.PixelAt(startRow + 8, col) = this->ShapeColor();
                    }
                }

                // left vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();

                    if (row >= startRow && row <= (startRow + 8)) {
                        image.PixelAt(row, startCol + 15) = this->ShapeColor();
                    }
                }
            }
        };

        class H : public taswira::Parallelogram {
        public:
            H(void)
                :Parallelogram()
            {  }

            H(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bar
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 7, col) = this->ShapeColor();
                }

                // vertical bars
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                    image.PixelAt(row, startCol + 15) = this->ShapeColor();
                }
            }
        };

        class I : public taswira::Parallelogram {
        public:
            I(void)
                :Parallelogram()
            {  }

            I(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol + 8) = this->ShapeColor();
                }
            }
        };

        class J : public taswira::Parallelogram {
        public:
            J(void)
                :Parallelogram()
            {  }

            J(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // vertical bar
                for (int row = startRow + 4; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol + 15) = this->ShapeColor();
                }

                // add the "curve" lines
                taswira::Geometry::DrawLineOnImage(image, startRow + 4, startCol + 15,
                    startRow + 1, startCol + 11, this->ShapeColor());

                taswira::Geometry::DrawLineOnImage(image, startRow + 1, startCol + 6,
                    startRow + 4, startCol + 2, this->ShapeColor());

                // horizontal bars
                for (int col = startCol + 7; col < startCol + 11; ++col) {
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }
            }
        };

        class K : public taswira::Parallelogram {
        public:
            K(void)
                :Parallelogram()
            {  }

            K(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }

                // top diagonal line
                taswira::Geometry::DrawLineOnImage(image, startRow + 8, startCol + 1,
                    startRow + this->ShapeHeight() - 1, startCol + this->ShapeWidth() - 1, this->ShapeColor());

                // bottom diagonal line
                taswira::Geometry::DrawLineOnImage(image, startRow + 7, startCol + 1,
                    startRow, startCol + this->ShapeWidth() - 1, this->ShapeColor());
            }
        };

        class L : public taswira::Parallelogram {
        public:
            L(void)
                :Parallelogram()
            {  }

            L(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bar
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }
            }
        };

        class M : public taswira::Parallelogram {
        public:
            M(void)
                :Parallelogram()
            {  }

            M(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // vertical bars
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                    image.PixelAt(row, startCol + 15) = this->ShapeColor();
                }

                // left diagonal line
                int col = startCol + 7;
                for (int row = startRow + 1; row < startRow + 15; row += 2) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    image.PixelAt(row + 1, col) = this->ShapeColor();
                    --col;
                }

                // middle point
                image.PixelAt(startRow, startCol + 8) = this->ShapeColor();

                // right diagonal line
                col = startCol + 9;
                for (int row = startRow + 1; row < startRow + 15; row += 2) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    image.PixelAt(row + 1, col) = this->ShapeColor();
                    ++col;
                }
            }
        };

        class N : public taswira::Parallelogram {
        public:
            N(void)
                :Parallelogram()
            {  }

            N(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // vertical bars
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                    image.PixelAt(row, startCol + 15) = this->ShapeColor();
                }

                // left diagonal line
                int col = startCol + 1;
                for (int row = startRow + this->ShapeHeight() - 1; row > startRow; --row) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    ++col;
                }
            }
        };

        class O : public taswira::Parallelogram {
        public:
            O(void)
                :Parallelogram()
            {  }

            O(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color),
                OCircle(7, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                this->OCircle.DrawOnImage(image, startRow + (this->ShapeHeight() / 2), startCol + (this->ShapeWidth() / 2));
            }
        private:
            taswira::Circle OCircle;
        };

        class P : public taswira::Parallelogram {
        public:
            P(void)
                :Parallelogram()
            {  }

            P(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + 13; ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow + 8, col) = this->ShapeColor();
                }

                // add the "curve" dots
                image.PixelAt(startRow + 14, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 13, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 12, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 11, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 10, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 9, startCol + 13) = this->ShapeColor();
                
                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }
            }
        };

        class Q : public taswira::Parallelogram {
        public:
            Q(void)
                :Parallelogram()
            {  }

            Q(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color),
                QCircle(6, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                this->QCircle.DrawOnImage(image, startRow + 9, startCol + 8);
                image.PixelAt(startRow + 2, startCol + 10) = this->ShapeColor();
                image.PixelAt(startRow + 1, startCol + 11) = this->ShapeColor();
                image.PixelAt(startRow, startCol + 12) = this->ShapeColor();
            }
        private:
            taswira::Circle QCircle;
        };

        class R : public taswira::Parallelogram {
        public:
            R(void)
                :Parallelogram()
            {  }

            R(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + 13; ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow + 8, col) = this->ShapeColor();
                }

                // add the "curve" dots
                image.PixelAt(startRow + 14, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 13, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 12, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 11, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 10, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 9, startCol + 13) = this->ShapeColor();

                // diagonal line
               int col = startCol + 6;
                for (int row = startRow + 8; row >= startRow; --row) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    ++col;
                }

                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }
            }
        };

        class S : public taswira::Parallelogram {
        public:
            S(void)
                :Parallelogram()
            {  }

            S(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bar
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow + 8, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // vertical bars
                int col = startCol + 15;
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    if (row == (startRow + 8)) {
                        col = startCol;
                    }

                    image.PixelAt(row, col) = this->ShapeColor();
                }
            }
        };

        class T : public taswira::Parallelogram {
        public:
            T(void)
                :Parallelogram()
            {  }

            T(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bar
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                }

                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol + 7) = this->ShapeColor();
                }
            }
        };

        class U : public taswira::Parallelogram {
        public:
            U(void)
                :Parallelogram()
            {  }

            U(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // vertical bars
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                    image.PixelAt(row, startCol + 15) = this->ShapeColor();
                }

                // horizontal bar
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }
            }
        };

        class V : public taswira::Parallelogram {
        public:
            V(void)
                :Parallelogram()
            {  }

            V(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // diagonal lines
                taswira::Geometry::DrawLineOnImage(image, startRow, startCol + 8,
                    startRow + this->ShapeHeight() - 1, startCol, this->ShapeColor());

                taswira::Geometry::DrawLineOnImage(image, startRow, startCol + 8,
                    startRow + this->ShapeHeight() - 1, startCol + this->ShapeWidth() - 1, this->ShapeColor());
            }
        };

        class W : public taswira::Parallelogram {
        public:
            W(void)
                :Parallelogram()
            {  }

            W(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // outer diagonal lines
                taswira::Geometry::DrawLineOnImage(image, startRow, startCol + 4,
                    startRow + this->ShapeHeight() - 1, startCol, this->ShapeColor());

                taswira::Geometry::DrawLineOnImage(image, startRow, startCol + 11,
                    startRow + this->ShapeHeight() - 1, startCol + this->ShapeWidth() - 1, this->ShapeColor());

                // inner diagonal lines
                taswira::Geometry::DrawLineOnImage(image, startRow, startCol + 4,
                    startRow + this->ShapeHeight() - 1, startCol + 7, this->ShapeColor());

                taswira::Geometry::DrawLineOnImage(image, startRow, startCol + 11,
                    startRow + this->ShapeHeight() - 1, startCol + 8, this->ShapeColor());
            }
        };

        class X : public taswira::Parallelogram {
        public:
            X(void)
                :Parallelogram()
            {  }

            X(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // first diagonal line
                int col = startCol;
                for (int row = startRow + this->ShapeHeight() - 1; row >= startRow; --row) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    ++col;
                }

                // second diagonal line
                col = startCol;
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    ++col;
                }
            }
        };

        class Y : public taswira::Parallelogram {
        public:
            Y(void)
                :Parallelogram()
            {  }

            Y(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // diagonal lines
                int col1 = startCol + 8;
                int col2 = startCol + 8;
                for (int row = startRow + 8; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, col1) = this->ShapeColor();
                    --col1;

                    image.PixelAt(row, col2) = this->ShapeColor();
                    ++col2;
                }

                // vertical bar
                for (int row = startRow; row < startRow + 8; ++row) {
                    image.PixelAt(row, startCol + 8) = this->ShapeColor();
                }
            }
        };

        class Z : public taswira::Parallelogram {
        public:
            Z(void)
                :Parallelogram()
            {  }

            Z(const taswira::Pixel& color)
                :Parallelogram(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bar
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // diagonal line
                int col = startCol;
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    ++col;
                }
            }
        };
    }
}

#endif // !ALPHAUPPERCASE_H
