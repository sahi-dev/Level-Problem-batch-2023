/*Sort the above "data.csv" based on the "Temperature" field in descending order

a. Use only file handling concepts*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Function to count the number of lines in a file
int countLines(FILE *file) {
    int count = 0;
    char ch;

    while ((ch = fgetc(file)) != EOF) {
        if (ch == '\n')
            count++;
    }

    // Reset the file position indicator to the beginning of the file
    fseek(file, 0, SEEK_SET);

    return count;
}

// Structure to hold log entry data
typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

// Function to compare two log entries based on temperature
int compareEntries(const void *a, const void *b) {
    const LogEntry *entryA = (const LogEntry *)a;
    const LogEntry *entryB = (const LogEntry *)b;

    if (entryA->temperature < entryB->temperature)
        return 1;
    else if (entryA->temperature > entryB->temperature)
        return -1;
    else
        return 0;
}

// Function to sort the log entries in descending order based on temperature
void sortEntries(LogEntry *logEntries, int entryCount) {
    qsort(logEntries, entryCount, sizeof(LogEntry), compareEntries);
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = 0;

    // Open the file for reading
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 1;
    }

    // Count the number of lines in the file
    int lineCount = countLines(file);

    // Skip the header line
    char line[100];
    fgets(line, sizeof(line), file);

    // Read the log entries from the file
    while (fgets(line, sizeof(line), file)) {
        // Parse the line and extract values
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);

        // Store the entry in the array
        logEntries[entryCount++] = entry;
    }

    fclose(file);

    // Sort the log entries based on temperature
    sortEntries(logEntries, entryCount);

    // Open the file for writing (overwrite the original file)
    file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return 1;
    }

    // Write the header line to the file
    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Timestamp\n");

    // Write the sorted log entries to the file
    for (int i = 0; i < entryCount; i++) {
        LogEntry entry = logEntries[i];
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
                entry.entryNo, entry.sensorNo, entry.temperature,
                entry.humidity, entry.light, entry.timestamp);
    }

    fclose(file);

    printf("Data sorted and written back to data.csv successfully.\n");

    return 0;
}
