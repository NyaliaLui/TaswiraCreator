#ifndef UMLOBJECTS_H
#define UMLOBJECTS_H

#include "BaseShape.h"
#include "Geometry.h"
#include "BitmapImage.h"
#include "Shapes.h"
#include "Connector.h"
#include "TextBox.h"

#include <array>
#include <limits>
#include <memory>
#include <vector>
#include <stdexcept>

namespace taswira {
    namespace UML {
        class UMLObject : public taswira::IBaseShape {
        public:
            UMLObject(void)
            {  }

            UMLObject(const taswira::Pixel& color)
                :taswira::IBaseShape(color)
            {  }

            UMLObject(const UMLObject& obj)
                :taswira::IBaseShape(obj),
                Connectors(obj.Connectors)
            {  }

            virtual ~UMLObject(void)
            {  }

            virtual taswira::Connector& ConnectorLeft(void) {
                return this->Connectors[0];
            }

            virtual taswira::Connector& ConnectorTop(void) {
                return this->Connectors[1];
            }

            virtual taswira::Connector& ConnectorRight(void) {
                return this->Connectors[2];
            }

            virtual taswira::Connector& ConnectorBottom(void) {
                return this->Connectors[3];
            }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                // does nothing
            }

            virtual std::array<taswira::Connector, 4>& UMLConnectors(void) {
                return this->Connectors;
            }

        private:
            std::array<taswira::Connector, 4> Connectors;
        };

		class Inheritance : public UMLObject {
        public:
			Inheritance(void)
                :Shape(taswira::UMLDims::AssociationLineLength, taswira::Colors::Black)
			{  }

            Inheritance(const taswira::Pixel& color)
                :Shape(taswira::UMLDims::AssociationLineLength, color)
            {  }

            ~Inheritance(void)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                this->Shape.DrawOnImage(image, startRow, startCol);

                int LineLen = this->Shape.ShapeLineLength();

                // Set the connectors
                taswira::Connector Top(startRow + LineLen, startCol + (LineLen / 2));
                taswira::Connector Bottom(startRow, startCol + (LineLen / 2));

                this->ConnectorLeft() = Bottom;
                this->ConnectorTop() = Top;
                this->ConnectorRight() = Top;
                this->ConnectorBottom() = Bottom;
            }
        private:
            taswira::Triangle Shape;
		};

        class Aggregation : public UMLObject {
        public:
            Aggregation(void)
                :Shape(taswira::UMLDims::AssociationLineLength, taswira::Colors::Black)
            {  }

            Aggregation(const taswira::Pixel& color)
                :Shape(taswira::UMLDims::AssociationLineLength, color)
            {  }

            ~Aggregation(void)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                this->Shape.DrawOnImage(image, startRow, startCol);

                int LineLen = this->Shape.ShapeHeight();

                // Set the connectors
                taswira::Connector Left(startRow + (LineLen / 2), startCol);
                taswira::Connector Top(startRow + LineLen - 1, startCol + (LineLen / 2));
                taswira::Connector Right(startRow + (LineLen / 2), startCol + LineLen - 1);
                taswira::Connector Bottom(startRow, startCol + (LineLen / 2));

                this->ConnectorLeft() = Left;
                this->ConnectorTop() = Top;
                this->ConnectorRight() = Right;
                this->ConnectorBottom() = Bottom;
            }
        private:
            taswira::Diamond Shape;
        };

        // Simple refers to no association between objects
        struct Simple : public UMLObject {
            Simple(void)
            {  }

            ~Simple(void)
            {  }
        };

        class PartialClass : public UMLObject {
        public:
            PartialClass(void)
            {  }

            PartialClass(int rowDims, int colDims, const taswira::Pixel& color = taswira::Colors::Black)
                :Text(rowDims, colDims, color),
                Association(nullptr)
            {  }

            ~PartialClass(void)
            {  }

            void AddAssociation(std::shared_ptr<UMLObject> association) {
                this->Association = association;
            }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                this->Text.DrawOnImage(image, startRow, startCol);

                int NumRows = this->Text.ShapeHeight();
                int NumCols = this->Text.ShapeWidth();


                if (this->Association != nullptr) {
                    int MiddleCol = startCol + (NumCols / 2);
                    int AssociationStartRow = startRow - taswira::UMLDims::AssociationLineLength;
                    int AssociationStartCol = MiddleCol - (taswira::UMLDims::AssociationLineLength / 2);

                    this->Association->DrawOnImage(image, AssociationStartRow, AssociationStartCol);
                } else {
                    //There is no association, so we use the class connectors itself

                    // Set the connectors
                    taswira::Connector Left(startRow + (NumRows / 2), startCol);
                    taswira::Connector Top(startRow + NumRows - 1, startCol + (NumCols / 2));
                    taswira::Connector Right(startRow + (NumRows / 2), startCol + NumCols - 1);
                    taswira::Connector Bottom(startRow, startCol + (NumCols / 2));

                    this->ConnectorLeft() = Left;
                    this->ConnectorTop() = Top;
                    this->ConnectorRight() = Right;
                    this->ConnectorBottom() = Bottom;
                }
            }

            virtual taswira::Connector& ConnectorLeft(void) {
                if (this->Association == nullptr) {
                    return UMLObject::ConnectorLeft();
                }
                else {
                    return this->Association->ConnectorLeft();
                }
            }

            virtual taswira::Connector& ConnectorTop(void) {
                if (this->Association == nullptr) {
                    return UMLObject::ConnectorTop();
                }
                else {
                    return this->Association->ConnectorTop();
                }
            }

            virtual taswira::Connector& ConnectorRight(void) {
                if (this->Association == nullptr) {
                    return UMLObject::ConnectorRight();
                }
                else {
                    return this->Association->ConnectorRight();
                }
            }

            virtual taswira::Connector& ConnectorBottom(void) {
                if (this->Association == nullptr) {
                    return UMLObject::ConnectorBottom();
                }
                else {
                    return this->Association->ConnectorBottom();
                }
            }

            virtual std::array<taswira::Connector, 4>& UMLConnectors(void) {
                if (this->Association == nullptr) {
                    return UMLObject::UMLConnectors();
                }
                else {
                    return this->Association->UMLConnectors();
                }
            }

            taswira::TextBox& ObjectText(void) {
                return this->Text;
            }

        private:
            taswira::TextBox Text;
            std::shared_ptr<UMLObject> Association;
        };

        class Variable : public UMLObject {
        public:
            Variable(void)
                :Visibility(nullptr),
                Padding(4),
                VisibilityHeight(0),
                VisibilityWidth(0)
            {  }

            Variable(taswira::TextBoxNoBorder name)
                :UMLObject(name.ShapeColor()),
                Visibility(nullptr),
                Name(name),
                Padding(4),
                VisibilityHeight(0),
                VisibilityWidth(0)
            {  }

            Variable(taswira::TextBoxNoBorder& name)
                :UMLObject(name.ShapeColor()),
                Visibility(nullptr),
                Name(name),
                Padding(4),
                VisibilityHeight(0),
                VisibilityWidth(0)
            {  }

            Variable(const Variable& variable)
                :UMLObject(variable),
                Visibility(variable.Visibility),
                Name(variable.Name),
                Padding(variable.Padding),
                VisibilityHeight(variable.VisibilityHeight),
                VisibilityWidth(variable.VisibilityWidth)
            {  }

            ~Variable(void)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                if (this->Visibility == nullptr) {
                    throw std::logic_error("Variable Visibility is Null");
                }

                int ShapeMiddleRow = this->Name.ShapeHeight() / 2;
                int VisibilityMiddleRow = this->VisibilityHeight / 2;
                int Line = startRow + (ShapeMiddleRow - VisibilityMiddleRow);

                this->Visibility->DrawOnImage(image, Line, startCol);

                this->Name.DrawOnImage(image, startRow, startCol + this->VisibilityWidth + this->Padding);
            }

            template<typename VISTYPE>
            void AddVisibility(void) {
                this->Visibility = std::make_shared<VISTYPE>(taswira::AlphaDims::RowDim, taswira::AlphaDims::ColDim, this->Name.ShapeColor());
                this->VisibilityHeight = taswira::AlphaDims::RowDim;
                this->VisibilityWidth = taswira::AlphaDims::ColDim;
            }

            int ShapeHeight(void) {
                return this->Name.ShapeHeight();
            }

            int ShapeWith(void) {
                return this->VisibilityWidth + this->Padding + this->Name.ShapeWidth();
            }
        private:
            std::shared_ptr<taswira::IBaseShape> Visibility;
            taswira::TextBoxNoBorder Name;
            int Padding;
            int VisibilityHeight;
            int VisibilityWidth;
        };

        class FullClass : public UMLObject {
        public:
            FullClass(void)
            {  }

            // Minimum rowDims (i.e. Shape Height) for a FullClass is 100px so the 16px size letters
            // can fit in the upper quarter of the object. Otherwise you get undefined behaviour.
            FullClass(int rowDims, int colDims, const taswira::Pixel& color = taswira::Colors::Black)
                :ObjectBounds(rowDims, colDims, color),
                ClassName(rowDims / 4, colDims, color)
            {  }

            FullClass(int rowDims, int colDims, const std::vector<std::shared_ptr<taswira::IBaseShape>>& phrase, const taswira::Pixel& color = taswira::Colors::Black)
                :ObjectBounds(rowDims, colDims, color),
                ClassName(rowDims / 4, colDims, phrase, color)
            {  }

            ~FullClass(void)
            {  }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                int NumRows = this->ObjectBounds.ShapeHeight();
                int NumCols = this->ObjectBounds.ShapeWidth();
                int QuarterHeight = NumRows / 4;
                int LastQuarter = startRow + (3 * QuarterHeight);

                // Draw border and and class name
                this->ClassName.DrawOnImage(image, LastQuarter, startCol);
                this->ObjectBounds.DrawOnImage(image, startRow, startCol);

                // Set the connectors
                taswira::Connector Left(startRow + (NumRows / 2), startCol);
                taswira::Connector Top(startRow + NumRows - 1, startCol + (NumCols / 2));
                taswira::Connector Right(startRow + (NumRows / 2), startCol + NumCols - 1);
                taswira::Connector Bottom(startRow, startCol + (NumCols / 2));

                this->ConnectorLeft() = Left;
                this->ConnectorTop() = Top;
                this->ConnectorRight() = Right;
                this->ConnectorBottom() = Bottom;

                // Draw variables
                int Line = LastQuarter - this->Variables[0].ShapeHeight();
                for (taswira::UML::Variable& var : this->Variables) {
                    var.DrawOnImage(image, Line, startCol);
                    Line -= this->Variables[0].ShapeHeight();
                }
            }

            template<typename VISTYPE>
            void AddVariable(const std::vector<std::shared_ptr<taswira::IBaseShape>>& phrase) {
                int PhraseColSize = (phrase.size() * taswira::AlphaDims::ColDim) + ((phrase.size() - 1) * taswira::TextDims::LetterPadding);

                taswira::UML::Variable Var(taswira::TextBoxNoBorder(20, PhraseColSize, phrase));
                Var.AddVisibility<VISTYPE>();

                this->Variables.push_back(Var);
            }

            taswira::TextBox& ObjectName(void) {
                return this->ClassName;
            }

        private:
            taswira::Rectangle ObjectBounds;
            taswira::TextBox ClassName;
            std::vector<taswira::UML::Variable> Variables;
        };
	} // ! namespace UML

    namespace Geometry {
        static void DrawLineOnImage(taswira::BitmapImage& image, taswira::UML::UMLObject& obj1, taswira::UML::UMLObject& obj2, taswira::Pixel& color) {
            // find the connectors that are closest to each other
            int ClosestDistance = std::numeric_limits<int>::max(), Distance = 0;
            taswira::Connector ClosestConn1, ClosestConn2;
            for (taswira::Connector& Conn1 : obj1.UMLConnectors()) {
                for (taswira::Connector& Conn2 : obj2.UMLConnectors()) {
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