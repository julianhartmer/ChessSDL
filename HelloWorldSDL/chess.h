#ifndef CHESS_H
#define CHESS_H

#include "log.h"
#include "types.h"
#include "utils.h"

#define BOARD_SIDE_LENGTH 8

typedef struct {
	u8 x, y;
} pos;

typedef enum {
	NONE = 0,
	WHITE,
	BLACK,
	PIECE_COLOR_MAX
} piece_color;

static inline const char *piece_color_string(piece_color c)
{
	static const char *s[] = {"none", "white", "black", "invalid"};
	ASSERT_WARNING (c == PIECE_COLOR_MAX, "Invalid value PIECE_COLOR_MAX");
	return s[c];
}

typedef enum {
	EMPTY = 0,
	PAWN,
	ROOK,
	KNIGHT,
	BISHOP,
	QUEEN,
	KING,
	PIECE_TYPE_MAX
} piece_type;

static inline const char *piece_type_string(piece_type t)
{
	static const char *s[] = {"none","pawn","rook","knight","bishop","queen","king", "invalid"};
	ASSERT_WARNING (t == PIECE_TYPE_MAX, "Invalid value PIECE_COLOR_MAX");
	return s[t];
}

typedef struct {
	piece_color c;
	piece_type t;
} piece;

typedef struct {
	piece_color active_color;
	bool white_castle_l_possible;
	bool white_castle_r_possible;
	bool black_castle_l_possible;
	bool black_castle_r_possible;
	piece board[BOARD_SIDE_LENGTH][BOARD_SIDE_LENGTH];
} chess;

typedef struct {
	chess before;
	chess after;
	pos from;
	pos to;
} move;

chess * init_chess(chess *c);

dllist * valid_moves_starting_from(const chess *c, pos p);

#endif