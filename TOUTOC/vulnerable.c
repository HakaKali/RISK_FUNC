#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void read_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file != NULL) {
        char buffer[1024];
        fread(buffer, sizeof(char), sizeof(buffer), file);  // Time-of-Use
        printf("File content: %s\n", buffer);
        fclose(file);
    } else {
        perror("Error opening file");
    }
}

int main() {
    const char *filename = "example.txt";

    // Check if the file exists
    if (access(filename, F_OK) == -1) {
        printf("File not found\n");
        return 1;
    } else {
        printf("File exists\n");
    }

    // Add a delay to give time for the attacker to modify the file
    sleep(10); // Sleep for 10 seconds

    read_file(filename);
    return 0;
}
