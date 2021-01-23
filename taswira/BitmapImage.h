#ifndef BITMAPIMAGE_H
#define BITMAPIMAGE_H

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Pixel.h"
#include <fstream>
#include <stdexcept>
#include <string>
#include <iostream>

namespace taswira {
    class BitmapImage {
    public:
        BitmapImage(int fileHeaderSize, int infoHeaderSize,
            int width, int height, int bytesPerPixel, int pallets)
            :FileHeaderSize(fileHeaderSize),
            InfoHeaderSize(infoHeaderSize),
            FileSize(fileHeaderSize + infoHeaderSize + (width * height * bytesPerPixel)),
            Width(width),
            Height(height),
            BytesPerPixel(bytesPerPixel),
            Pallets(pallets),
            LeftMargin(25),
            RightMargin(width - LeftMargin),
            BottomMargin(25),
            TopMargin(height - 75),
            FileHeader(FileSize, fileHeaderSize, infoHeaderSize),
            InfoHeader(width, height, infoHeaderSize, bytesPerPixel, pallets),
            PixelData(new Pixel* [height])
        {
            for (int i = 0; i < height; ++i) {
                PixelData[i] = new Pixel[width];
            }
        }

        ~BitmapImage(void) {
            if (!PixelData || PixelData != NULL || PixelData != nullptr) {
                for (int i = 0; i < Height; ++i) {
                    delete[] PixelData[i];
                    PixelData[i] = nullptr;
                }

                delete[] PixelData;
                PixelData = nullptr;
            }
        }

        //---- Setters
        Pixel& PixelAt(int i, int j) {
            if (!PixelData) {
                throw std::logic_error("taswira::BitmapImage::PixelAt -- PixelData is not defined!");
            }

            return PixelData[i][j];
        }

        void WriteToDisk(std::string filename) {
            std::ofstream fout;
            fout.open(filename.c_str(), std::ios::binary);

            fout.write((char*)&FileHeader, FileHeaderSize);
            fout.write((char*)&InfoHeader, InfoHeaderSize);

            // writing pixel data
            for (int i = 0; i < Height; ++i) {
                for (int j = 0; j < Width; ++j) {
                    fout.write((char*)&PixelData[i][j], BytesPerPixel);
                }
            }
            fout.close();
        }

        //---- Getters
        int ImageFileHeaderSize(void) {
            return this->FileHeaderSize;
        }

        int ImageInfoHeaderSize(void) {
            return this->InfoHeaderSize;
        }

        int ImageFileSize(void) {
            return this->FileSize;
        }

        int ImageWidth(void) {
            return this->Width;
        }

        int ImageHeight(void) {
            return this->Height;
        }

        int ImageBytesPerPixel(void) {
            return this->BytesPerPixel;
        }

        int ImagePallets(void) {
            return this->Pallets;
        }

        int ImageLeftMargin(void) {
            return this->LeftMargin;
        }

        int ImageRightMargin(void) {
            return this->RightMargin;
        }

        int ImageBottomMargin(void) {
            return this->BottomMargin;
        }

        int ImageTopMargin(void) {
            return this->TopMargin;
        }

        taswira::BitmapFileHeader& ImageFileHeader(void) {
            return this->FileHeader;
        }

        taswira::BitmapInfoHeader& ImageInfoHeader(void) {
            return this->InfoHeader;
        }

        taswira::Pixel** ImagePixelData(void) {
            return this->PixelData;
        }

        void DrawFilledInSquare(int startRow, int startCol, int rowDims, int colDims, taswira::Pixel& color) {
            int RowLen = startRow + rowDims;
            int ColLen = startCol + colDims;

            for (int row = startRow; row < RowLen; ++row) {
                for (int j = startCol; j < ColLen; ++j) {
                    this->PixelAt(row, j).Blue = color.Blue;
                    this->PixelAt(row, j).Green = color.Green;
                    this->PixelAt(row, j).Red = color.Red;
                }
            }
        }

        void DrawEmptySquare(int startRow, int startCol, int rowDims, int colDims, taswira::Pixel& color) {
            int RowLen = startRow + rowDims;
            int ColLen = startCol + colDims;


            // draw top line
            for (int col = startCol; col < ColLen; ++col) {
                this->PixelAt(startRow, col).Blue = color.Blue;
                this->PixelAt(startRow, col).Green = color.Green;
                this->PixelAt(startRow, col).Red = color.Red;
            }

            // draw bottom line
            for (int col = startCol; col < ColLen; ++col) {
                this->PixelAt(RowLen - 1, col).Blue = color.Blue;
                this->PixelAt(RowLen - 1, col).Green = color.Green;
                this->PixelAt(RowLen - 1, col).Red = color.Red;
            }

            // draw left line
            for (int row = startRow; row < RowLen; ++row) {
                this->PixelAt(row, startCol).Blue = color.Blue;
                this->PixelAt(row, startCol).Green = color.Green;
                this->PixelAt(row, startCol).Red = color.Red;
            }

            // draw right line
            for (int row = startRow; row < RowLen; ++row) {
                this->PixelAt(row, ColLen - 1).Blue = color.Blue;
                this->PixelAt(row, ColLen - 1).Green = color.Green;
                this->PixelAt(row, ColLen - 1).Red = color.Red;
            }
        }

        // Uses the Midpoint Circle Algorithm https://en.wikipedia.org/wiki/Midpoint_circle_algorithm
        void DrawCircle(int CenterX, int CenterY, int Radius, taswira::Pixel &color) {
            int X = Radius, Y = 0;

            if (Radius > 0) {
                this->PixelAt(X + CenterX, -Y + CenterY) = color;
                this->PixelAt(Y + CenterX, X + CenterY) = color;
                this->PixelAt(-Y + CenterX, X + CenterY) = color;
            }

            // Initialising the value of P 
            int P = 1 - Radius;
            while (X > Y) {
                Y++;

                // Mid-point is inside or on the perimeter 
                if (P <= 0)
                    P = P + 2 * Y + 1;
                // Mid-point is outside the perimeter 
                else {
                    X--;
                    P = P + 2 * Y - 2 * X + 1;
                }

                // All the perimeter points have already been printed 
                if (X < Y)
                    break;

                // Printing the generated point and its reflection 
                // in the other octants after translation 
                this->PixelAt(X + CenterX, Y + CenterY) = color;
                this->PixelAt(-X + CenterX, Y + CenterY) = color;
                this->PixelAt(X + CenterX, -Y + CenterY) = color;
                this->PixelAt(-X + CenterX, -Y + CenterY) = color;

                // If the generated point is on the line x = y then  
                // the perimeter points have already been printed 
                if (X != Y) {
                    this->PixelAt(Y + CenterX, X + CenterY) = color;
                    this->PixelAt(-Y + CenterX, X + CenterY) = color;
                    this->PixelAt(Y + CenterX, -X + CenterY) = color;
                    this->PixelAt(-Y + CenterX, -X + CenterY) = color;
                }
            }
        }

    private:
        int FileHeaderSize;
        int InfoHeaderSize;
        int FileSize;
        int Width;
        int Height;
        int BytesPerPixel;
        int Pallets;
        int LeftMargin;
        int RightMargin;
        int BottomMargin;
        int TopMargin;
        taswira::BitmapFileHeader FileHeader;
        taswira::BitmapInfoHeader InfoHeader;
        taswira::Pixel** PixelData;

        BitmapImage(void)
            :FileSize(0),
            FileHeaderSize(0),
            InfoHeaderSize(0),
            Width(0),
            Height(0),
            BytesPerPixel(0),
            Pallets(0),
            LeftMargin(0),
            RightMargin(0),
            BottomMargin(0),
            TopMargin(0),
            FileHeader(FileSize, 0, 0),
            InfoHeader(0, 0, 0, 0, 0),
            PixelData(nullptr)
        {  }
    };
}

#endif // !BITMAPIMAGE_H