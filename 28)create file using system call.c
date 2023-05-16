#include <stdio.h>
#include <stdlib.h>
#define BUFFER_SIZE 100
int main() {
    FILE *file;
    char buffer[BUFFER_SIZE];
    file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening the file");
        exit(1);
    }
    printf("Enter data to write to the file (max %d characters):\n", BUFFER_SIZE);
    fgets(buffer, BUFFER_SIZE, stdin);
    fprintf(file, "%s", buffer);
    fclose(file);
    file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening the file for reading");
        exit(1);
    }
    printf("\nReading data from the file:\n");
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
    fclose(file);

    return 0;
}
