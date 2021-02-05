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

            UMLObject& operator = (const UMLObject& obj) {
                this->taswira::IBaseShape::operator=(obj);
                this->Connectors = obj.Connectors;
                return (*this);
            }

            virtual ~UMLObject(void)
            {  }

            //Connectors are for drying connections between UML objects
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

            virtual int ShapeHeight(void) {
                return 0;
            }

            virtual int ShapeWidth(void) {
                return 0;
            }

        private:
            std::array<taswira::Connector, 4> Connectors;
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

            Variable& operator = (const Variable& variable) {
                this->UMLObject::operator=(variable);
                this->Visibility = variable.Visibility;
                this->Name = variable.Name;
                this->Padding = variable.Padding;
                this->VisibilityHeight = variable.VisibilityHeight;
                this->VisibilityWidth = variable.VisibilityWidth;

                return (*this);
            }

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

            virtual int ShapeHeight(void) {
                return this->Name.ShapeHeight();
            }

            virtual int ShapeWidth(void) {
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
                :UMLObject(color), 
                ObjectBounds(rowDims, colDims, color),
                ClassName(taswira::UMLDims::ClassNameHeight, colDims, color)
            {  }

            FullClass(int rowDims, int colDims, const std::vector<std::shared_ptr<taswira::IBaseShape>>& name, const taswira::Pixel& color = taswira::Colors::Black)
                :UMLObject(color), 
                ObjectBounds(rowDims, colDims, color),
                ClassName(taswira::UMLDims::ClassNameHeight, colDims, name, color)
            {  }

            FullClass(const FullClass& full)
                :UMLObject(full),
                ObjectBounds(full.ObjectBounds),
                ClassName(full.ClassName),
                Variables(full.Variables)
            {  }

            ~FullClass(void)
            {  }

            FullClass& operator = (const FullClass& full) {
                this->UMLObject::operator=(full);
                this->ObjectBounds = full.ObjectBounds;
                this->ClassName = full.ClassName;
                this->Variables = full.Variables;
                return (*this);
            }

            virtual void DrawOnImage(taswira::BitmapImage& image, int startRow, int startCol) {
                int NumRows = this->ObjectBounds.ShapeHeight();
                int NumCols = this->ObjectBounds.ShapeWidth();
                int ClassNameRowStart = startRow + (NumRows - taswira::UMLDims::ClassNameHeight);

                // Draw border and and class name
                this->ClassName.DrawOnImage(image, ClassNameRowStart, startCol);
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
                int Line = ClassNameRowStart - this->Variables[0].ShapeHeight();
                for (taswira::UML::Variable& var : this->Variables) {
                    var.DrawOnImage(image, Line, startCol);
                    Line -= this->Variables[0].ShapeHeight();
                }
            }

            template<typename VISTYPE>
            void AddVariable(const std::vector<std::shared_ptr<taswira::IBaseShape>>& name) {
                int PhraseColSize = (name.size() * taswira::AlphaDims::ColDim) + ((name.size() - 1) * taswira::TextDims::LetterPadding);

                taswira::UML::Variable Var(taswira::TextBoxNoBorder(taswira::TextDims::NoBorderHeight, PhraseColSize, name));
                Var.AddVisibility<VISTYPE>();

                this->Variables.push_back(Var);
            }

            void AddVariable(taswira::UML::Variable& var) {
                this->Variables.push_back(var);
            }

            taswira::TextBox& ObjectName(void) {
                return this->ClassName;
            }
            
            virtual int ShapeHeight(void) {
                return this->ObjectBounds.ShapeHeight();
            }

            virtual int ShapeWidth(void) {
                return this->ObjectBounds.ShapeWidth();
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