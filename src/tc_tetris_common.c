#include "tc_tetris_common.h"

#define TETRIS_LAYOUT_COUNT 7
#define TETRIS_ROTATION_COUNT 4

int32_t TC_ERROR_CODE;
tetris_tetrimino_layout_t a_layouts[TETRIS_LAYOUT_COUNT][TETRIS_ROTATION_COUNT];

void tc_init() {

    /*
     *  Tetrimino I ("bar")
     */

    a_layouts[0][0].a_blocks[0] = (coord2_t){-2,0};
    a_layouts[0][0].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[0][0].a_blocks[2] = (coord2_t){1,0};

    a_layouts[0][1].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[0][1].a_blocks[1] = (coord2_t){0,1};
    a_layouts[0][1].a_blocks[2] = (coord2_t){0,2};

    a_layouts[0][2].a_blocks[0] = (coord2_t){-2,0};
    a_layouts[0][2].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[0][2].a_blocks[2] = (coord2_t){1,0};

    a_layouts[0][3].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[0][3].a_blocks[1] = (coord2_t){0,1};
    a_layouts[0][3].a_blocks[2] = (coord2_t){0,2};

    /*
     *  Tetrimino O ("Square")
     */
    a_layouts[1][0].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[1][0].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[1][0].a_blocks[2] = (coord2_t){-1,0};

    a_layouts[1][1].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[1][1].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[1][1].a_blocks[2] = (coord2_t){-1,0};

    a_layouts[1][2].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[1][2].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[1][2].a_blocks[2] = (coord2_t){-1,0};

    a_layouts[1][3].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[1][3].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[1][3].a_blocks[2] = (coord2_t){-1,0};

    /*
     * Tetrimino T ("T")
     */ 
    a_layouts[2][0].a_blocks[0] = (coord2_t){-1,0};
    a_layouts[2][0].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[2][0].a_blocks[2] = (coord2_t){1,0};

    a_layouts[2][1].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[2][1].a_blocks[1] = (coord2_t){1,0};
    a_layouts[2][1].a_blocks[2] = (coord2_t){0,1};

    a_layouts[2][2].a_blocks[0] = (coord2_t){-1,0};
    a_layouts[2][2].a_blocks[1] = (coord2_t){0,1};
    a_layouts[2][2].a_blocks[2] = (coord2_t){1,0};

    a_layouts[2][3].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[2][3].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[2][3].a_blocks[2] = (coord2_t){0,1};

    /*
     *  Tetrimino L ("Lambda", "L")
     */
    a_layouts[3][0].a_blocks[0] = (coord2_t){-1,0};
    a_layouts[3][0].a_blocks[1] = (coord2_t){1,-1};
    a_layouts[3][0].a_blocks[2] = (coord2_t){1,0};

    a_layouts[3][1].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[3][1].a_blocks[1] = (coord2_t){-1,1};
    a_layouts[3][1].a_blocks[2] = (coord2_t){1,1};

    a_layouts[3][2].a_blocks[0] = (coord2_t){-1,0};
    a_layouts[3][2].a_blocks[1] = (coord2_t){-1,1};
    a_layouts[3][2].a_blocks[2] = (coord2_t){1,0};

    a_layouts[3][3].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[3][3].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[3][3].a_blocks[2] = (coord2_t){0,1};

    /*
     *  Tetrimino J ("Gamma", "L Inversé")
     */
    a_layouts[4][0].a_blocks[0] = (coord2_t){-1,0};
    a_layouts[4][0].a_blocks[1] = (coord2_t){1,0};
    a_layouts[4][0].a_blocks[2] = (coord2_t){1,1};

    a_layouts[4][1].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[4][1].a_blocks[1] = (coord2_t){1,0};
    a_layouts[4][1].a_blocks[2] = (coord2_t){1,1};

    a_layouts[4][2].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[4][2].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[4][2].a_blocks[2] = (coord2_t){1,0};

    a_layouts[4][3].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[4][3].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[4][3].a_blocks[2] = (coord2_t){1,1};

    /*
     *  Tetrimino Z ("Biais")
     */
    a_layouts[5][0].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[5][0].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[5][0].a_blocks[2] = (coord2_t){-1,1};

    a_layouts[5][1].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[5][1].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[5][1].a_blocks[2] = (coord2_t){1,0};

    a_layouts[5][2].a_blocks[0] = (coord2_t){0,-1};
    a_layouts[5][2].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[5][2].a_blocks[2] = (coord2_t){-1,1};

    a_layouts[5][3].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[5][3].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[5][3].a_blocks[2] = (coord2_t){1,0};

    /*
     *  Tetrimino S ("Biais inversé")
     */
    a_layouts[6][0].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[6][0].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[6][0].a_blocks[2] = (coord2_t){0,1};

    a_layouts[6][1].a_blocks[0] = (coord2_t){-1,0};
    a_layouts[6][1].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[6][1].a_blocks[2] = (coord2_t){1,-1};

    a_layouts[6][2].a_blocks[0] = (coord2_t){-1,-1};
    a_layouts[6][2].a_blocks[1] = (coord2_t){-1,0};
    a_layouts[6][2].a_blocks[2] = (coord2_t){0,1};

    a_layouts[6][3].a_blocks[0] = (coord2_t){-1,0};
    a_layouts[6][3].a_blocks[1] = (coord2_t){0,-1};
    a_layouts[6][3].a_blocks[2] = (coord2_t){1,-1};
    return;
}

