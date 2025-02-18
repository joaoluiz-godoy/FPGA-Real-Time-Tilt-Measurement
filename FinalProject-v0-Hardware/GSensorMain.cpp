

#include <stdio.h>
#include "ADXL345.h"
#include "GSensor.h"

using namespace std;

int main(void) {

    GSensor *g = new GSensor();
    cout << "Start..." << endl;
    uint8_t devid;
    int16_t mg_per_lsb = 4;
    int16_t XYZ[3];
    
    g -> ADXL345_RegRead(0x00, &devid);
    
    if (devid == 0xE5){
        g -> ADXL345_Init();
        
        while(true){
            if (g -> ADXL345_IsDataReady()){
                g -> ADXL345_XYZ_Read(XYZ, mg_per_lsb);
                printf("X=%d mg, Y=%d mg, Z=%d mg\n", XYZ[0], XYZ[1], XYZ[2]);
            }
        }
    } else {
        printf("Incorrect device ID\n");
    }
    return 0;
}