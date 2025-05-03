/*
 * File: board.h
 * Author: Preston Shultz
 * Date: 5/02/2025
 * Description: Setup board structure
 */


#ifndef BOARD_H
#define BOARD_H

#include <stdint.h>

typedef struct board {

    uint64_t whitePawns;
    uint64_t whiteKnights;
    uint64_t whiteBishops;
    uint64_t whiteRooks;
    uint64_t whiteQueens;
    uint64_t whiteKing;

    uint64_t blackPawns;
    uint64_t blackKnights;
    uint64_t blackBishops;
    uint64_t blackRooks;
    uint64_t blackQueens;
    uint64_t blackKing;

    uint64_t occupied;
    uint64_t whitePieces;
    uint64_t blackPieces;
    int sideToMove;            // 0 = white, 1 = black
    int castlingRights;
    int enPassantSquare;
    int halfmoveClock;
    int fullmoveNumber;

}board;

#endif