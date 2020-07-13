#ifndef TC_TETRIS_COMMON_H
#define TC_TETRIS_COMMON_H

#include <inttypes.h>

typedef struct coord2_t {
    int32_t i32_x;
    int32_t i32_y;
} coord2_t;

typedef struct tetris_tetrimino_t {
    coord2_t st_position;
    uint8_t u8_type;
    uint8_t u8_rotation;
} tetris_tetrimino_t;

typedef struct tetris_tetrimino_layout_t {
    coord2_t a_blocks[3];
} tetris_tetrimino_layout_t;

/*
 * Error codes :
 *
 */
extern int32_t TC_ERROR_CODE;

void tc_init();
void tc_item_rotate(tetris_tetrimino_t *p_item);
void tc_item_move_down(tetris_tetrimino_t *p_item);

#endif /* define TC_TETRIS_COMMON */
