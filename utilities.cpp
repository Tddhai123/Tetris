#include "utilities.h"

#include "piece.h"

// Simple function to swap two pieces
void swap(Piece &a, Piece &b) {
    Piece temp = a;
    a = b;
    b = temp;
}
