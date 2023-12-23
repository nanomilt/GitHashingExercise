#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

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
        // Your program's main logic here
    }

    return 0;
}

