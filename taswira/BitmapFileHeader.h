#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

// Bitmap Format was learned from the following link
// http://www.ece.ualberta.ca/~elliott/ee552/studentAppNotes/2003_w/misc/bmp_file_format/bmp_file_format.htm

// The FileHeader and InfoHeader structs were influenced from user Minhas Kamal at
// https://stackoverflow.com/questions/2654480/writing-bmp-image-in-pure-c-c-without-other-libraries
namespace taswira {
    struct BitmapFileHeader {
        char Sign1;
        char Sign2;
        char FileSize1;
        char FileSize2;
        char FileSize3;
        char FileSize4;
        char Reserve1;
        char Reserve2;
        char Reserve3;
        char Reserve4;
        char PixelOffset1;
        char PixelOffset2;
        char PixelOffset3;
        char PixelOffset4;

        BitmapFileHeader(int fileSize, int fileHeaderSize, int infoHeaderSize)
            :Sign1('B'),
            Sign2('M'),
            FileSize1(fileSize),
            FileSize2(fileSize >> 8),
            FileSize3(fileSize >> 16),
            FileSize4(fileSize >> 24),
            Reserve1(0),
            Reserve2(0),
            Reserve3(0),
            Reserve4(0),
            PixelOffset1(fileHeaderSize + infoHeaderSize),
            PixelOffset2(0),
            PixelOffset3(0),
            PixelOffset4(0)
        {  }
    };
}

#endif // !BITMAPFILEHEADER_H