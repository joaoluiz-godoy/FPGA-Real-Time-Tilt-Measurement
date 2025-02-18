#ifndef DE1SoChps_h
#define DE1SoChps_h

#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <cstdlib>

class DE1SoChps {
private:
    char *pBase;
    int fd;

public:
    DE1SoChps();  // Constructor
    ~DE1SoChps(); // Destructor

    void RegisterWrite(unsigned int offset, int value);
    int RegisterRead(unsigned int offset);

    static const unsigned int HPS_BRIDGE_BASE; // Verify this value
    static const unsigned int HPS_BRIDGE_SPAN; // Verify this value
    // I2C0 and Pin Multiplexer register offsets
    static const unsigned int I2C0_BASE;       // Placeholder for I2C0 base offset
    static const unsigned int PIN_MUX_BASE;    // Placeholder for Pin Multiplexer base offset
    
    static const unsigned int I2C0_CON;
    static const unsigned int I2C0_TAR;
    static const unsigned int I2C0_DATA_CMD;
    static const unsigned int I2C0_FS_SCL_HCNT;
    static const unsigned int I2C0_FS_SCL_LCNT;
    
    static const unsigned int I2C0_CLKR_INTR;
    static const unsigned int I2C0_ENABLE;
    static const unsigned int I2C0_TXFLR;
    static const unsigned int I2C0_RXFLR;
    static const unsigned int I2C0_ENABLE_STATUS;
    
    static const unsigned int PIN_MUX_GEN_IO7;
    static const unsigned int PIN_MUX_GEN_IO8;
    static const unsigned int PIN_MUX_GPLMUX55;
    static const unsigned int PIN_MUX_GPLMUX56;
    static const unsigned int PIN_MUX_I2C0USEFPGA;
    
};

#endif // DE1SOCHPS_H
