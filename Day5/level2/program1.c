/*Data Parser:
   A data logger transmits the data in ascii format as shown below
   "S1-T:36.5-H:100-L:50"
   Write a function to populate all the data in an array of structure. The output should be like
   Sensor Info:
   ---------------------
   Sensor ID: S1
   Temperature: 36.5 C
   Humidity: 100
   Light Intensity: 50%
   ---------------------*/




#include <stdio.h>
#include <string.h>

struct SensorInfo {
    char sensorID[10];
    float temperature;
    int humidity;
    int lightIntensity;
};

void parseData(const char* data, struct SensorInfo* sensor) {
    sscanf(data, "%[^-]-T:%f-H:%d-L:%d", sensor->sensorID, &(sensor->temperature), &(sensor->humidity), &(sensor->lightIntensity));
}

int main() {
    const char* data = "S1-T:36.5-H:100-L:50";
    struct SensorInfo sensor;

    parseData(data, &sensor);

    printf("---------------------\n");
    printf("Sensor ID: %s\n", sensor.sensorID);
    printf("Temperature: %.1f C\n", sensor.temperature);
    printf("Humidity: %d\n", sensor.humidity);
    printf("Light Intensity: %d%%\n", sensor.lightIntensity);
    printf("---------------------\n");

    return 0;
}


