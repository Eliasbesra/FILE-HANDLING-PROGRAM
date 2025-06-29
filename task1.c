#include <stdio.h>
#include <stdlib.h>

void writeToFile() {
    FILE *file = fopen("example.txt", "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        return;
    }
    fprintf(file, "This is a new file.\n");
    fprintf(file, "Writing some initial content.\n");
    fclose(file);
    printf("Data written to file successfully.\n");
}

void readFromFile() {
    FILE *file = fopen("example.txt", "r");
    if (file == NULL) {
        perror("Error opening file for reading");
        return;
    }
    char ch;
    printf("Contents of the file:\n");
    while ((ch = fgetc(file)) != EOF) {
        putchar(ch);
    }
    fclose(file);
}

void appendToFile() {
    FILE *file = fopen("example.txt", "a");
    if (file == NULL) {
        perror("Error opening file for appending");
        return;
    }
    fprintf(file, "Appending a new line to the file.\n");
    fclose(file);
    printf("Data appended to file successfully.\n");
}

int main() {
    int choice;
    
    do {
        printf("\nFile Operation Menu:\n");
        printf("1. Create/Write to file\n");
        printf("2. Read from file\n");
        printf("3. Append to file\n");
        printf("4. Exit\n");
        printf("Enter your choice (1-4): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                writeToFile();
                break;
            case 2:
                readFromFile();
                break;
            case 3:
                appendToFile();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
