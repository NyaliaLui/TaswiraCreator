#ifndef ALPHAUPPERCASE_H
#define ALPHAUPPERCASE_H

#include "Shapes.h"
#include "BitmapImage.h"
#include "AlphaDims.h"

namespace taswira {

    namespace Uppercase {
        class A : public taswira::Square {
        public:
            A(void)
                :Square()
            {  }

            A(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // top horizontal bar
                for (int col = startCol + 4; col < startCol + 12; ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                }

                image.PixelAt(startRow + 14, startCol + 4) = this->ShapeColor(); image.PixelAt(startRow + 14, startCol + 11) = this->ShapeColor();
                image.PixelAt(startRow + 13, startCol + 4) = this->ShapeColor(); image.PixelAt(startRow + 13, startCol + 11) = this->ShapeColor();
                image.PixelAt(startRow + 12, startCol + 4) = this->ShapeColor(); image.PixelAt(startRow + 12, startCol + 11) = this->ShapeColor();
                image.PixelAt(startRow + 11, startCol + 3) = this->ShapeColor(); image.PixelAt(startRow + 11, startCol + 12) = this->ShapeColor();
                image.PixelAt(startRow + 10, startCol + 3) = this->ShapeColor(); image.PixelAt(startRow + 10, startCol + 12) = this->ShapeColor();
                image.PixelAt(startRow + 9, startCol + 3) = this->ShapeColor(); image.PixelAt(startRow + 9, startCol + 12) = this->ShapeColor();
                image.PixelAt(startRow + 8, startCol + 3) = this->ShapeColor(); image.PixelAt(startRow + 8, startCol + 12) = this->ShapeColor();

                // middle horizontal bar
                for (int col = startCol + 2; col < startCol + 14; ++col) {
                    image.PixelAt(startRow + 7, col) = this->ShapeColor();
                }

                image.PixelAt(startRow + 6, startCol + 2) = this->ShapeColor(); image.PixelAt(startRow + 6, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 5, startCol + 2) = this->ShapeColor(); image.PixelAt(startRow + 5, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 4, startCol + 2) = this->ShapeColor(); image.PixelAt(startRow + 4, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 3, startCol + 1) = this->ShapeColor(); image.PixelAt(startRow + 3, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 3, startCol) = this->ShapeColor(); image.PixelAt(startRow + 3, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 2, startCol) = this->ShapeColor(); image.PixelAt(startRow + 2, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow + 1, startCol) = this->ShapeColor(); image.PixelAt(startRow + 1, startCol + 15) = this->ShapeColor();
                image.PixelAt(startRow, startCol) = this->ShapeColor(); image.PixelAt(startRow, startCol + 15) = this->ShapeColor();
            }
        };

        class B : public taswira::Square {
        public:
            B(void)
                :Square()
            {  }

            B(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class C : public taswira::Square {
        public:
            C(void)
                :Square()
            {  }

            C(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class D : public taswira::Square {
        public:
            D(void)
                :Square()
            {  }

            D(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class E : public taswira::Square {
        public:
            E(void)
                :Square()
            {  }

            E(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class F : public taswira::Square {
        public:
            F(void)
                :Square()
            {  }

            F(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class G : public taswira::Square {
        public:
            G(void)
                :Square()
            {  }

            G(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol; col < startCol + this->ShapeWidth(); ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();

                    if (col >= (startCol + 11) && col <= (startRow + this->ShapeWidth())) {
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

        class H : public taswira::Square {
        public:
            H(void)
                :Square()
            {  }

            H(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class I : public taswira::Square {
        public:
            I(void)
                :Square()
            {  }

            I(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // horizontal bars
                for (int col = startCol + 4; col < startCol + 11; ++col) {
                    image.PixelAt(startRow + 15, col) = this->ShapeColor();
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }

                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol + 7) = this->ShapeColor();
                }
            }
        };

        class J : public taswira::Square {
        public:
            J(void)
                :Square()
            {  }

            J(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // vertical bar
                for (int row = startRow + 4; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol + 15) = this->ShapeColor();
                }

                // add the "curve" dots
                image.PixelAt(startRow + 4, startCol + 14) = this->ShapeColor();
                image.PixelAt(startRow + 3, startCol + 13) = this->ShapeColor();
                image.PixelAt(startRow + 2, startCol + 12) = this->ShapeColor();
                image.PixelAt(startRow + 1, startCol + 11) = this->ShapeColor();
                image.PixelAt(startRow + 2, startCol + 5) = this->ShapeColor();
                image.PixelAt(startRow + 1, startCol + 6) = this->ShapeColor();

                // horizontal bars
                for (int col = startCol + 7; col < startCol + 11; ++col) {
                    image.PixelAt(startRow, col) = this->ShapeColor();
                }
            }
        };

        class K : public taswira::Square {
        public:
            K(void)
                :Square()
            {  }

            K(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // vertical bar
                for (int row = startRow; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, startCol) = this->ShapeColor();
                }

                // top diagonal line
                int col = startCol + 1;
                for (int row = startRow + 8; row < startRow + this->ShapeHeight(); ++row) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    ++col;
                }

                // bottom diagonal line
                col = startCol + 1;
                for (int row = startRow + 7; row >= startRow; --row) {
                    image.PixelAt(row, col) = this->ShapeColor();
                    ++col;
                }
            }
        };

        class L : public taswira::Square {
        public:
            L(void)
                :Square()
            {  }

            L(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class M : public taswira::Square {
        public:
            M(void)
                :Square()
            {  }

            M(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class N : public taswira::Square {
        public:
            N(void)
                :Square()
            {  }

            N(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class O : public taswira::Square {
        public:
            O(void)
                :Square()
            {  }

            O(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color),
                OCircle(6, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                this->OCircle.DrawOnImage(image, startRow + (this->ShapeHeight() / 2), startCol + (this->ShapeWidth() / 2));
            }
        private:
            taswira::Circle OCircle;
        };

        class P : public taswira::Square {
        public:
            P(void)
                :Square()
            {  }

            P(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class Q : public taswira::Square {
        public:
            Q(void)
                :Square()
            {  }

            Q(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color),
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

        class R : public taswira::Square {
        public:
            R(void)
                :Square()
            {  }

            R(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class S : public taswira::Square {
        public:
            S(void)
                :Square()
            {  }

            S(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class T : public taswira::Square {
        public:
            T(void)
                :Square()
            {  }

            T(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class U : public taswira::Square {
        public:
            U(void)
                :Square()
            {  }

            U(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class V : public taswira::Square {
        public:
            V(void)
                :Square()
            {  }

            V(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // diagonal lines
                int col1 = startCol + 8;
                int col2 = startCol + 8;
                for (int row = startRow; row < startRow + this->ShapeHeight(); row += 2) {
                    image.PixelAt(row, col1) = this->ShapeColor();
                    image.PixelAt(row + 1, col1) = this->ShapeColor();
                    --col1;

                    image.PixelAt(row, col2) = this->ShapeColor();
                    image.PixelAt(row + 1, col2) = this->ShapeColor();
                    ++col2;
                }
            }
        };

        class W : public taswira::Square {
        public:
            W(void)
                :Square()
            {  }

            W(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // two mid points
                image.PixelAt(startRow, startCol + 5) = this->ShapeColor();
                image.PixelAt(startCol, startCol + 10) = this->ShapeColor();

                // outer diagonal lines
                int col1 = startCol + 4;
                int col2 = startCol + 11;
                for (int row = startRow; row < startRow + this->ShapeHeight(); row += 3) {
                    image.PixelAt(row, col1) = this->ShapeColor();
                    image.PixelAt(row + 1, col1) = this->ShapeColor();
                    image.PixelAt(row + 2, col1) = this->ShapeColor();
                    --col1;

                    image.PixelAt(row, col2) = this->ShapeColor();
                    image.PixelAt(row + 1, col2) = this->ShapeColor();
                    image.PixelAt(row + 2, col2) = this->ShapeColor();
                    ++col2;
                }

                // inner diagonal lines
                col1 = startCol + 6;
                col2 = startCol + 9;
                for (int row = startRow; row < startRow + 5; row += 2) {
                    image.PixelAt(row, col1) = this->ShapeColor();
                    image.PixelAt(row + 1, col1) = this->ShapeColor();
                    ++col1;

                    image.PixelAt(row, col2) = this->ShapeColor();
                    image.PixelAt(row + 1, col2) = this->ShapeColor();
                    --col2;
                }
            }
        };

        class X : public taswira::Square {
        public:
            X(void)
                :Square()
            {  }

            X(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class Y : public taswira::Square {
        public:
            Y(void)
                :Square()
            {  }

            Y(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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

        class Z : public taswira::Square {
        public:
            Z(void)
                :Square()
            {  }

            Z(const taswira::Pixel& color)
                :Square(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, color)
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
