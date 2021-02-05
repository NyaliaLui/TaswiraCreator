#ifndef UMLFACTORY_H
#define UMLFACTORY_H

#include "UMLObjects.h"
#include "AlphaFactory.h"
#include "TextBox.h"

#include <array>
#include <limits>
#include <memory>
#include <vector>
#include <stdexcept>
#include <string>

namespace taswira {
    namespace UML {
		class UMLFactory {
		public:
			UMLFactory(void)
			{  }

			UMLFactory(taswira::Pixel& color)
				:Color(color),
				LetterFactory(color)
			{  }

			UMLFactory(taswira::Pixel& color, taswira::AlphaFactory &letterFactory)
				:Color(color),
				LetterFactory(letterFactory)
			{  }

			UMLFactory(const UMLFactory& factory)
				:Color(factory.Color)
			{  }

			~UMLFactory(void)
			{  }

			UMLFactory& operator = (const UMLFactory& factory) {
				this->Color = factory.Color;

				return (*this);
			}

			template<typename VISTYPE>
			taswira::UML::Variable CreateVariable(const std::vector<std::shared_ptr<taswira::IBaseShape>>& name) {
				int PhraseColSize = (static_cast<int>(name.size()) * taswira::AlphaDims::ColDim) + (static_cast<int>(name.size() - 1) * taswira::TextDims::LetterPadding);

				taswira::UML::Variable Var(taswira::TextBoxNoBorder(taswira::TextDims::NoBorderHeight, PhraseColSize, name, this->Color));
				Var.AddVisibility<VISTYPE>();

				return Var;
			}

			template<typename VISTYPE>
			taswira::UML::Variable CreateVariable(std::string& name) {
				return this->CreateVariable<VISTYPE>(taswira::CreatePhrase(name, this->LetterFactory));
			}

			template<typename VISTYPE>
			taswira::UML::Variable CreateVariable(const char* name) {
				return this->CreateVariable<VISTYPE>(taswira::CreatePhrase(name, this->LetterFactory));
			}

			taswira::UML::FullClass CreateFullClass(const std::vector<std::shared_ptr<taswira::IBaseShape>>& name, std::vector<taswira::UML::Variable>& variables) {
				// Minimum rowDims (i.e. Shape Height) for a FullClass is 100px so the 16px size letters
				// can fit in the upper quarter of the object. Otherwise you get undefined behaviour.
				// This means that at a minimum, the class name is 25px in height.
				int RowDims = 100;

				// Height of the member variable box is the number of variables * the border height
				int VarBoxHeight = taswira::TextDims::NoBorderHeight * static_cast<int>(variables.size());

				// total height is minum class name height + variable box height
				if ((taswira::UMLDims::ClassNameHeight + VarBoxHeight) > RowDims) {
					RowDims = taswira::UMLDims::ClassNameHeight + VarBoxHeight;
				}

				// Minimum colDims (i.e. Shape Width) is the width of the largest phrase in the objects
				// accounting for both the class name and member variables naems
				int ColDims = (static_cast<int>(name.size()) * taswira::AlphaDims::ColDim) + (static_cast<int>(name.size()) * taswira::TextDims::LetterPadding);

				for (taswira::UML::Variable& var : variables) {
					if (var.ShapeWidth() > ColDims) {
						ColDims = var.ShapeWidth();
					}
				}
				
				taswira::UML::FullClass UMLObject(RowDims, ColDims, name, this->Color);
				for (taswira::UML::Variable& var : variables) {
					UMLObject.AddVariable(var);
				}

				return UMLObject;
			}

			taswira::UML::FullClass CreateFullClass(std::string& name, std::vector<taswira::UML::Variable>& variables) {
				return this->CreateFullClass(taswira::CreatePhrase(name, this->LetterFactory), variables);
			}

			taswira::UML::FullClass CreateFullClass(const char* name, std::vector<taswira::UML::Variable>& variables) {
				return this->CreateFullClass(taswira::CreatePhrase(name, this->LetterFactory), variables);
			}

		private:
			taswira::Pixel Color;
			taswira::AlphaFactory LetterFactory;
		};
    } // ! namespace UML
}

#endif // !UMLFACTORY_H