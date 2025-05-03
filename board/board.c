/*
 * File: board.c
 * Author: Preston Shultz
 * Date: 5/02/2025
 * Description: board functions and intialization
 */


#include <board.h>


// Set the bit at `index` to 1
#define SET_BIT(bitboard, index) ((bitboard) |= (1ULL << (index)))

// Clear the bit at `index` (set it to 0)
#define CLEAR_BIT(bitboard, index) ((bitboard) &= ~(1ULL << (index)))

// Check if the bit at `index` is set (1)
#define IS_BIT_SET(bitboard, index) (((bitboard) & (1ULL << (index))) != 0)


/*
 * squareIndex:
 * Converts a chessboard square (file 'a'–'h' and rank 1–8) into a 0-based index (0–63) for a bitboard.
 *
 * Parameters:
 *   - file (char): The file (column), a letter from 'a' to 'h'.
 *   - rank (int): The rank (row), an integer from 1 to 8.
 *
 * Returns:
 *   - int: The index (0–63) corresponding to the square on the chessboard.
 *
 * Example:
 *   - 'a1' -> Index 0
 *   - 'h8' -> Index 63
 */
int squareIndex(char file, int rank) {
    return (rank - 1) * 8 + (file - 'a');
}


/**
 * Initializes the board with the standard chess starting position.
 *
 * This function sets up the board by initializing the bitboards for both white and black pieces.
 * The pieces are placed in their respective starting positions on the chessboard using bitwise 
 * operations to set the appropriate bits on the bitboards.
 *
 * Parameters:
 *   - board: A pointer to the `board` structure that holds the bitboards for all the chess pieces.
 *            The structure will be modified to reflect the initial position of pieces.
 *
 * Returns:
 *   - void: This function does not return any value. It modifies the input `board` structure.
 */
void initBoard(board *board)
{
    board->whitePawns   = (1ULL << squareIndex('a', 2)) | (1ULL << squareIndex('b', 2)) | 
                          (1ULL << squareIndex('c', 2)) | (1ULL << squareIndex('d', 2)) | 
                          (1ULL << squareIndex('e', 2)) | (1ULL << squareIndex('f', 2)) | 
                          (1ULL << squareIndex('g', 2)) | (1ULL << squareIndex('h', 2));

    board->whiteKnights = (1ULL << squareIndex('b', 1)) | (1ULL << squareIndex('g', 1));

    board->whiteBishops = (1ULL << squareIndex('c', 1)) | (1ULL << squareIndex('f', 1));

    board->whiteRooks   = (1ULL << squareIndex('a', 1)) | (1ULL << squareIndex('h', 1));

    board->whiteQueens  = (1ULL << squareIndex('d', 1));

    board->whiteKing    = (1ULL << squareIndex('e', 1));


    board->blackPawns   = (1ULL << squareIndex('a', 7)) | (1ULL << squareIndex('b', 7)) | 
                          (1ULL << squareIndex('c', 7)) | (1ULL << squareIndex('d', 7)) | 
                          (1ULL << squareIndex('e', 7)) | (1ULL << squareIndex('f', 7)) | 
                          (1ULL << squareIndex('g', 7)) | (1ULL << squareIndex('h', 7));

    board->blackKnights = (1ULL << squareIndex('b', 8)) | (1ULL << squareIndex('g', 8));

    board->blackBishops = (1ULL << squareIndex('c', 8)) | (1ULL << squareIndex('f', 8));

    board->blackRooks   = (1ULL << squareIndex('a', 8)) | (1ULL << squareIndex('h', 8));

    board->blackQueens  = (1ULL << squareIndex('d', 8));

    board->blackKing    = (1ULL << squareIndex('e', 8));

}