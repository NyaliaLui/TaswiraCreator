#include "BitmapImage.h"
#include <iostream>
#include <cassert>
#include <filesystem>
#define VALUE1 123
#define WIDTH 480
#define HEIGHT 720

void TestPixel(void) {
    taswira::Pixel pixel;

    assert(pixel.Blue == 0);
    assert(pixel.Green == 0);
    assert(pixel.Red == 0);

    pixel.Blue = VALUE1;
    pixel.Green = VALUE1;
    pixel.Red = VALUE1;

    assert(pixel.Blue == VALUE1);
    assert(pixel.Green == VALUE1);
    assert(pixel.Red == VALUE1);
}

void TestBitmapFileHeader(void) {
    int FileSize = 14 + 40 + (WIDTH * HEIGHT * 3);
    taswira::BitmapFileHeader FileHeader(FileSize, 14, 40);

    assert(FileHeader.Sign1 == 'B');
    assert(FileHeader.Sign2 == 'M');
    assert(FileHeader.FileSize1 == (char)(FileSize));
    assert(FileHeader.FileSize2 == (char)(FileSize >> 8));
    assert(FileHeader.FileSize3 == (char)(FileSize >> 16));
    assert(FileHeader.FileSize4 == (char)(FileSize >> 24));
    assert(FileHeader.Reserve1 == (char)0);
    assert(FileHeader.Reserve2 == (char)0);
    assert(FileHeader.Reserve3 == (char)0);
    assert(FileHeader.Reserve4 == (char)0);
    assert(FileHeader.PixelOffset1 == (char)(14 + 40));
    assert(FileHeader.PixelOffset2 == (char)0);
    assert(FileHeader.PixelOffset3 == (char)0);
    assert(FileHeader.PixelOffset4 == (char)0);
}

void TestBitmapInfoHeader(void) {
    taswira::BitmapInfoHeader InfoHeader(WIDTH, HEIGHT, 40, 3, 8);

    assert(InfoHeader.Size1 == (char)40);
    assert(InfoHeader.Size2 == (char)0);
    assert(InfoHeader.Size3 == (char)0);
    assert(InfoHeader.Size4 == (char)0);
    assert(InfoHeader.Width1 == (char)WIDTH);
    assert(InfoHeader.Width2 == (char)(WIDTH >> 8));
    assert(InfoHeader.Width3 == (char)(WIDTH >> 16));
    assert(InfoHeader.Width4 == (char)(WIDTH >> 24));
    assert(InfoHeader.Height1 == (char)HEIGHT);
    assert(InfoHeader.Height2 == (char)(HEIGHT >> 8));
    assert(InfoHeader.Height3 == (char)(HEIGHT >> 16));
    assert(InfoHeader.Height4 == (char)(HEIGHT >> 24));
    assert(InfoHeader.Planes1 == (char)1);
    assert(InfoHeader.Planes2 == (char)0);
    assert(InfoHeader.BitsPerPixel1 == (char)(3 * 8));
    assert(InfoHeader.BitsPerPixel2 == (char)0);

    for (int i = 0; i < 24; ++i) {
        assert(InfoHeader.EverythingElse[i] == (char)0);
    }
}

void TestBitmapImage(void) {
    taswira::Pixel** PixelData = nullptr;

    {
        taswira::BitmapImage image(14, 40, WIDTH, HEIGHT, 3, 8);

        assert(image.ImageFileHeaderSize() == 14);
        assert(image.ImageInfoHeaderSize() == 40);
        assert(image.ImageFileSize() == (14 + 40 + (WIDTH * HEIGHT * 3)));
        assert(image.ImageWidth() == WIDTH);
        assert(image.ImageHeight() == HEIGHT);
        assert(image.ImageBytesPerPixel() == 3);
        assert(image.ImagePallets() == 8);
        assert(&image.ImageFileHeader() == &image.ImageFileHeader());
        assert(&image.ImageInfoHeader() == &image.ImageInfoHeader());
        assert(image.ImagePixelData() == image.ImagePixelData());

        PixelData = image.ImagePixelData();
        assert(PixelData || PixelData != NULL || PixelData != nullptr || PixelData != 0);

        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                image.PixelAt(i, j).Blue = VALUE1;
                image.PixelAt(i, j).Green = VALUE1;
                image.PixelAt(i, j).Red = VALUE1;
            }
        }

        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                assert(image.PixelAt(i, j).Blue == VALUE1);
                assert(image.PixelAt(i, j).Green == VALUE1);
                assert(image.PixelAt(i, j).Red == VALUE1);
            }
        }

        image.WriteToDisk("myimage.bmp");
        assert(std::filesystem::exists("myimage.bmp"));
        assert(std::filesystem::remove("myimage.bmp"));
    }

    // assert(!PixelData || PixelData == NULL || PixelData == nullptr || PixelData == 0);

}

int main(void) {

    std::cout << "Test Pixel" << std::endl;
    TestPixel();

    std::cout << "Test BitmapFileHeader" << std::endl;
    TestBitmapFileHeader();

    std::cout << "Test BitmapInfoHeader" << std::endl;
    TestBitmapInfoHeader();

    std::cout << "Test BitmapImage" << std::endl;
    TestBitmapImage();
    return 0;
}
