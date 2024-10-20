#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Target function for the buffer overflow
void secret_function() {
    const char *jokes[] = {
        "Why do programmers prefer dark mode? Because light attracts bugs!",
        "Why do Java developers wear glasses? Because they don't see sharp!",
        "How many programmers does it take to change a light bulb? None, that's a hardware problem."
    };
    int random_index = rand() % 3; // Get a random index
    printf("🎉 Oops! You've triggered a hidden function! 🎉\n");
    printf("Here's a joke for you: %s\n", jokes[random_index]);
    exit(1);
}


// Vulnerable function with an overflowable buffer
void vulnerable_function(char *str) {
    char buffer[16];

    // Print buffer and secret_function addresses for debugging
    printf("Buffer address: %p\n", (void*)&buffer);
    printf("Secret function address: %p\n", (void*)&secret_function);

    // Copy input into buffer without bounds checking (vulnerability)
    strcpy(buffer, str);
    printf("Buffer content: %s\n", buffer);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("Usage: %s <payload>\n", argv[0]);
        return 1;
    }

    printf("Running vulnerable function...\n");
    vulnerable_function(argv[1]);

    return 0;
}
