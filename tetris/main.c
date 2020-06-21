#include <stdio.h>
#include <termios.h>
#include <pthread.h>
#include <unistd.h>


#define STDIN_FILENO 0

pthread_t listening_thread_handle;
int a = 0;

void set_canonical_mode(int on) {
    struct termios ttystate;

    // get the terminal state
    tcgetattr(STDIN_FILENO, &ttystate);
    
    if (!on) {
        // turn off canonical mod
        ttystate.c_lflag &= ~ICANON;
        // minimum of number input read
        ttystate.c_cc[VMIN] = 1;
    } else {
        // turn on canonical mode
        ttystate.c_lflag |= ICANON;
    }
    // set the terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

void set_echo_mode(int on) {
    struct termios ttystate;

    // get the terminal state 
    tcgetattr(STDIN_FILENO, &ttystate);

    if (!on) {
        // turn off echo mod
        ttystate.c_oflag &= ~ECHO;
    } else {
        // turn on echo mod
        ttystate.c_oflag |= ECHO;
    }

    // set the terminal attributes
    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}

void listening_loop(void *arg) {
    while(1) {
        sleep(1);
        a += 1;
    }
}

int start_listening_thread() {
    return pthread_create(&listening_thread_handle, NULL, (void*)&listening_loop, NULL);
}

int main() {
    set_canonical_mode(0);
    set_echo_mode(0);

    start_listening_thread();
    while (1) {
        sleep(2);
        printf("A = %d\n", a);
    }

    return 0;
}
