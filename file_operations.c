#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    char data[100];

    // ----------- FILE CREATION AND WRITING DATA -----------
    // Open the file in write mode. This will create the file if it does not exist.
    file = fopen("myfile.txt", "w");
    if (file == NULL) {
        printf("Error creating file!\n");
        return 1;
    }

    printf("Enter some text to write to the file: ");
    fgets(data, sizeof(data), stdin);

    // Write the input data to the file
    fputs(data, file);
    fclose(file); // Always close the file after use
    printf("Data written to file successfully.\n");

    // ----------- READING DATA FROM THE FILE -----------
    // Open the file in read mode
    file = fopen("myfile.txt", "r");
    if (file == NULL) {
        printf("Error reading file!\n");
        return 1;
    }

    printf("\nReading from file:\n");
    while (fgets(data, sizeof(data), file) != NULL) {
        printf("%s", data);
    }
    fclose(file);

    // ----------- APPENDING DATA TO THE FILE -----------
    // Open the file in append mode
    file = fopen("myfile.txt", "a");
    if (file == NULL) {
        printf("Error opening file for appending!\n");
        return 1;
    }

    printf("\n\nEnter more text to append to the file: ");
    fgets(data, sizeof(data), stdin);

    // Append the new data
    fputs(data, file);
    fclose(file);
    printf("Data appended to file successfully.\n");

    return 0;
}
