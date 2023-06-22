/* Update an entry in the data.csv based on the "EntryNo" field

a. Use only file handling concepts*/




#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void updateEntry(int entryNo, float newTemperature, int newHumidity, int newLight) {
    FILE *inputFile = fopen("data.csv", "r");
    FILE *outputFile = fopen("temp.csv", "w");

    if (inputFile == NULL || outputFile == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[100];
    int entryFound = 0;

    while (fgets(line, sizeof(line), inputFile)) {
        if (strstr(line, "EntryNo") != NULL) {
            fputs(line, outputFile);
            continue;
        }

        int currentEntryNo;
        float temperature;
        int humidity;
        int light;
        char sensorNo[10];
        char timestamp[10];

        sscanf(line, "%d,%[^,],%f,%d,%d,%[^,]", &currentEntryNo, sensorNo, &temperature, &humidity, &light, timestamp);

        if (currentEntryNo == entryNo) {
            temperature = newTemperature;
            humidity = newHumidity;
            light = newLight;
            entryFound = 1;
        }

        fprintf(outputFile, "%d,%s,%.1f,%d,%d,%s\n", currentEntryNo, sensorNo, temperature, humidity, light, timestamp);
    }

    fclose(inputFile);
    fclose(outputFile);

    if (entryFound) {
        remove("data.csv");
        rename("temp.csv", "data.csv");
        printf("Entry updated successfully.\n");
    } else {
        remove("temp.csv");
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
