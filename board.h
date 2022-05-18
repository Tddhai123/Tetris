#ifndef BOARD_H_INCLUDED
#define BOARD_H_INCLUDED

#include <vector>

#include "config.h"
#include "piece.h"

using namespace std;

class Board {
    enum BlockStatus : int {block_empty, i_block, o_block, t_block, s_block, z_block, j_block, l_block};

    public:
        Board ();
        int getTetromino (int r, int c);
        bool isBlockFree (int r, int c);
        bool isPositionLegal (Piece p);
        void storePiece (Piece p);
        void clearFullLines ();
        bool isGameOver ();

    private:
        BlockStatus board_state [config::playfield_height][config::playfield_width];
        vector <Piece> pieces;

        void deleteLine (int y);
};

#endif // BOARD_H_INCLUDED
