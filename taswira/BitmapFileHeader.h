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

        BitmapFileHeader(const BitmapFileHeader& fileheader)
            :Sign1(fileheader.Sign1),
            Sign2(fileheader.Sign2),
            FileSize1(fileheader.FileSize1),
            FileSize2(fileheader.FileSize2),
            FileSize3(fileheader.FileSize3),
            FileSize4(fileheader.FileSize3),
            Reserve1(0),
            Reserve2(0),
            Reserve3(0),
            Reserve4(0),
            PixelOffset1(fileheader.PixelOffset1),
            PixelOffset2(0),
            PixelOffset3(0),
            PixelOffset4(0)
        {  }

        BitmapFileHeader& operator = (const BitmapFileHeader& fileheader) {
            this->Sign1 = fileheader.Sign1;
            this->Sign2 = fileheader.Sign2;
            this->FileSize1 = fileheader.FileSize1;
            this->FileSize2 = fileheader.FileSize2;
            this->FileSize3 = fileheader.FileSize3;
            this->FileSize4 = fileheader.FileSize3;
            this->PixelOffset1 = fileheader.PixelOffset1;

            return (*this);
        }
    };
}

#endif // !BITMAPFILEHEADER_H