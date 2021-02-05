#ifndef OBJECTDIMS_H
#define OBJECTDIMS_H

// All alphabetical characters are held in a 16x16 grid (i.e., square) of pixels.
namespace taswira {
    namespace AlphaDims {
        static const int RowDim = 16;
        static const int ColDim = 16;
    }

    namespace TextDims {
        static const int LetterPadding = 2;
        static const int NoBorderHeight = 20;
    }

    namespace UMLDims {
        static const int AssociationLineLength = 20;
        static const int ClassNameHeight = 25;
    }
}

#endif // !OBJECTDIMS_H
