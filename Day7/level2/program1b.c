/*Sort the above "data.csv" based on the "Temperature" field in descending order

b. Use array of structures and file handling*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

int compareTemperatureDescending(const void *a, const void *b) {
    const LogEntry *entryA = (const LogEntry *)a;
    const LogEntry *entryB = (const LogEntry *)b;
    if (entryA->temperature < entryB->temperature)
        return 1;
    else if (entryA->temperature > entryB->temperature)
        return -1;
    else
        return 0;
}

int readLogEntries(LogEntry logEntries[]) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "EntryNo") != NULL)
            continue;

        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);

        logEntries[count++] = entry;
    }

    fclose(file);
    return count;
}

void writeLogEntries(LogEntry logEntries[], int count) {
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Timestamp\n");

    for (int i = 0; i < count; i++) {
        LogEntry entry = logEntries[i];
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
                entry.entryNo, entry.sensorNo, entry.temperature,
                entry.humidity, entry.light, entry.timestamp);
    }

    fclose(file);
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = readLogEntries(logEntries);

    if (entryCount > 0) {
        qsort(logEntries, entryCount, sizeof(LogEntry), compareTemperatureDescending);

        writeLogEntries(logEntries, entryCount);

        printf("Data sorted and written back to data.csv.\n");
    } else {
        printf("No log entries found.\n");
    }

    return 0;
}
