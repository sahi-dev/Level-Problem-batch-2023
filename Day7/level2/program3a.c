/*Delete an entry in the file data.csv file  on the "EntryNo" field

a. Use only file handling concepts*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteEntry(int entryNo) {
    FILE *inputFile = fopen("data.csv", "r");
    if (inputFile == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    FILE *tempFile = fopen("temp.csv", "w");
    if (tempFile == NULL) {
        printf("Failed to create temporary file.\n");
        fclose(inputFile);
        return;
    }

    char line[100];

    while (fgets(line, sizeof(line), inputFile)) {
        int currentEntryNo;
        sscanf(line, "%d", &currentEntryNo);

        if (currentEntryNo != entryNo) {
            fputs(line, tempFile);
        }
    }

    fclose(inputFile);
    fclose(tempFile);

    remove("data.csv");

    rename("temp.csv", "data.csv");

    printf("Entry deleted successfully.\n");
}

int main() {
    int entryNo;

    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entryNo);

    deleteEntry(entryNo);

    return 0;
}
