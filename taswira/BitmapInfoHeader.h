#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

// Bitmap Format was learned from the following link
// http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm

// The FileHeader and InfoHeader structs were influenced from user Minhas Kamal at
// https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
namespace taswira {
    struct BitmapInfoHeader {
        char Size1;
        char Size2;
        char Size3;
        char Size4;
        char Width1;
        char Width2;
        char Width3;
        char Width4;
        char Height1;
        char Height2;
        char Height3;
        char Height4;
        char Planes1;
        char Planes2;
        char BitsPerPixel1;
        char BitsPerPixel2;
        char EverythingElse[24];

        BitmapInfoHeader(int width, int height, int infoHeaderSize, int bytesPerPixel, int pallets)
            :Size1(infoHeaderSize),
            Size2(0),
            Size3(0),
            Size4(0),
            Width1(width),
            Width2(width >> 8),
            Width3(width >> 16),
            Width4(width >> 24),
            Height1(height),
            Height2(height >> 8),
            Height3(height >> 16),
            Height4(height >> 24),
            Planes1(1),
            Planes2(0),
            BitsPerPixel1(bytesPerPixel* pallets),
            BitsPerPixel2(0)
        {
            for (int i = 0; i < 24; ++i) {
                EverythingElse[i] = (char)0;
            }
        }

        BitmapInfoHeader(const BitmapInfoHeader& infoheader)
            :Size1(infoheader.Size1),
            Size2(0),
            Size3(0),
            Size4(0),
            Width1(infoheader.Width1),
            Width2(infoheader.Width2),
            Width3(infoheader.Width3),
            Width4(infoheader.Width4),
            Height1(infoheader.Height1),
            Height2(infoheader.Height2),
            Height3(infoheader.Height3),
            Height4(infoheader.Height4),
            Planes1(1),
            Planes2(0),
            BitsPerPixel1(infoheader.BitsPerPixel1),
            BitsPerPixel2(0)
        {
            for (int i = 0; i < 24; ++i) {
                EverythingElse[i] = (char)0;
            }
        }

        BitmapInfoHeader& operator = (const BitmapInfoHeader& infoheader) {
            this->Size1 = infoheader.Size1;
            this->Width1 = infoheader.Width1;
            this->Width2 = infoheader.Width2;
            this->Width3 = infoheader.Width3;
            this->Width4 = infoheader.Width4;
            this->Height1 = infoheader.Height1;
            this->Height2 = infoheader.Height2;
            this->Height3 = infoheader.Height3;
            this->Height4 = infoheader.Height4;
            this->BitsPerPixel1 = infoheader.BitsPerPixel1;
            for (int i = 0; i < 24; ++i) {
                EverythingElse[i] = (char)0;
            }

            return (*this);
        }
    };
}

#endif // !BITMAPINFOHEADER_H