
#ifndef GSensor_h
#define GSensor_h

#include <stdint.h>

#include "ADXL345.h"
#include "DE1SoChps.h"
class GSensor : public DE1SoChps
{
private:
   
    void PinmuxConfig();
    
    void I2C0_Init();
    public:
   
    GSensor(); // Constructor
   
    ~GSensor(); // Destructor
    
    void ADXL345_Init();
    
    void ADXL345_RegRead(uint8_t address, uint8_t *value);
    
    void ADXL345_RegWrite(uint8_t address, uint8_t value);
   
    void ADXL345_RegMultiRead(uint8_t address, uint8_t values[], uint8_t len);
    
     void ADXL345_XYZ_Read(int16_t szData16[3], int16_t mg_per_lsb);
     
     bool ADXL345_IsDataReady();
     };
     #endif
