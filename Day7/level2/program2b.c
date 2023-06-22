/*Update an entry in the data.csv based on the "EntryNo" field

b. Use array of structures and file handling*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

// Structure to hold log entry data
typedef struct {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

// Function to update an entry in data.csv based on EntryNo
void updateEntry(int entryNo, float newTemperature, int newHumidity, int newLight) {
    LogEntry logEntries[MAX_ENTRIES];
    int entryCount = 0;

    // Read the log entries from data.csv
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[100];
    while (fgets(line, sizeof(line), file)) {
        // Skip the header line
        if (strstr(line, "EntryNo") != NULL)
            continue;

        // Parse the line and extract values
        LogEntry entry;
        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]",
               &entry.entryNo, entry.sensorNo, &entry.temperature,
               &entry.humidity, &entry.light, entry.timestamp);

        // Store the entry in the array
        logEntries[entryCount++] = entry;
    }

    fclose(file);

    // Find the entry with the matching EntryNo and update its values
    int entryFound = 0;
    for (int i = 0; i < entryCount; i++) {
        if (logEntries[i].entryNo == entryNo) {
            logEntries[i].temperature = newTemperature;
            logEntries[i].humidity = newHumidity;
            logEntries[i].light = newLight;
            entryFound = 1;
            break;
        }
    }

    if (entryFound) {
        // Write the updated log entries back to data.csv
        file = fopen("data.csv", "w");
        if (file == NULL) {
            printf("Failed to open the file.\n");
            return;
        }

        // Write the header line
        fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Timestamp\n");

        // Write the log entries
        for (int i = 0; i < entryCount; i++) {
            LogEntry entry = logEntries[i];
            fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
                    entry.entryNo, entry.sensorNo, entry.temperature,
                    entry.humidity, entry.light, entry.timestamp);
        }

        fclose(file);
        printf("Entry updated successfully.\n");
    } else {
        printf("Entry not found.\n");
    }
}

int main() {
    int entryNo;
    float newTemperature;
    int newHumidity;
    int newLight;

    printf("Enter the EntryNo to update: ");
    scanf("%d", &entryNo);

    printf("Enter the new Temperature: ");
    scanf("%f", &newTemperature);

    printf("Enter the new Humidity: ");
    scanf("%d", &newHumidity);

    printf("Enter the new Light: ");
    scanf("%d", &newLight);

    updateEntry(entryNo, newTemperature, newHumidity, newLight);

    return 0;
}
