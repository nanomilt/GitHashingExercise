#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void handle_sigint(int signum) {
    printf("SIGINT signal caught!\n");
    exit(signum);
}

int main() {
    signal(SIGINT, handle_sigint);
    
    while (1) {

        sleep(1);
    }

    return 0;
}
