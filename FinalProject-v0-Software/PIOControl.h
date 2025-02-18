#ifndef LEDCONTROL_H
#define LEDCONTROL_H

#include "DE1SoCfpga.h" // Include the header file for DE1SoCfpga class

class PIOControl : public DE1SoCfpga {
private:
    unsigned int out_regValue;
    unsigned int in_regValue;


public:
    PIOControl();
    ~PIOControl();

    void WritePIOout(int value);
    int ReadPIOin();
    
};

#endif // LEDCONTROL_H
