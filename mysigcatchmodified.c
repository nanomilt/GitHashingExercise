#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

int count = 0;

void custom_handler(int signum) {
    printf("Caught signal %d: SIGINT\n", signum);
    
    count++;
    
    if (count == 2) {
        signal(SIGINT, SIG_DFL);  // Restore default behavior
    }
}

int main() {
    signal(SIGINT, custom_handler);
    
    while (1) {
        sleep(1);
    }

    return 0;
}

