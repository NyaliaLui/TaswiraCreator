#ifndef BITMAPIMAGE_H
#define BITMAPIMAGE_H

#include "BitmapFileHeader.h"
#include "BitmapInfoHeader.h"
#include "Pixel.h"
#include <fstream>
#include <stdexcept>
#include <string>

namespace taswira {
    class BitmapImage {
    public:
        BitmapImage(int fileHeaderSize, int infoHeaderSize,
                    int width, int height, int bytesPerPixel, int pallets)
            :FileSize(fileHeaderSize + infoHeaderSize + (width * height * bytesPerPixel)),
            FileHeaderSize(fileHeaderSize),
            InfoHeaderSize(infoHeaderSize),
            Width(width),
            Height(height),
            BytesPerPixel(bytesPerPixel),
            Pallets(pallets),
            FileHeader(FileSize, fileHeaderSize, infoHeaderSize),
            InfoHeader(width, height, infoHeaderSize, bytesPerPixel, pallets),
            PixelData(new Pixel*[height])
        {
            for (int i=0; i<height; ++i) {
                PixelData[i] = new Pixel[width];
            }
        }

        ~BitmapImage(void) {
            if (!PixelData) {
                for (int i=0; i<Height; ++i) {
                    delete [] PixelData[i];
                }

                delete [] PixelData;
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

            fout.write((char *) &FileHeader, FileHeaderSize);
            fout.write((char *) &InfoHeader, InfoHeaderSize);

            // writing pixel data
            for (size_t i=0; i<Height; ++i) {
                for (size_t j=0; j<Width; ++j) {
                    fout.write((char *) &PixelData[i][j], BytesPerPixel);
                }
            }
            fout.close();
        }

        //---- Getters
        int& ImageWidth(void) {
            return Width;
        }

        int& ImageHeight(void) {
            return Height;
        }

    private:
        int FileSize;
        int FileHeaderSize;
        int InfoHeaderSize;
        int Width;
        int Height;
        int BytesPerPixel;
        int Pallets;
        taswira::BitmapFileHeader FileHeader;
        taswira::BitmapInfoHeader InfoHeader;
        taswira::Pixel **PixelData;

        BitmapImage(void)
            :FileSize(0),
        FileHeaderSize(0),
        InfoHeaderSize(0),
        Width(0),
        Height(0),
        BytesPerPixel(0),
        Pallets(0),
        FileHeader(FileSize, 0, 0),
        InfoHeader(0, 0, 0, 0, 0),
        PixelData(nullptr)
    {  }
    };
}

#endif // !BITMAPIMAGE_H