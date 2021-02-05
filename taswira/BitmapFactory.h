#ifndef BitmapFactory_H
#define BitmapFactory_H

#include "UMLObjects.h"
#include "BitmapImage.h"

#include <array>
#include <limits>
#include <memory>
#include <vector>
#include <stdexcept>
#include <string>

namespace taswira {
	class BitmapFactory {
	public:
		BitmapFactory(void)
			:FileHeaderSize(14),
			InfoHeaderSize(40),
			BytesPerPixel(3),
			Pallets(8)
		{  }

		BitmapFactory(const BitmapFactory& factory)
			:FileHeaderSize(factory.FileHeaderSize),
			InfoHeaderSize(factory.InfoHeaderSize),
			BytesPerPixel(factory.BytesPerPixel),
			Pallets(factory.Pallets)
		{  }

		~BitmapFactory(void)
		{  }

		BitmapFactory& operator = (const BitmapFactory& factory) {
			this->FileHeaderSize = factory.FileHeaderSize;
			this->InfoHeaderSize = factory.InfoHeaderSize;
			this->BytesPerPixel = factory.BytesPerPixel;
			this->Pallets = factory.Pallets;

			return (*this);
		}

		taswira::BitmapImage CreateImage(int height, int width) {
			taswira::BitmapImage image(this->FileHeaderSize, this->InfoHeaderSize, height, width, this->BytesPerPixel, this->Pallets);

			return image;
		}

		taswira::BitmapImage CreateImageFromUMLObject(taswira::UML::UMLObject& obj) {
			taswira::BitmapImage image(this->FileHeaderSize, this->InfoHeaderSize, obj.ShapeHeight(), obj.ShapeWidth(), this->BytesPerPixel, this->Pallets);

			return image;
		}

	private:
		int FileHeaderSize;
		int InfoHeaderSize;
		int BytesPerPixel;
		int Pallets;
	};
}

#endif // !BitmapFactory_H