#include <stdio.h>
#include <termios.h>
#include <pthread.h>
#include <unistd.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stdbool.h>
#include "qc_queue_char.h"
#include "tc_tetris_common.h"

#define STDIN_FILENO 0

pthread_t listening_thread_handle;
qc_queue_t *p_input_queue         = NULL;
uint8_t u8_initialized            = 0;

/******************************************************
 *                      CLI IHM
 ******************************************************/
void set_canonical_mode(bool b_on) {
    struct termios ttystate;

    /* get the terminal state */
    tcgetattr(STDIN_FILENO, &ttystate);
    
    if (!b_on) {
        ttystate.c_lflag &= ~ICANON;
        ttystate.c_cc[VMIN] = 1; /* minimum of number input read */
    } else {
        ttystate.c_lflag |= ICANON;
    }
    /* set the terminal attributes */
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

void set_echo_mode(bool b_on) {
    struct termios ttystate;

    /* get the terminal state  */
    tcgetattr(STDIN_FILENO, &ttystate);

    if (!b_on) {
        ttystate.c_lflag &= ~ECHO;
    } else {
        ttystate.c_lflag |= ECHO;
    }

    /* set the terminal attributes */
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

/******************************************************
 *                   Game Loop
 ******************************************************/
void* listening_loop(void *arg) {
    int32_t i32_return_code;
    int32_t i32_input;

    p_input_queue = qc_queue_init();
    if (p_input_queue == NULL) {
        fprintf(stderr, "Can't initialize input's queue\n");
    }

    u8_initialized = 1;

    while (1) {
        i32_input = getc(stdin);
        i32_return_code = qc_queue_enqueue(p_input_queue, (char)i32_input) ;

        if (i32_return_code != 0) {
            fprintf(stderr, "Err : qc_queue_enqueue returned %d\n", i32_return_code);
        }
    }

    qc_queue_clear(p_input_queue);
    free(p_input_queue);
    p_input_queue = NULL;
}

int process_input(uint8_t u8_input) {
    printf("Processing input '%c'\n", u8_input);
    return 0;
}

int main() {
    uint8_t u8_input;
    int32_t i32_return_code;

    /* Configure terminal behavior */
    set_canonical_mode(0);
    set_echo_mode(0);

    /* Init listening thread */
    i32_return_code = pthread_create(&listening_thread_handle, NULL, &listening_loop, NULL);
    if (i32_return_code != 0) {
        fprintf(stderr, "Err : phtread_create returned %d\n", i32_return_code);
    }

    tc_init();
    while(u8_initialized == 0) { }
    while(1) {
        sleep(1);
        if (qc_queue_get_size(p_input_queue) > 0) {

            i32_return_code = qc_queue_dequeue(p_input_queue, (char*)&u8_input);
            if (i32_return_code != 0) {
                fprintf(stderr, "Err : qc_queue_dequeue returned %d\n", i32_return_code);
            }

            process_input(u8_input);
        }
    }

    return 0;
}
