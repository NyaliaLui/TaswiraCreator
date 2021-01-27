#ifndef UMLOBJECTS_H
#define UMLOBJECTS_H

#include "BaseShape.h"
#include "Geometry.h"
#include "BitmapImage.h"
#include "Shapes.h"
#include "Connector.h"

#include <array>
#include <limits>

namespace taswira {
    namespace UML {
        struct UMLObject {
            std::array<taswira::Connector, 4> Connectors;

            UMLObject(void)
            {  }

            ~UMLObject(void)
            {  }

            taswira::Connector& ConnectorLeft(void) {
                return this->Connectors[0];
            }

            taswira::Connector& ConnectorTop(void) {
                return this->Connectors[1];
            }

            taswira::Connector& ConnectorRight(void) {
                return this->Connectors[2];
            }

            taswira::Connector& ConnectorBottom(void) {
                return this->Connectors[3];
            }
        };

		class Inheritance : public UMLObject, taswira::IBaseShape {
		public:
			Inheritance(void)
			{  }

            Inheritance(const taswira::Pixel& color)
                :taswira::IBaseShape(color),
                Triangle(20, color)
            {  }

            ~Inheritance(void)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                int LineLen = this->Triangle.ShapeLineLength();
                taswira::Connector Top(startRow + LineLen, startCol + (LineLen / 2));
                taswira::Connector Bottom(startRow, startCol + (LineLen / 2));

                this->ConnectorLeft() = Bottom;
                this->ConnectorTop() = Top;
                this->ConnectorRight() = Top;
                this->ConnectorBottom() = Bottom;

                this->Triangle.DrawOnImage(image, startRow, startCol);
            }

		private:
            taswira::Triangle Triangle;

		};

        class Aggregation : public UMLObject, taswira::IBaseShape {
        public:
            Aggregation(void)
            {  }

            Aggregation(const taswira::Pixel& color)
                :taswira::IBaseShape(color),
                Diamond(25, color)
            {  }

            ~Aggregation(void)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                int LineLen = this->Diamond.ShapeHeight();
                taswira::Connector Left(startRow + (LineLen / 2), startCol);
                taswira::Connector Top(startRow + LineLen - 1, startCol + (LineLen / 2));
                taswira::Connector Right(startRow + (LineLen / 2), startCol + LineLen - 1);
                taswira::Connector Bottom(startRow, startCol + (LineLen / 2));

                this->ConnectorLeft() = Left;
                this->ConnectorTop() = Top;
                this->ConnectorRight() = Right;
                this->ConnectorBottom() = Bottom;

                this->Diamond.DrawOnImage(image, startRow, startCol);
            }

        private:
            taswira::Diamond Diamond;

        };
	} // ! namespace UML

    namespace Geometry {
        static void DrawLineOnImage(taswira::BitmapImage& image, taswira::UML::UMLObject& obj1, taswira::UML::UMLObject& obj2, taswira::Pixel& color) {
            // find the connectors that are closest to each other
            int ClosestDistance = std::numeric_limits<int>::max(), Distance = 0;
            taswira::Connector ClosestConn1, ClosestConn2;
            for (taswira::Connector& Conn1 : obj1.Connectors) {
                for (taswira::Connector& Conn2 : obj2.Connectors) {
                    Distance = taswira::Geometry::CalculateDistance(Conn1, Conn2);

                    if (Distance < ClosestDistance) {
                        ClosestDistance = Distance;
                        ClosestConn1 = Conn1;
                        ClosestConn2 = Conn2;
                    }
                }
            }

            // draw line between the closest connectors
            taswira::Geometry::DrawLineOnImage(image, ClosestConn1, ClosestConn2, color);
        }
    } // ! namespace Geometry
}

#endif // !UMLOBJECTS_H