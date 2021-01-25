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
            int height, int width, int bytesPerPixel, int pallets)
            :FileHeaderSize(fileHeaderSize),
            InfoHeaderSize(infoHeaderSize),
            FileSize(fileHeaderSize + infoHeaderSize + (width * height * bytesPerPixel)),
            PixelPadding(25),
            Height(height),
            Width(width),
            BytesPerPixel(bytesPerPixel),
            Pallets(pallets),
            LeftMargin(PixelPadding),
            RightMargin(width - PixelPadding),
            BottomMargin(PixelPadding),
            TopMargin(height - PixelPadding),
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
        int& ImageFileHeaderSize(void) {
            return this->FileHeaderSize;
        }

        int& ImageInfoHeaderSize(void) {
            return this->InfoHeaderSize;
        }

        int& ImageFileSize(void) {
            return this->FileSize;
        }

        int& ImagePixelPadding(void) {
            return this->PixelPadding;
        }

        int& ImageWidth(void) {
            return this->Width;
        }

        int& ImageHeight(void) {
            return this->Height;
        }

        int& ImageBytesPerPixel(void) {
            return this->BytesPerPixel;
        }

        int& ImagePallets(void) {
            return this->Pallets;
        }

        int& ImageLeftMargin(void) {
            return this->LeftMargin;
        }

        int& ImageRightMargin(void) {
            return this->RightMargin;
        }

        int& ImageBottomMargin(void) {
            return this->BottomMargin;
        }

        int& ImageTopMargin(void) {
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

    private:
        int FileHeaderSize;
        int InfoHeaderSize;
        int FileSize;
        int PixelPadding;
        int Height;
        int Width;
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
            :FileHeaderSize(0),
            InfoHeaderSize(0),
            FileSize(0),
            PixelPadding(25),
            Height(0),
            Width(0),
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