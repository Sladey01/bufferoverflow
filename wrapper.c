#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char payload[256];
    FILE *file = fopen("payload.bin", "rb");
    if (!file) {
        perror("Error opening payload.bin");
        return 1;
    }

    fread(payload, sizeof(char), sizeof(payload), file);
    fclose(file);

    // Execute the vulnerable program with the payload
    execl("./buffer_overflow_demo", "./buffer_overflow_demo", payload, NULL);

    return 0;
}

