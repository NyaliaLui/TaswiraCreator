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
            Width2(width >>  8),
            Width3(width >>  16),
            Width4(width >>  24),
            Height1(height),
            Height2(height >>  8),
            Height3(height >>  16),
            Height4(height >>  24),
            Planes1(1),
            Planes2(0),
            BitsPerPixel1(bytesPerPixel * pallets),
            BitsPerPixel2(0)
        {
            for (int i=0; i<24; ++i) {
                EverythingElse[i] = (char) 0;
            }
        }
    };
}

#endif // !BITMAPINFOHEADER_H