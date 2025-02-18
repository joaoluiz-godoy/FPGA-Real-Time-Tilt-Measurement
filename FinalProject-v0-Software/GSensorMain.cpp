#include <iostream>
#include <stdio.h> // Include the <stdio.h> header for printf function
#include "ADXL345.h"
#include "GSensor.h"
#include "PIOControl.h"

using namespace std;

// Function to map a value from one range to another
int mapValue(int x, int in_min, int in_max, int out_min, int out_max) {
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}

int main() {
    GSensor *g = new GSensor();
    PIOControl *pio = new PIOControl();

    cout << "Start..." << endl;

    uint8_t devid;
    int16_t mg_per_lsb = 4;
    int16_t XYZ[3];

    g->ADXL345_RegRead(0x00, &devid);

    if (devid == 0xE5) {
        g->ADXL345_Init();

        while (true) {
            if (g->ADXL345_IsDataReady()) {
                g->ADXL345_XYZ_Read(XYZ, mg_per_lsb);
                printf("X=%d mg, Y=%d mg, Z=%d mg\n", XYZ[0], XYZ[1], XYZ[2]);

                // Map the X-axis accelerometer reading to the desired range of -90 to 90 degrees
                int tiltAngle = mapValue(XYZ[0], -1000, 1000, -90, 90);
                printf("Tilt Angle: %d degrees\n", tiltAngle);

                // Convert the tilt angle to a range of 0-180 degrees
                int displayAngle = tiltAngle + 90;
                printf("Display Angle: %d degrees\n", displayAngle);

                // Simulate LED output based on tilt angle (for demonstration)
                pio->WritePIOout(displayAngle);
            }
        }
    } else {
        printf("Incorrect device ID\n");
    }

    delete g;
    delete pio;

    return 0;
}



