/* Delete an entry in the file data.csv file  on the "EntryNo" field

b. Use array of structures and file handling*/





#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100

struct Entry {
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[9];
};

int readData(struct Entry entries[]) {
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    int count = 0;
    char line[100];

    // Skip the header line
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%d,%[^,],%f,%d,%d,%s",
               &entries[count].entryNo,
               entries[count].sensorNo,
               &entries[count].temperature,
               &entries[count].humidity,
               &entries[count].light,
               entries[count].timestamp);

        count++;
    }

    fclose(file);
    return count;
}

void writeData(struct Entry entries[], int count) {
    FILE *file = fopen("data.csv", "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    fprintf(file, "EntryNo,sensorNo,Temperature,Humidity,Light,Timestamp\n");

    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%.2f,%d,%d,%s\n",
                entries[i].entryNo,
                entries[i].sensorNo,
                entries[i].temperature,
                entries[i].humidity,
                entries[i].light,
                entries[i].timestamp);
    }

    fclose(file);
}

void deleteEntry(struct Entry entries[], int count, int entryNo) {
    int found = 0;
    for (int i = 0; i < count; i++) {
        if (entries[i].entryNo == entryNo) {
            found = 1;
            for (int j = i; j < count - 1; j++) {
                entries[j] = entries[j + 1];
            }
            break;
        }
    }

    if (!found) {
        printf("EntryNo %d not found.\n", entryNo);
        return;
    }

    count--;
    writeData(entries, count);
    printf("EntryNo %d deleted successfully.\n", entryNo);
}

void printData(struct Entry entries[], int count) {
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%.2f\t\t%d\t\t%d\t%s\n",
               entries[i].entryNo,
               entries[i].sensorNo,
               entries[i].temperature,
               entries[i].humidity,
               entries[i].light,
               entries[i].timestamp);
    }
}

int main() {
    struct Entry entries[MAX_ENTRIES];
    int count = readData(entries);

    if (count == 0) {
        return 1;
    }

    int entryNo;
    printf("Enter the EntryNo to delete: ");
    scanf("%d", &entryNo);

    deleteEntry(entries, count, entryNo);

    return 0;
}
