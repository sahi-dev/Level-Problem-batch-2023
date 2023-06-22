/*Data Viewer:
Write an application to view the log stored in data.csv
Example, say you have the following data in data.csv

------------------------------------

EntryNo,sensorNo,Temperature,Humidity,Light,

1,S1,36.5,100,50,10:30:50
2,S3,30,100,50,10:30:55
3,S2,-6.6,100,10,10:31:00
------------------------------------

b. Also implement functions to display the contents of the array of structures.*/





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

int extractLogEntries(LogEntry logEntries[]) {
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

void displayLogEntries(LogEntry logEntries[], int count) {
    for (int i = 0; i < count; i++) {
        LogEntry entry = logEntries[i];
        printf("EntryNo: %d\n", entry.entryNo);
        printf("SensorNo: %s\n", entry.sensorNo);
        printf("Temperature: %.1f\n", entry.temperature);
        printf("Humidity: %d\n", entry.humidity);
        printf("Light: %d\n", entry.light);
        printf("Timestamp: %s\n", entry.timestamp);
        printf("-------------------------------\n");
    }
}

int main() {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = extractLogEntries(logEntries);

    if (entryCount > 0) {
        // Display the log entries
        displayLogEntries(logEntries, entryCount);
    } else {
        printf("No log entries found.\n");
    }

    return 0;
}
